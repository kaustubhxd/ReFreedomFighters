"""specs_s35115.py - 0x54eb80 (thiscall, no args). this: random 0x90 bytes (every default store observable); [this+4] = owner (null in 1/5) whose slot 0x10 is called with ECX = vtable and seven stack args (callee pops 0x1c; result negative in a third: log line through the logger at 0x700390, slot 0x20 -> object with slot 0x2c, 2 args, caller-popped)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g54eb80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rv = r.choice([0, 1, 0x7fffffff, 0xffffffff, 0x80000000, 0x80004005])
    owner = 0 if r.random() < 0.2 else obj(c, 0x20, {0x10: pystub(c, 7, this=True, ret=rv)}, nslots=5)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    me = rnd(c, 0x90)
    e.w32(me + 4, owner)
    return [me]


S(0x54eb80, 'GUESS reset tuning block to defaults and register', 'thiscall', None, ret=None, gen=_g54eb80, note='batch35115')
