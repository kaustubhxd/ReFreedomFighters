"""specs_s3544.py - slice 14, batch 44: 0x472420 and 0x497720 (GUESS names). Stubs: the sub-object's vtable +8 (thiscall, two args,
logged) and 0x497610 (thiscall, one arg, logged, returns a heap pointer)."""
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


def _g472(c):
    self_obj = _rnd(c, 0x400)
    sub_vt = c.emu.fake_vtable('ZGapSub472420', 0x20, {0x8: _thiscall_log(c, 2, 0)})
    c.emu.w32(self_obj + 0x34f, sub_vt)
    return [self_obj, c.rng.getrandbits(32)]


def _g497(c):
    self_obj = _rnd(c, 0x100)
    inner = _rnd(c, 0x100)
    x = c.rng.randrange(0, 100)
    y = c.rng.randrange(0, 100)
    c.emu.w32(inner + 4, x)
    c.emu.w32(self_obj + 0x14, inner)
    c.emu.w32(self_obj + 0x28, y)
    c.emu.w32(self_obj + 0x24, c.rng.choice([0, 1, 1]))
    R = _rnd(c, 0x40)
    ss.patch(c, 0x497610, _thiscall_log(c, 1, R))
    arg = (x + y) if c.rng.random() < 0.4 else c.rng.randrange(0, 300)
    return [self_obj, arg]


S(0x472420, 'GUESS method 0x472420 thiscall, one arg', 'thiscall', None, ret=None, gen=_g472,
  note='slice 14 batch 44; sub-object vtable +8 stubbed (logged)')
S(0x497720, 'GUESS method 0x497720 thiscall, one arg', 'thiscall', None, ret='eax', gen=_g497,
  note='slice 14 batch 44; 0x497610 stubbed (logged)')
