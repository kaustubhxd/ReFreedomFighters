"""specs_s5744.py - unclaimed-57, band batch 44: 0x5d5fc0 (GUESS). Thiscall, no args. The bounds a and b (this+0x4c, +0x50) are chosen so that
a == b, b > a and b < a all occur, and a is zero in a third of the cases; the engine float at +0x48 (positive, zero, negative) sets the
limit L through the exe's constant at 0x686098. The sub-object (this+0x44) has logging slots +0xbc and +0x250 (one argument each)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _rng(c):
    vt = c.emu.logging_vtable('band5d5fc0_sub', 0x260 // 4 + 4, argwords={0xbc: 1, 0x250: 1})
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, vt)
    eng = _rnd(c, 0x100)
    fv = c.rng.choice([0.0, 1.5, 3.0, 100.0, -2.0, 0.25])
    c.emu.w32(eng + 0x48, struct.unpack('<I', struct.pack('<f', fv))[0])
    c.emu.w32(0x70039c, eng)
    obj = _rnd(c, 0x200)
    a = 0 if c.rng.random() < 0.33 else c.rng.randrange(1, 9)
    b = c.rng.choice([a, a + 3, a + 10, max(a - 2, 0), a + 40])
    c.emu.w32(obj + 0x4c, a)
    c.emu.w32(obj + 0x50, b)
    c.emu.w32(obj + 0x44, sub)
    return [obj]


S(0x5d5fc0, 'unnamed_5d5fc0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_rng,
  note='unclaimed-57 band batch 44; sub slots +0xbc and +0x250 stubbed (logged); clamp from the engine float at +0x48')
