"""specs_s1115.py - collision thread batch 1115: vmtmul (3-arg), GetCen, GetLocalMat, GetLocalMatPos,
GetRootMatPos, 0x4ec6d0. SetControl runs as exe code on geoms from the batch 1114 generator (world included)."""
from pilot import S, F
from specs_s1100 import _chain, _vec, _cancel


def _vmt3(c):
    r = c.rng
    m = _vec(c, 9, -2.0, 2.0)
    v = _vec(c, 3, -100.0, 100.0)
    out = v if r.random() < 0.3 else _vec(c, 3, -1.0, 1.0)
    if r.random() < 0.25:
        _cancel(c, v, m, [(6, 7), (3, 4), (0, 1)])
    return [out, v, m]


def _g1(c):
    return [_chain(c), _vec(c, 9, -2.0, 2.0)]


def _g2(c):
    return [_chain(c), _vec(c, 9, -2.0, 2.0), _vec(c, 3, -50.0, 50.0)]


def _cm(c):
    from specs_s1114 import _sc
    e, r = c.emu, c.rng
    n = r.choice([0, 1, 2, 3])
    this = e.alloc(0x1080, 4)
    for i in range(n):
        g, _, _ = _sc(c)
        e.w32(this + 0x74 + 4 * i, g)
    e.w32(this + 0x1074, n)
    return [this]


S(0x459fc0, 'vmtmul(out, v, m)', 'fastcall', None, gen=_vmt3, note='batch1115')
S(0x4daf90, 'ZBaseGeom::GetCen', 'thiscall', None, gen=lambda c: [c.bytes_(0x40), c.emu.alloc(0x10, 4)], note='batch1115')
S(0x4db150, 'ZBaseGeom::GetLocalMat', 'thiscall', None, gen=_g1, note='batch1115')
S(0x4db1b0, 'ZBaseGeom::GetLocalMatPos', 'thiscall', None, gen=_g2, note='batch1115')
S(0x4db600, 'ZBaseGeom::GetRootMatPos', 'thiscall', None, gen=_g2, note='batch1115')
S(0x4ec6d0, 'clear marked geoms (guessed)', 'thiscall', None, gen=_cm, note='batch1115')
