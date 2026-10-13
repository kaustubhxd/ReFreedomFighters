"""specs_s639.py - band 0x421000-0x441000, batch 639 (see src/batch639.cpp).
0x434d10: thiscall(arg1), loops through vtable slots 0x4c, 0x64, 0x14.
Tests arg1; loops while slot[0x64] returns non-null and slot[0x14] returns false.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402
import serial_stubs as ss  # noqa: E402


def _rec_slot_4c(e, rr):
    """Recording handler for vtable slot 0x4c: thiscall(self, local)."""
    e.calllog.append(('slot.4c', 0x4c, e.reg('ecx'), ()))
    e.ret(eax=0, argbytes=4)


def _rec_slot_64(e, rr):
    """Recording handler for vtable slot 0x64: thiscall(self, local), returns obj or null."""
    # Return a non-null object pointer 40% of the time
    if e.rng.random() < 0.4:
        obj = e.emu.alloc(0x40, 16)
        e.emu.wbytes(obj, bytes(e.rng.getrandbits(8) for _ in range(0x40)))

        # Create fake vtable for this object with slot 0x14
        obj_vtable = e.emu.fake_object('func434d10_result_vt', 0x80, nslots=0x20, slots={
            0x14 // 4: _rec_slot_14
        })
        e.emu.w32(obj, obj_vtable)

        e.calllog.append(('slot.64', 0x64, e.reg('ecx'), (obj,)))
        e.ret(eax=obj, argbytes=4)
    else:
        e.calllog.append(('slot.64', 0x64, e.reg('ecx'), (0,)))
        e.ret(eax=0, argbytes=4)


def _rec_slot_14(e, rr):
    """Recording handler for vtable slot 0x14: thiscall(self, arg1), returns bool in eax."""
    arg1 = e.arg32(0)
    # Return true 30% of the time, false 70%
    result = 1 if e.rng.random() < 0.3 else 0
    e.calllog.append(('slot.14', 0x14, e.reg('ecx'), (arg1,)))
    e.ret(eax=result, argbytes=4)


def _gen(c):
    r = c.rng

    # Create self object
    self = c.emu.alloc(0x40, 16)
    c.emu.wbytes(self, bytes(r.getrandbits(8) for _ in range(0x40)))

    # Create member object and set at [self+0x4] (50% of the time, else null)
    if r.random() < 0.5:
        member = c.emu.alloc(0x60, 16)
        c.emu.wbytes(member, bytes(r.getrandbits(8) for _ in range(0x60)))
        c.emu.w32(self + 0x4, member)

        # Create fake vtable for member with slots 0x4c, 0x64
        member_vtable = c.emu.fake_object('func434d10_member_vt', 0x200, nslots=0x80, slots={
            0x4c // 4: _rec_slot_4c,
            0x64 // 4: _rec_slot_64
        })
        c.emu.w32(member, member_vtable)
    else:
        c.emu.w32(self + 0x4, 0)

    # Test arg1: either 0 (early return) or a random value
    arg1 = r.getrandbits(32) if r.random() < 0.7 else 0

    return [self, arg1]


S(0x434d10, 'func_434d10', 'thiscall', None, ret='eax', gen=_gen)
