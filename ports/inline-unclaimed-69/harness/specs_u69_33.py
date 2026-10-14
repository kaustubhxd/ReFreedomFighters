"""specs_u69_33.py - area 69, group 33 (slice 8): vtable store and four bit clears at large offsets."""
from pilot import S
from ckit import rnd


def _init(c):
    return [rnd(c, 0x18300)]


S(0x648280, 'initVt6c2c20 (thiscall, no args)', 'thiscall', None, ret=None, gen=_init, note='u69 group 33; no callees')
