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


def _grid(c):
    """Integer-grid cases: exact edge hits, t exactly 1, the tolerance margin, a direction in the triangle's plane, mixed magnitudes."""
    r = c.rng
    v = [[float(r.randint(-8, 8)) for _ in range(3)] for _ in range(3)]
    e1 = [v[1][i] - v[0][i] for i in range(3)]
    e2 = [v[2][i] - v[0][i] for i in range(3)]
    mode = r.randrange(4)
    if mode == 0:    # direction in the plane: det 0 or tiny
        a, b = r.randint(-2, 2), r.randint(-2, 2)
        d = [a * e1[i] + b * e2[i] + r.choice((0.0, 0.0, 1e-7, -1e-7)) for i in range(3)]
    else:
        d = [float(r.randint(-6, 6)) for _ in range(3)]
    u, w = r.choice(((0.0, 0.0), (1.0, 0.0), (0.0, 1.0), (0.5, 0.5), (0.25, 0.75), (0.5, 0.0), (0.0, 0.5), (0.25, 0.25),
                     (-1e-5, 0.5), (0.5, -1e-5), (0.5, 0.50001), (-2e-4, 0.5), (1.00005, 0.0)))
    q = [v[0][i] + u * e1[i] + w * e2[i] for i in range(3)]
    sc = r.choice((1.0, 2.0, 0.5, -1.0))
    p = [q[i] - sc * d[i] for i in range(3)]
    if mode == 3:    # mixed magnitudes
        k = r.choice((1e3, 1e4, 1e-3))
        v = [[x * k for x in vv] for vv in v]
        p = [x * k for x in p]
    t = c.emu.alloc(16, 4)
    c.emu.w32(t, r.getrandbits(32))
    flag = r.choice([0, 1, 0x100 | r.getrandbits(8)])
    return [_vec(c, p), _vec(c, d), _vec(c, v[0]), _vec(c, v[1]), _vec(c, v[2]), t, flag]


def _tri(c):
    r = c.rng
    if r.random() < 0.4:
        return _grid(c)
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
