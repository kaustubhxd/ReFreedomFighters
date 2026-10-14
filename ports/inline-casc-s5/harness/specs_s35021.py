"""specs_s35021.py - 0x505fa0. [this+0x14] = P with slots 0x2c0 (returns an object or 0), 0x2c4 (returns an object or 0), 0x30c (returns a name word); the returned objects have slot 0x18 (1 arg,
returns 0 in half the cases); logger at 0x700390 slot 0x20 -> object with slot 0x30 (4 args, caller-popped)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g505fa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def item():
        return obj(c, 0x20, {0x18: pystub(c, 1, this=True, ret=0 if r.random() < 0.5 else r.getrandbits(32) | 1)}, nslots=8)
    a1 = 0 if r.random() < 0.2 else item()
    b1 = 0 if r.random() < 0.3 else item()
    P = obj(c, 0x20, {0x2c0: pystub(c, 0, this=True, ret=a1), 0x2c4: pystub(c, 0, this=True, ret=b1), 0x30c: pystub(c, 0, this=True, ret=r.getrandbits(32))}, nslots=0xc4)
    me = rnd(c, 0x40)
    e.w32(me + 0x14, P)
    lg2 = obj(c, 0x20, {0x30: pystub(c, 4, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    return [me, r.getrandbits(32)]


S(0x505fa0, 'GUESS lookup in two sources', 'thiscall', None, ret='eax', gen=_g505fa0, note='batch35021')
