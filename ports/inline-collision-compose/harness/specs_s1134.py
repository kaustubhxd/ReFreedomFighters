"""specs_s1134.py - collision thread batch 1134 (GUESS name): 0x5eef00, a dispatcher over three fake objects. Slot 8 of each
object is a logging fake (thiscall, no arguments); the last one returns a per-case EAX (the tail jump's result)."""
from pilot import S, F


def _disp(c):
    e, r = c.emu, c.rng
    retv = r.getrandbits(32)
    objs = []
    for k in range(3):
        if k == 2:
            vt = e.logging_vtable('obj8_5eef00_%d' % k, 0x12, impl={8: lambda em, a, v=retv: (v, None)}, argwords={8: 0})
        else:
            vt = e.logging_vtable('obj8_5eef00_%d' % k, 0x12, impl={8: lambda em, a: (None, None)}, argwords={8: 0})
        o = e.alloc(0x40, 4)
        e.w32(o, vt)
        objs.append(o)
    self_ = e.alloc(0x40, 4)
    e.w32(self_ + 4, objs[0])
    e.w32(self_ + 8, objs[1])
    e.w32(self_ + 0xc, objs[2])
    return [self_]


S(0x5eef00, 'dispatch: slot 8 of two objects, then the third object returns (name GUESS)', 'thiscall', None, ret='eax',
  gen=_disp, note='batch1134')
