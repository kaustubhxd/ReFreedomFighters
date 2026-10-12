"""specs_s6234.py - unclaimed-62 claim 27 (short exe leaves): 0x4dd8d0 (thiscall, no argument, returns al; this+0x54 -> +0x10 -> byte +0x18: null in
about a third of the cases each, the flag bit random) and 0x54e600 (thiscall, one argument; a zero-terminated buffer of 0..30 bytes is copied to
this+0x1ca, written bytes compared). The records are 0x1000 bytes of random data. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _x4dd(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x1000)
    if r.random() < 0.7:
        q = rnd(c, 0x100)
        e.w32(q + 0x18, r.getrandbits(8))
        p = rnd(c, 0x100)
        e.w32(p + 0x10, q if r.random() < 0.8 else 0)
        e.w32(rec + 0x54, p if r.random() < 0.8 else 0)
    else:
        e.w32(rec + 0x54, 0)
    return [rec]


def _x54e(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x1000)
    n = r.randint(0, 30)
    buf = e.alloc(64)
    e.wbytes(buf, bytes(r.choice(b'abcxyz') for _ in range(n)) + b'\x00')
    return [rec, buf]


S(0x4dd8d0, 'unnamed 0x4dd8d0', 'thiscall', None, ret='al', gen=_x4dd, n=300)
S(0x54e600, 'unnamed 0x54e600', 'thiscall', None, gen=_x54e, n=300)
