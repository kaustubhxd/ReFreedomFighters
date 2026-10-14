"""specs_s34040.py - cascade tier E, batch 34040.
0x509ff0: like batch 34039's 0x509aa0 (iterator list at [[this+0xc]+0x18] null in a seventh, 0..3 ids, engine table slot 0x58 returns an object (null in a quarter) with slot 0xbc recorder).
0x54bae0: each of the five members (+0x63ec, +0x63e8, +0x63f0, +0x63f4) is null in a third; objects have slots 0x48 (returns an object or 0), 8 and 0 as recorders; hooked 0x54f2b0 (fastcall; ECX and EDX
recorded) and 0x54da10.
0x54dd50: this slots 0x34 (returns a value) and 0x30 (returns 0 / non-zero); mode at the unaligned +0x75 is 1, 3 or another value; byte +0x7e / +0x7c random; the pointer at the unaligned +0x29 is null in
a fifth, else a block whose byte +0x59 is zero or not (the real 0x54e1e0 reads it)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g509ff0(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3])

    def begin(em, k):
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))

    def nxt(em, k):
        em.w32(em.arg32(0), 1 if k < n else 0)
    l = 0 if r.random() < 1 / 7 else obj(c, 0x20, {0x4c: pystub(c, 1, this=True, side=begin, stackmark=(0,)),
                                                   0x5c: pystub(c, 1, this=True, side=nxt, stackmark=(0,), ret=lambda em, k: r.getrandbits(32))},
                                         nslots=0x60 // 4)
    objs = [0 if r.random() < 0.25 else obj(c, 0x20, {0xbc: pystub(c, 1, this=True)}, nslots=0xc0 // 4) for _ in range(4)]
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: objs[min(k, 3)], this=True)})
    owner = rnd(c, 0x30)
    c.emu.w32(owner + 0x18, l)
    me = rnd(c, 0x20)
    c.emu.w32(me + 0xc, owner)
    return [me, r.getrandbits(32)]


def _g54bae0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x54da10, 0, this=True, pop=0)
    hook_rec(c, 0x54f2b0, 0, this=True, pop=0, side=lambda em, k: em.calllog.append(('edx', em.reg('edx'))))
    inner = lambda: 0 if r.random() < 0.3 else rnd(c, 0x20)
    mk = lambda: 0 if r.random() < 1 / 3 else obj(c, 0x20, {0x48: pystub(c, 1, ret=inner(), this=True), 8: pystub(c, 1, this=True), 0: pystub(c, 1, this=True)},
                                                  nslots=0x50 // 4)
    me = rnd(c, 0x6400)
    for off in (0x63ec, 0x63e8, 0x63f0, 0x63f4):
        c.emu.w32(me + off, mk())
    return [me]


def _g54dd50(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x100, {0x34: pystub(c, 0, ret=r.getrandbits(32), this=True),
                        0x30: pystub(c, 0, ret=r.choice([0, 0, 1, r.getrandbits(32) | 1]), this=True)}, nslots=0x40 // 4)
    c.emu.wbytes(me + 0x75, r.choice([1, 3, 3, 1, 0, 2, 4, r.getrandbits(32)]).to_bytes(4, 'little'))
    p = 0 if r.random() < 0.2 else rnd(c, 0x80)
    if p:
        c.emu.wbytes(p + 0x59, bytes([r.choice([0, 1, r.getrandbits(8)])]))
    c.emu.wbytes(me + 0x29, p.to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x7c, bytes([r.choice([0, 1, r.getrandbits(8)])]))
    c.emu.wbytes(me + 0x7e, bytes([r.choice([0, 1, r.getrandbits(8)])]))
    return [me]


S(0x509ff0, 'GUESS show every object of a list', 'thiscall', None, ret=None, gen=_g509ff0, note='batch34040')
S(0x54bae0, 'GUESS tear down five owned members', 'thiscall', None, ret=None, gen=_g54bae0, note='batch34040')
S(0x54dd50, 'GUESS advance three-mode state machine', 'thiscall', None, ret=None, gen=_g54dd50, note='batch34040')
