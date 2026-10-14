"""specs_u69_17.py - area 69, group 17 (unclaimed-69 thread): 0x5b7bd0."""
from pilot import S
from ckit import rnd


def _init(c):
    return [rnd(c, 0x40)]


S(0x5b7bd0, 'initFields5b7bd0 (thiscall, no args, returns this)', 'thiscall', None, ret='eax', gen=_init, note='u69 group 17; no callees')
