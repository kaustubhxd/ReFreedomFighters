"""specs_s1052.py - area 81, batch 1052: 0x651940 (thiscall: this, one stack argument flag; ret 4; eax returned).
Calls 0x651880, tests flag bit in argument, conditionally calls 0x634273(this, 0x12a3), returns this."""
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

    # Argument with flag bit always 0 to avoid free call (real free faults)
    arg = 0  # flag = 0, so free is not called

    # Patch 0x651880 (helper): simple return
    ss.patch(c, 0x651880, ss.code(c, b'\xc3'))  # ret

    # Patch 0x634273 (free): not called in this test
    ss.patch(c, 0x634273, ss.rec(c, 2))

    return [this_, arg]


S(0x651940, 'GUESS 0x651940 conditional free with return', 'thiscall', None, ret='eax', gen=g)
