"""specs_s901.py - vehicles batch 901: undercarriage impacts, damper bump, GetMatPos."""
import struct
from pilot import S
from vh import _rnd, obj, r32, rf


def g_bump(c):
    o = _rnd(c, 0x100)
    for off in (0x41, 0x55):
        c.emu.w32(o + off, rf(c))
    return [o, rf(c, -100, 100)]


S(0x516040, 'CDamper::DoBump', 'thiscall', gen=g_bump)


def sysobj(c):
    s = c.emu.alloc(0x100, 4)
    c.emu.w32(s + 0x40, r32(c))
    c.emu.w32(0x70039c, s)


def g_imp(n1, n2, p1, s1, p2, s2):
    def g(c):
        sysobj(c)
        o = _rnd(c, 0x2400)
        a, b = c.rng.randint(0, 4), c.rng.randint(0, 4)
        if c.rng.random() < 0.1:
            a = -c.rng.randint(1, 3)
        c.emu.w32(o + n1, a & 0xffffffff)
        c.emu.w32(o + n2, b)
        for i in range(max(a, 0)):
            for k in range(3):
                c.emu.w32(o + p1 + i * s1 + 4 * k, rf(c, -200, 200))
        for i in range(b):
            for k in range(3):
                c.emu.w32(o + p2 + i * s2 + 4 * k, rf(c, -200, 200))
        d = c.emu.alloc(12, 4)
        for k in range(3):
            c.emu.w32(d + 4 * k, rf(c, -200, 200))
        return [o, rf(c, 0, 50), d]
    return g


S(0x525e20, 'CUnderCarriageCar::ReceiveImpact', 'thiscall', gen=g_imp(0x8c, 0x90, 0x7c9, 0x163, 0xd55, 0x133))
S(0x5289d0, 'CUnderCarriageTank::ReceiveImpact', 'thiscall', gen=g_imp(0x8d, 0x91, 0xe91, 0x133, 0x1829, 0x133))


def g_mp(c):
    return [_rnd(c, 0x40), c.emu.alloc(36, 4), c.emu.alloc(12, 4)]


S(0x525380, 'CUnderCarriageTank::GetMatPos', 'thiscall', gen=g_mp)
