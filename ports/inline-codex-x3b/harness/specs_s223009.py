"""Strict scalar-return spec for 0x5272d0."""
import struct

from pilot import S
from recruits_util import clear_hooks, rnd


def g5272d0(c):
    clear_hooks(c)
    self = rnd(c, 0x20)
    bits = c.rng.choice([
        0x00000000, 0x80000000, 0x3f800000, 0xbf800000,
        0x7f800000, 0xff800000, 0x7fc12345, c.rng.getrandbits(32),
    ])
    c.emu.w32(self + 0x10, bits)
    return [self]


S(0x5272d0, 'float_field_getter_10', 'thiscall', None, ret='st0',
  gen=g5272d0, reg_values=True)
