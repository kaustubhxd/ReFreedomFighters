"""specs_s1053.py - area 81, batch 1053: 0x658d80 (fastcall: this in ecx, no stack args, ret eax).
Loads byte at this+0x3f; if zero returns (byte*3)*16, else loads pointer from this+0x48 and returns (byte*3)*16 + (ptr+0x90)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def g(c):
    # Create this object
    this_ = c.emu.alloc(0x50, 4)

    # Randomly choose zero or non-zero byte
    if c.rng.random() < 0.5:
        # Zero case
        byte_val = 0
        c.emu.w8(this_ + 0x3f, byte_val)
    else:
        # Non-zero case: set a random byte and a pointer at 0x48
        byte_val = c.rng.randint(1, 255)
        c.emu.w8(this_ + 0x3f, byte_val)
        # Allocate and set pointer at 0x48
        ptr = c.emu.alloc(0x100, 4)
        c.emu.w32(this_ + 0x48, ptr)

    return [this_]


S(0x658d80, 'GUESS 0x658d80 index calc', 'fastcall', None, ret='eax', gen=g)
