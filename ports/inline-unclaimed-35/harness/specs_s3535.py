"""specs_s3535.py - gap band claim 35: 0x561eb0 (GUESS name, thiscall, one arg). Stubs: 0x561180, 0x5612c0, 0x561330
(thiscall, one arg, logged) and the object's vtable +0xc8 (thiscall, one arg, logged)."""
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
    obj = _rnd(c, 0x200)
    vt = c.emu.fake_vtable('ZGapV561eb0', 0xd0, {0xc8: _thiscall_log(c, 1, 0)})
    c.emu.w32(obj, vt)
    ss.patch(c, 0x561180, _thiscall_log(c, 1, 0))
    ss.patch(c, 0x5612c0, _thiscall_log(c, 1, 0))
    ss.patch(c, 0x561330, _thiscall_log(c, 1, 0))
    return [obj, c.rng.getrandbits(32)]


S(0x561eb0, 'GUESS method 0x561eb0 thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='gap band claim 35; 0x561180, 0x5612c0, 0x561330 and vtable +0xc8 stubbed (logged)')
