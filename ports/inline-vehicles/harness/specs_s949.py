"""specs_s949.py - vehicles batch 949: ZHeli::Save (0x51cbd0). The header (0x513ff0) and the sub-object and weapon saves
(0x527190, 0x5274f0, 0x516e20, 0x513f50) are stood in; the save object's slots are counting stubs. The first vector save
passes the caller's EDI, which the checker fixes at 0x0badf00d."""
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
    for a in (0x527190, 0x5274f0, 0x516e20, 0x513f50):
        ss.patch(c, a, ss.rec(c, 1))
    sg = ss.save_obj(c, {0x10: ss.rec(c, 2), 0x3c: ss.rec(c, 1), 0x44: ss.rec(c, 1), 0x4c: ss.rec(c, 1),
                         0x60: ss.rec(c, 1), 0x64: ss.rec(c, 1), 0x68: ss.rec(c, 1), 0x70: ss.rec(c, 1)})
    heli = _rnd(c, 0x1000)
    c.emu.mu.ctl_flush_tb()
    return [heli, sg]


S(0x51cbd0, 'ZHeli::Save', 'thiscall', ret='al', gen=g)
