"""specs_s1208.py - pathfinding batch 1208: octree walk with visitor functors."""
from pilot import S
from pfspec import rnd, vtable
from specs_s1206 import octree, NN, NA


def _s16(e, a):
    v = e.r32(a)
    return v - (1 << 32) if v & 0x80000000 else v


def funcs(c, o, depth_hint):
    """SPFFuncs with logging functors whose results depend only on what they are given."""
    r = c.rng
    e = c.emu
    salt = r.getrandbits(8)
    peek = {'peek': {2: 12, 3: 12}}

    def chk(em, a):
        lo = [_s16(em, a[2] + 4 * k) for k in range(3)]
        return 1 if (lo[0] * 7 + lo[1] * 3 + lo[2] + a[1] + salt) % 5 else 0

    def nodef(em, a):
        idv = em.r32(a[1]) & 0xffff
        if (idv + salt) % 7 == 0:
            em.w16(a[1], (idv * 3 + 1) % NN)       # relink: exercises the write-back
        return (idv + a[4] + salt) % 3 == 0

    def elemf(em, a):
        v = em.r32(a[1])
        return (v + a[2] + salt) & 1

    fn = rnd(c, 0x14)
    objs = []
    for k, (nm, impl, n, opt) in enumerate([('check', chk, 4, {'peek': {2: 12, 3: 12}}),
                                            ('node', nodef, 5, {'peek': {1: 2, 2: 12, 3: 12}}),
                                            ('leaf', nodef, 5, {'peek': {1: 2, 2: 12, 3: 12}}),
                                            ('elem', elemf, 7, {'peek': {1: 4, 3: 12, 4: 12}})]):
        if r.random() < 0.2:
            e.w32(fn + 4 * k, 0)
            continue
        ob = rnd(c, 8)
        e.w32(ob, vtable(c, nm, 2, impl={0: impl}, argwords={0: n}, opts={0: opt}))
        e.w32(fn + 4 * k, ob)
    e.w8(fn + 0x10, r.choice([0, 0, 1, 2]))
    return fn


def _walk(c, leaf=False):
    r = c.rng
    e = c.emu
    o = octree(c)
    e.w32(o + 0x48, r.choice([1, 2]))
    if leaf:
        depth = r.choice([0, 0, 1, 5])
    else:
        depth = r.choice([0, 1, 1, 2, 2, 3])
    fn = funcs(c, o, depth)
    node = rnd(c, 4)
    e.w16(node, r.randrange(NA if depth == 0 else NN))
    if r.random() < 0.05:
        e.w16(node, 0)
    lo = [r.randint(0, 30) for _ in range(3)]
    hi = [x + r.choice([1, 2, 8, 16, 33]) for x in lo]
    if r.random() < 0.1:
        lo[0] = r.getrandbits(32)
    return [o, fn, node, depth] + lo + hi


S(0x52d580, 'ZPFOctree_packed::<leaf walk> (no GC name)', 'thiscall', None, ret='eax',
  gen=lambda c: _walk(c, True), n=300)
S(0x52d750, 'ZPFOctree_packed::<octree walk> (no GC name)', 'thiscall', None, ret='eax', gen=_walk, n=300)
