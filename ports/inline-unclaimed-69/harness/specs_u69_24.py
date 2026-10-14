"""specs_u69_24.py - area 69, group 24 (slice 8): void setter, stdcall or-with-1, list pop."""
from pilot import S
from ckit import rnd


def _clr(c):
    return [rnd(c, 0x20)]


def _or1(c):
    return [c.rng.choice([0, 0x10, c.rng.getrandbits(32)])]


def _pop(c):
    o = rnd(c, 0x40)
    node = rnd(c, 0x10)
    c.emu.w32(node + 4, c.rng.getrandbits(32))
    c.emu.w32(o + 0x2c, c.rng.choice([0, node]))
    return [o]


S(0x4d2900, 'clearDwordAtC (thiscall, void)', 'thiscall', None, ret=None, gen=_clr, note='u69 group 24; no callees')
S(0x4e6900, 'orOne4e6900 (stdcall, one arg)', 'stdcall', None, ret='eax', gen=_or1, note='u69 group 24; no callees')
S(0x41ef40, 'popHead41ef40 (thiscall, no args)', 'thiscall', None, ret='eax', gen=_pop, note='u69 group 24; no callees')
