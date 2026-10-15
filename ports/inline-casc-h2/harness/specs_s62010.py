from pilot import S
from recruits_util import obj, clear_hooks, hook_rec

def gen(c):
    clear_hooks(c)
    hook_rec(c, 0x634273, 2, pop=0)
    self = obj(c, 0x80, {})
    member = obj(c, 0x20, {}) if c.rng.random() < 0.7 else 0
    allocation = obj(c, 0x20, {}) if c.rng.random() < 0.7 else 0
    c.emu.w32(self + 0x65, member)
    c.emu.w32(self + 8, allocation)
    return [self]

S(0x435b50, 'GUESS destroy optional member and allocation', 'thiscall', None, ret=None, gen=gen, note='batch62010')
