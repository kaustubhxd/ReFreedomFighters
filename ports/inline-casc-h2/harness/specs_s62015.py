from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g5e5bc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    replacement = rnd(c, 0x20)
    result = r.getrandbits(32)

    def replace_arg(emu, call_no):
        emu.w32(emu.arg32(0), replacement)

    hook_rec(c, 0x489350, 1, this=True, pop=4)
    arg = obj(c, 0x20, {0x40: pystub(c, 1, this=True, pop=4, nullflag=(0,), side=replace_arg)})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=result)})
    self = rnd(c, 0x560)
    e.w32(self + 0x54c, r.getrandbits(32))
    return [self, arg]


S(0x5e5bc0, 'GUESS update owner from table lookup', 'thiscall', None, ret='al', gen=g5e5bc0, note='batch62015')
