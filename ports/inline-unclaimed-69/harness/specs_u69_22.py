"""specs_u69_22.py - area 69, group 22 (slice 8): clear bit 1 at self+5."""
from pilot import S
from ckit import rnd


def _cb(c):
    return [rnd(c, 0x20)]


S(0x613940, 'clearBit2At5 (thiscall, no args)', 'thiscall', None, ret=None, gen=_cb, note='u69 group 22; no callees')
