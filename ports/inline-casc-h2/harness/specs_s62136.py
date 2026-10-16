from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = rnd(c, 0x1120)
    # Sparse non-null slots still make both cleanup loops observable without
    # turning each 1000-case pilot into a million unnecessary calls.
    for i in range(1000):
        e.w32(self + 0x0f + 4 * i, rnd(c, 4) if i in (0, 317, 999) else 0)
    for i in range(20):
        e.w32(self + 0xfb7 + 4 * i, rnd(c, 4) if i in (1, 19) else 0)
    dtor = obj(c, 0x20, {0: pystub(c, 1, this=True, pop=4)})
    e.w32(self + 0x10f0, dtor if r.randrange(2) else 0)
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x4d8450, 0, this=True, pop=0)
    return [self]

S(0x4d3f80, 'GUESS release_two_arrays_and_tail_cleanup', 'thiscall', None, ret=None, gen=gen, note='batch62136')
