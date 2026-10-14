"""specs_s35007.py - 0x486e90. Engine object at [this+8] (slot 0x560 returns want, slot 0x564 recorded with 2 args); b object with slots 0x364 (end), 0x35c (cur) returning values,
0x360 / 0x358 (1 arg) and 0x2d0 (2 args) recorded. Values mix small, negative and extreme numbers; limit is 0, small, negative or random."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g486e90(c):
    clear_hooks(c)
    r = c.rng
    vals = [0, 1, 5, 100, 1000, -1, -50, 0x7fffffff, -0x80000000]

    def v():
        return (r.choice(vals) if r.random() < 0.5 else r.randint(-300, 300)) & 0xffffffff
    eng = obj(c, 0x10, {0x560: pystub(c, 1, ret=v(), this=True), 0x564: pystub(c, 2, this=True)}, nslots=0x160)
    b = obj(c, 0x20, {0x364: pystub(c, 0, ret=v(), this=True), 0x35c: pystub(c, 0, ret=v(), this=True),
                      0x360: pystub(c, 1, this=True), 0x358: pystub(c, 1, this=True), 0x2d0: pystub(c, 2, this=True)}, nslots=0xe0)
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, eng)
    return [me, b, r.choice([0, 0, v(), v(), r.getrandbits(32)])]


S(0x486e90, 'GUESS clamp advance and commit', 'thiscall', None, ret=None, gen=_g486e90, note='batch35007')
