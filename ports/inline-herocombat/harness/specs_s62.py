"""specs_s62.py - inline session batch 62: BasicShape::GetSplineVelocity and ZSHAPE::GetSegment. The shape list's
slots 0xfc and 0x100 are recorder stubs returning the point array and a pointer to its count; ParametricCurve::
GetSplineVelocity runs as exe code on the batch 58 random segments."""
import math
import struct
from pilot import S, F
import specs_s58 as k58

_rnd, _stub, _obj, _fv = k58._rnd, k58._stub, k58._obj, k58._fv


def _shape_padded(c):
    # 2026-10-13 (wire-hero-combat): the generator fix for docs/39's faulting cases (41 / 51). The segment index
    # trunc(count * t) is clamped to count - 1 above but not below 0, so k58._t's t in [-2, 0) indexes up to 2 * count
    # segments BEFORE the array, which k58._shape left unmapped (both builds faulted the same way). Here that much random
    # memory is mapped in front of the segments, so negative t reads it in both builds and is compared. (The ladder
    # itself, ZFFHeroMovementGuide::WantControl, passes t = 0, 1, 2 ...)
    r = c.rng
    n = r.choice((1, 1, 2, 3, 5))
    pad = 0x38 * (2 * n + 1)
    base = _rnd(c, pad + 0x38 * n)
    segs = base + pad
    for i in range(n):
        c.emu.wbytes(segs + 0x38 * i, b''.join(struct.pack('<f', v) for v in k58._coef(c)))
    b = _rnd(c, 0x20)
    c.emu.w32(b + 0xc, segs)
    c.emu.w32(b + 0x10, n)
    return b


def _bsv(c):
    return [_shape_padded(c), _fv(c, [9.0] * 3), F(k58._t(c))]


def _seg(c):
    r = c.rng
    n = r.choice((2, 2, 3, 4, 5, 9, 1, 0))
    pts = _rnd(c, 36 * 10 + 64)
    cnt = c.emu.alloc(8, 4)
    c.emu.w32(cnt, n)
    lst = _obj(c, 0x110, {0xfc: _stub(c, 1, ret=pts + 36), 0x100: _stub(c, 1, ret=cnt)})
    x = _rnd(c, 0x20)
    c.emu.w32(x + 0x18, lst)
    sysobj = _rnd(c, 0x1ab0)
    c.emu.w32(sysobj + 0x1aa3, x)
    c.emu.w32(0x70039c, sysobj)
    key = _rnd(c, 0x70)
    self = _rnd(c, 0x20)
    c.emu.w32(self + 8, key)
    if n >= 2 and r.random() < 0.3:   # exactly on a point: t = k / (n - 1) in float
        k = r.randint(0, n - 1)
        t = struct.unpack('<f', struct.pack('<f', k / (n - 1)))[0]
    else:
        t = r.choice((r.uniform(0, 1), r.uniform(-0.5, 1.5), 0.0, 1.0, -0.0, 0.5, math.nan, 1e-8, 0.99999994))
    local = _rnd(c, 8) if r.random() < 0.8 else 0
    c.emu.mu.ctl_flush_tb()
    return [self, F(t), local]


S(0x460b60, 'BasicShape::GetSplineVelocity', 'thiscall', None, gen=_bsv, note='batch62; ladder tree')
S(0x44ad50, 'ZSHAPE::GetSegment', 'thiscall', None, ret='eax', gen=_seg, note='batch62; ladder tree')
