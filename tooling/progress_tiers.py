#!/usr/bin/env python3
"""progress_tiers.py - how many functions are at each verification tier, from what is in this repository (plus your own generated results).

  python3 tooling/progress_tiers.py [--classes FILE] [--json FILE] [--tsv FILE]

Tiers (each includes the one below it):
  T0  function of the original executable (denominator)
  T1  ported: a `PCREG(<addr>, ...)` line in ports/*/src/*.cpp
  T2  differential-verified: RESULTS.tsv has exact-1000-faults0 on seeds 1 and 2 (checker with the callee stubs of the spec files)
  T3  strict-verified: classify.py (tooling/strict) classified it `strict-exact` (exact on both seeds under FF_STRICT_STUBS=1)
Inputs: ports/ (FF_PORTS), RESULTS.tsv, the denominator from <FF_RE_ROOT>/out/functions.jsonl if you have that file (otherwise the denominator is the
set of addresses found in ports/ and RESULTS.tsv, and T0 is then not the whole executable), and the strict classes json (default
tooling/strict/out/full/classes.json, written by `classify.py full --write`; without it T3 is reported as not run).
Only addresses, counts and result rows are read: no game data. Standard library only."""
import argparse
import collections
import glob
import json
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)
PCREG = re.compile(r'PCREG\(\s*(?:0[xX])?([0-9a-fA-F]{5,6})\b')


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--results', default=os.path.join(REPO, 'RESULTS.tsv'))
    ap.add_argument('--ports', default=os.environ.get('FF_PORTS') or os.path.join(REPO, 'ports'))
    ap.add_argument('--classes', default=os.path.join(HERE, 'strict', 'out', 'full', 'classes.json'))
    ap.add_argument('--functions', default=os.path.join(os.environ.get('FF_RE_ROOT') or '', 'out', 'functions.jsonl'))
    ap.add_argument('--json', help='write the per-function rows and the summary here')
    ap.add_argument('--tsv', help='write one row per function (address, folder, tier, strict_class) here')
    a = ap.parse_args()

    funcs = {}
    if os.path.isfile(a.functions):
        with open(a.functions) as f:
            for l in f:
                j = json.loads(l)
                if not j.get('external'):
                    funcs[j['entry']] = sum(e - s for s, e in j['ranges'])
    ported = collections.defaultdict(set)
    for src in sorted(glob.glob(os.path.join(a.ports, '*', 'src', '*.cpp'))):
        folder = src.split(os.sep)[-3]
        with open(src, errors='ignore') as f:
            for m in PCREG.findall(f.read()):
                ported[int(m, 16)].add(folder)
    t2 = {}
    if os.path.isfile(a.results):
        with open(a.results) as f:
            head = f.readline().rstrip('\n').split('\t')
            for l in f:
                r = dict(zip(head, l.rstrip('\n').split('\t')))
                if r.get('seed1', '').startswith('exact') and r.get('seed2', '').startswith('exact') and '-faults0' in r['seed1'] + r['seed2']:
                    t2[int(r['address'], 16)] = r.get('folder', '')
    strict = {}
    have_strict = os.path.isfile(a.classes)
    if have_strict:
        with open(a.classes) as f:
            for addr, v in json.load(f).items():
                strict[int(addr, 16)] = v[1]
    universe = set(funcs) | set(ported) | set(t2)
    rows = []
    for addr in sorted(universe):
        tier = 0
        if addr in ported:
            tier = 1
        if addr in t2:
            tier = 2
        if strict.get(addr) == 'strict-exact' and addr in t2:
            tier = 3
        rows.append({'address': '0x%x' % addr, 'size': funcs.get(addr), 'folder': t2.get(addr) or ','.join(sorted(ported.get(addr, ()))[:1]),
                     'tier': tier, 'strict_class': strict.get(addr, '')})
    tot = len(rows)
    summary = {'denominator': 'out/functions.jsonl' if funcs else 'addresses found in ports/ and RESULTS.tsv', 'total_functions': tot,
               'strict_results': 'present' if have_strict else 'not run (no classes json)'}
    print('denominator: %s (%d functions)' % (summary['denominator'], tot))
    for k, name in enumerate(('T0 original function', 'T1 ported', 'T2 differential-verified, seeds 1+2', 'T3 strict-verified')):
        n = sum(1 for r in rows if r['tier'] >= k)
        summary['T%d' % k] = n
        note = '' if k < 3 or have_strict else '   (strict results not found: run tooling/strict/run_full.py and classify.py)'
        print('  %-38s %6d  %5.1f%%%s' % (name, n, 100.0 * n / max(tot, 1), note))
    if have_strict:
        cls = collections.Counter(r['strict_class'] or '(not run)' for r in rows if r['tier'] >= 2)
        print('  strict classes of the T2 functions:', ', '.join('%s %d' % kv for kv in cls.most_common()))
        summary['strict_classes'] = dict(cls)
    if a.json:
        with open(a.json, 'w') as f:
            json.dump({'summary': summary, 'functions': rows}, f)
    if a.tsv:
        with open(a.tsv, 'w') as f:
            f.write('address\tsize\tfolder\ttier\tstrict_class\n')
            for r in rows:
                f.write('%s\t%s\t%s\t%d\t%s\n' % (r['address'], r['size'] if r['size'] is not None else '', r['folder'], r['tier'], r['strict_class']))


if __name__ == '__main__':
    main()
