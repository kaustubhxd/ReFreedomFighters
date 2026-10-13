"""specs_c1039.py - camera batch 1039: ZCAMERA::Proj2D3D and ZCAMERA::Proj3D."""
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


def _vec(c, n=3):
    v = c.emu.alloc(4 * n + 8, 4)
    for i in range(n):
        c.emu.w32(v + 4 * i, fbits(c) if c.rng.random() < 0.2 else _fl(c, -300, 300))
    return v


def _p2(c):
    b = _vec(c) if c.rng.random() < 0.8 else 0
    return [_cam(c), _vec(c), b]


S(0x446280, 'ZCAMERA::Proj2D3D', 'thiscall', gen=_p2)


def _p3(c):
    z = _vec(c)
    c.emu.w32(z + 8, _fl(c, 0.5, 900.0) if c.rng.random() < 0.9 else 0)
    return [_cam(c), _vec(c), z]


S(0x446430, 'ZCAMERA::Proj3D', 'thiscall', gen=_p3)
