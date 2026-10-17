"""specs_s1212.py - pathfinding batch 1212: coarse flood fill steps."""
from pilot import S, F
from pfspec import rnd, hooks, reporter, RET
from specs_s1206 import NN, NA, iterator
from specs_s1209 import geo_octree

NS = 120
NC = 6
NR = 16


def coarse_octree(c):
    r = c.rng
    e = c.emu
    o, lv = geo_octree(c)
    e.w16(o + 0x50, NS)
    arr = rnd(c, NS * 0x15 + 0x40)
    for k in range(NS):
        p = arr + k * 0x15
        e.wf32(p + 0xa, c.fv(0, 30) if r.random() < 0.8 else 100000.0)
        e.w16(p + 0x10, 0)
        e.w16(p + 0x12, 0)
        e.w8(p + 3, r.randint(0, 3))
        e.w16(p, r.randrange(NA))
        for j in range(3):
            e.w16(p + 4 + 2 * j, r.randint(0, 60))
    e.w32(o + 0x98, arr)
    sz = rnd(c, NN * 10 + 0x20)
    for k in range(NN):
        e.w8(sz + 10 * k, r.randint(0, 4))
        e.w8(sz + 10 * k + 1, r.randint(0, 4))
        e.w8(sz + 10 * k + 2, r.randint(0, 4))
        e.w16(sz + 10 * k + 6, r.randint(0, 8))
        e.w16(sz + 10 * k + 8, r.randrange(NR - 3))
    e.w32(o + 0x78, sz)
    e.w32(o + 0x60, rnd(c, 4 * 40))
    area = e.r32(o + 0x5a)
    comp = e.r32(o + 0x54)
    for k in range(NA):
        e.w16(area + k * 12, r.randrange(NN))
        e.w16(area + k * 12 + 2, r.randrange(1, NS - 10) if r.random() < 0.5 else 0)
        e.w16(area + k * 12 + 0xa, r.randrange(NS - 70) if r.random() < 0.5 else 0)
    for k in range(NN):
        e.w16(comp + k * 0x16, r.randrange(NN))
        e.w16(comp + k * 0x16 + 2, r.randrange(1, NS - 10) if r.random() < 0.5 else 0)
    cnts = rnd(c, NN + 4)
    for k in range(NN):
        e.w8(cnts + k, r.choice([0, 1, 2, 3]))
    e.w32(o + 0x7c, cnts)
    refs = rnd(c, NR * 10 + 0x10)
    for k in range(NR):
        e.w8(refs + 10 * k, r.randint(0, 3))
        e.w8(refs + 10 * k + 1, r.randint(0, 3))
        for j in range(3):
            e.w16(refs + 10 * k + 2 + 2 * j, r.choice([0, 0, 1, -1, 2]) & 0xffff)
        ln = r.randrange(1, 8)
        e.w16(refs + 10 * k + 8, (ln if r.random() < 0.5 else -ln) & 0xffff)
    e.w32(o + 0x66, refs)
    acts = rnd(c, 64)
    for k in range(16):
        e.w16(acts + 2 * k, r.choice([0, 1, 2, 0x4002, 0x8001]))
    e.w32(o + 0x8c, acts)
    e.w8(o + 4, r.choice([0, 1]))
    e.w8(0x6e9000, r.choice([0, 1]))
    it = iterator(c, o)
    ctr = rnd(c, 4)
    e.w16(ctr, r.randint(1, 40))
    e.w32(it + 4, ctr)
    e.w32(it + 8, r.choice([1, 2, 4]))
    e.w8(it + 0x20, r.choice([1, 2, 3, 3]))
    return o, lv, it


def goal(c):
    if c.rng.random() < 0.2:
        return 0
    a = c.emu.alloc(8, 2)
    for k in range(3):
        c.emu.w16(a + 2 * k, c.rng.randint(0, 60))
    return a


def _dist(c):
    return [goal(c) or c.emu.alloc(8, 2), goal(c) or c.emu.alloc(8, 2)]


S(0x532850, 'ZPFOctree_packed::<cell Manhattan distance> (no GC name)', 'fastcall', None, ret='st0', gen=_dist)


def _split(c):
    r = c.rng
    o, lv, it = coarse_octree(c)
    e = c.emu
    S1 = e.r32(o + 0x78) + 10 * r.randrange(NN)
    S0 = e.r32(o + 0x78) + 10 * r.randrange(NN)
    rec = e.r32(o + 0x98) + 0x15 * r.randrange(NS)
    pos = goal(c) or e.alloc(8, 2)
    return [o, it + 0x16, r.randrange(NS), goal(c), r.randint(0, 6), F(c.fv()), pos, r.randrange(1, NS - 8),
            S1, S0, rec, r.randint(0, 4), r.randint(0, 4), r.getrandbits(32), r.randint(0, 20)]


S(0x531e70, 'ZPFOctree_packed::VisitNeighborFloodFillCoarseSplit', 'thiscall', None, ret='eax', gen=_split)


def _flood(c):
    r = c.rng
    reporter(c, 0.9)
    o, lv, it = coarse_octree(c)
    level = r.choice([lv - 1, lv - 2, lv - 1])
    dirv = r.choice([0, 1, 2, 3, 4, 5, 0, 1, 4, 5, 10, 11, 7])
    return [o, r.randrange(NS) | (r.getrandbits(16) << 16 if r.random() < 0.2 else 0), level, it, dirv, goal(c)]


S(0x531c40, 'ZPFOctree_packed::VisitNeighborFloodFillCoarse', 'thiscall', None, ret='ax', gen=_flood)


def _special(c):
    r = c.rng
    o, lv, it = coarse_octree(c)
    return [o, r.randrange(NS) | (r.getrandbits(16) << 16 if r.random() < 0.2 else 0),
            r.choice([lv - 1, lv - 2, lv]), it, goal(c)]


S(0x5320b0, 'ZPFOctree_packed::VisitNeighborSpecialFloodFillCoarse', 'thiscall', None, ret='ax', gen=_special)
