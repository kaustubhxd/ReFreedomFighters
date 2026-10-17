"""specs_s1219.py - pathfinding batch 1219: ProcessAdditionalDoors (gates and door quads)."""
from pilot import S
from pfspec import rnd, hooks, allocator, vtable, sf, reporter
import math


def _pad(c):
    r = c.rng
    e = c.emu
    allocator(c)
    hooks(e, {0x4db7c0: ('ZBaseGeom::GetSize', 'this', 1, {'fill': {0: 12}}),
              0x4daf90: ('ZBaseGeom::GetCen', 'this', 1, {'fill': {0: 12}}),
              0x4cc850: ('striwcmp', 'fast', 0)})
    from pfspec import RET
    RET[0x4cc850] = r.choice([0, 1])
    # collision manager: first item, next via vtable +0x50 (iterator in the arg)
    items = []
    for k in range(r.randint(0, 5)):
        it = rnd(c, 0x60)
        obj = rnd(c, 0x80)
        e.w32(it + 0x54, obj if r.random() < 0.9 else 0)
        e.w8(obj + 0x5b, r.choice([0, 1]))
        cls = rnd(c, 0x40)
        e.w32(obj + 0xc, cls)
        e.w32(cls + 0x23, 0x200015 if r.random() < 0.7 else 0x200074)
        e.w32(obj + 0x54, obj if False else e.r32(it + 0x54))
        items.append(it)
    def nxt(em, a):
        cur = em.r32(a[0])
        i = items.index(cur) if cur in items else -1
        em.w32(a[0], items[i + 1] if 0 <= i + 1 < len(items) else 0)
    mgr = rnd(c, 0x20)
    e.w32(mgr + 8, items[0] if items else 0)
    e.w32(mgr, vtable(c, 'collmgr', 0x60, impl={0x50: nxt}, argwords={0x50: 1}))   # first dword = the vtable
    m = rnd(c, 0xae0)
    e.w32(m + 0xadc, mgr)
    sysi = e.alloc(0x200, 4)          # the engine object at 0x70039c (own allocation, not the image's pointer)
    e.wbytes(sysi, bytes(0x200))
    e.w32(sysi + 0x9b, m)
    e.w32(0x70039c, sysi)
    # gate objects: 0x244 gives 12 floats, 0x84 transforms in place
    for it in items:
        obj = e.r32(it + 0x54)
        if obj:
            cor = rnd(c, 64)
            for j in range(12):
                e.wf32(cor + 4 * j, c.fv(-300, 300))
            e.w32(obj, vtable(c, 'gate', 0x260, impl={0x244: lambda em, a, cor=cor: cor,
                                                       0x84: lambda em, a: 0},
                              argwords={0x84: 1}))
    # door REFTAB: count, iterator, geoms
    refs = []
    for k in range(r.randint(0, 4)):
        g = rnd(c, 0x20)
        e.w32(g, vtable(c, 'geom', 0x240, impl={0x84: lambda em, a: 0}, argwords={0x84: 1}))
        e.w32(g + 8, rnd(c, 0x40))
        e.w32(g + 4, rnd(c, 16) if r.random() < 0.5 else 0)
        e.w32(e.r32(g + 8) + 0, e.r32(g + 8))
        refs.append(g)
    st = {'i': 0}
    def rt_start(em, a):
        st['i'] = 0
        em.w32(a[0], 1)
        em.w32(a[0] + 4, 0)
    def rt_next(em, a):
        if st['i'] < len(refs):
            em.w32(a[0], 1)
            st['i'] += 1
            return refs[st['i'] - 1]
        em.w32(a[0], 0)
        return 0
    reftab = rnd(c, 16)
    e.w32(reftab, vtable(c, 'REFTAB', 0x80, impl={0x4c: rt_start, 0x5c: rt_next, 0x14: lambda em, a: len(refs)},
                         argwords={0: 1, 0x4c: 1, 0x5c: 1}))
    o = rnd(c, 0x100)
    door_obj = rnd(c, 0x40)
    e.w32(o, vtable(c, 'ZPathfinder3', 0x240, impl={0x228: lambda em, a: door_obj}, argwords={0x228: 1}))
    e.w32(o + 0x2d, reftab if r.random() < 0.9 else 0)
    e.w32(o + 0x36, 0)
    e.w32(o + 0x3e, 0)
    return [o]


S(0x52b9d0, 'ZPathfinder3::ProcessAdditionalDoors', 'thiscall', None, gen=_pad, n=200)
