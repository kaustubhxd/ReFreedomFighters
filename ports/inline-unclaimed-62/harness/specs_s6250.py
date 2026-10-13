"""specs_s6250.py - hit-reaction hand-off (claim 43): 0x5438f0 BlowDirBomb (thiscall, three stack arguments, ret 0xc). The particle system has a count in 1..3
at +0x28 and an element array at +0xf (0x34-byte elements: position at +0xc, velocity at +0x24). Direction vectors are random, sometimes near zero (the
BlowBomb path), force is random (sometimes below the threshold 0x67d9fc). 0x543810 (BlowBomb) is a recording stub by address (GUESS: its body is not part of
this batch). The distance, scale and vector-add helpers are the real exe code. Floats are finite. No faulting cases."""
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

    def bomb(em, rr):
        em.calllog.append(('543810', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8)
    e.hook(0x543810, bomb)
    ps = rnd(c, 0x400)
    n = r.randint(1, 3)
    elems = e.alloc(0x34 * n + 0x40)
    e.wbytes(elems, bytes(r.getrandbits(8) for _ in range(0x34 * n + 0x40)))
    for i in range(n):
        for k in range(3):
            e.wf32(elems + i * 0x34 + 0xc + 4 * k, sf(c.fv(-30, 30)))
            e.wf32(elems + i * 0x34 + 0x24 + 4 * k, sf(c.fv(-5, 5)))
    e.w32(ps + 0xf, elems)
    e.w32(ps + 0x28, n)
    pos = e.alloc(16)
    for k in range(3):
        e.wf32(pos + 4 * k, sf(c.fv(-30, 30)))
    dirb = e.alloc(16)
    scale = 1e-7 if r.random() < 0.15 else c.fv(0.5, 5)
    for k in range(3):
        e.wf32(dirb + 4 * k, sf(c.fv(-1, 1) * scale))
    if r.random() < 0.25:
        # the length equals the threshold exactly (sqrt of K*K is K): the len comparison's boundary
        import struct
        kt = struct.unpack('<f', bytes(e.rbytes(0x681370, 4)))[0]
        e.wf32(dirb, sf(kt))
        e.wf32(dirb + 4, 0.0)
        e.wf32(dirb + 8, 0.0)
    force = c.fv(0.0005, 3) if r.random() < 0.8 else c.fv(0.0, 0.0005)
    return [ps, pos, F(force), dirb]


S(0x5438f0, 'unnamed 0x5438f0', 'thiscall', None, gen=_x, n=1000)
