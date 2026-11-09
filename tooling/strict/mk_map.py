#!/usr/bin/env python3
"""mk_map.py [--results RESULTS.tsv] [--ports DIR] [--out FILE]

Map every function that RESULTS.tsv lists as exact on both seeds to the port folder that holds BOTH a spec row (`S(0x<addr>`) and a registered
port (`PCREG(<addr>`) for it. Writes {folder: [0x<addr>, ...]} (default tooling/strict/out/folders.json), the input of run_full.py.
The folder named in RESULTS.tsv is preferred; otherwise the last folder (sorted) that has both. Functions with no such folder are listed and skipped.
Read-only on the repository. Default RESULTS.tsv = <repo>/RESULTS.tsv, ports = $FF_PORTS or <repo>/ports."""
import argparse
import collections
import glob
import json
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
S_RE = re.compile(r'\bS\(\s*(0x[0-9a-fA-F]+)')
P_RE = re.compile(r'\bPCREG\(\s*(?:0[xX])?([0-9a-fA-F]{5,6})\b')


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--results', default=os.path.join(REPO, 'RESULTS.tsv'))
    ap.add_argument('--ports', default=os.environ.get('FF_PORTS') or os.path.join(REPO, 'ports'))
    ap.add_argument('--out', default=os.path.join(os.environ.get('FF_STRICT_OUT') or os.path.join(HERE, 'out'), 'folders.json'))
    a = ap.parse_args()
    specs = collections.defaultdict(set)   # addr -> folders with a spec row
    ports = collections.defaultdict(set)   # addr -> folders whose src registers it
    for d in sorted(glob.glob(os.path.join(a.ports, '*', ''))):
        f = os.path.basename(d.rstrip('/'))
        for p in glob.glob(d + 'harness/specs*.py'):
            with open(p, errors='ignore') as fh:
                for m in S_RE.finditer(fh.read()):
                    specs[int(m.group(1), 16)].add(f)
        for p in glob.glob(d + 'src/*.cpp'):
            with open(p, errors='ignore') as fh:
                for m in P_RE.finditer(fh.read()):
                    ports[int(m.group(1), 16)].add(f)
    verified = []
    with open(a.results) as fh:
        head = fh.readline().rstrip('\n').split('\t')
        for line in fh:
            r = dict(zip(head, line.rstrip('\n').split('\t')))
            if r.get('seed1', '').startswith('exact') and r.get('seed2', '').startswith('exact'):
                verified.append((int(r['address'], 16), r.get('folder', '')))
    per = collections.defaultdict(list)
    miss = []
    for addr, folder in sorted(verified):
        cands = specs.get(addr, set()) & ports.get(addr, set())
        ch = folder if folder in cands else (sorted(cands)[-1] if cands else None)
        if ch:
            per[ch].append('0x%x' % addr)
        else:
            miss.append('0x%x' % addr)
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, 'w') as fh:
        json.dump(per, fh, indent=0)
    print('exact on both seeds: %d, mapped: %d in %d folders, unmapped: %d' % (len(verified), sum(len(v) for v in per.values()), len(per), len(miss)))
    if miss:
        print('unmapped (no folder with both a spec row and a registered port):', ' '.join(miss[:20]) + (' ...' if len(miss) > 20 else ''))
    print('wrote', a.out)


if __name__ == '__main__':
    main()
