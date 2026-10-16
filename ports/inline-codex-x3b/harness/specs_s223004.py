"""Controlled strict spec for 0x662b70's easing-duration setter."""
from pilot import S
from recruits_util import clear_hooks, rnd


def g662b70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    easing = rnd(c, 0x40)
    now_owner = rnd(c, 0x50)
    e.w32(0x70039c, now_owner)
    e.w32(now_owner + 0x40, r.getrandbits(32))

    old_duration, milliseconds = r.choice([
        (0, 0), (1, 1), (-1, -1), (0, 1), (1, 0),
        (0, 2), (2, 0), (-2, 0), (0, -2),
        (1024, 0), (0, 1024), (-1024, 1024),
        (0x7fffffff, 0x7fffffff), (0x80000000, 0x80000000),
        (0x7fffffff, 0x80000000), (r.getrandbits(32), r.getrandbits(32)),
    ])
    e.w32(easing + 0x11, old_duration)
    return [easing, milliseconds]


S(0x662b70, 'ease_set_duration', 'thiscall', None, ret=None,
  gen=g662b70, reg_values=True)
