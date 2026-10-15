"""specs_s66071.py - cascade s4 batch 66071: 0x56f440 (collect the capable children of a group and refresh the view objects)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g56f440(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5613a0, 2, this=True)
    nk = r.choice([0, 1, 2, 3, 5, 5, 66])
    kids = []
    for i in range(nk):
        k = e.alloc(0x70, 8)
        if nk > 20 or r.random() < 0.85:
            w = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=1 if nk > 20 else r.choice([0, 1, 0x100, 0x101]))})
            ty = e.alloc(0x40, 8)
            e.w32(ty + 0x23, 0x100000 if nk > 20 else r.choice([0x100000, 0x100000, 0x100000, 0x300000, 0]))
            e.w32(w + 0xc, ty)
            e.w32(k + 0x54, w)
        else:
            e.w32(k + 0x54, 0)
        kids.append(k)
    for i, k in enumerate(kids):
        e.w32(k + 0x60, kids[i + 1] if i + 1 < nk else 0)
    group = e.alloc(0x80, 8)
    e.w32(group + 0x50, kids[0] if kids else 0)
    m = obj(c, 0x40, {0x25c: pystub(c, 2, this=True, ret=r.choice([group, group, 0]))})

    def s88(em, rr):
        em.calllog.append(('s88', em.arg32(0)))
        em.w32(em.arg32(1), r.getrandbits(32))
        em.ret(eax=0, argbytes=8)
    o = obj(c, 0x30, {0x88: e.stub_fn('s88', s88)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o)})
    v1 = obj(c, 0x40, {0x28: pystub(c, 0, this=True)})
    v2 = obj(c, 0x40, {0x28: pystub(c, 0, this=True)})
    v3 = obj(c, 0x40, {0x28: pystub(c, 0, this=True)})
    a = obj(c, 0x400, {0x31c: pystub(c, 2, this=True)})
    z = obj(c, 0x40, {0x370: pystub(c, 1, this=True)})
    t = e.alloc(0x740, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x640)))
    e.w32(t + 0x5d6, r.choice([0, m, m, m]))
    e.w32(t + 0x4be, a)
    e.w32(t + 0x5ce, v1)
    e.w32(t + 0x5da, v2)
    e.w32(t + 0x5ca, v3)
    e.w32(t + 0x5e2, z)
    return [t]


S(0x56f440, 'GUESS collect capable children of a group and refresh views', 'thiscall', None, ret=None, gen=_g56f440, note='batch66071')
