"""specs_s35170.py - 0x43fdd0 (thiscall(a, b, c, d) ret 0x10, ret=None). this: object with slots 0xe0 (4 args recorded) and 0x20 (0 args; returns zero in half, else non-zero), [+8] -> block with dword +0x6c zero in half, byte +0x14 with bit 0 set in half.
a: object with slot 0x84 (3 args; the vector, arg 2, is recorded as its 3 dwords)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g43fdd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a = obj(c, 0x20, {0x84: pystub(c, 3, this=True, deref={2: 3})}, nslots=0x30)
    blk = rnd(c, 0x80)
    e.w32(blk + 0x6c, 0 if r.random() < 0.5 else r.getrandbits(32) | 1)
    me = obj(c, 0x20, {0xe0: pystub(c, 4, this=True), 0x20: pystub(c, 0, this=True, ret=0 if r.random() < 0.5 else r.getrandbits(32) | 1)}, nslots=0x40)
    e.w32(me + 8, blk)
    e.w8(me + 0x14, r.getrandbits(8) | 1 if r.random() < 0.5 else r.getrandbits(8) & 0xfe)
    return [me, a, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x43fdd0, 'GUESS forward event to handler with default placement fallback', 'thiscall', None, ret=None, gen=_g43fdd0, note='batch35170')
