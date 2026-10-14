"""specs_s34127.py - three items; callees are recorders.
0x45be60: [this+0x20] 0..3 entries (pointer array at +0x254, some zero); engine object at the unaligned [[0x70039c]+0x1aa3] with a sub object (+0x18, slot 0xe4) and slots 0x80 returning a record whose byte +2 matches want in a quarter.
0x54dff0: kind (+0x18) 3 / 4 / other, unaligned pointer +0x29 to a block (null in a quarter), byte +0x79 in a half, slot 0x58; p random.
0x5f0380: table object slots 0x138 (returns an object with slot 0x88 that writes l4) and 0x114 (writes l8, returns a word); [this+4] object with slot 0x12c and +0x684; helper 0x5f0e10."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g5f0380(c, HELP):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, HELP, 1, this=True, ret=r.getrandbits(32))

    def w4(em, k):
        em.w32(em.arg32(1), r.getrandbits(32))

    def w8(em, k):
        em.w32(em.arg32(4), 0 if r.random() < 0.4 else r.getrandbits(32) | 1)
    x = obj(c, 0x20, {0x88: pystub(c, 2, this=True, side=w4, deref={1: 1})}, nslots=0x8c // 4)
    tbl = obj(c, 0x20, {0x138: pystub(c, 0, ret=x, this=True),
                        0x114: pystub(c, 5, ret=lambda em, k: r.choice([0, 1, 0x12345, 0xabcd0000 | r.getrandbits(16)]), this=True, side=w8, deref={4: 1})}, nslots=0x118 // 4)
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x9b, tbl)
    c.emu.w32(0x70039c, so)
    tgt = obj(c, 0x700, {0x12c: pystub(c, 2, this=True)}, nslots=0x130 // 4)
    c.emu.w32(tgt + 0x684, r.getrandbits(32))
    me = rnd(c, 0x20)
    c.emu.w32(me + 4, tgt)
    return [me]



import functools
def _mk(h):
    def g(c):
        return _g5f0380(c, h)
    return g
S(0x5f04a0, 'GUESS query engine values and apply them B', 'thiscall', None, ret=None, gen=_mk(0x5f0f00), note='batch34128')
S(0x5f0540, 'GUESS query engine values and apply them C', 'thiscall', None, ret=None, gen=_mk(0x5f0e10), note='batch34128')
