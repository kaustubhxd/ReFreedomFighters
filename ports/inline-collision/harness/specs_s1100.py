"""specs_s1100.py - collision thread batch 1100: vmmul (3-arg), vmtmul, ZBaseGeom::GetRootVect/Point/Mat."""
import struct
from pilot import S, F


def _vec(c, n, lo, hi):
    a = c.emu.alloc(4 * n + 0x10, 4)
    for i in range(n + 4):
        c.emu.wf32(a + 4 * i, c.fv(lo, hi, 0.05))
    return a


def _mat(c):
    return _vec(c, 9, -2.0, 2.0)


def _cancel(c, v, m, cols):
    # v0*m[a] + v1*m[b] cancels exactly, so the add order shows in the result
    x = c.rng.uniform(1e6, 1e8)
    c.emu.wf32(v, x)
    c.emu.wf32(v + 4, x)
    c.emu.wf32(v + 8, c.rng.uniform(-1e-3, 1e-3))
    for a, b in cols:
        c.emu.wf32(m + 4 * a, 1.0)
        c.emu.wf32(m + 4 * b, -1.0)


def _vm3(c):
    r = c.rng
    m = _mat(c)
    v = _vec(c, 3, -100.0, 100.0)
    out = v if r.random() < 0.3 else _vec(c, 3, -1.0, 1.0)
    if r.random() < 0.25:
        _cancel(c, v, m, [(6, 3), (7, 4), (8, 5)])
    return [out, v, m]


def _vmt(c):
    m = _mat(c)
    v = _vec(c, 3, -100.0, 100.0)
    if c.rng.random() < 0.25:
        _cancel(c, v, m, [(6, 7), (3, 4), (0, 1)])
    return [v, m]


def _chain(c):
    r = c.rng
    depth = r.choice([1, 1, 2, 3, 4])
    nxt = 0
    g = 0
    for _ in range(depth):
        g = c.emu.alloc(0x60, 4)
        for i in range(0x60 // 4):
            c.emu.wf32(g + 4 * i, c.fv(-2.0, 2.0, 0.03) if i < 9 else c.fv(-100.0, 100.0, 0.03))
        c.emu.w32(g + 0x50, nxt)
        nxt = g
    return g


def _root(c):
    return [_chain(c), _vec(c, 3, -50.0, 50.0)]


def _rootmat(c):
    return [_chain(c), _vec(c, 9, -2.0, 2.0)]


S(0x441970, 'vmmul(out, v, m)', 'fastcall', None, gen=_vm3, note='batch1100')
S(0x441a60, 'vmtmul(v, m)', 'fastcall', None, gen=_vmt, note='batch1100')
S(0x4db780, 'ZBaseGeom::GetRootVect', 'thiscall', None, gen=_root, note='batch1100')
S(0x4db670, 'ZBaseGeom::GetRootPoint', 'thiscall', None, gen=_root, note='batch1100')
S(0x4db5a0, 'ZBaseGeom::GetRootMat', 'thiscall', None, gen=_rootmat, note='batch1100')
