"""specs_s423.py - unclaimed-42 batch 3 (claim 3): ParametricCurve::RecSub (0x460650), thiscall, nine stack arguments.
The output cursor is a cell holding a pointer into a zeroed buffer (or null, which skips the copy). The four points are
random floats in [-1, 1]; the tolerance is in [0.05, 2] so that the subdivision stops after a few levels. The leaf test
0x460870 is original code (another area's function) and runs as is."""
import struct
from pilot import S, F


def _pt(c, cell):
    for i in range(3):
        c.emu.wbytes(cell + 4 * i, struct.pack('<f', F(c.rng.uniform(-1.0, 1.0))))
    return cell


def _rs(c):
    obj = c.emu.alloc(0x100, 16)
    c.emu.wbytes(obj, bytes(0x100))
    out = c.emu.alloc(0x4000, 16)
    c.emu.wbytes(out, bytes(0x4000))
    cur = c.emu.alloc(4, 4)
    c.emu.w32(cur, out if c.rng.random() < 0.9 else 0)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, c.rng.randrange(0, 3))
    pts = [_pt(c, c.emu.alloc(12, 4)) for _ in range(4)]
    tol = F(c.rng.uniform(0.05, 2.0))
    maxd = c.rng.randrange(1, 8)
    extra = c.rng.getrandbits(32)
    return [obj, cur, cnt, pts[0], pts[1], pts[2], pts[3], tol, maxd, extra]


S(0x460650, 'ParametricCurve::RecSub (unknown) thiscall', 'thiscall', None, ret=None, gen=_rs,
  note='unclaimed-42 batch 3; de Casteljau split; leaf test 0x460870 (other area, original code)')
