"""specs_u69_49.py - area 69, group 49 (slice 8): 0x56ed00, a block copy with no callees. self and src are separate 0x980-byte blocks."""
from pilot import S
from ckit import rnd


def _cp(c):
    dst = rnd(c, 0x980)
    src = rnd(c, 0x980)
    return [dst, src]


S(0x56ed00, 'copyBlock56ed00 (thiscall, one arg, returns this)', 'thiscall', None, ret='eax', gen=_cp, note='u69 group 49; no callees')
