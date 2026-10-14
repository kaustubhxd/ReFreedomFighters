"""specs_s940.py - area 50 batch 940: 0x5edb20 (no name in map; thiscall, two float args and one unused word, ret 0xc, void). The block's float
fields are drawn equal to a and b (the no-change case), one equal and one not, or NaN, so both branches run."""
import struct
from pilot import S, F
from anim_common import rnd


def _bits(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _gen(c):
    e, r = c.emu, c.rng
    self = rnd(c, 0x100)
    a = r.choice([1.5, -0.25, 0.0, 3.0e6, float('nan')]) if r.random() < 0.3 else r.uniform(-8.0, 8.0)
    b = r.choice([2.5, 0.0, -1.0, float('nan')]) if r.random() < 0.3 else r.uniform(-8.0, 8.0)
    ch = r.random()
    fa = a if ch < 0.7 else (a + 1.0)
    fb = b if ch < 0.35 else (float('nan') if ch < 0.5 else b - 1.0)
    e.w32(self + 0xd7, _bits(fa))
    e.w32(self + 0xdb, _bits(fb))
    return [self, F(a), F(b), r.getrandbits(32)]


S(0x5edb20, 'set two floats (no name in map)', 'thiscall', None, gen=_gen, note='area50 batch940 (label D)')
