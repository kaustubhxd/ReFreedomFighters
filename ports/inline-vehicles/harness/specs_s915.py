"""specs_s915.py - vehicles batch 915: ZTank driving."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, cstub, hookrec
import specs_s907 as b907

PT = [(0, 'd'), (4, 'd'), (8, 'd')]


def vec(c, lo=-100, hi=100):
    v = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(v + 4 * k, rf(c, lo, hi))
    return v


S(0x515930, 'ZVehicle::DriveFwd/BkwToSplineVal', 'thiscall',
  gen=lambda c: [obj(c, 0x40, {0x2f8: _stub(c, 2)}), rf(c, 0, 1), r32(c)])
S(0x521930, 'ZTank start backward (inferred)', 'thiscall', gen=lambda c: [obj(c, 0x400, {0x2f8: _stub(c, 2)})])
S(0x5233a0, 'CMoveAlongPath::GetDirToSplineVal', 'thiscall', gen=lambda c: [b907.path(c), c.emu.alloc(12, 4), rf(c, -0.5, 1.5)])


def sysx(c, body_flag=True):
    s = _rnd(c, 0x200)
    grp = _rnd(c, 0x40)
    c.emu.w32(grp + 0x3c, c.rng.choice([0, 0x1000, 0xffffffff]))
    g = _rnd(c, 0x20)
    c.emu.w32(g + 8, grp)
    c.emu.w32(s + 0x9b, obj(c, 0x40, {0x58: idstub(c, [g] * 4)}))
    dbg = obj(c, 0x10, {0x184: cstub(c, 5)})
    c.emu.w32(s, c.emu.r32(obj(c, 4, {0x190: _stub(c, 0, ret=dbg)})))
    c.emu.w32(0x70039c, s)
    lg = obj(c, 0x40, {0x30: cstub(c, 2)})
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: _stub(c, 2, ret=lg)}))


def tank(c, slots):
    t = obj(c, 0x2800, slots)
    for o in list(range(0x60, 0xc0, 4)) + list(range(0x2d8, 0x2fc, 4)):
        c.emu.w32(t + o, rf(c, -2, 2))
    c.emu.w32(t + 0x2f0, c.rng.choice([0x3f800000, 0xbf800000]))
    c.emu.w32(t + 0x2f4, c.rng.choice([0, 1, 2, 3, 4]))
    c.emu.w32(t + 0x2f8, rf(c, 0, 1))
    c.emu.w32(t + 0x216, c.rng.choice([0, 1]))
    c.emu.w32(t + 0x123, c.rng.choice([1, 1, 1, 0]))
    p = b907.path(c)
    c.emu.w32(p + 0x24, rf(c, 0, 100))
    c.emu.w32(t + 0x5c, p)
    dv = vec(c, -1, 1)
    vt = c.emu.alloc(0x20, 4)
    c.emu.w32(vt + 8, _stub(c, 1, fills=((0, dv, 3),)))
    c.emu.w32(vt + 0xc, _stub(c, 0, ret=c.rng.choice([0, 1])))
    c.emu.w32(vt + 4, _stub(c, 2))
    c.emu.w32(t + 0x2695, vt)
    return t


def g_dir(c):
    sysx(c)
    return [tank(c, {0x130: _stub(c, 3)})]


S(0x521bd0, 'ZTank::UpdateDir', 'thiscall', gen=g_dir)


def g_pd(c):
    sysx(c)
    hookrec(c, 0x527d10, 7, skip=(0, 1, 2), peeks=((3, 0), (3, 8)))
    hookrec(c, 0x520450, 4, skip=(2, 3))
    return [tank(c, {0x370: _stub(c, 0), 0x7c: _stub(c, 2, skip=(0, 1)), 0x2f8: _stub(c, 2)})]


S(0x521f90, 'ZTank::UpdatePosDir', 'thiscall', gen=g_pd)


def g_su(c):
    sysx(c)
    hookrec(c, 0x515c70, 0)
    hookrec(c, 0x527d10, 7)
    for a in (0x522520, 0x521db0, 0x521ab0, 0x522250):
        hookrec(c, a, 0)
    t = tank(c, {0x36c: _stub(c, 0), 0x80: _stub(c, 2), 0x2ec: _stub(c, 1)})
    c.emu.w8(t + 0x133, c.rng.choice([0, 1]))
    c.emu.w8(t + 0x215, c.rng.choice([0, 1]))
    return [t]


S(0x521830, 'ZTank::SplineUpdate', 'thiscall', gen=g_su)
