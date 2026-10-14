"""specs_u69_30.py - area 69, group 30 (slice 8): a two-arg constructor and a three-dword copy."""
from pilot import S
from ckit import rnd


def _ctor(c):
    return [rnd(c, 0x20), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _copy(c):
    return [rnd(c, 0x40), rnd(c, 0x10)]


S(0x6168c0, 'ctorVt6bdda8 (thiscall, two args, returns this)', 'thiscall', None, ret='eax', gen=_ctor, note='u69 group 30; no callees')
S(0x45acc0, 'copyVec3To18 (thiscall, one pointer arg)', 'thiscall', None, ret=None, gen=_copy, note='u69 group 30; no callees')
