"""specs_u69_62.py - area 69, group 62 (slice 8): 0x56dcc0, a block copy (no callees). self and src are separate 0x220-byte blocks."""
from pilot import S
from ckit import rnd


def _cp(c):
    return [rnd(c, 0x220), rnd(c, 0x220)]


S(0x56dcc0, 'copyMultiplayerStat56dcc0 (thiscall, one arg, ret 4)', 'thiscall', None, ret=None, gen=_cp, note='u69 group 62; no callees')
