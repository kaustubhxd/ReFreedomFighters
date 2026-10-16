"""specs_s638.py - band 0x421000-0x441000, batch 638 (see src/batch638.cpp).
0x425310: thiscall(no args), complex loop with vtable calls to slots 0x4c, 0x64, 0xcc, 0x18, 0x0c.
Reads global at 0x70038c; loops while slot[0x64] returns non-null.
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
    """Recording handler for vtable slot 0x64: thiscall(self, local), returns obj."""
    # Return a non-null object pointer 30% of iterations, then null to break loop
    if e.rng.random() < 0.3:
        obj = e.emu.alloc(0x40, 16)
        e.emu.wbytes(obj, bytes(e.rng.getrandbits(8) for _ in range(0x40)))
        e.calllog.append(('slot.64', 0x64, e.reg('ecx'), (obj,)))
        e.ret(eax=obj, argbytes=4)
    else:
        e.calllog.append(('slot.64', 0x64, e.reg('ecx'), (0,)))
        e.ret(eax=0, argbytes=4)


def _rec_slot_cc(e, rr):
    """Recording handler for vtable slot 0xcc: thiscall(self, val), returns result."""
    val = e.arg32(0)
    # 50% return a valid object, 50% return null
    if e.rng.random() < 0.5:
        result = e.emu.alloc(0x80, 16)
        e.emu.wbytes(result, bytes(e.rng.getrandbits(8) for _ in range(0x80)))
        e.calllog.append(('slot.cc', 0xcc, e.reg('ecx'), (val,)))
        e.ret(eax=result, argbytes=4)
    else:
        e.calllog.append(('slot.cc', 0xcc, e.reg('ecx'), (val,)))
        e.ret(eax=0, argbytes=4)


def _rec_slot_18(e, rr):
    """Recording handler for vtable slot 0x18: thiscall(self, arg1, arg2, arg3)."""
    arg1 = e.arg32(0)
    arg2 = e.arg32(1)
    arg3 = e.arg32(2)
    e.calllog.append(('slot.18', 0x18, e.reg('ecx'), (arg1, arg2, arg3)))
    e.ret(eax=0, argbytes=12)


def _rec_slot_0c(e, rr):
    """Recording handler for vtable slot 0x0c: thiscall(self)."""
    e.calllog.append(('slot.0c', 0x0c, e.reg('ecx'), ()))
    e.ret(eax=0, argbytes=0)


def _gen(c):
    r = c.rng

    # Create self object
    self = c.emu.alloc(0x40, 16)
    c.emu.wbytes(self, bytes(r.getrandbits(8) for _ in range(0x40)))

    # Create fake vtable for self with slots 0x18
    self_vtable = c.emu.fake_object('func425310_self_vt', 0x200, nslots=0x80, slots={
        0x18 // 4: _rec_slot_18
    })
    c.emu.w32(self, self_vtable)

    # Create obj and set at [self+0xc]
    obj = c.emu.alloc(0x60, 16)
    c.emu.wbytes(obj, bytes(r.getrandbits(8) for _ in range(0x60)))
    c.emu.w32(self + 0xc, obj)

    # Create fake vtable for obj with slots 0x4c, 0x64, 0x0c
    obj_vtable = c.emu.fake_object('func425310_obj_vt', 0x200, nslots=0x80, slots={
        0x4c // 4: _rec_slot_4c,
        0x64 // 4: _rec_slot_64,
        0x0c // 4: _rec_slot_0c
    })
    c.emu.w32(obj, obj_vtable)

    # Create global object and set at 0x70038c
    gobj = c.emu.alloc(0x60, 16)
    c.emu.wbytes(gobj, bytes(r.getrandbits(8) for _ in range(0x60)))

    # Create fake vtable for global object with slot 0xcc
    gobj_vtable = c.emu.fake_object('func425310_gobj_vt', 0x200, nslots=0x80, slots={
        0xcc // 4: _rec_slot_cc
    })
    c.emu.w32(gobj, gobj_vtable)

    # Patch global at 0x70038c
    c.emu.w32(0x70038c, gobj)
    c.emu._image_dirty = True

    # Set [self+0x11] flag (50% of time)
    if r.random() < 0.5:
        c.emu.wbytes(self + 0x11, bytes([0x01]))
    else:
        c.emu.wbytes(self + 0x11, bytes([0x00]))

    return [self]


S(0x425310, 'func_425310', 'thiscall', None, ret=None, gen=_gen)
