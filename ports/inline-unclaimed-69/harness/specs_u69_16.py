"""specs_u69_16.py - area 69, group 16 (unclaimed-69 thread): 0x54cb50."""
from pilot import S
from ckit import rnd


def _init(c):
    return [rnd(c, 0x20)]


S(0x54cb50, 'initVt6a3de4 (thiscall, no args, returns this)', 'thiscall', None, ret='eax', gen=_init, note='u69 group 16; no callees')
