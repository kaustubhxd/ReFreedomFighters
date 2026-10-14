"""specs_s36039.py - cascade s4 batch 36039: 0x45e840 (destroy a list of children), 0x474320 (find a validated target object), 0x495f10 (guarded dispatch), 0x4f8320 (send a text to every listed object), 0x515f60 (notify and clear two lists)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger, reftab, reftab_vt


def _g45e840(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    elems = []
    for _ in range(r.choice([0, 1, 2, 3])):
        v = rnd(c, 0x20)
        e.w32(v + 0x14, 0 if r.random() < 0.3 else obj(c, 0x20, {0: pystub(c, 1, this=True)}))
        elems.append(v)
    lst = reftab(c, elems)
    X = rnd(c, 0x20)
    e.w32(X + 0x14, lst if r.random() < 0.9 else 0)
    g = obj(c, 0x20, {0xc0: pystub(c, 1, this=True, ret=lambda em, k: [0, 1, 0x100, 1][(k * 7 + 3) % 4])})
    e.w32(0x70038c, g)
    e._image_dirty = True
    s = rnd(c, 0x20)
    e.w32(s + 0x10, X)
    return [s]


def _g474320(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    z = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 1, 0x100]))})
    ytab = r.getrandbits(32) | 1
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=z if r.random() < 0.85 else 0)})
    w = obj(c, 0x20, {0x328: pystub(c, 0, this=True, ret=r.choice([0, 1, 1, 1, 0x100])),
                      0x340: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    a = obj(c, 0x20, {0x350: pystub(c, 0, this=True, ret=w if r.random() < 0.85 else 0)})
    Q = obj(c, 0x20, {0x98: pystub(c, 2, this=True, ret=0 if r.random() < 0.15 else ytab)})
    s = rnd(c, 0x300)
    e.w32(s + 0x2e3, 0 if r.random() < 0.15 else Q)
    return [s, a]


def _g495f10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e.wbytes(0x6ffaa0, bytes([r.choice([0, 0, 1, 0x80])]))
    e._image_dirty = True
    hook_rec(c, 0x4cbe20, 3, this=True, side=lambda em, k: em.calllog.append(('g8', bytes(em.rbytes(0x6ffaa0, 1)))))
    s = obj(c, 0x20, {0x30: pystub(c, 0, this=True, ret=r.choice([0, 0, 1, 0x100])), 0xc: pystub(c, 0, this=True, ret=r.getrandbits(32) | 1)})
    b = 0 if r.random() < 0.2 else rnd(c, 0x20)
    return [s, r.getrandbits(32), b, 0 if r.random() < 0.4 else r.getrandbits(32), r.getrandbits(32)]


def _g4f8320(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ids = [r.getrandbits(32) | 1 for _ in range(r.choice([0, 1, 2, 3, 4]))]
    objs = {}
    for i in ids:
        if r.random() < 0.8:
            objs[i] = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 1, 0x100])),
                                    0x284: pystub(c, 1, this=True), 0x288: pystub(c, 2, this=True)})

    def find(em, rr):
        em.calllog.append(('tab.slot58', em.arg32(0)))
        em.ret(objs.get(em.arg32(0), 0), 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    s = rnd(c, 0x100)
    vt = reftab_vt(c, ids)
    e.w32(s + 0xb3, vt)
    text = (b'%' if r.random() < 0.5 else b'x') + bytes(r.randint(0x41, 0x5a) for _ in range(5)) + b'\0'
    t = e.alloc(16, 4)
    e.wbytes(t, text)
    return [s, t]


def _g515f60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    X = obj(c, 0x20, {0x220: pystub(c, 1, this=True), 0x240: pystub(c, 1, this=True)})
    e.w32(tab + 0xadc, X)
    s = rnd(c, 0x100)
    for off in (0xd6, 0xda):
        elems = [r.getrandbits(32) for _ in range(r.choice([0, 1, 2, 3]))]
        l = reftab(c, elems)
        vt = e.r32(l)
        e.w32(vt + 0xc, pystub(c, 0, this=True))
        e.w32(s + off, l)
    return [s]


S(0x45e840, 'GUESS destroy a list of children', 'thiscall', None, ret=None, gen=_g45e840, note='batch36039')
S(0x474320, 'GUESS find a validated target object', 'thiscall', None, ret='eax', gen=_g474320, note='batch36039')
S(0x495f10, 'GUESS guarded dispatch', 'thiscall', None, ret='eax', gen=_g495f10, note='batch36039')
S(0x4f8320, 'GUESS send a text to every listed object', 'thiscall', None, ret=None, gen=_g4f8320, note='batch36039')
S(0x515f60, 'GUESS notify and clear two lists', 'thiscall', None, ret=None, gen=_g515f60, note='batch36039')
