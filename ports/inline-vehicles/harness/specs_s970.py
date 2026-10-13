"""specs_s970.py - residue-04, batch 970: the CopyEventDataBlock forwarders 0x4b89c0 and 0x4c8dc0. Their targets (0x4b8a30 and
0x4c8e20) are stood in for each case with hookrec: the record holds ECX (this) and the DBREAD argument (heap)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import _rnd, hookrec


def mk(target):
    def g(c):
        hookrec(c, target, 1, ret=0, this=True)
        return [_rnd(c, 0x80), _rnd(c, 0x40)]
    return g


S(0x4b89c0, 'ZRelayMessageList::CopyEventDataBlock (forwarder; 0x4b8a30 stood in)', 'thiscall', gen=mk(0x4b8a30))
S(0x4c8dc0, 'ZShotActivate::CopyEventDataBlock (forwarder; 0x4c8e20 stood in)', 'thiscall', gen=mk(0x4c8e20))
