#!/usr/bin/env python3
"""classify.py [<name>] [--write] [--out DIR] [--map FILE]    name = result directory written by run_full.py (default `full`)
Reads <out>/<name>/p1 (seed 1) and p2 (seed 2, only functions exact in p1) and classifies every function of the map ({folder: [addr]}, default <out>/folders.json):
  strict-exact            exact + 0 faulting on seeds 1 and 2 under the strict stubs
  <defect class>          mismatch under strict, baseline (strict off) exact  -> the strict stubs found it
  baseline-fail           mismatch/not-exercisable also without strict stubs (stale build, TEB fault, spec): not a strict finding
  harness-error           no usable result (not built, spec load error, crash, timeout)
Defect classes (from the first strict message and the failure text): missing-this/ecx, missing-edx, stdcall-vs-thiscall, wrong-arg-count,
wrong-arg-order, wrong-arg-value, pop-count, tail-jump, call-sequence, junk-deref (fault on a junked register), orig-junk-sensitive
(the ORIGINAL changes under strict: the strict machinery, not the port, is the suspect), unknown.
The classes are a triage aid, not defect counts: many strict-only failures are false positives of the checker (tail jumps, partial-width reads, shared
cleanups); read the evidence column before calling something a bug. seed2-incomplete = exact on seed 1, no usable seed-2 result.
Writes (with --write) <out>/<name>/reverify-strict.tsv (address, folder, class, evidence) and <out>/<name>/classes.json."""
import argparse, json, os, re, sys, glob, collections
HERE = os.path.dirname(os.path.abspath(__file__))
ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
ap.add_argument('name', nargs='?', default='full')
ap.add_argument('--write', action='store_true')
ap.add_argument('--out', default=os.environ.get('FF_STRICT_OUT') or os.path.join(HERE, 'out'))
ap.add_argument('--map')
args = ap.parse_args()
mode = args.name
BASE = os.path.abspath(args.out)
OUT = f'{BASE}/{mode}'
with open(args.map or f'{BASE}/folders.json') as fh:
    todo = json.load(fh)
JUNK = re.compile(r'0xe1c[0-9a-f]{5}\b')


def rows(p):
    d = {}
    for f in glob.glob(f'{OUT}/{p}/*.json'):
        try:
            for r in json.load(open(f)):
                d[r['addr']] = r
        except Exception:
            pass
    return d


def classify_row(r):
    """-> (class, evidence) for one mismatch row."""
    why = r.get('why') or ''
    notes = '; '.join(r.get('strict_notes') or [])
    if r.get('orig_stable') is False:
        return 'orig-junk-sensitive', why[:200] + ' | ' + ' '.join(r.get('orig_diff') or [])[:200]
    m = re.search(r"strict orig='ok' mine=\"?'?(call#\d+ [^\"]*?)\"?(;|$)", why)
    s = m.group(1) if m else None
    if s is None:
        m = re.search(r"strict orig='ok' mine=(.*?)(; |$)", why)
        s = m.group(1).strip('"\'') if m else None
    if s:
        if ' ecx ' in s:
            return 'missing-this/ecx', s[:240]
        if ' edx ' in s:
            return 'missing-edx', s[:240]
        if 'args-permuted' in s:
            return 'wrong-arg-order', s[:240]
        if ' args(' in s:
            cc = re.findall(r"0xcccccccc|0xe1c[0-9a-f]{5}", s.split('port=')[-1])
            return ('wrong-arg-count' if cc else 'wrong-arg-value'), s[:240]
        if 'popdiff' in s:
            return 'pop-count', s[:240]
        if 'orig=tail port=call' in s:
            return 'tail-jump', s[:240]
        if 'callee orig' in s or 'never calls' in s or 'extra call' in s:
            return 'call-sequence', s[:240]
        return 'unknown', s[:240]
    if re.search(r"fault orig=None mine=.*0xe1c", why) or ("fault" in why and JUNK.search(why)):
        return 'junk-deref', why[:240]
    if 'strict orig' in why:
        return 'unknown', why[:240]
    return 'unknown', ('no strict message; ' + why)[:240] + (' | ' + notes if notes else '')


def main():
    p1, p2 = rows('p1'), rows('p2')
    out = []
    cnt = collections.Counter()
    for f, addrs in sorted(todo.items()):
        for a in addrs:
            r1, r2 = p1.get(a), p2.get(a)
            if r1 is None:
                c, ev = 'harness-error', 'no pass-1 row'
            elif r1['status'] == 'harness-error':
                c, ev = ('strict-unsupported' if 'STRICT-UNSUPPORTED' in r1.get('why', '') else 'harness-error'), r1.get('why', '')[-200:]
            elif r1['status'] in ('not-built', 'not-exercisable') or r1['status'] not in ('exact', 'mismatch'):
                c, ev = 'harness-error' if r1['status'] == 'not-built' else 'baseline-fail', '%s %s' % (r1['status'], (r1.get('why') or '')[:160])
            elif r1['status'] == 'mismatch':
                if r1.get('baseline') not in (None, 'exact'):
                    c, ev = 'baseline-fail', 'strict off: %s; %s' % (r1.get('baseline'), (r1.get('baseline_why') or r1.get('why') or '')[:160])
                else:
                    c, ev = classify_row(r1)
                    ev = 's1 case %s: %s' % (r1.get('cases'), ev)
            elif r1.get('faulting_cases', 0):
                c, ev = 'baseline-fail', 'faulting cases %s' % r1['faulting_cases']
            else:   # exact on seed 1
                if r2 is None:
                    c, ev = 'harness-error', 'no pass-2 row'
                elif r2['status'] == 'exact' and not r2.get('faulting_cases'):
                    c, ev = 'strict-exact', ''
                elif r2['status'] == 'harness-error':
                    c, ev = 'seed2-incomplete', 'exact on seed 1; seed 2 did not complete: %s' % (r2.get('why') or '')[:120]
                elif r2['status'] == 'mismatch':
                    if r2.get('baseline') not in (None, 'exact'):
                        c, ev = 'baseline-fail', 'seed 2, strict off: %s' % r2.get('baseline')
                    else:
                        c, ev = classify_row(r2)
                        ev = 's2 case %s: %s' % (r2.get('cases'), ev)
                else:
                    c, ev = 'baseline-fail', 'seed 2 %s' % r2['status']
            cnt[c] += 1
            out.append((a, f, c, ev.replace('\t', ' ').replace('\n', ' ')))
    print('mode', mode, 'functions', len(out))
    for k, v in cnt.most_common():
        print('  %-22s %6d  %5.1f%%' % (k, v, 100.0 * v / len(out)))
    if args.write:
        with open(f'{OUT}/reverify-strict.tsv', 'w') as fh:
            fh.write('address\tfolder\tclass\tevidence\n')
            for a, f, c, ev in out:
                if c != 'strict-exact':
                    fh.write('%s\t%s\t%s\t%s\n' % (a, f, c, ev))
        with open(f'{OUT}/classes.json', 'w') as fh:
            json.dump({a: [f, c, ev] for a, f, c, ev in out}, fh)
        print('wrote', OUT)


main()
