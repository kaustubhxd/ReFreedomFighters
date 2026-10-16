"""Strict scalar-return spec for 0x526fe0."""
from pilot import S
from recruits_util import clear_hooks, rnd


def g526fe0(c):
    clear_hooks(c)
    self = rnd(c, 0x20)
    bits = c.rng.choice([
        0x00000000, 0x80000000, 0x3f800000, 0xbf800000,
        0x7f800000, 0xff800000, 0x7fc0a5a5, c.rng.getrandbits(32),
    ])
    c.emu.w32(self + 8, bits)
    return [self]


S(0x526fe0, 'float_field_getter_8', 'thiscall', None, ret='st0',
  gen=g526fe0, reg_values=True)
