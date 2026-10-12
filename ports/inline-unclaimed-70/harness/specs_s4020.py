"""specs_s4020.py - area 70 batch 4020: two pure initialisers (GUESS names). No callees."""
from pilot import S, F


def _obj(c):
    e, r = c.emu, c.rng
    o = e.alloc(0x40, 16)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x40)))
    return [o]


def _init(c):
    e, r = c.emu, c.rng
    o = e.alloc(0x40, 16)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x40)))
    return [o, r.getrandbits(32), r.getrandbits(32)]


S(0x5aef10, 'zero the sixteen dwords at [this] (name GUESS)', 'thiscall', None, gen=_obj, note='batch4020')
S(0x487650, 'initialiser: two stored dwords, vtable 0x68d14c, byte at +0x1c (name GUESS)', 'thiscall', None, ret='eax',
  gen=_init, note='batch4020')
