"""specs_s916.py - vehicles batch 916: ZTank drive orders, InitTankPosDir."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, fconst, hookrec
import specs_s907 as b907

PT = [(0, 'd'), (4, 'd'), (8, 'd')]


def vec(c, lo=-100, hi=100):
    v = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(v + 4 * k, rf(c, lo, hi))
    return v


S(0x4e09b0, 'vneg', 'thiscall', gen=lambda c: [vec(c)])


def tank(c, slots=None):
    t = obj(c, 0x2800, slots)
    for o in list(range(0x60, 0xc0, 4)) + list(range(0x2d8, 0x2fc, 4)):
        c.emu.w32(t + o, rf(c, -2, 2))
    c.emu.w32(t + 0x2f0, c.rng.choice([0x3f800000, 0xbf800000]))
    p = b907.path(c)
    vt = c.emu.r32(p) if False else c.emu.alloc(0x40, 4)
    c.emu.w32(vt + 0xc, _stub(c, 0, fld=fconst(c, c.rng.random())))
    c.emu.w32(vt + 0x14, _stub(c, 0, fld=fconst(c, c.rng.uniform(-50, 50))))
    c.emu.w32(p, vt)
    c.emu.w32(t + 0x5c, p)
    for off in (0x2695, 0x263c):
        v2 = c.emu.alloc(0x20, 4)
        c.emu.w32(v2, _stub(c, 3))
        c.emu.w32(v2 + 4, _stub(c, 2))
        c.emu.w32(t + off, v2)
    return t


S(0x520b10, 'ZTank::DriveBkwToSplineVal', 'thiscall', gen=lambda c: [tank(c), rf(c, 0, 1), r32(c)])
S(0x520bb0, 'ZTank::DriveFwdToSplineVal', 'thiscall', gen=lambda c: [tank(c), rf(c, 0, 1), r32(c)])
S(0x520c50, 'ZTank::DriveToSplineVal', 'thiscall',
  gen=lambda c: [tank(c, {0x360: _stub(c, 2), 0x364: _stub(c, 2)}), rf(c, 0, 1), r32(c)])
S(0x520e40, 'ZTank set hull dir (inferred)', 'thiscall', gen=lambda c: [tank(c), vec(c, -1, 1)])


def g_itpd(c):
    hookrec(c, 0x528100, 2)
    hookrec(c, 0x525380, 2)
    t = tank(c, {0x80: _stub(c, 2)})
    c.emu.w8(t + 0x133, c.rng.choice([0, 1]))
    return [t, r32(c)]


S(0x520f20, 'ZTank::InitTankPosDir', 'thiscall', gen=g_itpd)
