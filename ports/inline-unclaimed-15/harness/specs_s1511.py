"""specs_s1511.py - unclaimed-15 claim 11 (docs/20-unclaimed-15.md): ZOnScreenDisplay::Load2 (0x5aa0e0).

The render manager (global 0x70039c, +0x9b) is an object whose vtable slot +0x134 is a code stub returning the address
of a second object X. X's vtable slot +0x88 is a code stub that writes a per-case dword through its second stack argument
(the stack address of the local) and returns with ret 8; it also keeps its first argument in a heap cell. These are code stubs, not logged, because the local's stack
address differs between the exe run and the port run. The global object at 0x7003b8 is 0x200 random bytes; its +0x4ac is
copied into this+0x8a3. The self object is 0x1000 random bytes. Verified: this+0x8a3 and this+0x8d0 (heap compare)."""
import os
import struct
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load2(c):
    self_obj = _rnd(c, 0x1000)
    g = _rnd(c, 0x200)
    c.emu.w32(0x7003b8, g)
    x = _rnd(c, 0x200)
    write_val = c.rng.getrandbits(32)
    cell = c.emu.alloc(4, 4)                 # the stub also keeps its first argument in this cell, so it is compared
    c.emu.w32(cell, 0)
    stub88 = ss.code(c, b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cell)
                     + b'\x8b\x44\x24\x08' + b'\xc7\x00' + struct.pack('<I', write_val) + b'\xc2\x08\x00')
    xvt = c.emu.fake_vtable('ZOSDSub', 0x140, {0x88: stub88})
    c.emu.w32(x, xvt)
    stub134 = ss.code(c, b'\xb8' + struct.pack('<I', x) + b'\xc3')
    rvt = c.emu.fake_vtable('ZOSDRender', 0x140, {0x134: stub134})
    robj = _rnd(c, 0x200)
    c.emu.w32(robj, rvt)
    rm = _rnd(c, 0x1000)
    c.emu.w32(rm + 0x9b, robj)
    c.emu.w32(0x70039c, rm)
    return [self_obj]


S(0x5aa0e0, 'ZOnScreenDisplay::Load2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_load2,
  note='unclaimed-15 claim 11; render slot +0x134 and sub slot +0x88 are code stubs (not logged)')
