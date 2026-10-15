from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    resource = 0
    if r.random() < 0.65:
        description = rnd(c, 0x20)
        e.w32(description + 4, r.choice([0, 0x681234, 0x6a55a0]))
        resource = obj(c, 0x20, {0x2e8: pystub(c, 0, this=True, ret=description)}, nslots=0x2e8 // 4 + 1)
    manager = obj(c, 0x20, {0x504: pystub(c, 0, this=True, ret=resource)}, nslots=0x504 // 4 + 1)
    self = rnd(c, 0x1d20)
    logger = obj(c, 0x700, {}) if r.random() < 0.8 else 0
    e.w32(self + 0x1d0b, manager)
    e.w32(self + 0x1d0f, logger)
    hook_rec(c, 0x5a9e20, 1, this=True, pop=4)
    hook_rec(c, 0x5aa060, 1, this=True, pop=4)
    hook_rec(c, 0x5b0010, 1, this=True, pop=4)
    return [self]


S(0x5b0220, 'GUESS resource error logging and setup dispatch', 'thiscall', None,
  ret=None, gen=gen, note='batch62111')
