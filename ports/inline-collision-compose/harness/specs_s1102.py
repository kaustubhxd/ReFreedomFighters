"""specs_s1102.py - collision thread batch 1102: 0x4e9380 sphere vs triangle. solve3 and the sphere-segment test
run as exe code; the random-direction slot is the batch 1101 stub."""
import struct
from pilot import S, F
from specs_s1101 import _sys, _vec


def _tri(c):
    r = c.rng
    _sys(c)
    this = c.emu.alloc(0x40, 4)
    tri = c.emu.alloc(0x40, 4)
    base = [r.uniform(-20, 20) for _ in range(3)]
    pts = []
    for i in range(3):
        pts.append([base[j] + r.uniform(-5, 5) for j in range(3)])
    if r.random() < 0.08:   # degenerate: v2 = v0 + k (v1 - v0)
        k = r.uniform(-1, 2)
        pts[2] = [pts[0][j] + k * (pts[1][j] - pts[0][j]) for j in range(3)]
    for i in range(3):
        for j in range(3):
            c.emu.wf32(tri + 12 * i + 4 * j, pts[i][j])
    # p: a random barycentric point (often outside) plus an offset along a random direction
    u, v = r.uniform(-0.5, 1.2), r.uniform(-0.5, 1.2)
    q = [pts[0][j] + u * (pts[1][j] - pts[0][j]) + v * (pts[2][j] - pts[0][j]) for j in range(3)]
    off = r.uniform(-3, 3)
    p = c.emu.alloc(0x20, 4)
    for j in range(3):
        c.emu.wf32(p + 4 * j, q[j] + off * r.uniform(-1, 1))
    if r.random() < 0.05:   # p on a vertex
        vi = r.randrange(3)
        for j in range(3):
            c.emu.wf32(p + 4 * j, c.emu.rf32(tri + 12 * vi + 4 * j))
    rad = c.fv(0.2, 4.0, 0.05)
    k = r.random()
    if k < 0.06:   # axis triangle with |n|^2 exactly 2^-26 (times a power of 4 near it)
        e = 2.0 ** -13 * r.choice([0.5, 1.0, 1.0, 1.0, 2.0])
        for i, v in enumerate([0, 0, 0, e, 0, 0, 0, 1, 0]):
            c.emu.wf32(tri + 4 * i, v)
    elif k < 0.16:   # axis triangle in z = 0, p at height h, radius exactly |h| (sphere touching the plane)
        a, b = r.randint(1, 8), r.randint(1, 8)
        for i, v in enumerate([0, 0, 0, a, 0, 0, 0, b, 0]):
            c.emu.wf32(tri + 4 * i, float(v))
        h = r.choice([-1, 1]) * r.randint(1, 4) * 0.5
        c.emu.wf32(p, r.randint(0, a) * 0.25)
        c.emu.wf32(p + 4, r.randint(0, b) * 0.25)
        c.emu.wf32(p + 8, h)
        rad = abs(h) * r.choice([1.0, 1.0, 1.0, 0.5, 2.0])
    push = _vec(c, 3, -1, 1)
    depth = _vec(c, 1, -1, 1)
    return [this, tri, p, F(rad), push, depth]


S(0x4e9380, 'sphere vs triangle (guessed)', 'thiscall', None, ret='al', gen=_tri, note='batch1102')
