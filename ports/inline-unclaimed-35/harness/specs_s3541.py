"""specs_s3541.py - gap band claim 41: 0x5636c0 and 0x56a8b0 (GUESS names). Stubs: M.vt+0x58 (returns R), R.vt+0x1e0 (returns al),
0x563650 (thiscall, two args, logged), this.vt+0x84 (returns O), O.vt+0x350 (thiscall, three args, logged), 0x562e90 (thiscall,
two args, logged)."""
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


def _gen_5636(c):
    ss.patch(c, 0x563650, _thiscall_log(c, 2, 0))
    R = _rnd(c, 0x100)
    rvt = c.emu.fake_vtable('ZGapR5636', 0x1e8, {0x1e0: _thiscall_log(c, 1, c.rng.choice([0, 1]))})
    c.emu.w32(R, rvt)
    M = _rnd(c, 0x200)
    mvt = c.emu.fake_vtable('ZGapM5636', 0x64, {0x58: _thiscall_log(c, 1, R if c.rng.random() < 0.85 else 0)})
    c.emu.w32(M, mvt)
    mgr = _rnd(c, 0x2000)
    c.emu.w32(mgr + 0x9b, M)
    c.emu.w32(0x70039c, mgr)
    return [_rnd(c, 0x200), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _gen_56a8(c):
    ss.patch(c, 0x562e90, _thiscall_log(c, 2, 0))
    O = _rnd(c, 0x100)
    ovt = c.emu.fake_vtable('ZGapO56a8', 0x354, {0x350: _thiscall_log(c, 3, 0)})
    c.emu.w32(O, ovt)
    self_obj = _rnd(c, 0x200)
    svt = c.emu.fake_vtable('ZGapS56a8', 0x88, {0x84: _thiscall_log(c, 0, O)})
    c.emu.w32(self_obj, svt)
    c.emu.w32(self_obj + 0x1c5, c.rng.choice([4, 4, 3, 5]))
    return [self_obj, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5636c0, 'GUESS method 0x5636c0 thiscall', 'thiscall', None, ret=None, gen=_gen_5636,
  note='gap band claim 41; M.vt+0x58, R.vt+0x1e0 and 0x563650 stubbed (logged)')
S(0x56a8b0, 'GUESS method 0x56a8b0 thiscall', 'thiscall', None, ret='eax', gen=_gen_56a8,
  note='gap band claim 41; 0x562e90, this.vt+0x84 and O.vt+0x350 stubbed (logged)')
