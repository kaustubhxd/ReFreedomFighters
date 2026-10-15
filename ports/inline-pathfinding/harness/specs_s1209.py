"""specs_s1209.py - pathfinding batch 1209: users of the octree walk, iterator SetPosition, special links."""
from pilot import S, F
from pfspec import rnd, hooks, sf, RET
from specs_s1206 import octree, iterator, NN, NA


def geo_octree(c):
    """octree() plus cells / extent consistent with the level count (leaf = 8 x 8 x 1 cells)."""
    r = c.rng
    e = c.emu
    o = octree(c)
    lv = r.randint(1, 4)
    e.w32(o + 0x38, lv)
    e.w32(o + 0x3c, 8 << (lv - 1))
    e.w32(o + 0x40, 8 << (lv - 1))
    e.w32(o + 0x44, 1 << (lv - 1))
    e.w32(o + 0x48, r.choice([1, 2]))
    for k in range(3):
        lo = c.fv(-3000, 3000)
        e.wf32(o + 6 + 4 * k, lo)
        e.wf32(o + 0x12 + 4 * k, sf(lo + abs(c.fv(10, 4000))) if r.random() < 0.9 else c.fv())
    return o, lv


def cell(c, o, extra=2):
    e = c.emu
    a = e.alloc(8, 2)
    for k, off in enumerate((0x3c, 0x40, 0x44)):
        n = e.r32(o + off)
        e.w16(a + 2 * k, c.rng.randint(0, n + extra - 1) if c.rng.random() < 0.95 else c.rng.getrandbits(16))
    return a


def _find(c):
    o, lv = geo_octree(c)
    return [o, rnd(c, 12), cell(c, o), c.rng.randint(0, lv)]


S(0x5307c0, 'ZPFOctree_packed::<find area at cell> (no GC name)', 'thiscall', None, ret='eax', gen=_find, n=300)


def _setpos(c):
    o, lv = geo_octree(c)
    it = iterator(c, o)
    lev = c.rng.randint(0, lv)
    if c.rng.random() < 0.4:
        c.emu.w32(it + 0x12, lev)
    return [it, cell(c, o), lev]


S(0x531740, 'ZPFOctreeIterator_packed::<SetPosition> (no GC name)', 'thiscall', None, ret='ax', gen=_setpos, n=300)


def _nearest(c):
    o, lv = geo_octree(c)
    r = c.rng
    return [o, rnd(c, 8), cell(c, o), r.choice([10, 1, 0, 3, 0xfff6]) | (r.getrandbits(16) << 16),
            r.choice([1, 0, 2, 0xffff]) | (r.getrandbits(16) << 16), F(c.fv(0, 4))]


S(0x530e80, 'ZPFOctree_packed::<nearest walkable cell> (no GC name)', 'thiscall', None, ret='eax', gen=_nearest,
  n=300)


def _checkpos(c):
    o, lv = geo_octree(c)
    e = c.emu
    p = e.alloc(16, 4)
    for k in range(3):
        mn = e.rf32(o + 6 + 4 * k)
        mx = e.rf32(o + 0x12 + 4 * k)
        v = mn + (mx - mn) * c.rng.random() if c.rng.random() < 0.85 and mx == mx and mn == mn else c.fv(-5000, 5000)
        e.wf32(p + 4 * k, sf(v))
    return [o, p]


S(0x52e240, 'ZPFOctree_packed::CheckPosition', 'thiscall', None, ret='al', gen=_checkpos, n=300)


def _thin(c):
    r = c.rng
    e = c.emu
    o, lv = geo_octree(c)
    NS, NC, NL, NR = 100, 6, 8, 16
    e.w16(o + 0x50, NS)
    arr = rnd(c, NS * 0x15 + 0x40)
    for k in range(NS):
        e.wf32(arr + k * 0x15 + 0xa, c.fv(0, 20) if r.random() < 0.8 else 100000.0)
        e.w16(arr + k * 0x15 + 0x10, 0)
        e.w16(arr + k * 0x15 + 0x12, 0)
    e.w32(o + 0x98, arr)
    area = e.r32(o + 0x5a)
    for k in range(NA):
        e.w16(area + k * 12, r.randrange(NC))
        e.w16(area + k * 12 + 0xa, r.randrange(NS - 70) if r.random() < 0.7 else 0)
        e.w16(area + k * 12 + 2, r.randrange(1, NS - 4) if r.random() < 0.5 else 0)
    comp = e.r32(o + 0x54)
    for k in range(NN):
        e.w16(comp + k * 0x16 + 2, r.randrange(1, NS - 4) if r.random() < 0.5 else 0)
        e.w16(comp + k * 0x16, r.randrange(NN))
    sz = rnd(c, NN * 10 + 0x20)
    for k in range(NN):
        e.w8(sz + 10 * k, r.randint(0, 3))
    cnts = rnd(c, NC + 4)
    for k in range(NC):
        e.w8(cnts + k, r.choice([0, 1, 2, 3]))
    for k in range(NC):
        e.w16(sz + 10 * k + 8, r.randrange(NR - 3))
    e.w32(o + 0x78, sz)
    e.w32(o + 0x7c, cnts)
    refs = rnd(c, NR * 10 + 0x10)
    for k in range(NR):
        e.w8(refs + 10 * k + 1, r.randint(0, 3))
        ln = r.randrange(1, NL)
        e.w16(refs + 10 * k + 8, (ln if r.random() < 0.5 else -ln) & 0xffff if r.random() < 0.9 else 0)
    e.w32(o + 0x66, refs)
    frm = r.randrange(1, NS)
    fr = arr + frm * 0x15
    e.w16(fr, r.randrange(NA))
    pos = [r.randint(0, e.r32(o + off) - 1) for off in (0x3c, 0x40, 0x44)]
    for k in range(3):
        e.w16(fr + 4 + 2 * k, pos[k])
    links = rnd(c, NL * 12 + 0x10)
    for k in range(NL):
        for end in range(2):
            p = pos if r.random() < 0.5 else [r.randint(0, e.r32(o + off) - 1) for off in (0x3c, 0x40, 0x44)]
            for j in range(3):
                e.w16(links + k * 12 + end * 6 + 2 * j, p[j])
    e.w32(o + 0x88, links)
    acts = rnd(c, NL * 4 + 8)
    for k in range(2 * NL):
        e.w16(acts + 2 * k, r.choice([0, 1, 2, 0x4002, 0x8001, 0x4001, r.getrandbits(16)]))
    e.w32(o + 0x8c, acts)
    e.w32(o + 0x90, c.fbuf(NL * 6))
    e.w8(o + 4, r.choice([0, 1]))
    e.w8(o + 5, r.choice([0, 1]))
    e.w16(o + 0x96, r.randint(1, 40))
    e.w16(o + 0x9c, r.randint(0, 5))
    return [o, frm | (r.getrandbits(16) << 16 if r.random() < 0.2 else 0), rnd(c, 8)]


S(0x532420, 'ZPFOctree_packed::VisitNeighborSpecialThin', 'thiscall', None, ret='eax', gen=_thin, n=500)
