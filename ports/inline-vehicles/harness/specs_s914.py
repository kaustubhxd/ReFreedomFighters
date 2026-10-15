"""specs_s914.py - vehicles batch 914: ZTank cannon, machine gun, turret."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, fconst
from specs_s905 import weapon

PT = [(0, 'd'), (4, 'd'), (8, 'd')]


def vec(c, lo=-100, hi=100):
    v = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(v + 4 * k, rf(c, lo, hi))
    return v


S(0x4ddfa0, 'vector remove component along n', 'fastcall', gen=lambda c: [vec(c), vec(c, -1, 1)])


def sysw(c):
    s = _rnd(c, 0x200)
    c.emu.w32(s + 0x48, rf(c, 0, 0.1))
    c.emu.w32(s + 0x20, rf(c, 0, 0.1))
    node = _rnd(c, 0x90)
    c.emu.w32(s + 0x9b, obj(c, 0x40, {0x60: idstub(c, [c.rng.choice([0, node]), node, 0, node])}))
    c.emu.w32(0x70039c, s)


def tank(c, slots):
    t = obj(c, 0x2800, slots)
    for o in list(range(0x25e5, 0x2635, 4)) + [0x60, 0x64, 0x68, 0x6c, 0x70, 0x74, 0x78, 0x7c, 0x80,
                                                0x268d, 0x2691, 0x2618, 0x261c]:
        c.emu.w32(t + o, rf(c, -2, 2))
    c.emu.w32(t + 0x2618, rf(c, 0, 50))
    c.emu.w32(t + 0x261c, rf(c, 0, 50))
    for o in (0x2610, 0x260c, 0x2614, 0x2620):
        c.emu.w32(t + o, c.rng.choice([0, 1]))
    off = vec(c, -1, 1)
    tg = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),)),
                       0x90: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),))})
    c.emu.w32(tg + 8, _rnd(c, 0x48))
    c.emu.w32(t + 0x25d1, tg)
    c.emu.w32(t + 0x25e1, weapon(c))
    c.emu.w32(t + 0x25dd, weapon(c))
    return t


def g_cannon(c):
    sysw(c)
    return [tank(c, {0x384: _stub(c, 0)})]


S(0x521ab0, 'ZTank::UpdateCannon', 'thiscall', gen=g_cannon)


def g_mg(c):
    sysw(c)
    av = vec(c)
    t = tank(c, {0x308: _stub(c, 2, skip=(0,), fills=((0, av, 3),))})
    return [t]


S(0x521db0, 'ZTank::UpdateMachineGun', 'thiscall', gen=g_mg)


def g_wtd(c):
    off = vec(c, -1, 1)
    t = tank(c, {0x90: _stub(c, 1, adds=((0, off, 3),))})
    c.emu.w8(t + 0x260b, c.rng.choice([0, 1]))
    p = _rnd(c, 0x40)
    c.emu.w32(p + 0x24, rf(c, 0, 300))
    c.emu.w32(t + 0x5c, p)
    if c.rng.random() < 0.2:
        c.emu.w32(t + 0x25d1, 0)
    return [t]


S(0x5216a0, 'ZTank wanted turret dir (inferred)', 'thiscall', gen=g_wtd)


def g_utd(c):
    sysw(c)
    off = vec(c, -1, 1)
    av = vec(c)
    t = tank(c, {0x308: _stub(c, 2, fills=((0, av, 3),)), 0x90: _stub(c, 1, adds=((0, off, 3),)),
                 0x2e8: _stub(c, 1, ret=c.rng.choice([0, 1, 2])), 0x2ec: _stub(c, 1)})
    c.emu.w8(t + 0x260b, c.rng.choice([0, 1]))
    p = _rnd(c, 0x40)
    c.emu.w32(p + 0x24, rf(c, 0, 300))
    c.emu.w32(t + 0x5c, p)
    dv = vec(c, -1, 1)
    vt = c.emu.alloc(0x20, 4)
    c.emu.w32(vt + 8, _stub(c, 1, fills=((0, dv, 3),)))
    c.emu.w32(vt + 0xc, _stub(c, 0, ret=c.rng.choice([0, 1])))
    c.emu.w32(vt + 4, _stub(c, 2))
    c.emu.w32(t + 0x263c, vt)
    vt2 = c.emu.alloc(0x20, 4)
    c.emu.w32(vt2 + 0x18, _stub(c, 0, fld=fconst(c, c.rng.uniform(0, 1))))
    c.emu.w32(t + 0x2664, vt2)
    for o in (0x26fe, 0x2702):
        c.emu.w32(t + o, rf(c, 0, 0.3))
    c.emu.w32(t + 0x26fa, c.rng.choice([0, 1, 2]))
    return [t]


S(0x522520, 'ZTank::UpdateTurretDir', 'thiscall', gen=g_utd)
