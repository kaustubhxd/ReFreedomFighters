"""specs_s3518.py - area 35 claim 18 (docs/20-unclaimed-35.md): 0x5f3e20 (GUESS name).

Stubbed (logged): 0x5f5620 (thiscall, one argument; returns a per-case eax, stored at this+0xa6). The object at this+0x96 is
a 0x100-byte heap object whose +0x38 dword is the argument."""
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


def _w5f3e(c):
    self_obj = _rnd(c, 0x200)
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0x38, c.rng.getrandbits(32))
    c.emu.w32(self_obj + 0x96, o)
    ss.patch(c, 0x5f5620, _thiscall_log(c, 1, c.rng.getrandbits(32)))
    return [self_obj]


S(0x5f3e20, 'GUESS FUN_5f3e20 (thiscall)', 'thiscall', None, ret=None, gen=_w5f3e,
  note='area 35 claim 18; calls 0x5f5620 (stubbed, one arg, logged); stores eax at +0xa6')
