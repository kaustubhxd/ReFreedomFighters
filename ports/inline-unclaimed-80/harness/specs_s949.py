"""specs_s949.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x483df0. The argument struct's first dword points to an anim (null
15%) with two int fields (+0x60, +0x64) and three float fields (+0x70, +0x74, +0x78) that are finite random values in -100..100. The
constant 0x68c748 is read from the exe image. The helper 0x634d7c (sqrt) is the exe's own code, run for real."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _fn(c):
    s = _rnd(c, 0x20)
    if c.rng.random() < 0.15:
        c.emu.w32(s, 0)
    else:
        a = _rnd(c, 0x80)
        c.emu.w32(a + 0x60, c.rng.getrandbits(32))
        c.emu.w32(a + 0x64, c.rng.getrandbits(32))
        for off in (0x70, 0x74, 0x78):
            c.emu.w32(a + off, _fl(c.rng.uniform(-100.0, 100.0)))
        c.emu.w32(s, a)
    return [s]


S(0x483df0, 'ZPlayer::GetSettingsFromAnim (unknown) stdcall', 'stdcall', None, ret=None, gen=_fn,
  note='unclaimed-80 gap band; reads three floats and two ints from the anim, length over frame difference')
