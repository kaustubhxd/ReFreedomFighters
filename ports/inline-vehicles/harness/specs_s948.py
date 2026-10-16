"""specs_s948.py - vehicles batch 948: ZTank::Save (0x5213f0). ZVehicle::Save (0x515b70) runs as exe code with its header
(0x513ff0) stood in; the undercarriage save (0x528c80) and the two turret saves (0x5274f0) are stood in; the save object's
slots are counting stubs (serial_stubs rec)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd


def g(c):
    ss.patch(c, 0x513ff0, ss.rec(c, 1, ret=1))
    ss.patch(c, 0x528c80, ss.rec(c, 1))
    ss.patch(c, 0x5274f0, ss.rec(c, 1))
    sg = ss.save_obj(c, {0x10: ss.rec(c, 2), 0x3c: ss.rec(c, 1), 0x44: ss.rec(c, 1), 0x4c: ss.rec(c, 1),
                         0x60: ss.rec(c, 1), 0x64: ss.rec(c, 1), 0x68: ss.rec(c, 1), 0x70: ss.rec(c, 1)})
    tank = _rnd(c, 0x2800)
    c.emu.mu.ctl_flush_tb()
    return [tank, sg]


S(0x5213f0, 'ZTank::Save', 'thiscall', ret='al', gen=g)
