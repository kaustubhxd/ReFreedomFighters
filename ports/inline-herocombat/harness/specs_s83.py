"""specs_s83.py - inline session batch 83 (2026-10-12, docs/41): vdist2 0x4e0830 (fastcall, result in ST0). The
subtraction 0x43e920 runs as exe code."""
from pilot import S


def _v(c):
    r = c.rng
    v = c.emu.alloc(0x20, 4)
    vals = [c.fv(-1000.0, 1000.0), c.fv(-1000.0, 1000.0), c.fv(-1000.0, 1000.0)]
    if r.random() < 0.15:
        vals = [0.0, 0.0, 0.0]
    for i, x in enumerate(vals):
        c.emu.wf32(v + 4 * i, x)
    return v


def _vd(c):
    a = _v(c)
    return [a, a if c.rng.random() < 0.1 else _v(c)]


S(0x4e0830, 'vdist2', 'fastcall', None, ret='st0', gen=_vd, note='batch83; squared distance of two points, ST0')
