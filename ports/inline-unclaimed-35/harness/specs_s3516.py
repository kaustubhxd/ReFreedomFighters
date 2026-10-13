"""specs_s3516.py - area 35 claim 16 (docs/20-unclaimed-35.md): four wrappers in slice 14 (GUESS names).

Stubbed (logged): 0x4d24e0 (stdcall, four arguments), 0x4e6880 (fastcall: ecx, edx and one stack argument; returns a
per-case eax), 0x4ef0e0 (thiscall, no arguments, logs ecx), 0x61c3d0 (cdecl, one argument). The object at 0x4f5aa0 has a
logged vtable slot +0xbc (one argument)."""
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


def _stdcall4_log(c):
    cells = c.emu.alloc(4 * 4, 4)
    c.emu.wbytes(cells, bytes(16))
    code = b''
    for i in range(4):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 * i)   # mov eax, [esp+4+4i]; mov [cells+4i], eax
    code += b'\xb8' + ss.P(0) + b'\xc2\x10\x00'                                       # mov eax, 0; ret 16
    return ss.code(c, code)


def _fastcall2_log(c, ret):
    cells = c.emu.alloc(4 * 3, 4)
    c.emu.wbytes(cells, bytes(12))
    code = (b'\x89\x0d' + ss.P(cells)                          # mov [cells], ecx
            + b'\x89\x15' + ss.P(cells + 4)                    # mov [cells+4], edx
            + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells + 8)   # mov eax, [esp+4]; mov [cells+8], eax
            + b'\xb8' + ss.P(ret)                              # mov eax, ret
            + b'\xc2\x04\x00')                                 # ret 4
    return ss.code(c, code)


def _cdecl1_log(c):
    cells = c.emu.alloc(4, 4)
    c.emu.wbytes(cells, bytes(4))
    code = b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells) + b'\xc3'   # mov eax, [esp+4]; mov [cells], eax; ret
    return ss.code(c, code)


def _w4d(c):
    ss.patch(c, 0x4d24e0, _stdcall4_log(c))
    return [c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _w91(c):
    ss.patch(c, 0x4e6880, _fastcall2_log(c, c.rng.getrandbits(32)))
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _w4f(c):
    o = _rnd(c, 0x200)
    vt = c.emu.logging_vtable('ZGuessBC', 0x100, impl={}, argwords={0xbc: 1})
    c.emu.w32(o, vt)
    ss.patch(c, 0x4ef0e0, _thiscall_log(c, 0, 0))
    return [o]


def _w61(c):
    o = _rnd(c, 0x200)
    p = _rnd(c, 0x40) if c.rng.random() < 0.7 else 0
    c.emu.w32(o + 4, p)
    ss.patch(c, 0x61c3d0, _cdecl1_log(c))
    return [o]


S(0x4d39a0, 'GUESS FUN_4d39a0 (stdcall, two args)', 'stdcall', None, ret=None, gen=_w4d,
  note='area 35 claim 16; calls 0x4d24e0 (stubbed, four args, logged)')
S(0x491e60, 'GUESS FUN_491e60 (stdcall, three args)', 'stdcall', None, ret='eax', gen=_w91,
  note='area 35 claim 16; calls 0x4e6880 (stubbed, fastcall, logged)')
S(0x4f5aa0, 'GUESS FUN_4f5aa0 (thiscall)', 'thiscall', None, ret=None, gen=_w4f,
  note='area 35 claim 16; calls 0x4ef0e0 (stubbed) then slot +0xbc (logged)')
S(0x61ba60, 'GUESS FUN_61ba60 (thiscall)', 'thiscall', None, ret=None, gen=_w61,
  note='area 35 claim 16; calls 0x61c3d0 (stubbed, cdecl) when this+4 is non-null')
