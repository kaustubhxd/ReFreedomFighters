"""specs_s325.py - decomp area 64 (docs/20-unclaimed-64.md): 0x59d330 constructor; exe switch 0x59d450 runs as original code."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ctor(c):
    e = c.emu
    # The global list head at 0x7142cc: a random previous head (the port reads it, then replaces it).
    e.w32(0x7142cc, c.rng.getrandbits(32))
    self_ = _rnd(c, 0x40)
    # The switch reads mode = self[+4] (set from the second stack word). Vary across the table (0..7) and the default.
    mode = c.rng.randrange(0, 12) if c.rng.random() < 0.9 else c.rng.getrandbits(32)
    e.w32(self_ + 0x8, c.rng.getrandbits(32))     # read by the switch's final check (cmp [ecx+8], 3)
    return [self_, c.rng.getrandbits(32), mode]


S(0x59d330, 'ctorLink (GUESS)', 'thiscall', None, ret='eax', gen=_ctor,
  note='batch325; stack words a and b (b = mode); ret 8; exe switch 0x59d450 runs as original code')
