"""specs_u69_29.py - area 69, group 29 (slice 8): stdcall clearBits through the global pointer 0x70039c."""
from pilot import S
from ckit import rnd


def _cb(c):
    obj = rnd(c, 0x1500)
    c.emu.w32(0x70039c, obj)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x655200, 'clearBits655200 (stdcall, three ignored args)', 'stdcall', None, ret=None, gen=_cb,
  note='u69 group 29; reads the global 0x70039c, which the spec points at a 0x1500-byte object')
