"""specs_s1001.py - area 81 (residue 0), batch 1001: ZPlayer::ClassInit (0x4824c0). The helper 0x472ff0 is a GUESS stand-in (counting); the
object's slots are counting stubs (0x41c, 0x628, 0x110, 0x80, 0x370) and 0x218 on the render result. The render manager's 0x25c answers
zero or the object whose 0x294 answers that object; the stack-address arguments of 0x80 and 0x370 are not recorded."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32


def g(c):
    ss.patch(c, 0x472ff0, ss.rec(c, 0))
    X = obj(c, 0x40, {0x218: ss.rec(c, 1)})
    Y = obj(c, 0x40, {0x218: ss.rec(c, 1)})
    R = obj(c, 0x40, {0x25c: _stub(c, 2, ret=(0 if c.rng.random() < 0.5 else Y)),
                      0x294: _stub(c, 4, ret=X)})
    rm = obj(c, 0x1000)
    c.emu.w32(rm + 0xadc, R)
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x800, {0x41c: _stub(c, 1), 0x628: _stub(c, 0), 0x110: _stub(c, 2),
                       0x80: _stub(c, 2, skip=(0, 1)), 0x370: _stub(c, 2, skip=(0, 1))})
    M = obj(c, 0x40)
    c.emu.w32(t + 0x6c, M)
    c.emu.w32(t + 8, obj(c, 0x40))
    return [t]


S(0x4824c0, 'ZPlayer::ClassInit', 'thiscall', gen=g)
