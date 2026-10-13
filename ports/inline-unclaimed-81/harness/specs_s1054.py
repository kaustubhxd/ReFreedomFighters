"""specs_s1054.py - area 81, batch 1054: 0x661340 (thiscall: this, one byte flag argument; ret 4; eax returned).
Sets vtable word 0x6c4a00, calls 0x4eb3d0, tests flag, optionally calls 0x634273(this, 0x21b1) to free, returns this."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def g(c):
    # Create this object
    this_ = c.emu.alloc(0x40, 4)

    # Flag always 0 to avoid free faults
    arg = 0  # flag = 0, so free is not called

    # Patch 0x4eb3d0 (helper): simple return
    ss.patch(c, 0x4eb3d0, ss.code(c, b'\xc3'))  # ret

    # Patch 0x634273 (free): not called in this test
    ss.patch(c, 0x634273, ss.rec(c, 2))

    return [this_, arg]


S(0x661340, 'GUESS 0x661340 vtable init and free', 'thiscall', None, ret='eax', gen=g)
