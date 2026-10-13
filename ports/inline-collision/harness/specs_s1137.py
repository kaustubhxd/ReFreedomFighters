"""specs_s1137.py - collision thread batch 1137 (GUESS name): 0x5b9100, a chain of 23 virtual calls on the argument object (logged
fakes for slots 0x3c, 0x4c, 0x60, 0x64, 0x68, 0x6c, 0x70; each records its argument). The this object is random bytes; the
bit-0x40 clear on [this+4] is compared as data."""
from pilot import S, F


def _ser(c):
    e, r = c.emu, c.rng
    slots = {}
    for off in (0x3c, 0x4c, 0x60, 0x64, 0x68, 0x6c, 0x70):
        slots[off] = (lambda em, a: (None, None))
    lvt = e.logging_vtable('obj_5b9100', 0x1e, impl=slots, argwords={0x3c: 1, 0x4c: 1, 0x60: 1, 0x64: 1, 0x68: 1, 0x6c: 1, 0x70: 1})
    o = e.alloc(0x40, 4)
    e.w32(o, lvt)
    self_ = e.alloc(0x100, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    return [self_, o]


S(0x5b9100, 'chain of 23 virtual calls on the argument with fields of this (name GUESS)', 'thiscall', None, ret='al',
  gen=_ser, note='batch1137')
