"""specs_u69_70.py - area 69, group 70 (slice 8): 0x499880, a constructor with field stores (no callees)."""
from pilot import S
from ckit import rnd


def _ctor(c):
    return [rnd(c, 0x40), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x499880, 'ctor68e9cc499880 (thiscall, two args, ret 8, returns this)', 'thiscall', None, ret='eax', gen=_ctor, note='u69 group 70; no callees')
