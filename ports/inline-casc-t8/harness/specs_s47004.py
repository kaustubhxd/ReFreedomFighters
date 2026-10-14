"""specs_s47004.py - cascade t8 batch 47004: 0x4ce870 (iterate a set and allocate the next id), 0x564e80 (look up child objects by name)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True


def _g4ce870(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    sysobj(c)
    lo = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)})
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lo), 0x24: pystub(c, 3, pop=0)})
    e.w32(0x700390, lg)
    mask = r.choice([0xf, 0x1f, 0xff, 0x7, 0xffff])
    nvals = r.choice([0, 1, 2, 3, 5])

    def vals(em, k):
        return r.choice([0, 1, 2, 3, 7, 0xf, 0x10, r.getrandbits(32)]) if k >= nvals else r.randrange(0, mask + 2)

    def put(em, k):
        em.w32(em.arg32(0), 1 if k < nvals else 0)
    it = obj(c, 0x40, {0x4c: pystub(c, 1, this=True, nullflag=(0,)),
                       0x5c: pystub(c, 1, this=True, nullflag=(0,), ret=vals, side=put),
                       0x44: pystub(c, 1, this=True, nullflag=(0,))})
    tab = rnd(c, 0x200) + 0x10
    for i in range(-1, 0x40):
        w = r.getrandbits(32) & (mask if r.random() < 0.8 else 0xffffffff)
        e.w32(tab + 4 * i, w)
    me = rnd(c, 0x40)
    e.w32(me + 4, tab)
    e.w32(me + 8, it if r.random() < 0.85 else 0)
    e.w32(me + 0x10, mask)
    e.w32(me + 0xc, r.choice([0, 1, mask, mask + 1, mask + 5, r.getrandbits(32)]))
    e.wbytes(me + 0x18, bytes([r.choice([0, 1])]))
    e.wbytes(c.emu.r32(0x70039c) + 0x9b7, bytes([r.choice([0, 1])]))
    return [me]


def _g564e80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    kids = []

    def kid_slot():
        return pystub(c, 2, this=True, ret=lambda em, k: kids[r.randrange(len(kids))] if False else r.choice(pool))
    pool = []
    leaf = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=lambda em, k: r.choice(pool) if pool else 0),
                         0x258: pystub(c, 2, this=True, deref={0: 2})})
    mid = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=lambda em, k: r.choice(pool)),
                        0x258: pystub(c, 2, this=True, deref={0: 2})})
    for i in range(6):
        pool.append(obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=lambda em, k: r.choice(pool)),
                                  0x258: pystub(c, 2, this=True, deref={0: 2})}))
    pool.append(mid)
    me = obj(c, 0x1200, {0x64: pystub(c, 1, this=True)})
    e.w32(me + 0x54, r.choice(pool))
    hook_rec(c, 0x564a40, 1, this=True)
    return [me]


S(0x4ce870, 'GUESS iterate set and allocate next id', 'thiscall', None, ret='eax', gen=_g4ce870, note='batch47004')
S(0x564e80, 'GUESS look up child objects by name', 'thiscall', None, ret=None, gen=_g564e80, note='batch47004')
