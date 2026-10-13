"""specs_s202.py - ladder thread batch 202: 0x460100 Bezier segment set-up (power basis + arc length)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _sb(c):
    r = c.rng
    obj = _rnd(c, 0x40)
    pts = [c.fbuf(3, lambda cc: cc.fv(-400.0, 400.0)) for _ in range(4)]
    h = r.choice([0.1, 0.05, 0.25, 0.2, 0.5, 1.0, 0.07]) if r.random() < 0.9 else r.uniform(0.03, 1.2)
    return [obj] + pts + [F(h)]


S(0x460100, 'ParametricCurve::DefineBezier', 'thiscall', None, ret=None, gen=_sb,
  note='batch202; c0..c3 from Bezier points, then +0x34 = ArcLength(h)')
