"""specs_s50008.py - u3 (Sonnet) batch 50008, tier H (x87 normalisation). 0x4669f0: this slot 0x390(0, a, &t) rewrites the stack vector t (random floats), slot 0x98(a, b) recorded; 0x441940 and 0x446ee0 run
as exe code; the forward vector at a+0x18 is zero, axis-aligned, parallel to (0,1,0), random, tiny, huge, or NaN / inf, so normalisation runs, is skipped, and hits its edge cases; a and b blocks are random-filled."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _fb(v):
    return struct.pack('<f', v)


def _g4669f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))

    def vec(em, k):
        p = em.arg32(2)
        for j in range(3):
            em.wbytes(p + 4 * j, _fb(r.uniform(-500, 500)))
    me = obj(c, 0x40, {0x390: pystub(c, 3, this=True, stackmark=(1, 2), side=vec), 0x98: pystub(c, 2, this=True)}, nslots=0x394 // 4)
    a = rnd(c, 0x40)
    b = rnd(c, 0x20)
    k = r.random()
    if k < 0.1:
        v = (0.0, 0.0, 0.0)
    elif k < 0.25:
        v = r.choice([(1.0, 0.0, 0.0), (0.0, 0.0, 1.0), (0.0, 1.0, 0.0), (0.0, -2.0, 0.0), (0.0, 3.5, 0.0), (0.0, 0.0, -1.0)])
    elif k < 0.35:
        v = tuple(r.choice([0.0, r.uniform(-3, 3)]) for _ in range(3))
    elif k < 0.42:
        v = tuple(r.uniform(-1e-20, 1e-20) for _ in range(3))
    elif k < 0.5:
        v = tuple(r.uniform(-1e18, 1e18) for _ in range(3))
    elif k < 0.55:
        v = tuple(r.choice(EDGE_F) for _ in range(3))
    else:
        v = tuple(r.uniform(-100, 100) for _ in range(3))
    for j, x in enumerate(v):
        e.wbytes(a + 0x18 + 4 * j, _fb(x) if abs(x) < 3e38 or x != x else _fb(1.0))
    return [me, a, b]


S(0x4669f0, 'GUESS build orthonormal frame from forward vector', 'thiscall', None, ret=None, gen=_g4669f0, nan_heap=True, note='batch50008')
