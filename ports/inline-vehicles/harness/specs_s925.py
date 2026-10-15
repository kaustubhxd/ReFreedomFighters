"""specs_s925.py - vehicles batch 925: car positioning along the path, vaddscalar4."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf
import specs_s907 as b907


def vec(c, lo=-100, hi=100):
    v = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(v + 4 * k, rf(c, lo, hi))
    return v


S(0x443ef0, 'vaddscalar(out, a, b, k)', 'fastcall', gen=lambda c: [c.emu.alloc(12, 4), vec(c), vec(c), rf(c, -10, 10)])


def car(c):
    o = _rnd(c, 0x1700)
    grp = _rnd(c, 0x40)
    for k in range(3):
        c.emu.w32(grp + 0x24 + 4 * k, rf(c))
    c.emu.w32(o + 8, grp)
    for off in list(range(0x15d3, 0x1603, 4)) + [0x378, 0x37c]:
        c.emu.w32(o + off, rf(c, -2, 2))
    c.emu.w32(o + 0x378, rf(c, 50, 150))
    c.emu.w32(o + 0x37c, rf(c, 50, 150))
    c.emu.w32(o + 0x15fb, rf(c, -0.5, 0.5))
    c.emu.w32(o + 0x5c, b907.path(c))
    return o


def g(c):
    return [car(c), vec(c), c.emu.alloc(12, 4), c.emu.alloc(12, 4), c.emu.alloc(4, 4)]


S(0x518380, 'ZCar::PositionCarDrivingForward', 'thiscall', gen=g)
S(0x518190, 'ZCar::PositionCarDrivingBackward', 'thiscall', gen=g)
