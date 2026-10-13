"""specs_s3534.py - gap band claim 34: 0x561f10 (GUESS name, stdcall, one arg). Stubs: M.vt+0x134 (returns R) and R.vt+0x68
(thiscall, three args, logged)."""
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
    R = _rnd(c, 0x100)
    rvt = c.emu.fake_vtable('ZGapR561f10', 0x70, {0x68: _thiscall_log(c, 3, 0)})
    c.emu.w32(R, rvt)
    M = _rnd(c, 0x200)
    mvt = c.emu.fake_vtable('ZGapM561f10', 0x140, {0x134: _thiscall_log(c, 0, R)})
    c.emu.w32(M, mvt)
    mgr = _rnd(c, 0x2000)
    c.emu.w32(mgr + 0x9b, M)
    c.emu.w32(0x70039c, mgr)
    return [c.rng.choice([0, 1, 2, c.rng.getrandbits(32), 0x100, 0xff00])]


S(0x561f10, 'GUESS static 0x561f10 stdcall', 'stdcall', None, ret=None, gen=_gen,
  note='gap band claim 34; M.vt+0x134 and R.vt+0x68 stubbed (logged)')
