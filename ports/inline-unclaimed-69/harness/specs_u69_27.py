"""specs_u69_27.py - area 69, group 27 (slice 8): setFlag40At5f1700 through two pointers."""
from pilot import S
from ckit import rnd


def _flag(c):
    o = rnd(c, 0x20)
    mid = rnd(c, 0x10)
    inner = rnd(c, 0x50)
    c.emu.w32(o + 0xc, mid)
    c.emu.w32(mid + 4, inner)
    return [o, c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])]


S(0x5f1700, 'setFlag40At5f1700 (thiscall, one arg, ret 4)', 'thiscall', None, ret=None, gen=_flag, note='u69 group 27; no callees')
