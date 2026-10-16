"""specs_s904.py - vehicles batch 904: axis-angle rotation, roll/tilt, undercarriage InitPosDir."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf
import specs_s903 as b903


def g_rot(c):
    ax = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(ax + 4 * k, rf(c, -1, 1))
    return [c.emu.alloc(36, 4), ax, rf(c, -7, 7)]


S(0x4ddcb0, 'LoadRotationAxisAngle', 'fastcall', gen=g_rot)


def sys_(c):
    s = _rnd(c, 0x200)
    c.emu.w32(s + 0x48, rf(c, 0, 0.1))
    c.emu.w32(0x70039c, s)
    return s


def g_rt(n1, d1, n2, d2, w, l):
    def g(c):
        sys_(c)
        o = _rnd(c, 0x2400)
        c.emu.w32(o + n1, c.rng.randint(0, 6))
        c.emu.w32(o + n2, c.rng.randint(0, 6))
        for d in (d1, d2):
            for i in range(8):
                c.emu.w32(o + d + i * 0xde + 0x55, rf(c, -50, 50))
        for off in (w, l):
            c.emu.w32(o + off, rf(c, 50, 400))
        for off in (0x30, 0x38):
            c.emu.w32(o + off, rf(c, -1, 1))
        return [o]
    return g


S(0x524b00, 'CUnderCarriageCar::CalcRollAndTilt', 'thiscall', gen=g_rt(0x8c, 0xbd, 0x90, 0x435, 0xa8, 0xac))
S(0x527710, 'CUnderCarriageTank::CalcRollAndTilt', 'thiscall', gen=g_rt(0x8d, 0x95, 0x91, 0x785, 0x21b9, 0x21bd))


def g_ipd(car):
    n1, n2, g, a1, s1, d1, a2, s2, d2 = ((0x8c, 0x90, 0x88, 0x7c9, 0x163, 0xbd, 0xd55, 0x133, 0x435) if car else
                                         (0x8d, 0x91, 0x89, 0xe91, 0x133, 0x95, 0x1829, 0x133, 0x785))
    w1, w2 = (0x7ad, 0xd39) if car else (0xe75, 0x180d)
    ws1 = 0x163 if car else 0x133

    def gen(c):
        o = b903.g_gd(n1, n2, g, a1, s1, d1, a2, s2, d2)(c)[0]
        s = c.emu.r32(0x70039c)
        c.emu.w32(s + 0x48, rf(c, 0, 0.1))
        c.emu.w32(s + 0x40, r32(c))
        grp = c.emu.r32(o + g)
        c.emu.w32(c.emu.r32(grp) + 0x7c, _stub(c, 2))
        for off in (0xa8, 0xac, 0x21b9, 0x21bd):
            c.emu.w32(o + off, rf(c, 50, 400))
        c.emu.w32(o + 0x64, rf(c, -100, 100))
        lg = obj(c, 0x40, {0x30: __import__('vh').cstub(c, 2)})
        c.emu.w32(0x700390, obj(c, 0x40, {0x20: _stub(c, 2, ret=lg)}))
        for cnt, w, st in ((n1, w1, ws1), (n2, w2, 0x133)):
            for i in range(c.emu.r32(o + cnt)):
                h = c.emu.alloc(0x10, 4)
                c.emu.w32(h + 8, _rnd(c, 0x60))
                c.emu.w32(o + w + i * st + 0x18, h)
        p, d = c.emu.alloc(12, 4), c.emu.alloc(12, 4)
        for k in range(3):
            c.emu.w32(p + 4 * k, rf(c, -100, 100))
            c.emu.w32(d + 4 * k, rf(c, -1, 1))
        return [o, p, d]
    return gen


S(0x525640, 'CUnderCarriageCar::InitPosDir', 'thiscall', gen=g_ipd(True))
S(0x528100, 'CUnderCarriageTank::InitPosDir', 'thiscall', gen=g_ipd(False))
