"""specs_s959.py - residue-04, batch 959: ZMoveOnSpline body (0x5124d0) and its jmp thunk (0x513500). The helper 0x513d10 is a
counting stub in the exe image; the vector init (0x4de7a0) runs as exe code; the object's vslots are stubs. Stack-address
arguments of the 0x1bc slot (&loc34, &loc10) are not recorded."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, obj, r32


def g(c):
    ss.patch(c, 0x513d10, ss.rec(c, 0))
    rm = obj(c, 0x1000)
    c.emu.w32(rm + 0xadc, r32(c))
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x400, {0x110: _stub(c, 2), 0x2c8: _stub(c, 2), 0x2e4: _stub(c, 0)})
    c.emu.w32(t + 0xce, r32(c))
    if c.rng.random() < 0.6:
        n = obj(c, 0x40, {0x28: _stub(c, 0)})
        o = obj(c, 0x40, {0x28: _stub(c, 0), 0x1bc: _stub(c, 7, skip=(1, 2), ret=n)})
        c.emu.w32(t + 0x134, o)
    else:
        c.emu.w32(t + 0x134, 0)
    return [t]


S(0x5124d0, 'ZMoveOnSpline::Body (0x5124d0)', 'thiscall', gen=g)
S(0x513500, 'ZMoveOnSpline::Body (jmp thunk 0x513500)', 'thiscall', gen=g)
