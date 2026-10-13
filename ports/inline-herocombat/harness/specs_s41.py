"""specs_s41.py - inline session batch 41 (Haiku, night): 0x460af0 BasicShape::GetSplinePosVelocity. The segment index
is trunc(n*t) clamped to n-1; GetSplinePos (0x4604f0) and GetSplineVelocity (0x460570) run as original code."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gspv(c):
    r = c.rng
    n = r.randint(1, 6)
    obj = _rnd(c, 0x40)
    segs = _rnd(c, n * 56 + 0x40)
    if r.random() < 0.3:
        for off in range(0, n * 56, 4):
            c.emu.wf32(segs + off, 0.0)
    c.emu.w32(obj + 0x10, n)
    c.emu.w32(obj + 0xc, segs)
    posOut = _rnd(c, 0x20)
    velOut = _rnd(c, 0x20)
    t = c.rng.uniform(0.0, 1.2) if r.random() < 0.8 else r.choice([0.0, 1.0, 1.2])
    return [obj, posOut, velOut, F(t)]


S(0x460af0, 'BasicShape::GetSplinePosVelocity', 'thiscall', None, ret=None, gen=_gspv,
  note='batch41; segment index trunc(n*t) clamped to n-1; 56-byte records; callees GetSplinePos and GetSplineVelocity as original code')
