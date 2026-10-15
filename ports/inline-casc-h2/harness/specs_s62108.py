from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, reftab_vt


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = rnd(c, 0x40)
    vtable = reftab_vt(c, [r.getrandbits(32) or 1 for _ in range(r.choice([0, 1, 3, 6]))])
    e.w32(self + 0xa, vtable)
    hook_rec(c, 0x4d92d0, 0, this=True, pop=0)
    hook_rec(c, 0x634273, 2, pop=0)
    return [self]


S(0x4d6880, 'GUESS initialize and release list entries', 'thiscall', None,
  ret=None, gen=gen, note='batch62108')
