"""specs_c1064.py - camera batch 1064: ZCAMERA::Proj2D (0x446320): ortho and perspective, with the clamp 0.001 on the depth."""
import struct
from pilot import S
from camgen import rnd, fbits


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _cam(c):
    r = c.rng
    cam = rnd(c, 0x200)
    c.emu.w32(cam + 0x48, r.choice([0, 1, 0xff]))
    c.emu.w32(cam + 0x3c, _fl(c, 0.5, 4.0))
    c.emu.w32(cam + 0x40, _fl(c, 0.5, 4.0))
    c.emu.w32(cam + 0x58, _fl(c, 0.5, 900.0))
    return cam


def _p2(c):
    r = c.rng
    out = rnd(c, 0x20)
    inp = rnd(c, 0x20)
    for i in range(3):
        c.emu.w32(inp + 4 * i, fbits(c) if r.random() < 0.15 else _fl(c, -300, 300))
    if r.random() < 0.8:
        c.emu.w32(inp + 8, _fl(c, -2.0, 900.0))
    return [_cam(c), out, inp]


S(0x446320, 'ZCAMERA::Proj2D', 'thiscall', gen=_p2)
