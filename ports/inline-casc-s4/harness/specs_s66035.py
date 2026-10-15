"""specs_s66035.py - cascade s4 batch 66035: 0x45e570 (detach an actor from a controller's list)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, reftab


def _g45e570(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4da3a0, 0, this=True, ret=r.choice([0, 1, 1, 1, 0x100, 0x101]))
    a = obj(c, 0x30, {0x5c: pystub(c, 3, this=True), 0x54: pystub(c, 1, this=True)})
    ids = [r.getrandbits(32) | 1 for _ in range(r.choice([0, 1, 2, 3]))]
    omap = {}

    def mko():
        o = obj(c, 0x30, {0x54: pystub(c, 1, this=True)})
        e.wbytes(o + 4, bytes([r.choice([0, 4, 5, 1])]))
        e.wbytes(o + 0x14, bytes([r.choice([0, 8, 9])]))
        e.w32(o + 0x1c, r.choice([0, 3]))
        return o
    target = r.randrange(len(ids)) if ids and r.random() < 0.7 else -1
    for i, v in enumerate(ids):
        omap[v] = a if i == target else mko()
    # an equal object must still behave like a (flags live on a)
    if target >= 0:
        e.wbytes(a + 4, bytes([r.choice([0, 4, 5, 1])]))
        e.wbytes(a + 0x14, bytes([r.choice([0, 8, 9])]))
        e.w32(a + 0x1c, r.choice([0, 3]))

    def look(em, rr):
        v = em.arg32(0)
        em.calllog.append(('look', v))
        em.ret(eax=omap.get(v, 0), argbytes=4)
    g = obj(c, 0x30, {0xcc: e.stub_fn('look', look)})
    e.w32(0x70038c, g)
    e._image_dirty = True
    cnt = r.choice([0, 1, 2])
    lst = reftab(c, ids)
    lst_vt = int.from_bytes(bytes(e.rbytes(lst, 4)), 'little') if lst else 0
    if lst:
        e.w32(lst_vt + 0x14, pystub(c, 0, this=True, ret=cnt))
    inner = e.alloc(0x40, 8)
    e.wbytes(inner, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.w32(inner + 8, lst)
    e.wbytes(inner + 4, bytes([r.choice([0, 1, 4, 5])]))
    e.w32(inner + 0x10, r.choice([0, rnd(c, 8)]))
    t = obj(c, 0x40, {0x140: pystub(c, 0, this=True)})
    e.w32(t + 8, rnd(c, 8))
    e.w32(t + 0x10, inner)
    return [t, a]


S(0x45e570, 'GUESS detach an actor from a controller list', 'thiscall', None, ret=None, gen=_g45e570, note='batch66035')
