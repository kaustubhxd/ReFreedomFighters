"""specs_s3546.py - slice 14, batch 46: 0x549420, 0x64f5e0, 0x65a3a0, 0x4fb9a0, 0x4d61a0, 0x55ffe0, 0x62d260 (GUESS names).
Stubs: 0x634273 (cdecl, two args, logged, caller cleans), 0x64f380, 0x63ab30, 0x469870 (thiscall, no args, logged),
0x62f980 (stdcall, one arg, logged), 0x5003d0 and 0x5a46f0 (thiscall, one arg, logged, return a pointer or, for 0x5a46f0,
sometimes null)."""
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


def _stdcall1_log(c):
    cells = c.emu.alloc(4, 4)
    c.emu.wbytes(cells, bytes(4))
    return ss.code(c, b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells) + b'\xc2\x04\x00')


def _cdecl_log2(c):
    cells = c.emu.alloc(8, 4)
    c.emu.wbytes(cells, bytes(8))
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells)
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(cells + 4)
            + b'\xc3')
    return ss.code(c, code)


def _flag(c):
    return c.rng.choice([0, 1, 2, 3, 0xff, c.rng.getrandbits(32)])


def _dtor_gen(base):
    def g(c):
        if base:
            ss.patch(c, base, _thiscall_log(c, 0, 0))
        ss.patch(c, 0x634273, _cdecl_log2(c))
        return [_rnd(c, 0x100), _flag(c)]
    return g


def _g4fb9(c):
    ss.patch(c, 0x469870, _thiscall_log(c, 0, 0))
    return [_rnd(c, 0x100)]


def _g4d61(c):
    ss.patch(c, 0x62f980, _stdcall1_log(c))
    ss.patch(c, 0x634273, _cdecl_log2(c))
    return [_rnd(c, 0x100)]


def _g55ff(c):
    R = _rnd(c, 0x40)
    Q = _rnd(c, 0x40)
    ss.patch(c, 0x5003d0, _thiscall_log(c, 1, R))
    ss.patch(c, 0x5a46f0, _thiscall_log(c, 1, Q if c.rng.random() < 0.6 else 0))
    mgr = _rnd(c, 0x3000)
    c.emu.w32(0x7003b8, mgr)
    return [_rnd(c, 0x40)]


def _g62d2(c):
    p = _rnd(c, 0x40)
    if c.rng.random() < 0.4:
        c.emu.w32(p + 0xc, 0)
    code = c.rng.choice([0xf, 0x12, 0x29, 0x1c, 0x1c, 0x1b, 0x1d, 0x10, 0, c.rng.getrandbits(32)])
    return [p, code]


S(0x549420, 'GUESS scalar deleting dtor 0x549420 thiscall, one arg', 'thiscall', None, ret='eax', gen=_dtor_gen(None),
  note='slice 14 batch 46; 0x634273 stubbed (logged)')
S(0x64f5e0, 'GUESS scalar deleting dtor 0x64f5e0 thiscall, one arg', 'thiscall', None, ret='eax', gen=_dtor_gen(0x64f380),
  note='slice 14 batch 46; 0x64f380 and 0x634273 stubbed (logged)')
S(0x65a3a0, 'GUESS scalar deleting dtor 0x65a3a0 thiscall, one arg', 'thiscall', None, ret='eax', gen=_dtor_gen(0x63ab30),
  note='slice 14 batch 46; 0x63ab30 and 0x634273 stubbed (logged)')
S(0x4fb9a0, 'GUESS ctor 0x4fb9a0 thiscall, no args', 'thiscall', None, ret='eax', gen=_g4fb9,
  note='slice 14 batch 46; 0x469870 stubbed (logged)')
S(0x4d61a0, 'GUESS function 0x4d61a0 stdcall, one arg', 'stdcall', None, ret=None, gen=_g4d61,
  note='slice 14 batch 46; 0x62f980 and 0x634273 stubbed (logged)')
S(0x55ffe0, 'GUESS function 0x55ffe0 stdcall, one arg', 'stdcall', None, ret='eax', gen=_g55ff,
  note='slice 14 batch 46; 0x5003d0 and 0x5a46f0 stubbed (logged)')
S(0x62d260, 'GUESS function 0x62d260 cdecl, two args', 'cdecl', None, ret='eax', gen=_g62d2, note='slice 14 batch 46 leaf')
