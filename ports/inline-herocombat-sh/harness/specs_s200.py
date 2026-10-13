"""specs_s200.py - ladder thread batch 200: 0x45fe90 spline arc length (trapezoid rule, step h)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _arc(c):
    r = c.rng
    obj = _rnd(c, 0x40)
    for off in range(4, 0x34, 4):
        v = c.fv(-500.0, 500.0)
        if r.random() < 0.15:
            v = 0.0
        c.emu.wf32(obj + off, v)
    k = r.random()
    if k < 0.7:
        h = r.choice([0.1, 0.05, 0.25, 0.2, 0.125, 0.3, 0.07, 1.0 / 3])
    elif k < 0.85:
        h = r.uniform(0.02, 1.5)
    else:
        # 2026-10-13 (wire-hero-combat): -0.5 removed. A step h <= 0 (with 1 - h >= 0) never ends the loop in the exe
        # either (t never reaches 1 - h): both builds hit the instruction limit, which counted as faulting (19 / 26).
        # 1.5 (1 - h < 0: the loop is skipped) takes its place; NaN and inf also skip the loop and stay.
        h = r.choice([0.0 if r.random() < 0.0 else 1.0, 1.5, 2.0, float('nan'), float('inf'), 0.999, 1.0001])
    return [obj, F(h)]


S(0x45fe90, 'ParametricCurve::ArcLength (name inferred)', 'thiscall', None, ret='st0', gen=_arc,
  note='batch200; trapezoid rule on |P\'(t)|, sum kept at +0x34')
