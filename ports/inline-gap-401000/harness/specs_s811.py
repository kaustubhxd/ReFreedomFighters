"""specs_s811.py - core batch 811 (docs/20-unclaimed-65.md). 0x51a7c0: no arguments, returns the constant 0x69f26c in eax. 0x53e800
(CRigidBody::CopyData): thiscall with one stack argument (the source object, ret 4); copies the byte at +0x149 and the dwords at +0x145
and +0x141 from the source into this. Both blocks are random per case."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


S(0x51a7c0, 'core method 0x51a7c0 (unknown) no args', 'thiscall', None, ret='eax', gen=lambda c: [_rnd(c, 0x10)],
  note='core batch 811: constant return 0x69f26c')


S(0x53e800, 'CRigidBody::CopyData (unknown) thiscall one arg', 'thiscall', None, ret=None,
  gen=lambda c: [_rnd(c, 0x200), _rnd(c, 0x200)], note='core batch 811: copy three fields from the source object')
