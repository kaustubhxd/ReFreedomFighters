"""specs_s2104.py - wire-hero-combat batch 2104: 0x4de520 mpul (matrix blend), 2026-10-13. Every callee runs as exe code
(vcross 0x446ee0, vnorm 0x44c840, the slerp 0x4e0390 with its CRT calls). Frames: random rotations (so both paths run),
random floats, a few degenerate rows; t from edges (0, 1/8192, 0.99987..., 1, NaN) and (0, 1)."""
import math
import struct
from pilot import S, F


def _rot(r):
    # a random rotation as three rows
    a, b, c = (r.uniform(-math.pi, math.pi) for _ in range(3))
    ca, sa, cb, sb, cc, sc = math.cos(a), math.sin(a), math.cos(b), math.sin(b), math.cos(c), math.sin(c)
    return [cb * cc, cb * sc, -sb,
            sa * sb * cc - ca * sc, sa * sb * sc + ca * cc, sa * cb,
            ca * sb * cc + sa * sc, ca * sb * sc - sa * cc, ca * cb]


def _mat(c):
    r = c.rng
    k = r.random()
    if k < 0.7:
        m = _rot(r)
    elif k < 0.85:
        m = [r.uniform(-2, 2) for _ in range(9)]
    else:
        m = _rot(r)
        i = r.randint(0, 2)
        m[3 * i:3 * i + 3] = [0.0, 0.0, 0.0] if r.random() < 0.5 else [1e-6, 0.0, -1e-6]
    a = c.emu.alloc(48, 4)
    c.emu.wbytes(a, b''.join(struct.pack('<f', v) for v in m))
    return a


def _mpul(c):
    r = c.rng
    out = c.emu.alloc(48, 4)
    c.emu.wbytes(out, bytes(r.getrandbits(8) for _ in range(48)))
    m0 = _mat(c)
    m1 = _mat(c) if r.random() < 0.85 else m0
    t = r.choice((r.random(), r.random(), r.random(), 0.0, 1.0 / 8192, 0.9998779296875, 0.99988, 1.0, -0.5, 1.5, float('nan'), 1e-4))
    return [out, m0, m1, F(t)]


S(0x4de520, 'mpul (matrix blend)', 'fastcall', None, ret=None, gen=_mpul,
  note='batch2104; vcross, vnorm and the slerp 0x4e0390 as exe code')
