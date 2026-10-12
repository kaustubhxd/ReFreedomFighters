"""specs_s318.py - gap band, batch 318: two float leaves returning on st0 (ret='st0').
0x601590 (cdecl, no arguments): (float)[engine+0x40] * [0x6785e4]; the engine global 0x70039c points to a fake block.
0x60ffb0 (thiscall, no arguments): (float)[this+0x84] / (float)[this+0x88]; the denominator may be zero (inf or NaN)."""
from pilot import S


def _eng(c):
    e = c.emu
    eng = e.alloc(0x200, 4)
    e.wbytes(eng, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    e.w32(0x70039c, eng)
    return []


def _ratio(c):
    e = c.emu
    o = e.alloc(0x100, 4)
    e.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    a = c.rng.getrandbits(32)
    b = c.rng.choice([0, 1, -1, c.rng.getrandbits(32), c.rng.randrange(1, 1000)])
    e.w32(o + 0x84, a)
    e.w32(o + 0x88, b)
    return [o]


S(0x601590, 'tick float (GUESS)', 'cdecl', None, ret='st0', gen=_eng, note='batch318; plain ret; float on st0')
S(0x60ffb0, 'ratio float (GUESS)', 'thiscall', None, ret='st0', gen=_ratio, note='batch318; plain ret; float on st0')
