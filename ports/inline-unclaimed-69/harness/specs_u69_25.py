"""specs_u69_25.py - area 69, group 25 (slice 8): field ops on self."""
from pilot import S
from ckit import rnd


def _or(c):
    return [rnd(c, 0x200), c.rng.choice([0, 1, 7, 0x20, c.rng.getrandbits(8)])]


def _ret(c):
    return [rnd(c, 0x200), c.rng.choice([0, 1, 3, c.rng.getrandbits(32)])]


S(0x5ad000, 'orInto5ad000 (thiscall, one arg, ret 4)', 'thiscall', None, ret=None, gen=_or, note='u69 group 25; no callees')
S(0x65ca00, 'advance65ca00 (thiscall, one arg, ret 4)', 'thiscall', None, ret='eax', gen=_ret, note='u69 group 25; no callees')
S(0x650fc0, 'swap5c650fc0 (thiscall, one arg, ret 4)', 'thiscall', None, ret='eax', gen=_ret, note='u69 group 25; no callees')
