from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec

def gen(c):
    clear_hooks(c)
    hook_rec(c, 0x5ec090, 2, this=True, pop=8)
    self = obj(c, 0x480, {})
    sub = obj(c, 0x20, {})
    c.emu.w32(self + 0x43c, sub)
    # Include both the reset-special case and ordinary frame updates.
    if c.rng.random() < 0.25:
        c.emu.w32(self + 0x47c, 12)
    else:
        c.emu.w32(self + 0x47c, c.rng.choice([0, 1, 11, 13, c.rng.getrandbits(32)]))
    c.emu.w32(self + 0x370, c.rng.choice([0, 100, c.rng.getrandbits(32)]))
    return [self, c.rng.choice([0, 1, 99, 100, 101, c.rng.getrandbits(32)])]

S(0x5a5e90, 'GUESS update frame progress', 'thiscall', None, ret=None, gen=gen, note='batch62001')
