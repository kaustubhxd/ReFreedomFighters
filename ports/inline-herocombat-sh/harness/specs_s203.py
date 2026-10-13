"""specs_s203.py - ladder thread batch 203: 0x44ace0 ZSHAPE::GetDistToSegment (Bezier on the stack + closest point)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gd(c):
    r = c.rng
    this = _rnd(c, 0x20)
    out = _rnd(c, 0x10)
    base = [c.fv(-300.0, 300.0) for _ in range(3)]
    pts = c.emu.alloc(0x40, 4)
    for i in range(12):
        v = base[i % 3] + (r.uniform(-60.0, 60.0) if r.random() < 0.9 else c.fv())
        c.emu.wf32(pts + 4 * i, v)
    p = c.fbuf(3, lambda cc: cc.fv(-400.0, 400.0))
    return [this, out, pts, p]


S(0x44ace0, 'ZSHAPE::GetDistToSegment', 'thiscall', None, ret='st0', gen=_gd,
  note='batch203; DefineBezier(step 0.1) then GetClosestPoint(p, 0, out, 10)')
