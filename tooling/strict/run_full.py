#!/usr/bin/env python3
"""run_full.py <pass> [-j N] [--chunk N] [--map FILE] [--name NAME] [--only ADDR,ADDR,...] [--reprep]

Run the strict checker over many functions.
  pass 1   seed 1, n=1000, every function of the map
  pass 2   seed 2, n=1000, only the functions that were exact under strict in pass 1 (read from the same result directory)
The map is {folder: [0x<addr>, ...]} (default <out>/folders.json, written by mk_map.py; or any file of that shape). --only restricts it to some addresses.
Work copies: <work>/<folder> (prep.py: copy of ports/<folder> + build); jobs are chunks of --chunk N functions (default 25) of one folder, one pilot_strict.py process each
(FF_STRICT_STUBS=1, nice 10). Results: <out>/<name>/p<pass>/<folder>.c<NN>.json (+ .log), default name `full`. Resumable: a chunk whose json exists is
skipped, so re-run the same command after a stop. Progress: <out>/<name>/progress_p<pass>.txt. Parallelism default = cores - 2.
Environment: FF_RE_ROOT (directory with bin/ and the original executable), FF_PORTS, FF_STRICT_WORK, FF_STRICT_OUT (default tooling/strict/out), PY.
Reads the ports only. Then run classify.py <name>."""
import argparse
import concurrent.futures as cf
import glob
import json
import os
import subprocess
import sys
import threading
import time

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLING = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import prep  # noqa: E402

PY = prep.PY
ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
ap.add_argument('pass_', metavar='pass', choices=('1', '2'))
ap.add_argument('-j', type=int, default=max(1, (os.cpu_count() or 4) - 2))
ap.add_argument('--chunk', type=int, default=25, help='functions per pilot process')
ap.add_argument('--name', default='full', help='result directory name under the out directory')
ap.add_argument('--out', default=os.environ.get('FF_STRICT_OUT') or os.path.join(HERE, 'out'))
ap.add_argument('--map', help='folders json (default <out>/folders.json)')
ap.add_argument('--only', help='comma-separated addresses to run')
ap.add_argument('--reprep', action='store_true', help='rebuild the work copies')
args = ap.parse_args()
ps, j, CHUNK = args.pass_, args.j, args.chunk
OUT = os.path.join(os.path.abspath(args.out), args.name)
os.makedirs('%s/p%s' % (OUT, ps), exist_ok=True)
with open(args.map or os.path.join(os.path.abspath(args.out), 'folders.json')) as fh:
    todo = json.load(fh)
if args.only:
    want = {a.strip().lower() if a.strip().lower().startswith('0x') else '0x' + a.strip().lower() for a in args.only.split(',') if a.strip()}
    todo = {f: [x for x in addrs if x.lower() in want] for f, addrs in todo.items()}
    todo = {f: a for f, a in todo.items() if a}
seed = int(ps)
if ps == '2':     # only what passed pass 1
    keep = {}
    for f, addrs in todo.items():
        ok = set()
        for p in glob.glob('%s/p1/%s.c*.json' % (OUT, f)):
            try:
                with open(p) as fh:
                    for r in json.load(fh):
                        if r['status'] == 'exact' and r.get('faulting_cases', 0) == 0:
                            ok.add(r['addr'])
            except Exception:
                pass
        a = [x for x in addrs if x in ok]
        if a:
            keep[f] = a
    todo = keep
lock = threading.Lock()
pg = open('%s/progress_p%s.txt' % (OUT, ps), 'a')


def log(s):
    with lock:
        pg.write('%s %s\n' % (time.strftime('%m-%d %H:%M:%S'), s))
        pg.flush()


prepped = {}


def run_chunk(f, ci, addrs):
    out = '%s/p%s/%s.c%02d.json' % (OUT, ps, f, ci)
    if os.path.exists(out):
        return f, ci, 'skip'
    w = os.path.join(prep.WORK, f)
    with lock:
        need = f not in prepped
        if need:
            prepped[f] = threading.Event()
    if need:
        try:
            if not os.path.exists(w + '/build/pilot.bin') or args.reprep:
                prep.prep(f, None, f)
        except Exception as e:
            prepped[f].err = str(e)
        prepped[f].set()
    else:
        prepped[f].wait()
    if getattr(prepped[f], 'err', None):
        with open(out[:-5] + '.log', 'w') as fh:
            fh.write('PREP ERROR ' + prepped[f].err)
        with open(out, 'w') as fh:
            json.dump([{'addr': a, 'status': 'harness-error', 'why': 'prep error: ' + prepped[f].err[:200], 'cases': 0} for a in addrs], fh)
        return f, ci, 'prep error'
    env = dict(os.environ, PILOT_SPECS=w + '/harness', PILOT_BUILD=w + '/build', FF_STRICT_STUBS='1')
    env.pop('PILOT_EXE_VERIFY', None)
    cmd = ['nice', '-n', '10', PY, os.path.join(HERE, 'pilot_strict.py'), os.path.join(TOOLING, 'pilot.py')] + [a.replace('0x', '') for a in addrs] + \
          ['-n', '1000', '--seed', str(seed), '--no-build', '-q', '--json', out + '.part']
    try:
        r = subprocess.run(cmd, capture_output=True, text=True, env=env, cwd=w, timeout=5400)
        with open(out[:-5] + '.log', 'w') as fh:
            fh.write(r.stdout[-20000:] + '\n--stderr--\n' + r.stderr[-6000:])
        if os.path.exists(out + '.part'):
            os.rename(out + '.part', out)
        else:
            with open(out, 'w') as fh:
                json.dump([{'addr': a, 'status': 'harness-error', 'why': 'no result file (pilot crashed): ' + r.stderr[-300:], 'cases': 0} for a in addrs], fh)
    except subprocess.TimeoutExpired:
        with open(out[:-5] + '.log', 'w') as fh:
            fh.write('TIMEOUT')
        with open(out, 'w') as fh:
            json.dump([{'addr': a, 'status': 'harness-error', 'why': 'timeout 5400 s', 'cases': 0} for a in addrs], fh)
    return f, ci, 'done'


jobs = []
for f, addrs in sorted(todo.items(), key=lambda kv: -len(kv[1])):
    for ci, k in enumerate(range(0, len(addrs), CHUNK)):
        jobs.append((f, ci, addrs[k:k + CHUNK]))
log('START name=%s pass=%s jobs=%d functions=%d j=%d' % (args.name, ps, len(jobs), sum(len(a) for a in todo.values()), j))
with cf.ThreadPoolExecutor(j) as ex:
    futs = [ex.submit(run_chunk, *jb) for jb in jobs]
    for fu in cf.as_completed(futs):
        try:
            log('%s c%02d %s' % fu.result())
        except Exception as e:
            log('EXC %r' % (e,))
    log('ALL DONE')
print('done: results in %s/p%s' % (OUT, ps))
