"""specs_s635.py - band 0x421000-0x441000, batch 635 (see src/batch635.cpp).
0x435bc0: ZInputDeviceBase destructor. Sets vtable, calls exe 0x634273 based on member and flag.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402
import serial_stubs as ss  # noqa: E402


def _gen(c):
    r = c.rng
    # Patch exe function 0x634273 with recording stub (stdcall, 2 args, ret nothing)
    stub_addr = ss.rec(c, 2, ret=0)
    c.emu.w32(0x634273, stub_addr)
    c.emu._image_dirty = True

    # Create self object (44 bytes: 0x8 for member, rest for data)
    self = c.emu.alloc(0x44, 16)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x44)))

    # Randomly set member at offset 0x8 (50% chance of non-zero)
    if r.random() < 0.5:
        member = c.emu.alloc(0x40, 16)
        c.emu.wbytes(member, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
        c.emu.w32(self + 0x8, member)
    else:
        c.emu.w32(self + 0x8, 0)

    # Test flag: 0 or 1
    test_flag = r.choice((0, 1))

    return [self, test_flag]


S(0x435bc0, 'ZInputDeviceBase::~ZInputDeviceBase()', 'thiscall', None, ret=None, gen=_gen)
