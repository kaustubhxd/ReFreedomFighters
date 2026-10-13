"""specs_s6251.py - hit-reaction hand-off (claim 44): 0x543810 BlowBomb (thiscall, two stack arguments: pos pointer and force; ret 8). The particle system has
a count of 1..3 at +0x28 and an element array at +0xf (0x34-byte elements: position at +0xc, old position at +0x18, velocity at +0x24). The exe helpers (0x43e920,
0x4e0d00, 0x441940, 0x43e960) are the real exe code; no callee is stubbed. The force is sometimes below the threshold 0x67d9fc, and positions are random with
some coinciding with pos (so the squared length is tiny and the maximum takes the constant 0x67cd40). Floats are finite. The record is 0x400 random bytes;
element data is a separate block. Cases: 1000. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S, F
from pfspec import rnd, sf


def _x(c):
    e = c.emu
    r = c.rng
    ps = rnd(c, 0x400)
    n = r.randint(1, 3)
    elems = e.alloc(0x34 * n + 0x40)
    e.wbytes(elems, bytes(r.getrandbits(8) for _ in range(0x34 * n + 0x40)))
    pos = e.alloc(16)
    for k in range(3):
        e.wf32(pos + 4 * k, sf(c.fv(-30, 30)))
    for i in range(n):
        for k in range(3):
            if r.random() < 0.1:
                v = e.rf32(pos + 4 * k)       # coincides with pos: the squared length is tiny
            else:
                v = sf(c.fv(-30, 30))
            e.wf32(elems + i * 0x34 + 0xc + 4 * k, v)
            e.wf32(elems + i * 0x34 + 0x18 + 4 * k, sf(c.fv(-30, 30)))
            e.wf32(elems + i * 0x34 + 0x24 + 4 * k, sf(c.fv(-5, 5)))
    e.w32(ps + 0xf, elems)
    e.w32(ps + 0x28, n)
    force = c.fv(0.0005, 3) if r.random() < 0.8 else c.fv(0.0, 0.0005)
    return [ps, pos, F(force)]


S(0x543810, 'unnamed 0x543810', 'thiscall', None, gen=_x, n=1000)
