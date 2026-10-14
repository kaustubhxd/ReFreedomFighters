"""specs_u69_37.py - area 69, group 37 (slice 8): ZColiTreeCompiled::Init-style copy."""
from pilot import S
from ckit import rnd


def _init(c):
    return [rnd(c, 0x20), rnd(c, 0x20)]


S(0x4ede80, 'initFromCompiled4ede80 (ZColiTreeCompiled::Init, thiscall, one arg, ret 4)', 'thiscall', None, ret='eax', gen=_init, note='u69 group 37; no callees')
