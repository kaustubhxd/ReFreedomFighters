"""specs_u69_18.py - area 69, group 18 (unclaimed-69 thread): 0x410250."""
from pilot import S
from ckit import rnd


def _rd(c):
    obj = rnd(c, 0x40)
    pp = rnd(c, 0x10)
    c.emu.w32(pp, obj)
    return [pp]


S(0x410250, 'readU32At12 (cdecl, one stack arg)', 'cdecl', None, ret='eax', gen=_rd, note='u69 group 18; no callees')
