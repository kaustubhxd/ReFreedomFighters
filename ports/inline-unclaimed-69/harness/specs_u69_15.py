"""specs_u69_15.py - area 69, group 15 (unclaimed-69 thread): 0x658fd0."""
from pilot import S
from ckit import rnd


def _set(c):
    o = rnd(c, 0x60)
    v = c.rng.choice([0, 1, 0x80000000, c.rng.getrandbits(32)])
    return [o, v]


S(0x658fd0, 'setPtrFlag10 (thiscall, one stack arg, ret 4)', 'thiscall', None, ret=None, gen=_set, note='u69 group 15; no callees')
