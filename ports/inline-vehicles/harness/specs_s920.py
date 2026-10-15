"""specs_s920.py - vehicles batch 920: ground probing and damper resets."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, hookrec
import specs_s903 as b903
import specs_s919 as b919


def g_sg(c):
    p = _rnd(c, 0x20)
    return [p, c.rng.choice([0xfe967699, rf(c)]), rf(c)]


S(0x5244d0, 'pull set ground (inferred)', 'thiscall', gen=g_sg)


def g_ug(c):
    b903.world(c)
    return [b903.damper(c), rf(c), c.rng.choice([0, 1]), rf(c), 0]


S(0x5165d0, 'CDamper update ground (inferred)', 'thiscall', gen=g_ug)


def g_ra(c):
    b903.world(c)
    p = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(p + 4 * k, rf(c))
    return [b903.damper(c), p]


S(0x5162e0, 'CDamper reset at (inferred)', 'thiscall', gen=g_ra)


def g_pg(c):
    b903.world(c)
    o = b919.uc(c)
    c.emu.w32(o + 0x8d, c.rng.randint(1, 4))
    c.emu.w32(o + 0x91, c.rng.randint(1, 4))
    for b in (0x95, 0x785):
        for i in range(4):
            b919.damper(c, o + b + i * 0xde)
    c.emu.w32(o + 0x40, c.rng.randint(0, 4))
    c.emu.w32(o + 0x44, c.rng.randint(0, 4))
    return [o]


S(0x529130, 'CUnderCarriageTank probe ground (inferred)', 'thiscall', gen=g_pg)


def g_cr(c):
    b903.world(c)
    o = b919.uc(c)
    for a, n in ((0xe91, 0x8d), (0x1829, 0x91)):
        for i in range(c.emu.r32(o + n)):
            for k in range(3):
                c.emu.w32(o + a + i * 0x133 + 4 * k, rf(c))
    return [o]


S(0x5279f0, 'CUnderCarriageTank correct reversed dampers (inferred)', 'thiscall', gen=g_cr)
