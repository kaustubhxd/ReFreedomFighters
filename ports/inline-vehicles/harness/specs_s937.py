"""specs_s937.py - vehicles batch 937: ZCar::ClassInit2 and ZVehicle::ClassInit2. The ZMoveOnSpline class-init step
(0x5124c0) and the undercarriage Init (0x5253b0) are stood in; the transform (slot 0x80) and the frame step (0x36c) are
stubs on the car object."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, obj, r32, rf


def car(c):
    v = obj(c, 0x1800, {0x80: _stub(c, 2), 0x36c: _stub(c, 1)})
    for off in (0x133, 0x160c, 0x1610):
        pass
    c.emu.w8(v + 0x133, c.rng.choice([0, 1]))
    c.emu.w32(v + 0x160c, r32(c))
    c.emu.wf32(v + 0x1610, c.rng.uniform(-5, 5))
    c.emu.w8(v + 0x1614, 0)
    return v


def g(c):
    ss.patch(c, 0x5124c0, ss.rec(c, 0))
    ss.patch(c, 0x5253b0, ss.rec(c, 5, ret=c.rng.choice([0, 1])))
    s = car(c)
    c.emu.mu.ctl_flush_tb()
    return [s]


S(0x517540, 'ZCar::ClassInit2', 'thiscall', gen=g)
S(0x515620, 'ZVehicle::ClassInit2', 'thiscall', gen=g)
