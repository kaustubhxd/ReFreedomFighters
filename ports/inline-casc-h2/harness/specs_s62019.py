from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g466890(c):
    clear_hooks(c)
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda emu, k: emu.reg('eax'))
    nested = obj(c, 0x20, {0x10: pystub(c, 4, this=True, pop=16, nullflag=(0,))})
    self = rnd(c, 0x80)
    c.emu.w32(self + 0x6c, nested)
    return [self, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x466890, 'GUESS pass fields to nested object with GS check', 'thiscall', None, ret=None, gen=g466890, note='batch62019')
