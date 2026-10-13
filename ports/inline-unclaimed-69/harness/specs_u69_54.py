"""specs_u69_54.py - area 69, group 54 (slice 8): 0x41e180, a constructor with field stores (no callees)."""
from pilot import S
from ckit import rnd


def _ctor(c):
    return [rnd(c, 0x60)]


S(0x41e180, 'ctor67716c41e180 (thiscall, no args, returns this)', 'thiscall', None, ret='eax', gen=_ctor, note='u69 group 54; no callees')
