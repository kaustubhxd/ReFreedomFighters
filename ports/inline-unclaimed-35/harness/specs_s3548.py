"""specs_s3548.py - slice 14, batch 48: 0x656160, 0x616a60, 0x6364a0.
Stubs: 0x634273 (cdecl, two args, logged), 0x6363a0 (thiscall, no args, logged);
mgr at 0x70039c; this vtable slots +0xc (thiscall, no args, logged) and +0x6c (thiscall, two args, logged)."""
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


def _g6561(c):
    mgr = _rnd(c, 0x2000)
    c.emu.w32(0x70039c, mgr)
    r0 = _rnd(c, 0x100)
    c.emu.w32(mgr + 0x1aa3, r0)
    r1 = _rnd(c, 0x100)
    c.emu.w32(r0 + 0x20, r1)
    obj = _rnd(c, 0x100)
    obj_vt = _rnd(c, 0x100)
    c.emu.w32(obj, obj_vt)
    stub1 = _thiscall_log(c, 0, 0)
    c.emu.w32(obj_vt + 0xc, stub1)
    stub2 = _thiscall_log(c, 2, 0)
    c.emu.w32(obj_vt + 0x6c, stub2)
    return [obj, c.rng.getrandbits(32)]


def _g616a(c):
    ss.patch(c, 0x634273, _cdecl_log2(c))
    obj = _rnd(c, 0x100)
    c.emu.w32(obj + 0xc, _rnd(c, 4) if c.rng.random() < 0.5 else 0)
    return [obj, c.rng.choice([0, 1])]


def _g6364(c):
    ss.patch(c, 0x634273, _cdecl_log2(c))
    ss.patch(c, 0x6363a0, _thiscall_log(c, 0, 0))
    obj = _rnd(c, 0x100)
    c.emu.w32(obj + 0x31, c.rng.choice([0, 1]))
    if c.emu.r32(obj + 0x31) != 0:
        c.emu.w32(obj + 0x2d, _rnd(c, 4))
    return [obj, c.rng.choice([0, 1])]


S(0x656160, 'GUESS method 0x656160 thiscall, one arg', 'thiscall', None, ret='eax', gen=_g6561,
  note='slice 14 batch 48; mgr and vtable stubs (logged)')
S(0x616a60, 'GUESS dtor 0x616a60 thiscall, one arg', 'thiscall', None, ret='eax', gen=_g616a,
  note='slice 14 batch 48; 0x634273 stubbed (logged)')
S(0x6364a0, 'GUESS dtor 0x6364a0 thiscall, one arg', 'thiscall', None, ret='eax', gen=_g6364,
  note='slice 14 batch 48; 0x634273 and 0x6363a0 stubbed (logged)')
