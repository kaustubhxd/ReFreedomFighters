"""specs_s902.py - vehicles batch 902: damper/wheel heights and undercarriage Y updates."""
from pilot import S
from vh import _rnd, _stub, cstub, obj, r32, rf


def g_d(c):
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0x55, rf(c))
    return [o]


S(0x5162d0, 'CDamper::GetY (inferred)', 'thiscall', ret='st0', gen=g_d)
S(0x516230, 'CDamper::GetLowerPos', 'thiscall', gen=lambda c: [_rnd(c, 0x100), c.emu.alloc(12, 4)])


def wheel(c, o, offs):
    for off in offs:
        c.emu.w32(o + off, rf(c, -100, 100))
    h = c.emu.alloc(0x10, 4)
    g = _rnd(c, 0x60)
    c.emu.w32(h + 8, g)
    c.emu.w32(o + 0x18, h)


def g_w(offs):
    def g(c):
        o = _rnd(c, 0x180)
        wheel(c, o, offs)
        return [o, rf(c, -100, 100)]
    return g


S(0x52a270, 'CWheel::SetYPos', 'thiscall', gen=g_w((0x31, 0x14, 0x35, 0x39)))
S(0x52a220, 'front wheel SetYPos (inferred)', 'thiscall', gen=g_w((0x61, 0x44, 0x28, 0x2c)))


def uc(c, n1, d1, n2, d2, wheels=None, size=0x2400):
    o = _rnd(c, size)
    a, b = c.rng.randint(0, 4), c.rng.randint(0, 4)
    if c.rng.random() < 0.05:
        a = b = 0
    c.emu.w32(o + n1, a)
    c.emu.w32(o + n2, b)
    for k in range(12):
        c.emu.w32(o + 4 * k, rf(c, -100, 100))   # pos + rotation
    for cnt, d, w in ((a, d1, wheels and wheels[0]), (b, d2, wheels and wheels[1])):
        for i in range(cnt):
            for off in (0, 8, 0x41, 0x55):
                c.emu.w32(o + d + i * 0xde + off, rf(c, -100, 100))
            if w:
                base, st, offs = w
                wheel(c, o + base + i * st, offs)
    return o


S(0x529760, 'CUnderCarriageTank::UpdateYPos', 'thiscall', gen=lambda c: [uc(c, 0x8d, 0x95, 0x91, 0x785)])


def g_car_y(c):
    o = uc(c, 0x8c, 0xbd, 0x90, 0x435)
    c.emu.w32(o + 0x64, rf(c, -5200, -4800) if c.rng.random() < 0.5 else rf(c, -100, 100))
    lg = obj(c, 0x40, {0x30: cstub(c, 2)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=lg)})
    c.emu.w32(0x700390, dbg)
    return [o]


S(0x526df0, 'CUnderCarriageCar::UpdateYPos', 'thiscall', gen=g_car_y)
CW = (0x31, 0x14, 0x35, 0x39)
FW = (0x61, 0x44, 0x28, 0x2c)
S(0x529660, 'CUnderCarriageTank::UpdateWheelsYPos', 'thiscall',
  gen=lambda c: [uc(c, 0x8d, 0x95, 0x91, 0x785, ((0xe75, 0x133, CW), (0x180d, 0x133, CW)))])
S(0x526cf0, 'CUnderCarriageCar::UpdateWheelsYPos', 'thiscall',
  gen=lambda c: [uc(c, 0x8c, 0xbd, 0x90, 0x435, ((0x7ad, 0x163, FW), (0xd39, 0x133, CW)))])
