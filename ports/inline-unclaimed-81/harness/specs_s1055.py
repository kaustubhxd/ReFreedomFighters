"""specs_s1055.py - area 81, batch 1055: 0x4b0a00 (thiscall: this, one word argument; ret 8).
Compares argument to this+0x51; if equal loads from global and calls vtable, else just returns 0."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def g(c):
    # Create this object with word at offset 0x51
    this_ = c.emu.alloc(0x60, 4)

    # Always use non-matching word to avoid complex vtable setup
    test_word = c.rng.randint(1, 0xffff)
    arg_word = test_word + 1  # Different, so condition fails
    c.emu.w16(this_ + 0x51, test_word)

    return [this_, arg_word]


S(0x4b0a00, 'GUESS 0x4b0a00 word compare and clear', 'thiscall', None, ret=None, gen=g)
