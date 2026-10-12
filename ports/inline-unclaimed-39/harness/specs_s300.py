"""specs_s300.py - decomp area 39 (docs/20-unclaimed-39.md): 0x4e2c60 (fastcall, 3x3 abs transform), 0x4e65e0 (reciprocal pair)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fbits(c):
    # Mix of ordinary values, the edge constants, and random bit patterns (including NaN and inf).
    r = c.rng.random()
    if r < 0.15:
        v = (0.0, -0.0, 1e-4, 9.9e-5, 1.0001e-4, 10000.0, 9999.9, 1.0, -1.0, 0.5, 2.0)[c.rng.getrandbits(4) % 11]
        return struct.unpack('<I', struct.pack('<f', v))[0]
    if r < 0.5:
        return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-30000.0, 30000.0)))[0]
    return c.rng.getrandbits(32)


def _mul(c):
    m = _rnd(c, 0x24)
    for i in range(9):
        c.emu.w32(m + 4 * i, _fbits(c))
    v = _rnd(c, 0x0c)
    for i in range(3):
        c.emu.w32(v + 4 * i, _fbits(c))
    return [m, v]


def _pair(c):
    out = _rnd(c, 0x10)
    return [out, _fbits(c), _fbits(c)]


S(0x4e2c60, 'absTransform (GUESS)', 'fastcall', None, ret=None, gen=_mul,
  note='batch300; ecx = 3x3 matrix, edx = float[3] in/out; no stack args')
S(0x4e65e0, 'recipPair (GUESS)', 'thiscall', None, ret='al', gen=_pair,
  note='batch300; ecx = out float[2]; two float stack args; ret 8')
