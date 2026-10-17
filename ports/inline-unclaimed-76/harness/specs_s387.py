"""specs_s387.py - area 76, residue 17, batch 387 (thiscall, two words, ret 8; GUESS), see batch387.cpp.
0x663d90: this holds two small indices at +0 and +4 and floats at +8..+0x38 (mostly modest values, sometimes raw bits);
the second argument is an array of 8 floats, the first an 8-byte output block."""
import struct
from pilot import S


def _f(rng):
    if rng.random() < 0.1:
        return rng.randbytes(4)
    return struct.pack('<f', rng.uniform(-1000.0, 1000.0))


def _gen_663d(c):
    e = c.emu
    rng = c.rng
    this = e.alloc(0x40, 4)
    e.wbytes(this, b''.join(_f(rng) for _ in range(0x10)))
    e.w32(this, rng.randrange(8))
    e.w32(this + 4, rng.randrange(8))
    src = e.alloc(0x20, 4)
    e.wbytes(src, b''.join(_f(rng) for _ in range(8)))
    out = e.alloc(0x10, 4)
    e.wbytes(out, rng.randbytes(0x10))
    return [this, out, src]


S(0x663d90, 'map663d90 (GUESS)', 'thiscall', None, ret=None, gen=_gen_663d, note='area 76 batch 387; residue 17')
