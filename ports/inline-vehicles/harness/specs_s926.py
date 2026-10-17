"""specs_s926.py - vehicles batch 926: ZCar drive orders."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, fconst, cstub
import specs_s907 as b907


def env(c):
    s = _rnd(c, 0x200)
    p = _rnd(c, 0xb00)
    c.emu.w32(p + 0xadc, obj(c, 0x40, {0x218: _stub(c, 3, skip=(0,), copy=(0, [(0, 'd'), (4, 'd'), (8, 'd')]))}))
    c.emu.w32(s + 0x9b, p)
    c.emu.w32(0x70039c, s)
    lg = obj(c, 0x40, {0x2c: cstub(c, 3)})   # (o, fmt, name); the double of the 2nd message is not recorded
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: _stub(c, 2, ret=lg)}))


def car(c):
    o = obj(c, 0x1700, {0x2f8: _stub(c, 2), 0x360: _stub(c, 2), 0x364: _stub(c, 2)})
    grp = _rnd(c, 0x40)
    for k in range(3):
        c.emu.w32(grp + 0x24 + 4 * k, rf(c))
    c.emu.w32(o + 8, grp)
    c.emu.w32(o + 4, c.rng.choice([0, 0x69f03c]))
    for off in list(range(0x15d3, 0x1603, 4)):
        c.emu.w32(o + off, rf(c, -2, 2))
    c.emu.w32(o + 0x378, rf(c, 50, 150))
    c.emu.w32(o + 0x37c, rf(c, 50, 150))
    c.emu.w32(o + 0x1650, c.rng.choice([0, 1, 2]))
    p = b907.path(c)
    vt = c.emu.alloc(0x40, 4)
    c.emu.w32(vt + 0xc, _stub(c, 0, fld=fconst(c, c.rng.random())))
    c.emu.w32(vt + 0x14, _stub(c, 0, fld=fconst(c, c.rng.uniform(-50, 50))))
    c.emu.w32(vt + 4, _stub(c, 1, fld=fconst(c, c.rng.uniform(-0.1, 0.1))))
    c.emu.w32(vt + 0x20, _stub(c, 1))
    c.emu.w32(p, vt)
    for off in (8, 0xc, 0x10):
        c.emu.w32(p + off, rf(c, -300, 300))
    c.emu.w32(o + 0x5c, p)
    return o


def g(c):
    env(c)
    return [car(c), rf(c, 0, 1), r32(c)]


S(0x517c60, 'ZCar::DriveToSplineVal', 'thiscall', gen=g)
S(0x5179c0, 'ZCar::DriveFwdToSplineVal', 'thiscall', gen=g)
S(0x517670, 'ZCar::DriveBkwToSplineVal', 'thiscall', gen=g)
