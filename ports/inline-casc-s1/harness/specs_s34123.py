"""specs_s34123.py - three items; callees are recorders (this recorded).
0x464dc0: engine table [[0x70039c]+0x9b] slot 0x58 returns an object (slot 0x210) or null; the three unaligned handles are zero in a third.
0x476a60: helper 0x4e1600 returns 3 / 8 / other low bytes; 0x4e12e0 writes a random value through its pointer argument (the argument slot or this+0x73); the others are plain recorders.
0x484a80: unaligned counter +0x60a is 1 in a half (else 2..4 or 0, which wraps and returns); this slots 0x220 / 0x36c / 0x5b0, table slot 0x58, object slot 0x98."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g464dc0(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x210: pystub(c, 1, this=True)}, nslots=0x214 // 4)
    tbl = obj(c, 0x20, {0x58: pystub(c, 1, ret=lambda em, k: 0 if r.random() < 0.3 else o, this=True)}, nslots=0x5c // 4)
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x9b, tbl)
    c.emu.w32(0x70039c, so)
    me = rnd(c, 0x140)
    for off in (0x12a, 0x12e, 0x132):
        c.emu.wbytes(me + off, (0 if r.random() < 0.33 else r.getrandbits(32) | 1).to_bytes(4, 'little'))
    return [me]


def _g476a60(c):
    clear_hooks(c)
    r = c.rng

    def w(em, k):
        em.w32(em.arg32(0), r.choice([0, 0, 1, r.getrandbits(32)]))
    hook_rec(c, 0x43f900, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x4e11e0, 2, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x4e11d0, 2, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x4e12e0, 2, this=True, ret=r.getrandbits(32), side=w, stackmark=(0,))
    hook_rec(c, 0x4e1600, 0, this=True, pop=0, ret=lambda em, k: r.choice([3, 3, 8, 8, 0, 0x103, 0x108]))
    hook_rec(c, 0x4e1b30, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x80), rnd(c, 0x20)]


def _g484a80(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x467390, 0, this=True, pop=0, ret=r.getrandbits(32))
    o = obj(c, 0x20, {0x98: pystub(c, 2, this=True)}, nslots=0x9c // 4)
    tbl = obj(c, 0x20, {0x58: pystub(c, 1, ret=lambda em, k: 0 if r.random() < 0.3 else o, this=True)}, nslots=0x5c // 4)
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x9b, tbl)
    c.emu.w32(0x70039c, so)
    me = obj(c, 0x620, {0x220: pystub(c, 1, this=True), 0x36c: pystub(c, 0, this=True), 0x5b0: pystub(c, 2, this=True)}, nslots=0x5b4 // 4)
    c.emu.wbytes(me + 0x60a, r.choice([1, 1, 2, 3, 0]).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x5ca, (0 if r.random() < 0.3 else r.getrandbits(32) | 1).to_bytes(4, 'little'))
    return [me]


S(0x464dc0, 'GUESS release three handles', 'thiscall', None, ret=None, gen=_g464dc0, note='batch34123')
S(0x476a60, 'GUESS read fields from a stream object', 'thiscall', None, ret='eax', gen=_g476a60, note='batch34123')
S(0x484a80, 'GUESS finish a nested update', 'thiscall', None, ret=None, gen=_g484a80, note='batch34123')
