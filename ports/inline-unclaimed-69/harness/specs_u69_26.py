"""specs_u69_26.py - area 69, group 26 (slice 8): stdcall zeroFirst."""
from pilot import S
from ckit import rnd


def _zf(c):
    return [rnd(c, 0x10), rnd(c, 0x20), c.rng.getrandbits(32)]


S(0x607a00, 'zeroFirst607a00 (stdcall, three args)', 'stdcall', None, ret='eax', gen=_zf, note='u69 group 26; no callees')
