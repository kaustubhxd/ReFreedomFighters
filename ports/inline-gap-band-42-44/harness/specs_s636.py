"""specs_s636.py - band 0x421000-0x441000, batch 636 (see src/batch636.cpp).
0x43e700: ZHELPER::ModifyBox. Tests flag byte; if set, calls vtable slot and exe function,
copies three dwords from arg3 to this+0x28/0x2c/0x30.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402
import serial_stubs as ss  # noqa: E402


def _rec_slot74(e, rr):
    """Recording handler for vtable slot 0x74: thiscall(self, arg1, arg2)."""
    arg1 = e.arg32(0)
    arg2 = e.arg32(1)
    e.calllog.append(('modifybox.74', 0x74, e.reg('ecx'), (arg1, arg2)))
    e.ret(eax=0, argbytes=8)  # thiscall, 2 args, callee pops


def _gen(c):
    r = c.rng
    # Create self object (0x40 bytes)
    self = c.emu.alloc(0x40, 16)
    c.emu.wbytes(self, bytes(r.getrandbits(8) for _ in range(0x40)))

    # Create fake vtable with slot 0x74
    fake_vtable = c.emu.fake_object('modifybox_vt', 0x80, nslots=0x20, slots={
        0x74 // 4: _rec_slot74
    })
    c.emu.w32(self, fake_vtable)

    # Set flag byte at [self+0x18] to trigger code path (50% chance)
    if r.random() < 0.5:
        c.emu.wbytes(self + 0x18, bytes([0x08]))  # Set bit 0x8
    else:
        c.emu.wbytes(self + 0x18, bytes([0x00]))  # Clear bit 0x8

    # Set member at [self+0x8]
    member = c.emu.alloc(0x40, 16)
    c.emu.wbytes(member, bytes(r.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(self + 0x8, member)

    # Patch exe function 0x4690b0 with stub
    stub_addr = ss.rec(c, 1, ret=0)
    c.emu.w32(0x4690b0, stub_addr)
    c.emu._image_dirty = True

    # Create arg3 (pointer to three dwords)
    arg3_data = c.emu.alloc(12, 4)
    c.emu.w32(arg3_data, r.getrandbits(32))
    c.emu.w32(arg3_data + 4, r.getrandbits(32))
    c.emu.w32(arg3_data + 8, r.getrandbits(32))

    # Test arguments (4 args on stack)
    arg1 = r.getrandbits(32)
    arg2 = r.getrandbits(32)
    arg4 = r.getrandbits(32)

    return [self, arg1, arg2, arg3_data, arg4]


S(0x43e700, 'ZHELPER::ModifyBox', 'thiscall', None, ret=None, gen=_gen)
