"""specs_s35130.py - 0x4d0fc0 (thiscall(a, b, c) ret 0xc). this: random 0x100 bytes with the record counter [+0x88] 0..5, array pointer [+0] (heap block of 0x40 bytes, or null with n == 0), capacity [+4] and count [+8] (n < cap in 2/3, n >= cap otherwise); logger at 0x700390
(slot 0x20 -> object with slot 0x2c, 2 args, caller-popped)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4d0fc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    me = rnd(c, 0x100)
    e.w32(me + 0x88, r.randint(0, 5))
    if r.random() < 0.15:
        e.w32(me, 0)
        e.w32(me + 8, 0)
        e.w32(me + 4, r.choice([0, 3]))
    else:
        e.w32(me, rnd(c, 0x40))
        cap = r.randint(1, 6)
        n = r.randrange(cap) if r.random() < 2 / 3 else cap + r.randint(0, 2)
        n = min(n, 7)
        e.w32(me + 4, cap)
        e.w32(me + 8, n)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4d0fc0, 'GUESS append range record and bounded array entry', 'thiscall', None, ret=None, gen=_g4d0fc0, note='batch35130')
