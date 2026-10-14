"""specs_s34129.py - 0x5eee70: this +4/+8 objects with slot 0x14 (5 args) and a byte at +0x35, this+0xc a block; all callees hooked (this recorded)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5eecd0, 0, this=True, pop=0, ret=r.getrandbits(32))
    hook_rec(c, 0x5edc60, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x5edb00, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x5aba60, 4, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x5ac940, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x5ac5d0, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x5acac0, 1, this=True, ret=r.getrandbits(32))
    o4 = obj(c, 0x40, {0x14: pystub(c, 5, ret=r.getrandbits(32), this=True)}, nslots=0x18 // 4)
    o8 = obj(c, 0x40, {0x14: pystub(c, 5, ret=r.getrandbits(32), this=True)}, nslots=0x18 // 4)
    me = rnd(c, 0x20)
    c.emu.w32(me + 4, o4)
    c.emu.w32(me + 8, o8)
    c.emu.w32(me + 0xc, rnd(c, 0x20))
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x5eee70, 'GUESS set up a two-control dialog row', 'thiscall', None, ret=None, gen=_g, note='batch34129')
