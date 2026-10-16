from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    old = obj(c, 0x20, {0: pystub(c, 1, this=True, pop=4)}) if r.random() < 0.7 else 0
    self = rnd(c, 0x40)
    e.w32(self + 0x19, old)
    e.w32(self + 0x29, r.getrandbits(32))
    flags = r.choice([0, 1, 4, 5, 3, 7, 0xffffffff])
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x43de70, 0, this=True, pop=0)
    hook_rec(c, 0x45c510, 0, this=True, pop=0)
    hook_rec(c, 0x4690b0, 2, pop=0)
    return [self, flags]

S(0x5d57c0, 'GUESS reset_object_and_release_resources_by_flags', 'thiscall', None, ret='eax', gen=gen, note='batch62119')
