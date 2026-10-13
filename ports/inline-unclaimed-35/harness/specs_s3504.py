"""specs_s3504.py - area 35 claim 4 (docs/20-unclaimed-35.md): five leaves in slice 14.

Stubbed (unverified): 0x523650 (called by ZMoveOnSpline::InitSplineVal), a thiscall stub with one argument (ret 4) that logs
ecx and the argument. The objects are 0x200 or 0x100 random bytes; the pointer chains are built so each read lands in a
harness-owned object (the byte or dword read is then compared through the return value or the heap)."""
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


def _script(c):
    o = _rnd(c, 0x200)
    p1 = _rnd(c, 0x100)
    p2 = _rnd(c, 0x100)
    c.emu.w32(p1, p2)
    c.emu.w32(o + 0xc, p1)
    return [o]


def _self(c):
    return [_rnd(c, 0x200)]


def _geombuf(c):
    o = _rnd(c, 0x200)
    p = _rnd(c, 0x100)
    c.emu.w32(o + 0x14, p)
    return [o]


def _ttfont(c):
    o = _rnd(c, 0x200)
    p = _rnd(c, 0x100)
    c.emu.w32(o + 0x97, p)
    return [o]


def _spline(c):
    ss.patch(c, 0x523650, _thiscall_log(c, 1, 0))
    o = _rnd(c, 0x200)
    c.emu.w32(o + 0x5c, _rnd(c, 0x100))
    return [o, c.rng.getrandbits(32)]


S(0x5f23e0, 'ZScriptDll::IsExportingNif (unknown) thiscall', 'thiscall', None, ret='al', gen=_script,
  note='area 35 claim 4; byte at [[this+0xc]]+0x18')
S(0x60d820, 'ZRender::GetDrawBase (unknown) thiscall', 'thiscall', None, ret='eax', gen=_self,
  note='area 35 claim 4; dword at +0xbd')
S(0x496320, 'ZGeomBuffer::BaseGeomBufferPtr (unknown) thiscall', 'thiscall', None, ret='eax', gen=_geombuf,
  note='area 35 claim 4; dword at [+0x14]+4')
S(0x4f65e0, 'ZTTFONT::GetNumTextures (unknown) thiscall', 'thiscall', None, ret='eax', gen=_ttfont,
  note='area 35 claim 4; dword at [+0x97]+0x14')
S(0x513320, 'ZMoveOnSpline::InitSplineVal (unknown) thiscall', 'thiscall', None, ret=None, gen=_spline,
  note='area 35 claim 4; 0x523650 stubbed (logged)')
