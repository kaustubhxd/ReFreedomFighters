"""specs_s35048.py - 0x533e00 (thiscall, no args, ret='eax'). Pool object (0x1020 random bytes): [0] = H (slot 4 returns a random id; [H+0x10] mask among 0x3ff, 0xff, 0xf, 0), [4] = 0x1000-byte table,
[8] = entry area of 0x800 bytes of random data (entries at i * 0xfd, i = free-list head 0..5), count [+0x100c] = 0x400 in a fifth of the cases (log path through the logger at 0x700390: slot 0x20 -> object with
slot 0x2c, 3 args, caller-popped), else random below 0x400."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g533e00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    H = obj(c, 0x20, {4: pystub(c, 0, this=True, ret=r.getrandbits(32))}, nslots=2)
    e.w32(H + 0x10, r.choice([0x3ff, 0xff, 0xf, 0]))
    me = rnd(c, 0x1020)
    e.w32(me, H)
    e.w32(me + 4, rnd(c, 0x1000))
    e.w32(me + 8, rnd(c, 0x800))
    e.w32(me + 0x1010, r.randint(0, 5))
    e.w32(me + 0x100c, 0x400 if r.random() < 0.2 else r.randrange(0x400))
    return [me]


S(0x533e00, 'GUESS allocate pool entry and reset fields', 'thiscall', None, ret='eax', gen=_g533e00, note='batch35048')
