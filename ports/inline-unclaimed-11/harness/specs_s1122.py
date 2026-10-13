"""specs_s1122.py - unclaimed-11 batch 23 (gap band): 0x5b7630, thiscall, one argument (a DBREAD&, ret 4). GUESS on the name.
Body: this+0x4c = DBREAD::operator unsigned int(arg) (0x4e5e60); this+0x48 = the same operator again. The two results come from
serial_stubs.dbread_patch (seqr), so the first call returns v1 and the second v2 in every case. The DBREAD object is a dummy
0x40-byte buffer (the stub never reads it). The object is 0x80 random bytes."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _gen(c):
    o = c.emu.alloc(0x80, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    rd = c.emu.alloc(0x40, 4)
    c.emu.wbytes(rd, bytes(0x40))
    v1, v2 = c.rng.getrandbits(32), c.rng.getrandbits(32)
    ss.dbread_patch(c, [v1, v2], [0], [0])
    return [o, rd]


S(0x5b7630, 'GUESS (no name) two DBREAD reads thiscall ret 4', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 23 (gap band); DBREAD stubs')
