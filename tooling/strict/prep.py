#!/usr/bin/env python3
"""prep.py <folder> [--overlay DIR] [--work DIR] [--name NAME]

Prepare an isolated, built work copy of one port folder for the strict checker:

    <work>/<name>/src      copy of <ports>/<folder>/src
    <work>/<name>/harness  copy of <ports>/<folder>/harness
    <work>/<name>/build    pilot.bin + pilot.syms, built with tooling/build.sh

The ports are only read. <ports> is $FF_PORTS (default <repo>/ports); <work> is $FF_STRICT_WORK (default tooling/strict/work, git-ignored).
The shared tooling (pilot.py, pe_emu.py, ff.h, mini_ld.py, build.sh) is used from the repository, nothing is patched per folder.
Python for the linker step is $PY (default: the interpreter running this script).

With --overlay DIR (an experiment, e.g. a corrected spec for a known-bad port): every *.cpp / *.h in DIR is added to (or replaces the same-named file
in) the copy's src/, every specs_*.py replaces/adds a harness file, and DIR/edits.json, if present, is a list of exact, unique replacements
[{"where": "src"|"harness", "file": NAME, "old": TEXT, "new": TEXT}, ...]. $BUILD_SH optionally names an alternative build script (same arguments as build.sh).
"""
import argparse
import glob
import json
import os
import shutil
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLING = os.path.dirname(HERE)
REPO = os.path.dirname(TOOLING)
PORTS = os.environ.get('FF_PORTS') or os.path.join(REPO, 'ports')
WORK = os.environ.get('FF_STRICT_WORK') or os.path.join(HERE, 'work')
PY = os.environ.get('PY') or sys.executable
BUILD_SH = os.path.join(TOOLING, 'build.sh')


def prep(folder, overlay=None, name=None, work=None, ports=None):
    """Build a work copy and return its path."""
    ports = ports or PORTS
    w = os.path.join(work or WORK, name or folder)
    src = os.path.join(ports, folder)
    if not os.path.isdir(os.path.join(src, 'src')):
        raise RuntimeError('no such port folder: %s' % src)
    if os.path.exists(w):
        shutil.rmtree(w)
    os.makedirs(w)
    for part in ('src', 'harness'):
        if os.path.isdir(os.path.join(src, part)):
            shutil.copytree(os.path.join(src, part), os.path.join(w, part), ignore=shutil.ignore_patterns('__pycache__'))
        else:
            os.makedirs(os.path.join(w, part))
    if overlay:
        for p in glob.glob(os.path.join(overlay, '*.cpp')) + glob.glob(os.path.join(overlay, '*.h')):
            shutil.copy(p, os.path.join(w, 'src'))
        for p in glob.glob(os.path.join(overlay, 'specs_*.py')):
            shutil.copy(p, os.path.join(w, 'harness'))
        edits = os.path.join(overlay, 'edits.json')
        if os.path.exists(edits):
            with open(edits) as f:
                for e in json.load(f):
                    fp = os.path.join(w, e['where'], e['file'])
                    with open(fp) as f:
                        text = f.read()
                    if text.count(e['old']) != 1:
                        raise RuntimeError('overlay edit does not match exactly once: %s %r (%d)' % (fp, e['old'][:60], text.count(e['old'])))
                    with open(fp, 'w') as f:
                        f.write(text.replace(e['old'], e['new']))
    env = dict(os.environ, PY=PY, PILOT_BUILD=os.path.join(w, 'build'))
    r = subprocess.run(['sh', os.environ.get('BUILD_SH') or BUILD_SH, w], capture_output=True, text=True, env=env)
    if r.returncode:
        raise RuntimeError('build failed: ' + (r.stderr or r.stdout)[-1500:])
    return w


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('folder')
    ap.add_argument('--overlay')
    ap.add_argument('--work')
    ap.add_argument('--name')
    a = ap.parse_args()
    print(prep(a.folder, a.overlay, a.name, a.work))


if __name__ == '__main__':
    main()
