"""specs_s35177.py - 0x63b2c0 (thiscall, no args, ret='al'). this: object with slots 0x30 (0 args; returns a 0x400-byte random block, null in 1/6) and 0x28 (0 args; returns n in 1..6), byte +0x10 random, [+8] null in 1/3 else a ring node (random 0x20 bytes whose [+0xc] is another node)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g63b2c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = 0 if r.random() < 1 / 6 else rnd(c, 0x400)
    n = r.choice([1, 2, 3, 4, 5, 6])
    me = obj(c, 0x40, {0x30: pystub(c, 0, this=True, ret=blk), 0x28: pystub(c, 0, this=True, ret=n)}, nslots=0x14)
    e.w8(me + 0x10, r.getrandbits(8))
    if r.random() < 1 / 3:
        e.w32(me + 8, 0)
    else:
        a, b = rnd(c, 0x20), rnd(c, 0x20)
        e.w32(a + 0xc, b)
        e.w32(me + 8, a)
    return [me]


S(0x63b2c0, 'GUESS grow draw array block with free list and ring link', 'thiscall', None, ret='al', gen=_g63b2c0, note='batch35177')
