"""specs_s979.py - unclaimed-80 residue-19 batch 57 (docs/20-unclaimed-80.md), see src/batch979.cpp. self is a zeroed 0x40-byte block whose first dword is a
logging vtable: slot +0xd8 returns a per-case int (small 80% of the time, else any dword); slot +0xf4 returns a per-case nonzero finite float in st0
(about +/-100). Overflow and negative results both occur, so the 0x80000000 path runs."""
from pilot import S, F


def _gen(c):
    n = c.rng.randint(-1000, 1000) if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    n &= 0xffffffff
    g = c.rng.uniform(-100.0, 100.0)
    if abs(g) < 0.01:
        g = 1.0
    self_o = c.emu.alloc(0x40, 4)
    c.emu.wbytes(self_o, bytes(0x40))
    vt = c.emu.logging_vtable('ZGroupD8F4', 0xc0, impl={0xd8: (lambda e, a, v=n: (v, None)),
                                                      0xf4: (lambda e, a, v=g: (0, F(v)))})
    c.emu.w32(self_o, vt)
    return [self_o]


S(0x64fc70, 'int from ratio of two virtual results (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-80 residue-19; slot +0xd8 (int) and slot +0xf4 (float in st0) on self; cvttss2si clamp')
