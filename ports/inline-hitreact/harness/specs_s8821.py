"""specs_s8821.py - hitreact batch 8821: IntersectTriangleAndLine (0x4e2560). The generator is gateway-run/specs_big.py's _tri, with a local
float source in place of the gateway context's fv (finite values in several ranges plus edge values)."""
import math
import struct
from pilot import S
from wkit import fedge


def _f32(x):
    try:
        return struct.unpack('<f', struct.pack('<f', x))[0]
    except OverflowError:
        return math.copysign(math.inf, x)


def _fv(c):
    r = c.rng
    k = r.random()
    if k < 0.6:
        return r.uniform(-200, 200)
    if k < 0.8:
        return r.uniform(-2, 2)
    if k < 0.9:
        return float(r.randint(-3, 3))
    return fedge(c)


def _vec(c, v):
    a = c.emu.alloc(4 * 3 + 16, 4)
    for i in range(3):
        c.emu.wf32(a + 4 * i, _f32(v[i]))
    for i in range(3, 7):
        c.emu.wf32(a + 4 * i, _f32(_fv(c)))
    return a


def _tri(c):
    r = c.rng
    v = [[_fv(c) for _ in range(3)] for _ in range(3)]
    d = [_fv(c) for _ in range(3)]
    if r.random() < 0.6:       # aim the line at a point near or inside the triangle so both outcomes occur
        u, w = r.uniform(-0.3, 1.3), r.uniform(-0.3, 1.3)
        q = [v[0][i] + u * (v[1][i] - v[0][i]) + w * (v[2][i] - v[0][i]) for i in range(3)]
        s = r.uniform(-5, 5)
        p = [q[i] - s * d[i] for i in range(3)]
        if any(math.isnan(x) for x in p):
            p = [_fv(c) for _ in range(3)]
    else:
        p = [_fv(c) for _ in range(3)]
    if r.random() < 0.05:      # degenerate triangle
        v[2] = list(v[1])
    t = c.emu.alloc(16, 4)
    c.emu.w32(t, r.getrandbits(32))
    flag = r.choice([0, 1, 0x100 | r.getrandbits(8), r.getrandbits(32)])  # only the low byte is tested
    return [_vec(c, p), _vec(c, d), _vec(c, v[0]), _vec(c, v[1]), _vec(c, v[2]), t, flag]


S(0x4e2560, 'IntersectTriangleAndLine', 'fastcall', None, ret='al', gen=_tri)
