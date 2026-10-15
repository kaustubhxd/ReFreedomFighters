"""specs_s1210.py - pathfinding batch 1210: EnableSpecialLinks (octree), FindNearestPoint (octree)."""
from pilot import S, F
from pfspec import rnd, sf
from specs_s1209 import geo_octree


def _links(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0xa0)
    n = r.randint(0, 12)
    e.w16(o + 0x86, n)
    links = rnd(c, 12 * n + 12)
    for k in range(6 * n):
        e.w16(links + 2 * k, r.randint(0, 40) if r.random() < 0.95 else r.getrandbits(16))
    e.w32(o + 0x88, links)
    e.w32(o + 0x8c, rnd(c, 4 * n + 4))
    at = e.alloc(8, 2)
    hf = e.alloc(8, 2)
    for k in range(3):
        e.w16(at + 2 * k, r.randint(0, 40))
        e.w16(hf + 2 * k, r.choice([0, 1, 2, 5, 0xffff, 0x8000]))
    return [o, at, hf, r.getrandbits(32)]


S(0x52e4f0, 'ZPFOctree_packed::EnableSpecialLinks', 'thiscall', None, ret='eax', gen=_links)


def _nearest(c):
    o, lv = geo_octree(c)
    e = c.emu
    p = e.alloc(16, 4)
    for k in range(3):
        mn = e.rf32(o + 6 + 4 * k)
        mx = e.rf32(o + 0x12 + 4 * k)
        v = mn + (mx - mn) * c.rng.random() if c.rng.random() < 0.85 and mx == mx and mn == mn else c.fv(-5000, 5000)
        e.wf32(p + 4 * k, sf(v))
    r = c.rng
    return [o, p, F(r.choice([10.0, 3.5, 0.0, 40.0, c.fv()])), F(r.choice([1.0, 2.9, 0.0, c.fv()])),
            F(c.fv(0, 4))]


S(0x52e670, 'ZPFOctree_packed::FindNearestPoint', 'thiscall', None, ret='al', gen=_nearest, n=500)
