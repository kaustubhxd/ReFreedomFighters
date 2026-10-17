"""specs_s3547.py - slice 14, batch 47: 0x6563e0, 0x4c31e0, 0x565b20.
Stubs: 0x564fd0, 0x564600 (thiscall, no args and one arg, logged);
mgr at 0x70039c with vtable; [mgr+0x190f] vtable with slots +0x20 (no args) and +0x18 (two args);
[mgr+0x9b] vtable with slot +0x4c (one arg); arg0 vtable with slot +0x3c (no args);
this vtable with slot +0xd8 (no args)."""
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


def _thiscall_log(c, nargs, ret):
    cells = c.emu.alloc(4 * (1 + nargs), 4)
    c.emu.wbytes(cells, bytes(4 * (1 + nargs)))
    code = b'\x89\x0d' + ss.P(cells)
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 + 4 * i)
    code += b'\xb8' + ss.P(ret) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, code)


def _cdecl_log2(c):
    cells = c.emu.alloc(8, 4)
    c.emu.wbytes(cells, bytes(8))
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells)
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(cells + 4)
            + b'\xc3')
    return ss.code(c, code)


def _g6563(c):
    mgr = _rnd(c, 0x2000)
    c.emu.w32(0x70039c, mgr)
    vt_obj_190f = _rnd(c, 0x100)
    c.emu.w32(mgr + 0x190f, vt_obj_190f)
    vt_190f = _rnd(c, 0x100)
    c.emu.w32(vt_obj_190f, vt_190f)
    result = _rnd(c, 0x100)
    stub1 = _thiscall_log(c, 0, result)
    c.emu.w32(vt_190f + 0x20, stub1)
    vt_result = _rnd(c, 0x100)
    c.emu.w32(result, vt_result)
    stub2 = _thiscall_log(c, 2, 0)
    c.emu.w32(vt_result + 0x18, stub2)
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


def _g4c31(c):
    mgr = _rnd(c, 0x2000)
    c.emu.w32(0x70039c, mgr)
    vt_9b = _rnd(c, 0x100)
    c.emu.w32(mgr + 0x9b, vt_9b)
    vt = _rnd(c, 0x100)
    c.emu.w32(vt_9b, vt)
    stub1 = _thiscall_log(c, 1, 0)
    c.emu.w32(vt + 0x4c, stub1)
    arg0_obj = _rnd(c, 0x100)
    arg0_vt = _rnd(c, 0x100)
    c.emu.w32(arg0_obj, arg0_vt)
    stub2 = _thiscall_log(c, 0, 0)
    c.emu.w32(arg0_vt + 0x3c, stub2)
    return [_rnd(c, 0x100), arg0_obj]


def _g565b(c):
    ss.patch(c, 0x564fd0, _thiscall_log(c, 0, 0))
    ss.patch(c, 0x564600, _thiscall_log(c, 1, 0))
    obj = _rnd(c, 0x100)
    obj_vt = _rnd(c, 0x100)
    c.emu.w32(obj, obj_vt)
    stub_vt = _thiscall_log(c, 0, c.rng.choice([0, 1]))
    c.emu.w32(obj_vt + 0xd8, stub_vt)
    return [_rnd(c, 0x100), c.rng.choice([0, 1, 2])]


S(0x6563e0, 'GUESS function 0x6563e0 stdcall, two args', 'stdcall', None, ret=None, gen=_g6563,
  note='slice 14 batch 47; mgr and vtables stubbed (logged)')
S(0x4c31e0, 'GUESS method 0x4c31e0 thiscall, one arg', 'thiscall', None, ret='eax', gen=_g4c31,
  note='slice 14 batch 47; mgr vtable and arg0 vtable stubbed (logged)')
S(0x565b20, 'GUESS method 0x565b20 thiscall, one arg', 'thiscall', None, ret='eax', gen=_g565b,
  note='slice 14 batch 47; 0x564fd0 and 0x564600 stubbed (logged), this vtable stubbed (logged)')
