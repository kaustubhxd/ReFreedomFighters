"""specs_u69_31.py - area 69, group 31 (slice 8): a four-arg store, an or-with-zero-test, and a stdcall copy."""
from pilot import S
from ckit import rnd


def _four(c):
    return [rnd(c, 0x40)] + [c.rng.getrandbits(32) for _ in range(4)]


def _or(c):
    return [c.rng.choice([0, 0x100, 1, 0x80, c.rng.getrandbits(32)]), c.rng.choice([0, 0x200, 2, c.rng.getrandbits(32)])]


def _cp(c):
    return [rnd(c, 0x20), rnd(c, 0x20)]


S(0x5ac600, 'setFourAt9 (thiscall, four args, ret 0x10)', 'thiscall', None, ret=None, gen=_four, note='u69 group 31; no callees')
S(0x4273c0, 'orIsZero4273c0 (stdcall, two args)', 'stdcall', None, ret='eax', gen=_or, note='u69 group 31; no callees')
S(0x6564c0, 'copyLight6564c0 (stdcall, two pointer args)', 'stdcall', None, ret=None, gen=_cp, note='u69 group 31; no callees')
