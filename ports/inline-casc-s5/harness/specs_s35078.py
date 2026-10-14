"""specs_s35078.py - 0x4750b0 (thiscall(b) ret 4). this: slots 0x560 (returns want), 0x564 (2 args); b: slots 0x364 (end), 0x35c (cur) returning mixed small / negative / extreme values, 0x360 and 0x358 (1 arg);
logger at 0x700390 (slot 0x20 -> object with slot 0x2c, 3 args, caller-popped)."""
from pilot import S
from recruits_util import obj, clear_hooks, pystub


def _g4750b0(c):
    clear_hooks(c)
    r = c.rng
    vals = [0, 1, 5, 100, 1000, -1, -50, 0x7fffffff, -0x80000000]

    def v():
        return (r.choice(vals) if r.random() < 0.5 else r.randint(-300, 300)) & 0xffffffff
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, lg)
    me = obj(c, 0x20, {0x560: pystub(c, 1, this=True, ret=v()), 0x564: pystub(c, 2, this=True)}, nslots=0x15a)
    b = obj(c, 0x20, {0x364: pystub(c, 0, this=True, ret=v()), 0x35c: pystub(c, 0, this=True, ret=v()),
                      0x360: pystub(c, 1, this=True), 0x358: pystub(c, 1, this=True)}, nslots=0xe0)
    return [me, b]


S(0x4750b0, 'GUESS clamp advance, log and commit', 'thiscall', None, ret=None, gen=_g4750b0, note='batch35078')
