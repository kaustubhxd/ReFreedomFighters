from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    sys = obj(c, 0x20, {0x1a8: pystub(c, 1, this=True, pop=4)})
    e.w32(0x70039c, sys)
    self = rnd(c, 0x40)
    for off in (0x1d, 0x15, 0x19):
        ptr = obj(c, 0x20, {0: pystub(c, 1, this=True, pop=4)}) if r.random() < 0.7 else 0
        e.w32(self + off, ptr)
    return [self]

S(0x641bd0, 'GUESS release_and_clear_three_unaligned_object_fields', 'thiscall', None, ret=None, gen=gen, note='batch62121')
