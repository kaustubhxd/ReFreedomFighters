"""specs_u69_71.py - area 69, group 71 (slice 8): 0x624600, a two-level table bit test on the bytes at the second arg (no callees). The first arg is not read."""
from pilot import S
from ckit import rnd


def _bt(c):
    p = rnd(c, 4)
    return [c.rng.getrandbits(32), p]


S(0x624600, 'bitTest624600 (cdecl, two args, returns the masked dword)', 'cdecl', None, ret='eax', gen=_bt, note='u69 group 71; no callees; reads the tables 0x6bfc20 and 0x6bf720')
