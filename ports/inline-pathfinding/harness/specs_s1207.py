"""specs_s1207.py - pathfinding batch 1207: A* slot allocation, VisitNeighbor, TryLine."""
from pilot import S, F
from pfspec import rnd, hooks, allocator, RET
from specs_s1206 import octree, iterator, NN, NA

NS = 100


def full_iter(c):
    r = c.rng
    e = c.emu
    o = octree(c)
    sz = rnd(c, NN * 10 + 0x20)
    for k in range(NN):
        e.w8(sz + 10 * k, r.randint(0, 9))
    e.w32(o + 0x78, sz)
    for k in range(NN):
        e.w16(e.r32(o + 0x54) + k * 0x16 + 2, 0 if r.random() < 0.5 else r.randrange(1, 300))
        e.w16(e.r32(o + 0x54) + k * 0x16, r.randrange(NN))
    for k in range(NA):
        a = e.r32(o + 0x5a) + k * 12
        e.w16(a + 2, 0 if r.random() < 0.5 else r.randrange(1, 300))
        e.w16(a, r.randrange(NN))
        e.w16(a + 0xa, 0 if r.random() < 0.5 else r.randrange(1, 300))
    e.w16(o + 0x50, r.choice([NS, 300, 2, 0xffff]))
    it = iterator(c, o)
    e.w8(it + 0x20, r.choice([1, 2, 3, 3, 0, 4]))
    ctr = rnd(c, 4)
    e.w16(ctr, r.randint(0, 300) if r.random() < 0.8 else r.getrandbits(16))
    e.w32(it + 4, ctr)
    e.w32(it + 8, r.choice([64, 64, 8, 0x7fffffff, r.getrandbits(32)]))
    return o, it


def _idx(c):
    o, it = full_iter(c)
    return [it]


S(0x530a40, 'ZPFOctreeIterator_packed::<A* slot> (no GC name)', 'thiscall', None, ret='ax', gen=_idx)


def _visit(c):
    r = c.rng
    e = c.emu
    hooks(e, {0x532420: ('VisitNeighborSpecialThin', 'this', 2)})
    RET[0x532420] = r.getrandbits(32)
    o, it = full_iter(c)
    e.w16(o + 0x50, NS)
    arr = rnd(c, NS * 0x15 + 0x40)
    for k in range(NS):
        p = arr + k * 0x15
        e.wf32(p + 0xa, c.fv(0, 20) if r.random() < 0.9 else 100000.0)
        e.w16(p + 0x10, r.randrange(NS) if r.random() < 0.3 else 0)
        e.w16(p + 0x12, r.randrange(NS) if r.random() < 0.3 else 0)
    e.w32(o + 0x98, arr)
    for a in (e.r32(o + 0x54), e.r32(o + 0x5a)):
        pass
    e.w16(e.r32(it + 4), r.randint(0, NS - 10))
    e.w32(it + 8, r.choice([1, 2, 4]))
    for k in range(NN):
        e.w16(e.r32(o + 0x54) + k * 0x16 + 2, r.randrange(NS) if r.random() < 0.5 else 0)
    for k in range(NA):
        e.w16(e.r32(o + 0x5a) + k * 12 + 2, r.randrange(NS) if r.random() < 0.5 else 0)
        e.w16(e.r32(o + 0x5a) + k * 12 + 0xa, r.randrange(NS - 64) if r.random() < 0.5 else 0)
    dirv = r.choice([0, 1, 2, 3, 4, 5, 0, 2, 4, 10, 11])
    return [o, r.randrange(NS) | (r.getrandbits(16) << 16 if r.random() < 0.2 else 0), it, dirv, F(c.fv()),
            rnd(c, 8)]


S(0x531b40, 'ZPFOctree_packed::VisitNeighbor', 'thiscall', None, ret='eax', gen=_visit)


def _try(c):
    r = c.rng
    hooks(c.emu, {0x52e0a0: ('octCheckLine', 'this', 3)})
    RET[0x52e0a0] = r.choice([0, 1, 0x100, r.getrandbits(32)])
    allocator(c)
    a = c.fbuf(3)
    b = c.fbuf(3)
    return [rnd(c, 0xa0), a, b, r.getrandbits(32)]


S(0x531a50, 'ZPFOctree_packed::TryLine', 'thiscall', None, ret='eax', gen=_try)
