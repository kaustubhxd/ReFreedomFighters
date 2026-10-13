"""specs_s4026.py - area 70 batch 4026: 0x4d9590 (GUESS name). SEH frame not reproduced (see src/batch4026.cpp). The engine
global 0x70039c points to a fake whose +0x9b is the render manager; its +8 is the object whose slots 0x18 and 0x20 record their
argument and pop it (thiscall, ret 4)."""
from pilot import S, F


def _sr(c):
    e, r = c.emu, c.rng
    lvt = e.logging_vtable('obj_4d9590', 0x21, impl={0x18: lambda em, a: (None, None),
                                                    0x20: lambda em, a: (None, None)},
                           argwords={0x18: 1, 0x20: 1})
    obj = e.alloc(0x40, 4)
    e.w32(obj, lvt)
    rm = e.alloc(0x40, 4)
    e.w32(rm + 8, obj)
    sys_ = e.alloc(0xc0, 16)
    e.wbytes(sys_, bytes(r.getrandbits(8) for _ in range(0xc0)))
    e.w32(sys_ + 0x9b, rm)
    e.w32(0x70039c, sys_)
    arg = e.alloc(0x80, 4)
    e.wbytes(arg, bytes(r.getrandbits(8) for _ in range(0x80)))
    e.wbytes(arg + 0x59, bytes([0 if r.random() < 0.5 else 1]))
    return [arg]


S(0x4d9590, 'virtual call on the render manager object with the argument; SEH frame not reproduced (name GUESS)',
  'cdecl', None, gen=_sr, note='batch4026')
