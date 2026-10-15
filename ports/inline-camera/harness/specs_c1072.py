"""specs_c1072.py - camera batch 1072: ZCAMERA::CalcCenSize (0x445580), both flag branches.

The object at +8 is a plain block; its setters run as original code (direct calls, no vtables). The CRT tan and sqrt are the
exe's own. The fov (+0x5c) and +0x60 are random, with a few zeros and negatives."""
import struct
from pilot import S
from camgen import rnd


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _cen(c):
    r = c.rng
    self_ = rnd(c, 0x100)
    c.emu.w32(self_ + 0x14, r.getrandbits(8))
    c.emu.w32(self_ + 0x5c, _fl(c, 0.05, 2.5) if r.random() < 0.9 else 0)
    c.emu.w32(self_ + 0x60, _fl(c, -4.0, 40.0))
    obj = rnd(c, 0x100)
    for off in (0x30, 0x34, 0x38, 0x40, 0x44, 0x48, 0x4c):
        c.emu.w32(obj + off, _fl(c, -300, 300) if r.random() < 0.9 else 0)
    c.emu.w32(obj + 0x3c, r.getrandbits(32))
    c.emu.w32(self_ + 8, obj)
    return [self_]


S(0x445580, 'ZCAMERA::CalcCenSize', 'thiscall', gen=_cen)
