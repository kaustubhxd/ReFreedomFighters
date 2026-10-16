"""Strict raw-bit specs for seven x87 float-load leaf functions."""
from pilot import S
from recruits_util import clear_hooks, rnd


def _bits(c):
    return c.rng.choice([
        0x00000000, 0x80000000, 0x3f800000, 0xbf800000,
        0x3f000000, 0x7f800000, 0xff800000, 0x7fc12345,
        c.rng.getrandbits(32),
    ])


def _other(c, value):
    candidate = _bits(c)
    while candidate == value:
        candidate = _bits(c)
    return candidate


def _field(c, size, off):
    clear_hooks(c)
    self = rnd(c, size)
    value = _bits(c)
    c.emu.w32(self + off, value)
    c.emu.w32(self + off + 4, _other(c, value))
    return [self]


def g526fd0(c):
    return _field(c, 0x20, 4)


def g524390(c):
    return _field(c, 0x20, 0xc)


def g51c550(c):
    clear_hooks(c)
    self = rnd(c, 0x20)
    value = _bits(c)
    c.emu.w32(0x69f9e8, value)
    c.emu.w32(0x69f9ec, _other(c, value))
    return [self]


def g5162d0(c):
    return _field(c, 0x70, 0x55)


def g486cb0(c):
    return _field(c, 0x40, 0x30)


def g45efb0(c):
    clear_hooks(c)
    value = _bits(c)
    c.emu.w32(0x67cd44, value)
    c.emu.w32(0x67cd40, _other(c, value))
    return [c.rng.getrandbits(32)]


def g445fb0(c):
    return _field(c, 0x190, 0x181)


S(0x526fd0, 'float_field_getter_4', 'thiscall', None, ret='st0',
  gen=g526fd0, reg_values=True)
S(0x524390, 'float_field_getter_c', 'thiscall', None, ret='st0',
  gen=g524390, reg_values=True)
S(0x51c550, 'global_float_getter_69f9e8', 'thiscall', None, ret='st0',
  gen=g51c550, reg_values=True)
S(0x5162d0, 'float_field_getter_55', 'thiscall', None, ret='st0',
  gen=g5162d0, reg_values=True)
S(0x486cb0, 'float_field_getter_30', 'thiscall', None, ret='st0',
  gen=g486cb0, reg_values=True)
S(0x45efb0, 'global_float_getter_67cd44', 'stdcall', None, ret='st0',
  gen=g45efb0, reg_values=True)
S(0x445fb0, 'float_field_getter_181', 'thiscall', None, ret='st0',
  gen=g445fb0, reg_values=True)
