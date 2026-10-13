"""specs_s6232.py - unclaimed-62 claim 25 (short exe leaves): four small thiscall functions. The two chain counts (0x4d1b70 through +0x30 from
this+0x24, 0x4d1b90 through +8 from this+0x18) get chains of 0..4 nodes ending in null. 0x5a4590 gets an argument in 0..6 (the range test); 0x54a220 gets
a counter at this+0xa269 that is zero in about a third of cases and an argument that is zero in about a fifth. The records are 0x1000 bytes of random data.
No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _chain(c, head_off, link, hmm_off, rec):
    e = c.emu
    r = c.rng
    n = r.randint(0, 4)
    nodes = [rnd(c, 0x100) for _ in range(n)]
    for k, nd in enumerate(nodes):
        e.w32(nd + link, nodes[k + 1] if k + 1 < n else 0)
    e.w32(rec + head_off, nodes[0] if nodes else 0)
    return rec


def _x4d1b70(c):
    rec = rnd(c, 0x1000)
    return [_chain(c, 0x24, 0x30, 0, rec)]


def _x4d1b90(c):
    rec = rnd(c, 0x1000)
    return [_chain(c, 0x18, 0x8, 0, rec)]


def _x5a4590(c):
    rec = rnd(c, 0x1000)
    return [rec, c.rng.randint(0, 6)]


def _x54a220(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x1000)
    e.w32(rec + 0xa269, r.choice([0, 0, r.randint(1, 1000)]))
    return [rec, r.choice([0, r.getrandbits(16)])]


S(0x4d1b70, 'unnamed 0x4d1b70', 'thiscall', None, ret='eax', gen=_x4d1b70, n=1000)
S(0x4d1b90, 'unnamed 0x4d1b90', 'thiscall', None, ret='eax', gen=_x4d1b90, n=1000)
S(0x5a4590, 'unnamed 0x5a4590', 'thiscall', None, ret='eax', gen=_x5a4590, n=1000)
S(0x54a220, 'unnamed 0x54a220', 'thiscall', None, ret='eax', gen=_x54a220, n=1000)
