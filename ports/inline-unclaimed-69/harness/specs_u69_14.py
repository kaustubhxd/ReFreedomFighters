"""specs_u69_14.py - area 69, group 14 (unclaimed-69 thread): 0x54db90."""
from pilot import S
from ckit import rnd


def _sum(c):
    o = rnd(c, 0x8040)
    p = rnd(c, 0x10) if c.rng.random() < 0.8 else 0
    return [o, p]


S(0x54db90, 'sumAt8031 (thiscall, one stack arg, ret 4)', 'thiscall', None, ret='eax', gen=_sum, note='u69 group 14; no callees')
