"""specs_s1229.py - pathfinding batch 1229: ZActor::SetAutoNewPathDest (0x47bce0). vdist2 is the exe's own; the actor's
vtable slot +0x63c is a logged stub (the same in both builds). The path object has a count at +8 and a base at +0xc."""
import struct
from pilot import S, F
from pfspec import rnd, vtable, sf


def _ad(c):
    r = c.rng
    e = c.emu
    actor = rnd(c, 0x800)
    e.w32(actor, vtable(c, 'actor', 0x700, impl={0x63c: lambda em, a: 0}, argwords={0x63c: 1}))
    if r.random() < 0.6:
        n = r.randint(1, 4)
        pts = e.alloc(16 * (n + 1), 16)
        e.wbytes(pts, bytes(r.getrandbits(8) for _ in range(16 * (n + 1))))
        path = e.alloc(0x20, 4)
        e.w32(path + 8, n)
        e.w32(path + 0xc, pts + 0xc)     # base chosen so that base - 0xc + n*16 lands on a stored point
        e.w32(actor + 0x695, path)
    else:
        e.w32(actor + 0x695, 0)
    dest = e.alloc(16, 4)
    for k in range(3):
        e.wf32(dest + 4 * k, sf(c.fv(-300, 300)))
    return [actor, dest]


S(0x47bce0, 'ZActor::SetAutoNewPathDest', 'thiscall', None, gen=_ad, n=200)
