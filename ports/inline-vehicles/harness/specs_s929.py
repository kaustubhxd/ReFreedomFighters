"""specs_s929.py - vehicles batch 929: ZCar::CheckPlayerCollision, InitCarPosDir, OnCameraEnter."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, hookrec
import specs_s917 as b917
import specs_s907 as b907


def g_cpc(c):
    a = b917.g_cpc(c)
    t = a[0]
    car = obj(c, 0x1700)
    c.emu.wbytes(car, c.emu.rbytes(t, 0x1700))
    c.emu.w32(car + 0x164a, c.emu.r32(t + 0x2707) if c.rng.random() < 0.9 else 0)
    return [car] + a[1:]


S(0x5172e0, 'ZCar::CheckPlayerCollision', 'thiscall', gen=g_cpc)


def g_icpd(c):
    hookrec(c, 0x525640, 2, skip=(0, 1), peeks=((0, 0), (0, 4), (0, 8), (1, 0), (1, 8)))
    hookrec(c, 0x525380, 2)
    car = obj(c, 0x1700, {0x80: _stub(c, 2)})
    for off in list(range(0x60, 0x90, 4)) + [0x378, 0x37c]:
        c.emu.w32(car + off, rf(c, -2, 2))
    c.emu.w8(car + 0x133, c.rng.choice([0, 1]))
    c.emu.w8(car + 0x1614, c.rng.choice([0, 1, 1]))
    p = b907.path(c)
    c.emu.w32(car + 0x5c, p)
    return [car, r32(c)]


S(0x517d50, 'ZCar::InitCarPosDir', 'thiscall', gen=g_icpd)


def g_oce(c):
    s = _rnd(c, 0x200)
    c.emu.w32(0x70039c, s)
    car = obj(c, 0x1700, {0x80: _stub(c, 2), 0x36c: _stub(c, 1, skip=(0,))})
    c.emu.w8(car + 0x133, c.rng.choice([0, 1]))
    c.emu.w32(car + 0x35c, (c.emu.r32(s + 0x40) + c.rng.randint(-5, 5)) & 0xffffffff)
    c.emu.w32(car + 0x1650, c.rng.choice([0, 1]))
    return [car]


S(0x518110, 'ZCar::OnCameraEnter', 'thiscall', gen=g_oce)
