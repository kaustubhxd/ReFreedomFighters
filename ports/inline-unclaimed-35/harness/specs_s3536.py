"""specs_s3536.py - claim 36: 0x44e800 ZBOUND::CopyDataBlock(DBLK*). Stubs: 0x610100 (thiscall, one arg), 0x4e1b30 (thiscall,
no args), 0x4dc630 (thiscall, two args); all logged."""
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


def _gen(c):
    ss.patch(c, 0x610100, _thiscall_log(c, 1, 0))
    ss.patch(c, 0x4e1b30, _thiscall_log(c, 0, 0))
    ss.patch(c, 0x4dc630, _thiscall_log(c, 2, 0))
    self_obj = _rnd(c, 0x200)
    inner = _rnd(c, 0x100)
    c.emu.w32(self_obj + 8, inner)
    return [self_obj, _rnd(c, 0x200)]


S(0x44e800, 'ZBOUND::CopyDataBlock(DBLK*) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='claim 36; 0x610100, 0x4e1b30, 0x4dc630 stubbed (logged)')
