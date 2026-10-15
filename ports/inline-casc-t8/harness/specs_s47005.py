"""specs_s47005.py - cascade t8 batch 47005: 0x4a9110 (read fields from a stream), 0x4af5b0 (scan objects, toggle a state through slot 0x84)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4a9110(c):
    clear_hooks(c)
    r = c.rng
    slots = {}
    for off in (0x40, 0x48, 0x50, 0x68, 0x6c):
        slots[off] = pystub(c, 1, this=True, side=lambda em, k: em.w32(em.arg32(0), r.getrandbits(32)))
    s = obj(c, 0x20, slots)
    me = obj(c, 0x100, {0x84: pystub(c, 0, this=True)})
    return [me, s]


def _g4af5b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4])
    hit = r.choice([0, 0, 1, 2, 5])

    def put(em, k):
        em.w32(em.arg32(0), 1 if k < n else 0)
    it = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, nullflag=(0,)),
                       0x5c: pystub(c, 1, this=True, nullflag=(0,), ret=lambda em, k: r.getrandbits(32) & 0xff, side=put)})
    o2 = obj(c, 0x40, {0x84: pystub(c, 1, this=True, deref={0: 3})})
    e.w32(o2 + 8, rnd(c, 0x40))
    # engine table slot 0x58(id) returns o2-like objects
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: o2)})
    tgt = obj(c, 0x40, {0x8c: pystub(c, 1, this=True, deref={0: 3}),
                        0x180: pystub(c, 2, this=True, deref={0: 3}, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0x101]))})
    me = obj(c, 0x100, {0x84: pystub(c, 1, this=True)})
    e.w32(me + 0x44, tgt)
    for off in (0x5e, 0x5f):
        e.wbytes(me + off, bytes([r.choice([0, 0, 1, 7])]))
    a = rnd(c, 0x40)
    e.w32(a + 0x18, it if r.random() < 0.9 else 0)
    return [me, a]


S(0x4a9110, 'GUESS read fields from stream', 'thiscall', None, ret='al', gen=_g4a9110, note='batch47005')
S(0x4af5b0, 'GUESS scan objects toggle state', 'thiscall', None, ret=None, gen=_g4af5b0, note='batch47005')
