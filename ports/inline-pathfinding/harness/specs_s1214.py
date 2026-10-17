"""specs_s1214.py - pathfinding batch 1214: yield, path shortcut, fine A* (FindPath)."""
from pilot import S, F
from pfspec import rnd, reporter
from specs_s1206 import NN, NA
from specs_s1213 import comp_octree, cellp


def clock(c):
    r = c.rng
    e = c.emu
    t = [r.randint(0, 3000)]

    def now(em, a):
        t[0] += r.choice([0, 1, 5, 50, 400])
        return t[0]
    from pfspec import vtable
    vt = vtable(c, 'ZSysInterface', 0x80, impl={0x1c8: now}, argwords={0x1c8: 2})
    sysi = e.alloc(16)
    e.w32(sysi, vt)
    e.w32(0x70039c, sysi)


def context(c, fresh=None):
    r = c.rng
    e = c.emu
    ctx = rnd(c, 0xa0)
    k = r.random()
    if k < 0.3:
        e.w32(ctx + 0x44, 0)
    else:
        ts = rnd(c, 0x14)
        e.w8(ts + 0x10, r.choice([0, 1, 1]))
        e.w32(ts, r.randint(0, 3000))
        e.w32(ts + 4, r.choice([0, 10, 100, 1000, 0xffffffff]))
        e.w32(ts + 8, r.choice([0, 1, 3, 100]))
        e.w32(ts + 0xc, r.choice([0, 1, 2, 200]))
        e.w32(ctx + 0x44, ts)
    e.w8(ctx + 0x48, r.choice([0, 1, 1]) if fresh is None else fresh)
    e.w32(ctx + 0x49, r.choice([0, 1, 2, 3, 4, 5]))
    return ctx


def _yield(c):
    clock(c)
    return [context(c)]


S(0x52b0c0, 'CContext::<yield> (no GC name)', 'thiscall', None, ret='al', gen=_yield)


def astar_chain(c, o, n=200):
    r = c.rng
    e = c.emu
    arr = e.alloc(n * 0x15 + 0x40, 4)
    lv = e.r32(o + 0x38)
    for k in range(n):
        p = arr + k * 0x15
        e.wf32(p + 0xa, 100000.0)
        e.w16(p + 0xe, r.randrange(k) if k and r.random() < 0.9 else 0)
        e.w8(p + 0x14, 1 if r.random() < 0.08 else 0)
        e.w16(p, r.randrange(NA))
        for j, off in enumerate((0x3c, 0x40, 0x44)):
            e.w16(p + 4 + 2 * j, r.randint(0, e.r32(o + off) - 1))
    e.w32(o + 0x98, arr)
    e.w16(o + 0x50, n)
    for k in range(8):
        e.w16(o + 0x9e + 32 * k, r.randrange(n))
    return arr


def _short(c):
    o, lv, it = comp_octree(c)
    c.emu.w32(o + 0x48, 1)
    astar_chain(c, o)
    return [o, c.rng.randrange(200)]


S(0x5318a0, 'ZPFOctree_packed::<path shortcut> (no GC name)', 'thiscall', None, gen=_short, n=300)


def _fine(c):
    r = c.rng
    e = c.emu
    reporter(c)
    clock(c)
    o, lv, it = comp_octree(c)
    e.w32(o + 0x48, 1)
    arr = astar_chain(c, o, 400)
    for k in range(400):
        e.w16(arr + k * 0x15 + 0x10, 0)
        e.w16(arr + k * 0x15 + 0x12, 0)
    e.w16(o + 0x96, r.randint(1, 30))
    ctx = context(c)
    e.w32(ctx + 0x65, o)
    e.w32(ctx + 0x69, o + 0x96)
    e.w32(ctx + 0x6d, 0x40)
    e.w16(ctx + 0x51, r.randrange(400))
    e.w32(ctx + 0x55, arr + 0x15 * r.randrange(400))
    a = cellp(c, o)
    b = cellp(c, o)
    if r.random() < 0.5:
        for k in range(3):
            e.w16(b + 2 * k, max(0, e.r32(a + 2 * k) & 0xffff) + r.randint(0, 3))
    return [o, a, b, F(r.choice([0.0, 0.0, 10.0, c.fv(0, 40)])), r.choice([0, 1, 2]), ctx, r.getrandbits(32)]


S(0x52f2b0, 'ZPFOctree_packed::FindPath', 'thiscall', None, ret='ax', gen=_fine, n=300)
