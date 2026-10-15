"""specs_s928.py - vehicles batch 928: CUnderCarriageCar sub-steps."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, hookrec, cstub, fconst
import specs_s903 as b903
import specs_s919 as b919
import specs_s921 as b921
import specs_s922 as b922
import specs_s927 as b927

PT = [(0, 'd'), (4, 'd'), (8, 'd')]


def uc(c):
    o = b927.carUC(c)
    for off in (0x68, 0x6c, 0x74, 0x78, 0x7c, 0x94, 0x98, 0xa8):
        c.emu.w32(o + off, rf(c, -100, 100))
    return o


def g_pg(c):
    hookrec(c, 0x5165d0, 4)
    o = uc(c)
    c.emu.w32(o + 0x8c, c.rng.randint(1, 4))
    c.emu.w32(o + 0x90, c.rng.randint(1, 4))
    return [o]


S(0x526470, 'CUnderCarriageCar ground probe (inferred)', 'thiscall', gen=g_pg)
S(0x526ac0, 'CUnderCarriageCar weight transfer (inferred)', 'thiscall', gen=lambda c: [uc(c)])


def anchors(c, o):
    for a, n, st in ((0x7c9, 0x8c, 0x163), (0xd55, 0x90, 0x133)):
        for i in range(c.emu.r32(o + n)):
            for k in range(3):
                c.emu.w32(o + a + i * st + 4 * k, rf(c))


def g_df(c):
    o = uc(c)
    anchors(c, o)
    off = c.emu.alloc(12, 4)
    c.emu.w32(o + 0x88, obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),))}))
    return [o]


S(0x526360, 'CUnderCarriageCar dampers follow anchors (inferred)', 'thiscall', gen=g_df)


def g_cr(c):
    b903.world(c)
    hookrec(c, 0x5162e0, 1, skip=(0,), peeks=((0, 0), (0, 4), (0, 8)))
    lg = obj(c, 0x40, {0x2c: cstub(c, 2)})
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: _stub(c, 2, ret=lg)}))
    o = uc(c)
    anchors(c, o)
    return [o]


S(0x524de0, 'CUnderCarriageCar::CorrectReversedDampers', 'thiscall', gen=g_cr)


def steerwheel(c, w):
    for off in (0x10, 0x14):
        c.emu.w32(w + off, rf(c, -1, 1))
    if c.rng.random() < 0.2:
        c.emu.w32(w + 0x14, c.emu.r32(w + 0x10))
    h = _rnd(c, 0x10)
    c.emu.w32(h + 8, _rnd(c, 0x48))
    c.emu.w32(w + 0x18, h)


def g_st(c):
    b921.sysw(c)
    w = _rnd(c, 0x40)
    steerwheel(c, w)
    return [w, rf(c, -1, 1)]


S(0x52a0b0, 'CSteeringWheel steer to (inferred)', 'thiscall', gen=g_st)


def g_wh(c):
    b921.sysw(c)
    hookrec(c, 0x529e30, 2)
    o = uc(c)
    for i in range(5):
        steerwheel(c, o + 0x7ad + i * 0x163)
    return [o]


S(0x525f30, 'CUnderCarriageCar wheels (inferred)', 'thiscall', gen=g_wh)


def g_du(c):
    s = b921.sysw(c)
    b922.rmx(c, s)
    hookrec(c, 0x516b60, 3)
    o = uc(c)
    c.emu.w32(o + 0x435 + 0xad, c.rng.choice([0, 1]))
    c.emu.w32(o + 0xd49, c.rng.choice([0, 1, 2]))
    return [o]


S(0x526880, 'CUnderCarriageCar wheel dust (inferred)', 'thiscall', gen=g_du)


def g_ex(c):
    hookrec(c, 0x5168b0, 0)
    o = uc(c)
    c.emu.w32(o + 0x68, rf(c, 0, 300))
    c.emu.w32(o + 0x12f7, c.rng.randint(0, 3))
    return [o]


S(0x526c60, 'CUnderCarriageCar exhaust (inferred)', 'thiscall', gen=g_ex)
