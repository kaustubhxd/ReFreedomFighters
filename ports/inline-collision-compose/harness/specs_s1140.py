"""specs_s1140.py - collision thread batch 1140 (GUESS name): 0x5ef730. Logged fakes: the three objects at this+0xa9/0xa1/0xa5 and
the optional one at this+0xb1 (slot 0x10, one argument); the argument object o (slots 0x10 with two arguments, 0x3c, 0x44, 0x48,
0x4c (one float), 0x60; each records its arguments). Fields of this are random bytes, with the object pointers set."""
from pilot import S, F


def _ser(c):
    e, r = c.emu, c.rng

    def mk(name, slots):
        vt = e.logging_vtable(name, 0x62, impl={k: (lambda em, a: (None, None)) for k in slots},
                              argwords=slots)
        o = e.alloc(0x40, 4)
        e.w32(o, vt)
        return o

    objs = [mk('objA_5ef730', {0x10: 1}), mk('objB_5ef730', {0x10: 1}), mk('objC_5ef730', {0x10: 1})]
    b1 = mk('objB1_5ef730', {0x10: 1})
    o = mk('arg_5ef730', {0x10: 2, 0x3c: 1, 0x44: 1, 0x48: 1, 0x4c: 1, 0x60: 1})
    self_ = e.alloc(0x100, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x100)))
    e.w32(self_ + 0xa9, objs[0])
    e.w32(self_ + 0xa1, objs[1])
    e.w32(self_ + 0xa5, objs[2])
    e.w32(self_ + 0xb1, b1 if r.random() < 0.6 else 0)
    return [self_, o]


S(0x5ef730, 'three slot-0x10 calls, then a chain of calls on the argument with fields of this (name GUESS)', 'thiscall',
  None, gen=_ser, note='batch1140')
