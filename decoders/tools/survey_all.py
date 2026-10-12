#!/usr/bin/env python3
"""Run the existing decoders over every scene ZIP and tabulate pass/fail.
usage: python3 -I survey_all.py SCENES_DIR OUT.tsv
SCENES_DIR = samples/game/Scenes. Extracts each *_MAIN/InList ZIP to a temp dir, runs each decoder CLI
(tex.py validate, gms_world.py, oct.py, rooms.py, sgp.py, pathfind.py, zgf.py) and records exit code plus
the last line. Read-only on the game data."""
import glob, os, subprocess, sys, tempfile, zipfile
HERE = os.path.dirname(os.path.abspath(__file__)); DEC = os.path.dirname(HERE)
def run(args):
    try:
        r = subprocess.run([sys.executable, '-I'] + args, capture_output=True, text=True, timeout=300)
        out = (r.stdout + r.stderr).strip().splitlines()
        return r.returncode, (out[-1] if out else '')
    except subprocess.TimeoutExpired:
        return 99, 'timeout'
def main(sd, outp):
    zips = sorted(glob.glob(os.path.join(sd, '**', '*.ZIP'), recursive=True))
    zips = [z for z in zips if os.path.basename(z).lower() != 'loader.zip']
    rows = []
    for z in zips:
        with tempfile.TemporaryDirectory() as td:
            zipfile.ZipFile(z).extractall(td)
            f = {}
            for root, _, fs in os.walk(td):
                for n in fs: f[n.rsplit('.', 1)[-1].upper()] = os.path.join(root, n)
            name = os.path.relpath(z, sd)
            res = {}
            if 'TEX' in f: res['tex'] = run([f'{DEC}/tex.py', 'validate', f['TEX']])
            if 'GMS' in f: res['gms'] = run([f'{DEC}/gms_world.py', f['GMS']] + (['--buf', f['BUF']] if 'BUF' in f else []))
            if 'OCT' in f and 'GMS' in f: res['oct'] = run([f'{DEC}/oct.py', f['OCT'], '--gms', f['GMS']] + (['--prm', f['PRM']] if 'PRM' in f else []))
            if 'RMC' in f: res['rmc'] = run([f'{DEC}/rooms.py', f['RMC']])
            if 'SGP' in f: res['sgp'] = run([f'{DEC}/sgp.py', f['SGP']])
            if 'GMS' in f: res['path'] = run([f'{DEC}/pathfind.py', f['GMS']])
            if 'ZGF' in f: res['zgf'] = run([f'{DEC}/zgf.py', f['ZGF'], os.path.join(td, 'zgf_out')])
            res['_files'] = (0, ','.join(sorted(f)))
            rows.append((name, res))
            print(name, {k: v[0] for k, v in res.items() if k != '_files'}, flush=True)
    with open(outp, 'w') as o:
        for name, res in rows:
            for k, (rc, last) in res.items(): o.write(f'{name}\t{k}\t{rc}\t{last}\n')
if __name__ == '__main__': main(*sys.argv[1:3])
