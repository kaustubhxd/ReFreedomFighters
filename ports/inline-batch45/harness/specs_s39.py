"""specs_s39.py - inline session batch 39 (Haiku, night): 0x4db2c0 ZBaseGeom::GetMatPos (const; copies this's nine dwords
to the first buffer through mcpy, then this+0x24..0x2c to the second buffer)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gmp(c):
    obj = _rnd(c, 0x40)
    mat = _rnd(c, 0x40)
    pos = _rnd(c, 0x40)
    return [obj, mat, pos]


S(0x4db2c0, 'ZBaseGeom::GetMatPos', 'thiscall', None, ret=None, gen=_gmp,
  note='batch39; mat gets the nine dwords of this via mcpy; pos gets this+0x24..0x2c')
