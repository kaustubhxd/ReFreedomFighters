"""Controlled strict spec for 0x662e70's vector-easing time setter."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, rnd


def g662e70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self = rnd(c, 0x80)
    old_ticks, milliseconds = r.choice([
        (0, 0), (1, 1), (-1, -1), (0, 1), (1, 0),
        (0, 2), (2, 0), (-2, 0), (0, -2),
        (1024, 0), (0, 1024), (-1024, 1024),
        (0x7fffffff, 0x7fffffff), (0x80000000, 0x80000000),
        (0x7fffffff, 0x80000000), (r.getrandbits(32), r.getrandbits(32)),
    ])
    e.w32(self + 0x45, old_ticks)
    hook_rec(c, 0x662cf0, 0, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x662b70, 1, ret=r.getrandbits(32), this=True)
    return [self, milliseconds]


S(0x662e70, 'vector_ease_set_duration', 'thiscall', None, ret=None,
  gen=g662e70, reg_values=True)
