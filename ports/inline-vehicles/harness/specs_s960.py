"""specs_s960.py - residue-04, batch 960: ZMoveOnSpline::ClassInit2 (0x5124c0): the helper 0x45d3a0 is a counting stub in the
exe image; the tail body (0x5124d0) runs as exe code (its own spec is batch 959). The object is the same as in batch 959."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
import specs_s959 as b959


def g(c):
    ss.patch(c, 0x45d3a0, ss.rec(c, 0))
    return b959.g(c)


S(0x5124c0, 'ZMoveOnSpline::ClassInit2', 'thiscall', gen=g)
