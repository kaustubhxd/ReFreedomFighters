"""specs_s40.py - inline session batch 40 (Haiku, night): ladder-tree leaf 0x460570 (GetSplineVelocity, with the (0,0,1) fallback when all three results are tiny)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _curve(c):
    r = c.rng
    obj = _rnd(c, 0x40)
    if r.random() < 0.25:
        for off in range(4, 0x34, 4):
            c.emu.wf32(obj + off, 0.0 if r.random() < 0.8 else c.fv())
    return obj


def _sp(c):
    r = c.rng
    obj = _curve(c)
    out = _rnd(c, 0x20)
    t = c.fv() if r.random() < 0.8 else r.choice([0.0, 1.0, -1.0, 0.5])
    return [obj, out, F(t)]


S(0x460570, 'ParametricCurve::GetSplineVelocity', 'thiscall', None, ret=None, gen=_sp,
  note='batch40; derivative of the same cubic; (0,0,1) when all three results are tiny (2^-13)')
