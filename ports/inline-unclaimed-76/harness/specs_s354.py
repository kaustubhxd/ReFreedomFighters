"""specs_s354.py - area 76, batch 354: 0x616e00 (colour lerp; fastcall: ECX = out pointer, EDX = pointer to c1, stack: pointer to c2,
float t; ret 8; GUESS). The helper 0x633910 (CRT float-to-int) is exe code and runs unhooked on both sides. Colours are random dwords;
about 10% of cases use equal colours (the early store). t is random in [-0.5, 1.5] and sometimes exactly 0 or 1."""
import struct
from pilot import S, F


def _gen(c):
    e = c.emu
    rng = c.rng
    out = e.alloc(4, 4)
    e.w32(out, 0)
    c1 = rng.getrandbits(32)
    c2 = c1 if rng.random() < 0.1 else rng.getrandbits(32)
    c1p = e.alloc(4, 4)
    e.w32(c1p, c1)
    c2p = e.alloc(4, 4)
    e.w32(c2p, c2)
    r = rng.random()
    t = 0.0 if r < 0.05 else (1.0 if r < 0.1 else rng.uniform(-0.5, 1.5))
    return [out, c1p, c2p, F(t)]


S(0x616e00, 'lerp616e00 (GUESS)', 'fastcall', None, ret=None, gen=_gen,
  note='area 76 batch 354; parked row; the CRT helper 0x633910 is exe code')
