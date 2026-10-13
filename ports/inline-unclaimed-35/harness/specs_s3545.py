"""specs_s3545.py - slice 14, batch 45: 0x656f20 and 0x4286e0 (GUESS names). Stubs: this.vt+0xc (indexed log; returns R on every
call), 0x435b50 (thiscall, no args, logged), 0x634273 (cdecl, two args, logged, caller cleans)."""
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


def _indexed_ret(c, R, n):
    """thiscall, one arg: logs ecx and the arg per call (indexed by call count), returns R; count += 1."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    args = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(args, bytes(4 * n))
    thisv = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(thisv, bytes(4 * n))
    code = (b'\x8b\x15' + ss.P(cnt)                             # mov edx, [cnt]
            + b'\x89\x0c\x95' + ss.P(thisv)                     # mov [thisv + edx*4], ecx
            + b'\x8b\x44\x24\x04'                               # mov eax, [esp+4]
            + b'\x89\x04\x95' + ss.P(args)                      # mov [args + edx*4], eax
            + b'\xb8' + ss.P(R)                                 # mov eax, R
            + b'\xff\x05' + ss.P(cnt)                           # inc dword [cnt]
            + b'\xc2\x04\x00')
    return ss.code(c, code)


def _cdecl_log2(c):
    cells = c.emu.alloc(8, 4)
    c.emu.wbytes(cells, bytes(8))
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells)
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(cells + 4)
            + b'\xc3')
    return ss.code(c, code)


def _g656(c):
    R = _rnd(c, 0x100)
    c.emu.w32(R + 0x90, c.rng.getrandbits(32))
    self_obj = _rnd(c, 0x200)
    vt = c.emu.fake_vtable('ZGapV656f20', 0x20, {0xc: _indexed_ret(c, R, 4)})
    c.emu.w32(self_obj, vt)
    return [self_obj, c.rng.getrandbits(32)]


def _g4286(c):
    ss.patch(c, 0x435b50, _thiscall_log(c, 0, 0))
    ss.patch(c, 0x634273, _cdecl_log2(c))
    self_obj = _rnd(c, 0x200)
    return [self_obj, c.rng.choice([0, 1, 2, 3, 0x76, 0xff, c.rng.getrandbits(32)])]


S(0x656f20, 'GUESS method 0x656f20 thiscall, one arg', 'thiscall', None, ret=None, gen=_g656,
  note='slice 14 batch 45; vtable +0xc stubbed (indexed log)')
S(0x4286e0, 'GUESS method 0x4286e0 thiscall, one arg', 'thiscall', None, ret='eax', gen=_g4286,
  note='slice 14 batch 45; 0x435b50 and 0x634273 stubbed (logged)')
