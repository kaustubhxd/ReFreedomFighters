"""specs_s973.py - residue-04, batch 973: CMoveAlongPath::ChangePath (0x523040). The debug object (0x700390) has slot 0x20 stood
in and the channel it returns has a cdecl slot 0x2c (two stack args, caller cleans; cstub). The follow-up 0x523280 is a
counting stub in the exe image. The distance is exactly zero in half the cases (both sides of the test) and the shape is
null in some."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, cstub, obj, r32, rf


def g(c):
    ss.patch(c, 0x523280, ss.rec(c, 0))
    ch = obj(c, 0x40, {0x2c: cstub(c, 2)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=ch)})
    c.emu.w32(0x700390, dbg)
    t = obj(c, 0x100)
    shape = obj(c, 0x40) if c.rng.random() < 0.9 else 0
    dist = 0 if c.rng.random() < 0.5 else rf(c, -10, 10)
    return [t, shape, dist]


S(0x523040, 'CMoveAlongPath::ChangePath', 'thiscall', gen=g)
