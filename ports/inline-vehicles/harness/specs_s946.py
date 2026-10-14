"""specs_s946.py - vehicles batch 946: ZCar::Save. The vehicle save (0x515b70, exe) runs with its header (0x513ff0) and the
undercarriage save (0x526090) stood in; the save object's slots are counting stubs (serial_stubs rec)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, r32


def g(c):
    ss.patch(c, 0x513ff0, ss.rec(c, 1, ret=1))
    ss.patch(c, 0x526090, ss.rec(c, 1))
    sg = ss.save_obj(c, {0x10: ss.rec(c, 2), 0x3c: ss.rec(c, 1), 0x44: ss.rec(c, 1), 0x4c: ss.rec(c, 1),
                         0x60: ss.rec(c, 1), 0x64: ss.rec(c, 1), 0x68: ss.rec(c, 1), 0x70: ss.rec(c, 1)})
    car = _rnd(c, 0x1800)
    c.emu.mu.ctl_flush_tb()
    return [car, sg]


S(0x5184f0, 'ZCar::Save', 'thiscall', ret='al', gen=g)
