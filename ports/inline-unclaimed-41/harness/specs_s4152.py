"""specs_s4152.py - unclaimed-41 batch 48 (residue 0): 0x4e0980 (fastcall: ecx = this, edx = src; this.xyz *= src.xyz, plain ret). Two random
float triples (finite, small)."""
import struct
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    for k in range(n // 4):
        c.emu.w32(a + 4 * k, struct.unpack('<I', struct.pack('<f', c.rng.uniform(-20.0, 20.0)))[0])
    return a


def _layout(c):
    return [_rnd(c, 0x10), _rnd(c, 0x10)]


S(0x4e0980, 'FUN_4e0980 (fastcall vector multiply)', 'fastcall', None, ret=None, gen=_layout, note='unclaimed-41 batch 48; this.xyz *= src.xyz')
