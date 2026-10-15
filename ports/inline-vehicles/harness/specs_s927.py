"""specs_s927.py - vehicles batch 927: CUnderCarriageCar physics step, dynamics, frame update."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, hookrec, cstub
import specs_s919 as b919


def carUC(c):
    o = _rnd(c, 0x1800)
    a, b = c.rng.randint(0, 4), c.rng.randint(0, 4)
    c.emu.w32(o + 0x8c, a)
    c.emu.w32(o + 0x90, b)
    for base, n in ((0xbd, a), (0x435, b)):
        for i in range(n):
            b919.damper(c, o + base + i * 0xde)
    for k in range(0x60 // 4):
        c.emu.w32(o + 4 * k, rf(c, -1, 1))
    for off in (0xa8, 0xac):
        c.emu.w32(o + off, rf(c, 50, 400))
    c.emu.w32(o + 0x9c, rf(c, 0.001, 0.01))
    c.emu.w32(o + 0x64, rf(c, 0, 100))
    return o


def sysx(c):
    s = _rnd(c, 0x200)
    c.emu.w32(s + 0x40, c.rng.randint(0, 1 << 20))
    c.emu.w32(s + 0x48, rf(c, 0.001, 0.1))
    c.emu.w32(0x70039c, s)
    lg = obj(c, 0x40, {0x30: cstub(c, 2)})
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: _stub(c, 2, ret=lg)}))
    return s


S(0x524f50, 'CUnderCarriageCar physics step (inferred)', 'thiscall', gen=lambda c: [carUC(c)])


def g_dyn(c):
    s = sysx(c)
    hookrec(c, 0x525640, 2)   # InitPosDir on the too-high warning path
    o = carUC(c)
    c.emu.wf32(o + 0x48, (c.emu.r32(s + 0x40) - c.rng.randint(-20, 200)) / 1024.0)
    return [o]


S(0x524ff0, 'CUnderCarriageCar::DynamicsFrameUpdate', 'thiscall', gen=g_dyn)


def g_fu(c):
    s = sysx(c)
    for a in (0x524ff0, 0x526cf0, 0x524de0, 0x526470, 0x526ac0, 0x526360, 0x525f30, 0x526880, 0x526c60):
        hookrec(c, a, 0)
    o = carUC(c)
    c.emu.w8(o + 0xbc, c.rng.choice([0, 1]))
    c.emu.w32(o + 0x84, (c.emu.r32(s + 0x40) + c.rng.randint(-5, 5)) & 0xffffffff)
    c.emu.w32(o + 0x88, obj(c, 0x40, {0x7c: _stub(c, 2), 0x80: _stub(c, 2, skip=(0, 1))}))
    vs = []
    for _ in range(2):
        v = c.emu.alloc(12, 4)
        for k in range(3):
            c.emu.w32(v + 4 * k, rf(c, -1, 1))
        vs.append(v)
    return [o, c.emu.alloc(36, 4), c.emu.alloc(12, 4), vs[0], vs[1], rf(c, 0, 100), rf(c, -50, 50), rf(c, -1, 1),
            rf(c, -1, 1)]


S(0x5251c0, 'CUnderCarriageCar::FrameUpdate', 'thiscall', gen=g_fu)
