"""specs_s7920.py - unclaimed-79 batch 20 (docs/20-unclaimed-79.md, gap band): ZPlayer::GetSettingsFromAnim (0x483df0). The output struct
holds an anim pointer at +0 (null one time in four); the anim record has ints at +0x60 and +0x64 and floats at +0x70, +0x74, +0x78
(random, with a few edge values). No callees."""
from pilot import S
import struct


def _blk(c, n=0x100):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(c):
    return struct.unpack('<I', struct.pack('<f', c.rng.choice([0.0, 1.0, -3.5, 1e-4, c.rng.uniform(-50, 50)])))[0]


def _gs(c):
    out = _blk(c, 0x40)
    if c.rng.random() < 0.75:
        a = _blk(c, 0x100)
        c.emu.w32(a + 0x60, c.rng.getrandbits(32))
        c.emu.w32(a + 0x64, c.rng.getrandbits(32))
        c.emu.w32(a + 0x70, _fl(c))
        c.emu.w32(a + 0x74, _fl(c))
        c.emu.w32(a + 0x78, _fl(c))
        c.emu.w32(out, a)
    else:
        c.emu.w32(out, 0)
    self_ = _blk(c, 0x40)
    return [self_, out]


S(0x483df0, 'ZPlayer::GetSettingsFromAnim(ZAnimDefs*) const thiscall', 'thiscall', None, ret=None, gen=_gs,
  note='unclaimed-79 batch 20; vector length (crt sqrt), int difference, scaled quotient into the output struct')
