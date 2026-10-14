"""specs_s38012.py - cascade s8 batch 38012: 0x4b6b90. Table object (engine +0x9b): slot 0x54 returns the node (null 12%), slot 0x4c a random value, slot 0x50 either this+0x84 or
another value. 0x4b48c0 returns the entity (or 0), whose slots are recording stubs (0x1e0 flag tests random in the low byte, 0x80 fills the two stack structs with random
data, 0x370 records their contents, 0x504 / 0x500 return a helper object or 0); the node's +0x54 object (else path) always exists. 0x4db9a0 / 0x4b3a70 / 0x4dc030 hooked."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4b6b90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def rb(em, k):
        return r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)])
    helper = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)})

    hv = [helper if r.random() < 0.6 else 0, helper if r.random() < 0.6 else 0]

    def mh(em, k):
        return hv[0]

    def mh2(em, k):
        return hv[1]

    def fill(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(0x24)))
        em.wbytes(em.arg32(1), bytes(r.getrandbits(8) for _ in range(0xc)))
    ent = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=rb), 0x588: pystub(c, 0, this=True),
                        0x80: pystub(c, 2, this=True, stackmark=(0, 1), side=fill), 0x1b0: pystub(c, 0, this=True),
                        0x2f8: pystub(c, 1, this=True), 0x370: pystub(c, 2, this=True, deref={0: -0x24, 1: -0xc}),
                        0x504: pystub(c, 0, this=True, ret=mh), 0x500: pystub(c, 0, this=True, ret=mh2),
                        0x128: pystub(c, 3, this=True)})
    sub = obj(c, 0x20, {0x1b0: pystub(c, 0, this=True), 0x128: pystub(c, 3, this=True)})
    node = rnd(c, 0x60)
    e.w32(node + 0x54, sub)
    me = rnd(c, 0x100)
    cur = r.getrandbits(32)
    e.w32(me + 0x84, cur)
    pe = r.choice([0.3, 0.7])
    pn = 0.12
    so = sysobj(c, {}, table_slots={
        0x54: pystub(c, 1, this=True, ret=lambda em, k: 0 if r.random() < pn else node),
        0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32)),
        0x50: pystub(c, 1, this=True, ret=lambda em, k: cur if r.random() < 0.5 else r.getrandbits(32))})
    hook_rec(c, 0x4b48c0, 1, this=True, pop=4, ret=lambda em, k: ent if r.random() < pe else 0)
    hook_rec(c, 0x4db9a0, 1, this=True, pop=4, ret=rb)
    hook_rec(c, 0x4b3a70, 0, this=True)
    hook_rec(c, 0x4dc030, 0, this=True)
    req = rnd(c, 0x20)
    for off in (4, 0x10):
        if r.random() < 0.4:
            e.w32(req + off, 0)
    return [me, req]


S(0x4b6b90, 'GUESS refresh entity for request', 'thiscall', None, ret=None, gen=_g4b6b90, note='batch38012')
