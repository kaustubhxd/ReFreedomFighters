"""specs_s263.py - unclaimed area 26 (docs/20-unclaimed-26.md): 0x524810, six float calls to a sink object's slot 0x4c."""
from pilot import S, F
import struct


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _six(c):
    e = c.emu
    sink_vt = e.logging_vtable('sink524', 0x14, impl={}, argwords={0x4c: 1})
    sink = _rnd(c, 0x40)
    e.w32(sink, sink_vt)
    self_ = _rnd(c, 0x40)
    for i in range(6):   # finite floats, so the logged arguments compare
        e.w32(self_ + 4 * i, struct.unpack('<I', struct.pack('<f', c.rng.uniform(-1e4, 1e4)))[0])
    return [self_, sink]


S(0x524810, 'pushSix (GUESS)', 'thiscall', None, ret='al', gen=_six, note='batch263; six float calls to a.vtbl[0x4c]; ret 4')
