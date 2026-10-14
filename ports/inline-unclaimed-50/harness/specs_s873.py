"""specs_s873.py - area 50, batch 873: 0x4e5f10 (GUESS name), thiscall with a pointer-to-pointer, returns an int in eax.
The type byte is generated over 0..63 (the low six bits index the table); the payload is a double, a float or a dword.
Values are chosen so that the truncation stays in range (and out-of-range ones, which give 0x80000000 in both runs, are kept)."""
import struct
from pilot import S
from anim_common import rnd


def _gen(c):
    e, r = c.emu, c.rng
    cell = rnd(c, 16)
    rec = rnd(c, 16)
    t = r.choice(list(range(0, 14)) + [0x40 | 2, 0x40 | 5, 63])
    e.w8(rec, t)
    if r.random() < 0.8:
        e.wbytes(rec + 1, struct.pack('<d', r.uniform(-1e6, 1e6)))
    else:
        e.wbytes(rec + 1, struct.pack('<d', r.uniform(-1e12, 1e12)))
    e.w32(cell, rec)
    return [cell]


S(0x4e5f10, 'Value4e5f10 (GUESS name)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch873')
