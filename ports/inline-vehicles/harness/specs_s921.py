"""specs_s921.py - vehicles batch 921: tank weight transfer, track speeds, wheel spin, track UV scroll."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, hookrec
import specs_s919 as b919

PT = [(0, 'd'), (4, 'd'), (8, 'd')]


def ucx(c):
    o = b919.uc(c)
    for off in (0x68, 0x6c, 0x74, 0x78, 0x7c, 0x80, 0x21ad, 0x21b1, 0x21b9, 0x22c4, 0x22c8):
        c.emu.w32(o + off, rf(c, -100, 100))
    return o


S(0x529450, 'CUnderCarriageTank weight transfer (inferred)', 'thiscall', gen=lambda c: [ucx(c)])
S(0x516620, 'CDamper set x/z (inferred)', 'thiscall', gen=lambda c: [_rnd(c, 0x20), _rnd(c, 12)])


def g_df(c):
    o = ucx(c)
    off = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(off + 4 * k, rf(c, -5, 5))
    c.emu.w32(o + 0x89, obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),))}))
    return [o]


S(0x529020, 'CUnderCarriageTank dampers follow anchors (inferred)', 'thiscall', gen=g_df)


def sysw(c):
    s = _rnd(c, 0x1b00)
    c.emu.w32(s + 0x48, rf(c, 0, 0.1))
    c.emu.w32(0x70039c, s)
    g = _rnd(c, 0xb00)
    c.emu.w8(g + 0xab8, c.rng.choice([0, 1]))
    c.emu.w32(0x7003b8, g)
    return s


def wheel(c, w):
    for off in (0x14, 0x29, 0x2d):
        c.emu.w32(w + off, rf(c, 0, 50))
    h = _rnd(c, 0x10)
    g = _rnd(c, 0x48)
    for k in range(9):
        c.emu.w32(g + 4 * k, rf(c, -1, 1))
    c.emu.w32(h + 8, g)
    c.emu.w32(w + 0x18, h)


def g_rev(c):
    sysw(c)
    hookrec(c, 0x5168b0, 0)
    w = _rnd(c, 0x140)
    wheel(c, w)
    return [w, rf(c, -100, 100), rf(c, 0, 100)]


S(0x529e30, 'CWheel::Revolve', 'thiscall', gen=g_rev)


def g_tr(c):
    sysw(c)
    hookrec(c, 0x5168b0, 0)
    o = ucx(c)
    for base, n in ((0xe75, 0x8d), (0x180d, 0x91)):
        for i in range(c.emu.r32(o + n) + 1):
            wheel(c, o + base + i * 0x133)
    return [o]


S(0x528b60, 'CUnderCarriageTank track speeds (inferred)', 'thiscall', gen=g_tr)


def rm(c, s):
    u = _rnd(c, 0x20)
    sub = obj(c, 0x20, {0x60: _stub(c, 2, ret=r32(c)), 0xe4: _stub(c, 2, ret=r32(c))})
    m = obj(c, 0x20, {0x80: idstub(c, [u, c.rng.choice([0, u]), u, 0])})
    c.emu.w32(m + 0x18, sub)
    c.emu.w32(s + 0x1aa3, m)


def tgeom(c):
    g = _rnd(c, 0x20)
    grp = _rnd(c, 0x80)
    c.emu.w32(g + 8, grp)
    return g


def g_uv(c):
    s = sysw(c)
    rm(c, s)
    return [ucx(c), tgeom(c), rf(c)]


S(0x528f50, 'CUnderCarriageTank track UV (inferred)', 'thiscall', gen=g_uv)


def g_ts(c):
    s = sysw(c)
    rm(c, s)
    o = ucx(c)
    c.emu.w32(o + 0x21a5, tgeom(c))
    c.emu.w32(o + 0x21a9, tgeom(c))
    return [o]


S(0x528ae0, 'CUnderCarriageTank track scroll (inferred)', 'thiscall', gen=g_ts)
