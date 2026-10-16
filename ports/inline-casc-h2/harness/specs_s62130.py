from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = rnd(c, 0x300)
    e.w8(self + 0x21a, r.randrange(2))
    # Keep the counter nonnegative: the original uses a signed JL, so 0xffffffff
    # bypasses the bounds reset and indexes before the engine array.
    e.w32(self + 0x2a7, r.choice([0, 1, 7]))
    count = r.choice([0, 1, 2, 4])
    state = rnd(c, 0x600)
    e.w32(state + 0x4b0, count)
    for i in range(5):
        item = obj(c, 0x20, {0x630: pystub(c, 1, this=True, pop=4)})
        entry = rnd(c, 0x10)
        e.w32(entry + 4, item)
        e.w32(state + 0x4b4 + 4 * i, entry)
    e.w32(0x7003b8, state)
    hook_rec(c, 0x515850, 0, this=True, pop=0)
    hook_rec(c, 0x5157d0, 0, this=True, pop=0)
    hook_rec(c, 0x514c70, 0, this=True, pop=0)
    hook_rec(c, 0x514cf0, 0, this=True, pop=0)
    return [self]

S(0x515d00, 'GUESS update_twenty_resource_entries', 'thiscall', None, ret=None, gen=gen, note='batch62130')
