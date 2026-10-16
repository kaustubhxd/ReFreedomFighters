"""specs_s637.py - band 0x421000-0x441000, batch 637 (see src/batch637.cpp).
0x424590: thiscall(arg1, arg2), calls exe 0x4248e0, calls vtable[0x1fc], returns edx:eax.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402
import serial_stubs as ss  # noqa: E402


def _rec_slot_1fc(e, rr):
    """Recording handler for vtable slot 0x1fc: thiscall with multiple args."""
    arg1 = e.arg32(0)
    # Skip local_addr (pointer), val1, val2 for arg recording
    arg2 = e.arg32(4)
    e.calllog.append(('slot.1fc', 0x1fc, e.reg('ecx'), (arg1, arg2)))
    # Return a value
    e.ret(eax=e.rng.getrandbits(32), argbytes=20)  # 5 stack args


def _gen(c):
    r = c.rng
    # Create self object with fake vtable
    self = c.emu.alloc(0x40, 16)
    c.emu.wbytes(self, bytes(r.getrandbits(8) for _ in range(0x40)))

    fake_vtable = c.emu.fake_object('func424590_vt', 0x200, nslots=0x80, slots={
        0x1fc // 4: _rec_slot_1fc
    })
    c.emu.w32(self, fake_vtable)

    # Patch exe function 0x4248e0 with stub that returns a value
    stub_addr = ss.rec(c, 0, ret=r.getrandbits(32))
    c.emu.w32(0x4248e0, stub_addr)
    c.emu._image_dirty = True

    # Test arguments
    arg1 = r.getrandbits(32)
    arg2 = r.getrandbits(32)

    return [self, arg1, arg2]


S(0x424590, 'func_424590', 'thiscall', None, ret='eax:edx', gen=_gen)
