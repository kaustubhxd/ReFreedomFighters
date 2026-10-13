"""specs_s201.py - ladder thread batch 201: 0x4602b0 closest point on a cubic (bisection, `steps` rounds)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cp(c):
    r = c.rng
    obj = _rnd(c, 0x40)
    for off in range(4, 0x34, 4):
        c.emu.wf32(obj + off, 0.0 if r.random() < 0.1 else c.fv(-300.0, 300.0))
    p = c.fbuf(3, lambda cc: cc.fv(-500.0, 500.0))
    out = _rnd(c, 0x10)
    steps = r.choice([10, 10, 10, 0, 1, 2, 5, 20, -1, -0x7fffffff, 3])
    return [obj, p, r.getrandbits(32), out, steps]


S(0x4602b0, 'ParametricCurve::GetClosestPoint', 'thiscall', None, ret='st0', gen=_cp,
  note='batch201; bisection on t, out = P(t), returns vdist(out, P)')
