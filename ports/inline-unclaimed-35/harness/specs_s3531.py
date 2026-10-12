"""specs_s3531.py - gap band claim 31: 0x573490 (GUESS name). Stub: 0x562e90 (thiscall, two args, logs ecx and both args)."""
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


def _log2(c):
    cells = c.emu.alloc(12, 4)
    c.emu.wbytes(cells, bytes(12))
    code = (b'\x89\x0d' + ss.P(cells)                                  # mov [cells], ecx
            + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells + 4)          # arg0 -> cells[1]
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(cells + 8)          # arg1 -> cells[2]
            + b'\xb8' + ss.P(0) + b'\xc2\x08\x00')
    return ss.code(c, code)


def _gen(c):
    ss.patch(c, 0x562e90, _log2(c))
    obj = _rnd(c, 0x200)
    return [obj, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x573490, 'GUESS method 0x573490 thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='gap band claim 31; 0x562e90 stubbed (logs ecx and both args)')
