"""specs_s1215.py - pathfinding batch 1215: FindPath3 and helpers."""
from pilot import S, F
from pfspec import rnd, reporter, allocator, vtable, sf
from specs_s1206 import NN, NA, iterator, SOLID
from specs_s1213 import comp_octree
from specs_s1214 import context, astar_chain


def _clear(c):
    o = rnd(c, 0xa0)
    e = c.emu
    na, nn = c.rng.randint(0, 30), c.rng.randint(0, 30)
    e.w16(o + 0x58, na)
    e.w16(o + 0x52, nn)
    e.w32(o + 0x5a, rnd(c, 12 * na + 4))
    e.w32(o + 0x54, rnd(c, 0x16 * nn + 4))
    return [o]


S(0x531220, 'ZPFOctree_packed::<clear corridor markers> (no GC name)', 'thiscall', None, gen=_clear)


def wpoint(c, o):
    e = c.emu
    p = e.alloc(16, 4)
    for k in range(3):
        mn = e.rf32(o + 6 + 4 * k)
        mx = e.rf32(o + 0x12 + 4 * k)
        v = mn + (mx - mn) * c.rng.random() if c.rng.random() < 0.9 and mx == mx and mn == mn else c.fv(-5000, 5000)
        e.wf32(p + 4 * k, sf(v))
    return p


def _endcell(c):
    o, lv, it = comp_octree(c)
    return [it, rnd(c, 8), wpoint(c, o), rnd(c, 4)]


S(0x530ca0, 'ZPFOctreeIterator_packed::<path end cell> (no GC name)', 'thiscall', None, ret='eax', gen=_endcell,
  n=300)


def sysi_full(c):
    """ZSysInterface with a clock (+0x1c8) and +0x9b -> message table whose +0xadc is a collision object."""
    r = c.rng
    e = c.emu
    t = [r.randint(0, 3000)]

    def now(em, a):
        t[0] += r.choice([0, 1, 5, 50, 400])
        return t[0]
    sysi = rnd(c, 0xa0)
    e.w32(sysi, vtable(c, 'ZSysInterface', 0x80, impl={0x1c8: now}, argwords={0x1c8: 2}))
    hit = r.choice([0, 0, 1, 0x100])
    col = rnd(c, 16)
    e.w32(col, vtable(c, 'collision', 0xc0, impl={0x2e0: lambda em, a: hit}, argwords={0x2e0: 6},
                      opts={0x2e0: {'peek': {0: 0x18}}}))
    m = rnd(c, 0xae0)
    e.w32(m + 0xadc, col)
    e.w32(sysi + 0x9b, m)
    e.w32(0x70039c, sysi)


def _fp3(c):
    r = c.rng
    e = c.emu
    reporter(c)
    allocator(c)
    sysi_full(c)
    # FindPathCoarse reads its iterator's kind uninitialised when the start cell has no record on the searched level
    # (stack garbage, which differs between the exe and the port): keep every cell resolvable here.
    SOLID[0] = True
    try:
        o, lv, it = comp_octree(c)
    finally:
        SOLID[0] = False
    e.w32(o + 0x48, 1)
    e.w32(o + 0x4c, r.randint(1, max(1, lv - 1)))   # coarse levels below the root (levels - 0x4c >= 0)
    arr = astar_chain(c, o, 400)
    for k in range(400):
        e.w16(arr + k * 0x15 + 0x10, 0)
        e.w16(arr + k * 0x15 + 0x12, 0)
    e.w16(o + 0x96, r.randint(1, 30))
    e.w16(o + 0x58, NA)
    e.w16(o + 0x52, NN)
    e.w8(o + 5, r.choice([0, 1]))
    ctx = rnd(c, 0x110)
    ctx2 = context(c)
    e.wbytes(ctx, e.rbytes(ctx2, 0x51))
    e.w8(ctx + 0x99, r.choice([0, 1]))
    e.w32(ctx + 0x95, 0 if r.random() < 0.7 else e.r32(ctx + 0x44))
    if r.random() < 0.7:
        e.w32(ctx + 0x44, 0)
    return [o, wpoint(c, o), wpoint(c, o), F(r.choice([0.0, 0.0, 10.0, c.fv(0, 40)])), r.getrandbits(32),
            r.getrandbits(32), ctx, r.getrandbits(32)]


S(0x52e830, 'ZPFOctree_packed::FindPath3', 'thiscall', None, ret='eax', gen=_fp3, n=300)


def _fp3_builder(c):
    """FindPath3 with the searches stubbed to succeed, so the path builder (points, link points, the last straight
    piece and its collision test) is exercised on every case."""
    from pfspec import hooks, RET
    r = c.rng
    e = c.emu
    reporter(c)
    allocator(c)
    sysi_full(c)
    o, lv, it = comp_octree(c)
    e.w32(o + 0x4c, r.randint(1, max(1, lv - 1)))
    arr = astar_chain(c, o, 120)
    e.w16(o + 0x96, r.randint(1, 30))
    e.w8(o + 5, r.choice([0, 1, 1]))
    for k in range(8):
        e.w16(o + 0x9e + 32 * k, r.randrange(120))
        for j in range(6):
            e.wf32(o + 0x9e + 32 * k + 4 + 4 * j, c.fv(-500, 500))
    ctx = rnd(c, 0x110)
    e.w32(ctx + 0x44, 0)
    e.w8(ctx + 0x48, 1)

    def endcell(em, a):
        em.wbytes(a[0], bytes(r.getrandbits(8) for _ in range(6)))
        em.w8(a[2], r.choice([0, 1]))
        return r.choice([1, 1, 1, 0])

    def fine(em, a):
        em.w8(ctx + 0x99, r.choice([1, 1, 1, 0]))
        return r.choice([r.randrange(1, 120), r.randrange(1, 120), 0, 0xffff])
    hooks(e, {0x530ca0: ('endPointCell', 'this', 3, {'impl': endcell}),
              0x530130: ('FindPathCoarse', 'this', 6),
              0x52f2b0: ('FindPath', 'this', 6, {'impl': fine}),
              0x531220: ('clearMarkers', 'this', 0)})
    RET[0x530130] = r.choice([1, 1, 1, 0, 0xffff])
    return [o, wpoint(c, o), wpoint(c, o), F(c.fv(0, 40)), r.choice([0, 0, 1]), r.choice([0, 0, 1]), ctx,
            r.getrandbits(32)]


S(0x52e830, 'ZPFOctree_packed::FindPath3 (path builder; searches stubbed)', 'thiscall', None, ret='eax',
  gen=_fp3_builder, n=500)
