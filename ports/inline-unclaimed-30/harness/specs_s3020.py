"""specs_s3020.py - unclaimed-30 claim 2 (residue 10): ZOnScreenDisplay::MapIconClear (0x5aa6e0). The 24 pointers at +0x4cc are objects
with a logged vtable (slot 8, no arguments); each object's byte +0x35 is in the heap compare. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _mic(c):
    e = c.emu
    self_ = rnd(c, 0x800)
    for i in range(24):
        o = rnd(c, 0x40)
        e.w32(o, vtable(c, 'mapicon', 0x20, argwords={0x8: 0}))
        e.w32(self_ + 0x4cc + 4 * i, o)
    return [self_]


S(0x5aa6e0, 'ZOnScreenDisplay::MapIconClear', 'thiscall', None, gen=_mic, n=300)
