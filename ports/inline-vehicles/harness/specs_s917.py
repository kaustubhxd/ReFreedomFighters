"""specs_s917.py - vehicles batch 917: ZTank::CheckPlayerCollision, ZTank::OnCameraEnter."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, hookrec

PT = [(0, 'd'), (4, 'd'), (8, 'd')]
HIT = [(0, 'b'), (1, 'd'), (5, 'd'), (9, 'd'), (0xd, 'd'), (0x11, 'd')] + [(o, 'd') for o in range(0x15, 0x79, 4)]


def vec(c, lo=-100, hi=100):
    v = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(v + 4 * k, rf(c, lo, hi))
    return v


def g_cpc(c):
    s = _rnd(c, 0x200)
    bg = _rnd(c, 0x60)
    body = obj(c, 0x40)
    mv, pv = vec(c, -1, 1), vec(c)
    c.emu.w32(c.emu.r32(body) + 0x80, _stub(c, 2, skip=(0, 1), fills=((1, pv, 3),)))
    c.emu.w32(body + 8, bg)
    c.emu.w32(s + 0x9b, obj(c, 0x40, {0x58: idstub(c, [body] * 4)}))
    c.emu.w32(0x70039c, s)
    pl = obj(c, 0x40)
    pp = vec(c, -200, 200)
    c.emu.w32(c.emu.r32(pl) + 0x84, _stub(c, 1, skip=(0,), fills=((0, pp, 3),)))
    off = vec(c, -50, 50)
    t = obj(c, 0x2800, {0x8c: _stub(c, 1, skip=(0,), adds=((0, off, 3),)), 0x94: _stub(c, 2, skip=(0, 1)),
                        0x130: _stub(c, 3, skip=(2,), copy=(2, HIT))})
    grp = _rnd(c, 0x60)
    for o in (0x30, 0x34, 0x38):
        c.emu.w32(grp + o, rf(c, -50, 50))
    c.emu.w32(grp + 0x4c, rf(c, 0, 100))
    c.emu.w32(t + 8, grp)
    c.emu.w32(t + 0x2707, pl)
    return [t, vec(c, -1, 1), vec(c), vec(c, -1, 1), vec(c)]


S(0x520450, 'ZTank::CheckPlayerCollision', 'thiscall', gen=g_cpc)


def g_oce(c):
    hookrec(c, 0x528100, 2, skip=(0,), peeks=((0, 0), (0, 4), (0, 8)))
    hookrec(c, 0x525380, 2)
    s = _rnd(c, 0x200)
    c.emu.w32(0x70039c, s)
    t = _rnd(c, 0x2800)
    c.emu.w8(t + 0x133, c.rng.choice([0, 1]))
    c.emu.w32(t + 0x382, (c.emu.r32(s + 0x40) + c.rng.randint(-5, 5)) & 0xffffffff)
    p = _rnd(c, 0x40)
    c.emu.w32(t + 0x5c, p)
    return [t]


S(0x5212f0, 'ZTank::OnCameraEnter', 'thiscall', gen=g_oce)
