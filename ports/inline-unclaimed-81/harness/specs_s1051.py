"""specs_s1051.py - area 81, batch 1051: 0x658240 (thiscall: this, no stack arguments, plain ret). Calls 0x64fae0,
then if a pointer at this+0x1186 is non-null, calls 0x634273(pointer, 4) and zeroes the field.
Spec uses null-only test case to avoid faults on the real free function."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def g(c):
    # Create this object with space for a pointer at offset 0x1186
    this_ = c.emu.alloc(0x1186 + 4, 4)

    # Null case only (non-null would trigger real free which faults)
    c.emu.w32(this_ + 0x1186, 0)

    # Patch 0x64fae0 (called unconditionally): simple return
    ss.patch(c, 0x64fae0, ss.code(c, b'\xc3'))  # ret

    # Patch 0x634273 (free-like): not called in null-case test
    ss.patch(c, 0x634273, ss.rec(c, 2))

    return [this_]


S(0x658240, 'GUESS 0x658240 free and clear', 'thiscall', None, ret=None, gen=g)
