"""specs_s3517.py - area 35 claim 17 (docs/20-unclaimed-35.md): two wrappers in slice 14 (GUESS names).

Stubbed (logged): 0x4edbd0 (thiscall, one argument). The object at this+0x65 has a logged vtable slot +4 (one argument),
or the field is null. The render manager at 0x70039c has an object at +0x1aa3 whose +0x1c is the thiscall object."""
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


def _w4362(c):
    o = _rnd(c, 0x200)
    if c.rng.random() < 0.6:
        child = _rnd(c, 0x100)
        cvt = c.emu.logging_vtable('ZGuessSlot4', 0x40, impl={}, argwords={4: 1})
        c.emu.w32(child, cvt)
        c.emu.w32(o + 0x65, child)
    else:
        c.emu.w32(o + 0x65, 0)
    return [o]


def _w48eda(c):
    self_obj = _rnd(c, 0x1000)
    c.emu.w32(self_obj + 0xaf4, c.rng.getrandbits(32))
    ss.patch(c, 0x4edbd0, _thiscall_log(c, 1, c.rng.getrandbits(32)))
    rm = _rnd(c, 0x2000)
    p = _rnd(c, 0x40)
    t = _rnd(c, 0x200)
    c.emu.w32(p + 0x1c, t)
    c.emu.w32(rm + 0x1aa3, p)
    c.emu.w32(0x70039c, rm)
    return [self_obj]


S(0x4362e0, 'GUESS FUN_4362e0 (thiscall)', 'thiscall', None, ret=None, gen=_w4362,
  note='area 35 claim 17; slot +4 of the object at +0x65 (logged, one arg) when non-null')
S(0x48eda0, 'GUESS FUN_48eda0 (thiscall)', 'thiscall', None, ret=None, gen=_w48eda,
  note='area 35 claim 17; calls 0x4edbd0 (stubbed, logged) on render-manager chain object with this+0xaf4')
