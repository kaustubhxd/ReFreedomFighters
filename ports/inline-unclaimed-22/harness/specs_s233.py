"""specs_s233.py - area 59, batch233 (src/batch233.cpp): 0x5eefa0. Vtable callees are logged sparse slots with one argument
each (ret 4); every object is a separate heap object, so the object each call goes to is compared."""
from pilot import S
from helpers22 import _rnd, _multi_vt


def _obj_with(c, slots):
    o = _rnd(c, 0x40)
    c.emu.w32(o, _multi_vt(c, {k: ((lambda em, args: (0, None)), 1) for k in slots}))
    return o


def _g_5eefa0(c):
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 4, _obj_with(c, [0x10]))
    c.emu.w32(self_ + 8, _obj_with(c, [0x10]))
    c.emu.w32(self_ + 0xc, _obj_with(c, [0x10]))
    obj = _obj_with(c, [0x60, 0x3c, 0x44])
    return [self_, obj]


S(0x5eefa0, 'serialize (GUESS)', 'thiscall', None, ret=None, gen=_g_5eefa0,
  note='batch233; one-argument vtable calls on the argument object and three sub-objects')
