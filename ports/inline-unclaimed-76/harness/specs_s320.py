"""specs_s320.py - gap band, batch 320: fixed-point fractional getters (thiscall, no arguments, float on st0).
The engine global 0x70039c is a fake block with a random +0x40 dword; this holds random floats, including zeros, NaN and infinities."""
import struct
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    eng = e.alloc(0x200, 4)
    e.wbytes(eng, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    e.w32(eng + 0x40, rng.choice([0, 1, -1, 1024, rng.getrandbits(32), rng.randrange(-100000, 100000) & 0xffffffff]))
    e.w32(0x70039c, eng)
    o = e.alloc(0x40, 4)
    e.wbytes(o, bytes(rng.getrandbits(8) for _ in range(0x40)))
    specials = [0.0, -0.0, float('nan'), float('inf'), -float('inf'), 1.5, -2.25, 1000.0, 3e9, -3e9]
    for off in (0x10, 0x14, 0x18, 0x1c):
        if rng.random() < 0.3:
            v = rng.choice(specials)
        else:
            v = rng.uniform(-500.0, 500.0)
        e.wf32(o + off, v)
    return [o]


S(0x60d840, 'frac60d840 (GUESS)', 'thiscall', None, ret='st0', gen=_gen, note='batch320; plain ret; float on st0')
S(0x60d8e0, 'frac60d8e0 (GUESS)', 'thiscall', None, ret='st0', gen=_gen, note='batch320; plain ret; float on st0')
