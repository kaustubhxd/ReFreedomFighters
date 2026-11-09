#!/usr/bin/env python3
"""selftest.py - regression corpus for the strict checker: ports KNOWN to be wrong must keep being reported as failing.

  python3 selftest.py calibrate [-j 4] [-n 300]   run every corpus row through every detector and record which detector caught it
  python3 selftest.py check     [-j 4] [-n 300]   re-run; exit 1 if a row that some detector caught at calibration is no longer caught
                                                  (= the checker lost a detection). Rows no detector catches are listed as BLIND, never silently passed.
Options: --only 0x4cd180,0x4e4050   run only these corpus rows (calibrate then updates just those rows of the table)
         --limit N                  run only the first N corpus rows
         --out DIR                  output directory (default $FF_STRICT_OUT or tooling/strict/out; per-run json in DIR/selftest/, tables in DIR)
         --overlays DIR             directory with per-address overlays (default $FF_STRICT_OVERLAYS; none = those detectors are skipped, see below)
         --fail-on-blind            also exit 1 for rows that no detector catches (by default only LOST detections fail)

Environment: FF_RE_ROOT  directory containing bin/ with the original executable (as for pe_emu.py)
             FF_PORTS    ports directory to test (default <repo>/ports). The corpus names ports as they were DEFECTIVE; once a defect is fixed
                         in ports/ the row is no longer detected, so point FF_PORTS at a checkout of the ports from before the fixes
             FF_STRICT_WORK  work directory for the built copies (default tooling/strict/work)    PY  python interpreter for the build step

Corpus (selftest_corpus_src.tsv): addr, folder, origin, note. 51 rows are the ports of a public issue about wrongly stubbed callees (origin issue1-51),
the rows of known.tsv are known-bad ports found earlier (they must all be in the corpus), the rest are further confirmed-bad ports. Some addresses
select ports that have since been corrected; an address alone does not prove its current source defective.

Detectors (a row counts as caught when any of them reports a mismatch on a run whose ORIGINAL side completed without fault and was unchanged by the
strict machinery):
  strict         the strict launcher (FF_STRICT_STUBS=1) on the folder's port, seed 1
  speconly       the old port with a corrected spec: needs <overlays>/<hex>-speconly (skipped when absent)
  noargs         fixture-specific run with strict argument logging disabled: needs <overlays>/<hex>-noargs (skipped when absent)
  eax-sensitive  synthetic target that observes incoming EAX (origin synthetic-contract): needs <overlays>/<hex>-eax-spec and -eax-control (skipped when absent)
  strict_seed2   seed 2, 1000 cases, when none of the above caught the row
A few corpus rows (a defect that is not at a call boundary, or one that only a source-level check can see) are expected to be BLIND here.
Results: DIR/selftest/<mode>/<hex>.<tag>.json ; tables DIR/selftest_corpus.tsv (calibrate) and DIR/selftest_last.tsv (check).
"""
import argparse
import concurrent.futures as cf
import hashlib
import json
import os
import subprocess
import sys
import threading

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLING = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import prep  # noqa: E402

PY = prep.PY
PREP_LOCK = threading.Lock()
OUT = os.environ.get('FF_STRICT_OUT') or os.path.join(HERE, 'out')
OVERLAYS = os.environ.get('FF_STRICT_OVERLAYS') or ''
COLS = ['addr', 'folder', 'origin', 'detected_by', 'strict', 'speconly', 'noargs', 'strict_seed2', 'eax_sensitive', 'original_audit', 'strict_why', 'note']
DETECTORS = ('strict', 'speconly', 'noargs', 'strict_seed2', 'eax-sensitive')


def corpus():
    with open(os.path.join(HERE, 'selftest_corpus_src.tsv')) as f:
        rows = [l.rstrip('\n').split('\t') for l in f if l.strip() and not l.startswith('#')]
    cases = [dict(addr=r[0], folder=r[1], origin=r[2], note=r[3] if len(r) > 3 else '') for r in rows]
    by_addr = {r['addr']: r['folder'] for r in cases}
    if len(by_addr) != len(cases):
        raise SystemExit('SELFTEST FAIL: duplicate corpus addresses')
    n_issue = sum(1 for r in cases if r['origin'] == 'issue1-51')
    if n_issue != 51:
        raise SystemExit('SELFTEST FAIL: expected 51 rows of origin issue1-51, found %d' % n_issue)
    with open(os.path.join(HERE, 'known.tsv')) as f:
        required = [tuple(line.split()[:2]) for line in f if line.strip() and not line.startswith('#')]
    missing = [(a, folder) for a, folder in required if by_addr.get(a) != folder]
    if missing:
        raise SystemExit('SELFTEST FAIL: known.tsv rows missing from the corpus or with another folder: ' + str(missing))
    return cases


def fingerprint(folder, overlay):
    """Invalidate a built work copy when its port files, the shared tooling or the overlay change."""
    h = hashlib.sha256()
    files = []
    pdir = os.path.join(prep.PORTS, folder)
    for sub in ('src', 'harness'):
        d = os.path.join(pdir, sub)
        if os.path.isdir(d):
            files += [os.path.join(d, n) for n in os.listdir(d) if os.path.isfile(os.path.join(d, n))]
    files += [os.path.join(TOOLING, n) for n in ('build.sh', 'mini_ld.py', 'ff.h', 'pe_emu.py', 'pilot.py')] + [os.path.join(HERE, 'prep.py')]
    if overlay and os.path.isdir(overlay):
        files += [os.path.join(overlay, n) for n in os.listdir(overlay) if os.path.isfile(os.path.join(overlay, n))]
    if os.environ.get('BUILD_SH'):
        files.append(os.environ['BUILD_SH'])
    for p in sorted(set(files)):
        h.update(p.encode() + b'\0')
        with open(p, 'rb') as f:
            h.update(f.read())
        h.update(b'\0')
    return h.hexdigest()


def run_strict(c, n, mode, overlay=None, tag='strict', seed=1, noargs=False):
    name = 'selftest-' + c['folder'] if not overlay else 'selftest-%s-%s' % (c['addr'][2:], os.path.basename(overlay))
    w = os.path.join(prep.WORK, name)
    outdir = os.path.join(OUT, 'selftest', mode)
    os.makedirs(outdir, exist_ok=True)
    j = os.path.join(outdir, '%s.%s.json' % (c['addr'][2:], tag))
    if os.path.exists(j):
        os.remove(j)
    try:
        with PREP_LOCK:
            stamp = os.path.join(w, 'input-fingerprint')
            fp = fingerprint(c['folder'], overlay)
            current = open(stamp).read().strip() if os.path.isfile(stamp) else None
            if not os.path.exists(os.path.join(w, 'build', 'pilot.bin')) or current != fp:
                prep.prep(c['folder'], overlay, name)
                with open(stamp, 'w') as f:
                    f.write(fp + '\n')
    except Exception as e:
        return {'status': 'harness-error', 'why': 'prep: ' + str(e)[:200]}
    env = dict(os.environ, PILOT_SPECS=os.path.join(w, 'harness'), PILOT_BUILD=os.path.join(w, 'build'), FF_STRICT_STUBS='1')
    env.pop('PILOT_EXE_VERIFY', None)
    env.pop('FF_STRICT_SITE_CONTRACTS', None)
    env['FF_AUDIT_CASES'] = '1'  # do not count a mismatch unless the observed original case completed
    if noargs:
        env['FF_STRICT_NOARGS'] = '1'
    else:
        env.pop('FF_STRICT_NOARGS', None)
    cmd = [PY, os.path.join(HERE, 'pilot_strict.py'), os.path.join(TOOLING, 'pilot.py'), c['addr'][2:], '-n', str(n), '--seed', str(seed),
           '--no-build', '-q', '--json', j]
    try:
        r = subprocess.run(cmd, env=env, cwd=w, capture_output=True, text=True, timeout=3600)
    except subprocess.TimeoutExpired:
        return {'status': 'timeout'}
    try:
        with open(j) as f:
            return json.load(f)[0]
    except Exception:
        return {'status': 'harness-error', 'why': (r.stdout + r.stderr)[-200:]}


def failing(res):
    # A mismatch cannot validate the port when strict instrumentation changes
    # the original execution or its recorded observations on that case.
    return (res.get('status') == 'mismatch'
            and res.get('audited_original_faults') == ['<no fault>']
            and res.get('orig_stable') is True
            and res.get('orig_rec_changed') is False)


def audit_label(res):
    if res.get('status') != 'mismatch':
        return ''
    vals = res.get('audited_original_faults')
    if vals == ['<no fault>']:
        if res.get('orig_stable') is not True:
            return 'original-core-unstable-or-unknown'
        if res.get('orig_rec_changed') is not False:
            return 'original-observation-changed-or-unknown'
        return 'original-completed-stable'
    if not vals:
        return 'original-audit-unavailable'
    if '<no fault>' in vals:
        return 'original-audit-ambiguous'
    return 'original-faulted'


def overlay_dir(addr, suffix):
    if not OVERLAYS:
        return None
    d = os.path.join(OVERLAYS, '%s-%s' % (addr[2:], suffix))
    return d if os.path.isdir(d) else None


def run_row(c, n, mode):
    out = dict(c)
    s = run_strict(c, n, mode)
    out['strict'] = s.get('status', '?') + ('' if not s.get('faulting_cases') else '+faults')
    out['strict_why'] = (s.get('why') or '')[:160]
    out['strict_fail'] = failing(s)
    audit = ['strict:' + audit_label(s)] if audit_label(s) else []
    ov = overlay_dir(c['addr'], 'speconly')
    if ov:
        s2 = run_strict(c, n, mode, ov, 'speconly')
        out['speconly'] = s2.get('status', '?')
        out['speconly_fail'] = failing(s2)
        if audit_label(s2):
            audit.append('speconly:' + audit_label(s2))
    # Explicit fixture-specific ablation: argument logging is disabled, not silently treated as full strict coverage.
    ab = overlay_dir(c['addr'], 'noargs')
    if ab:
        sa = run_strict(c, n, mode, ab, 'noargs', noargs=True)
        out['noargs'] = sa.get('status', '?')
        out['noargs_fail'] = failing(sa)
        if audit_label(sa):
            audit.append('noargs:' + audit_label(sa))
    eax_spec, eax_control = overlay_dir(c['addr'], 'eax-spec'), overlay_dir(c['addr'], 'eax-control')
    if c['origin'] == 'synthetic-contract' and eax_spec and eax_control:
        se = run_strict(c, n, mode, eax_spec, 'eax-spec')
        sc = run_strict(c, n, mode, eax_control, 'eax-control')
        out['eax_sensitive'] = '%s/control-%s' % (se.get('status', '?'), sc.get('status', '?'))
        out['eax-sensitive_fail'] = (failing(se) and (se.get('why') or '').startswith('eax orig=')
                                     and sc.get('status') == 'exact' and not sc.get('faulting_cases', 0))
        if audit_label(se):
            audit.append('eax-sensitive:' + audit_label(se))
    # A second independent seed can expose fixture-dependent mismatches.
    # Run it only when seed 1 and the overlay detectors did not fail.
    if not any(out.get(k + '_fail') for k in ('strict', 'speconly', 'noargs', 'eax-sensitive')):
        s3 = run_strict(c, max(n, 1000), mode + '-seed2', seed=2)
        out['strict_seed2'] = s3.get('status', '?')
        out['strict_seed2_fail'] = failing(s3)
        if audit_label(s3):
            audit.append('strict_seed2:' + audit_label(s3))
    out['original_audit'] = ';'.join(audit)
    out['detected_by'] = ','.join(k for k in DETECTORS if out.get(k + '_fail')) or 'BLIND'
    return out


def read_table(path):
    rows = {}
    if os.path.exists(path):
        with open(path) as f:
            lines = f.read().split('\n')
        head = lines[0].split('\t')
        for l in lines[1:]:
            if l.strip():
                r = dict(zip(head, l.split('\t')))
                rows[r['addr']] = r
    return rows


def write_table(path, rows):
    with open(path, 'w') as f:
        f.write('\t'.join(COLS) + '\n')
        for r in rows:
            f.write('\t'.join(' '.join(str(r.get(k, '')).split()) for k in COLS) + '\n')


def main():
    parser = argparse.ArgumentParser(description='Run the strict-checker regression corpus')
    parser.add_argument('mode', choices=('check', 'calibrate'))
    parser.add_argument('-j', type=int, default=4, help='workers (1-8)')
    parser.add_argument('-n', type=int, default=300, help='cases per run')
    parser.add_argument('--only', help='comma-separated corpus addresses to run')
    parser.add_argument('--limit', type=int, help='run only the first N corpus rows')
    parser.add_argument('--out', help='output directory')
    parser.add_argument('--overlays', help='directory with <hex>-speconly / -noargs / -eax-spec / -eax-control overlays')
    parser.add_argument('--fail-on-blind', action='store_true', help='exit 1 also when a row is caught by no detector')
    args = parser.parse_args()
    global OUT, OVERLAYS
    if args.out:
        OUT = os.path.abspath(args.out)
    if args.overlays:
        OVERLAYS = os.path.abspath(args.overlays)
    mode, j, n = args.mode, args.j, args.n
    if not 1 <= j <= 8:
        parser.error('workers must be between 1 and 8')
    if n < 1:
        parser.error('cases must be positive')
    os.makedirs(OUT, exist_ok=True)
    cs = corpus()
    if args.only:
        want = {a.strip().lower() if a.strip().lower().startswith('0x') else '0x' + a.strip().lower() for a in args.only.split(',') if a.strip()}
        unknown = sorted(want - {c['addr'] for c in cs})
        if unknown:
            parser.error('not in the corpus: ' + ' '.join(unknown))
        cs = [c for c in cs if c['addr'] in want]
    if args.limit:
        cs = cs[:args.limit]
    with cf.ThreadPoolExecutor(j) as ex:
        res = list(ex.map(lambda c: run_row(c, n, mode), cs))
    caught = [r for r in res if r['detected_by'] != 'BLIND']
    blind = [r for r in res if r['detected_by'] == 'BLIND']
    print('corpus rows run %d: caught %d, BLIND %d' % (len(res), len(caught), len(blind)))
    for r in res:
        print('  %-6s %s %s detected_by=%s strict=%s' % ('caught' if r['detected_by'] != 'BLIND' else 'BLIND', r['addr'], r['folder'], r['detected_by'], r['strict']))
    cal = os.path.join(OUT, 'selftest_corpus.tsv')
    if mode == 'calibrate':
        merged = read_table(cal)
        for r in res:
            merged[r['addr']] = r
        order = [c['addr'] for c in corpus()]
        write_table(cal, [merged[a] for a in order if a in merged])
        print('wrote', cal)
        return
    write_table(os.path.join(OUT, 'selftest_last.tsv'), res)
    exp = read_table(cal)
    if not exp:
        raise SystemExit('no calibration table at %s: run `selftest.py calibrate` first (on the ports as they were before the fixes)' % cal)
    lost = []
    for r in res:
        e = exp.get(r['addr'])
        if e is None:
            lost.append((r['addr'], 'a calibration row', r['detected_by']))
            continue
        for d in [x for x in e['detected_by'].split(',') if x != 'BLIND']:
            if d not in r['detected_by'].split(','):
                lost.append((r['addr'], d, r['detected_by']))
    for a, d, now in lost:
        if d == 'a calibration row':
            print('  NOCAL %s: no row in %s (calibrate it first)' % (a, cal))
        else:
            print('  LOST %s: was caught by %s, now %s' % (a, d, now))
    bad = bool(lost) or (args.fail_on_blind and blind)
    print('SELFTEST', 'FAIL' if bad else 'PASS', '(%d lost detections, %d blind rows)' % (len(lost), len(blind)))
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
