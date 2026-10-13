"""specs_s3549.py - slice 14, batch 49: 0x62cfe0 and 0x4cca60 (two 0-call leaves).
No external stubs; both are pure leaf functions with no vtable or external calls.
"""
import os
import struct
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_62cfe0(c):
    """0x62cfe0: cdecl(arg0, arg1) switch function, no side effects on arg0 for some paths."""
    arg0 = _rnd(c, 0x100)
    arg1 = c.rng.choice([0xf, 0x12, 0x29, 0x1c, 0x20, 0x99, 0xffffffff])
    return [arg0, arg1]


def _gen_4cca60(c):
    """0x4cca60: thiscall(this, arg0, arg1) initializer, stores to many offsets on this."""
    this = _rnd(c, 0x50)  # Need at least 0x24 bytes
    arg0 = c.rng.choice([0, 1, 2, 0x10, 0xffffffff])
    arg1 = c.rng.choice([0, 1, 0x100, 0xdeadbeef])
    return [this, arg0, arg1]


S(0x62cfe0, 'gap62cfe0 (GUESS)', 'cdecl', [None, None], ret=None, gen=_gen_62cfe0,
  note='slice 14, batch 49; switch on arg1 with multiple return paths (0, 0x23, 0x34, or -1)')

S(0x4cca60, 'gap4cca60 (GUESS)', 'thiscall', [None, None, None], ret='eax', gen=_gen_4cca60,
  note='slice 14, batch 49; initializer that stores multiple fields on this, returns this')
