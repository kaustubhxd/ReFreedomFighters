"""specs_s958.py - residue-03, batch 958: CPlayerInventory::PutDataIntoBuffer (0x5b06b0). The buffer put (0x5f01c0) and the three
getters (0x5af1d0, 0x5af230, 0x5aefc0) are counting stubs in the exe image (the getters return a constant per case). The
loop's constants come from the image (0x6a7400 and 0x6a7410), so the port reads the same values."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, r32


def g(c):
    ss.patch(c, 0x5f01c0, ss.rec(c, 1))
    ss.patch(c, 0x5af1d0, ss.rec(c, 1, ret=r32(c)))
    ss.patch(c, 0x5af230, ss.rec(c, 1, ret=r32(c)))
    ss.patch(c, 0x5aefc0, ss.rec(c, 1, ret=r32(c)))
    inv = _rnd(c, 0x80)
    buf = _rnd(c, 0x40)
    return [inv, buf]


S(0x5b06b0, 'CPlayerInventory::PutDataIntoBuffer', 'thiscall', ret='al', gen=g)
