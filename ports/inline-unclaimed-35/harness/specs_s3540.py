"""specs_s3540.py - gap band claim 40: 0x566e50 (GUESS name, thiscall, two args). Stubs: M.vt+0x114 (four args, returns a
per-case word), 0x561cb0 (thiscall, two args, logged)."""
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
    a0 = c.rng.getrandbits(32)
    r16 = (a0 & 0xffff) if c.rng.random() < 0.5 else c.rng.getrandbits(16)
    # four-arg slot: returns r16 in eax (cleaned by the callee)
    M = _rnd(c, 0x200)
    mvt = c.emu.fake_vtable('ZGapM566e50', 0x120, {0x114: _thiscall_log(c, 4, r16)})
    c.emu.w32(M, mvt)
    mgr = _rnd(c, 0x2000)
    c.emu.w32(mgr + 0x9b, M)
    c.emu.w32(0x70039c, mgr)
    ss.patch(c, 0x561cb0, _thiscall_log(c, 2, 0))
    self_obj = _rnd(c, 0x200)
    a1 = _rnd(c, 0x20)
    return [self_obj, a0, a1]


S(0x566e50, 'GUESS method 0x566e50 thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='gap band claim 40; M.vt+0x114 and 0x561cb0 stubbed (logged)')
