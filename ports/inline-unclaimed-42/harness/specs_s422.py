"""specs_s422.py - unclaimed-42 batch 2 (claim 2): ZOnScreenDisplay::CalcProjection2D (0x5a5dd0), thiscall, ret 0x14.
Pure float math plus one double-precision tan (the CRT IAT slot behind 0x634dac). The display object gets the three fields
the body reads (+0x2f4 divisor, +0x658 flag, +0x8d0 mode); the geom and camera are zero blocks with floats in the used slots."""
import struct
from pilot import S, F


def _f(c, lo=-100.0, hi=100.0):
    return struct.pack('<f', F(c.fv(lo, hi)))


def _gen(c):
    osd = c.emu.alloc(0x900, 16)
    c.emu.wbytes(osd, bytes(0x900))
    c.emu.wbytes(osd + 0x2f4, _f(c, 0.5, 4.0))
    c.emu.wbytes(osd + 0x658, bytes([c.rng.choice([0, 1])]))
    c.emu.w32(osd + 0x8d0, c.rng.choice([0, 1, 2, 3]))
    geom = c.emu.alloc(0x80, 16)
    c.emu.wbytes(geom, bytes(0x80))
    g8 = c.emu.alloc(0x80, 16)
    c.emu.wbytes(g8, bytes(0x80))
    c.emu.wbytes(g8 + 0x44, _f(c))
    c.emu.w32(geom + 8, g8)
    cam = c.emu.alloc(0x80, 16)
    c.emu.wbytes(cam, bytes(0x80))
    c.emu.wbytes(cam + 0x40, _f(c, 0.5, 4.0))
    c.emu.wbytes(cam + 0x5c, _f(c, -1.0, 1.0))
    out = c.emu.alloc(0x10, 16)
    c.emu.wbytes(out, bytes(0x10))
    return [osd, out, F(c.fv(-100.0, 100.0)), F(c.fv(-100.0, 100.0)), geom, cam]


S(0x5a5dd0, 'ZOnScreenDisplay::CalcProjection2D (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-42 batch 2; float math; double tan via IAT 0x676348 (crt::tan)')
