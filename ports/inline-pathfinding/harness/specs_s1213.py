"""specs_s1213.py - pathfinding batch 1213: component lookup, FindPathCoarse."""
from pilot import S, F
from pfspec import rnd, reporter
from specs_s1206 import NN, NA
from specs_s1212 import coarse_octree, NS


def comp_octree(c):
    r = c.rng
    e = c.emu
    o, lv, it = coarse_octree(c)
    e.w32(o + 0x6c, rnd(c, 4 * 64))
    for k in range(NA):
        e.w16(e.r32(o + 0x5a) + k * 12 + 8, r.randrange(48))
    sz = e.r32(o + 0x78)
    for k in range(NN):
        e.w16(sz + 10 * k + 4, r.randrange(40))
    remap = rnd(c, 64)
    for k in range(64):
        e.w8(remap + k, r.choice([0, 1, 2, 3]))
    e.w32(o + 0x82, remap)
    e.w8(0x701b5c, r.choice([0, 1]))
    e.w8(0x701b5d, r.choice([0, 1]))
    return o, lv, it


def cellp(c, o):
    e = c.emu
    a = e.alloc(8, 2)
    for k, off in enumerate((0x3c, 0x40, 0x44)):
        e.w16(a + 2 * k, c.rng.randint(0, e.r32(o + off) - 1))
    return a


def _bits(c):
    r = c.rng
    return [rnd(c, 4), rnd(c, 64), r.randrange(64), r.choice([0, 1, 2, 3])]


S(0x530890, 'ZPFOctree_packed::<bit planes value> (no GC name)', 'thiscall', None, ret='eax', gen=_bits)


def _ecomp(c):
    o, lv, it = comp_octree(c)
    return [it, cellp(c, o)]


S(0x531810, 'ZPFOctreeIterator_packed::<element component> (no GC name)', 'thiscall', None, ret='eax',
  gen=_ecomp, n=300)


def _comp(c):
    o, lv, it = comp_octree(c)
    return [o, cellp(c, o), c.rng.randint(0, lv)]


S(0x530940, 'ZPFOctree_packed::<cell component on level> (no GC name)', 'thiscall', None, ret='eax', gen=_comp,
  n=300)


def _coarse(c):
    r = c.rng
    reporter(c)
    o, lv, it = comp_octree(c)
    e = c.emu
    big = 600 if r.random() < 0.7 else NS
    arr = e.alloc(big * 0x15 + 0x40, 4)
    for k in range(big):
        p = arr + k * 0x15
        e.wf32(p + 0xa, 100000.0)
        e.w8(p + 0x14, r.choice([0, 0, 1]))
        e.w16(p + 0xe, r.randrange(4))
    e.w32(o + 0x98, arr)
    e.w16(o + 0x50, big)
    e.w16(e.r32(it + 4), r.randint(1, 40))
    return [o, cellp(c, o), cellp(c, o), F(r.choice([0.0, 0.0, 5.0, 30.0, c.fv(0, 50)])),
            r.choice([lv - 1, lv - 2, lv - 1]), r.choice([0, 1, 2]), r.getrandbits(32)]


S(0x530130, 'ZPFOctree_packed::FindPathCoarse', 'thiscall', None, ret='ax', gen=_coarse, n=300)
