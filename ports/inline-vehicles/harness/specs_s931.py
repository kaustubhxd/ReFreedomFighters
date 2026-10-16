"""specs_s931.py - vehicles batch 931: ZVehicle helpers, CMoveAlongPath::GetPosDir / Continue."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, hookrec, fconst
import specs_s907 as b907

PT = [(0, 'd'), (4, 'd'), (8, 'd')]


def path(c):
    p = b907.path(c)
    vt = c.emu.alloc(0x40, 4)
    for off, lo, hi in ((0xc, 0, 1), (0x10, 100, 5000), (0x14, -1, 1)):
        c.emu.w32(vt + off, _stub(c, 0, fld=fconst(c, c.rng.uniform(lo, hi))))
    c.emu.w32(vt + 8, _stub(c, 2))
    c.emu.w32(p, vt)
    for off in (0x24, 0x57, 0x5b, 0x5f):
        c.emu.w32(p + off, rf(c, 0, 200))
    c.emu.w32(p + 0x35, c.rng.choice([0, 1, 4]))
    c.emu.w32(p + 0x39, c.rng.choice([0, 1, 2]))
    c.emu.w8(p + 0x46, c.rng.choice([0, 1]))
    return p


S(0x523470, 'CMoveAlongPath::GetPosDir', 'thiscall',
  gen=lambda c: [b907.path(c), c.emu.alloc(12, 4), c.emu.alloc(12, 4), rf(c, -0.5, 1.5)])
S(0x523180, 'CMoveAlongPath::Continue', 'thiscall', gen=lambda c: [path(c)])


def veh(c, slots=None):
    v = obj(c, 0x400, slots)
    c.emu.w32(v + 0x5c, path(c))
    for off in (0x22f, 0x267, 0x223, 0xc0, 0x233):
        c.emu.w32(v + off, rf(c, 0, 300))
    c.emu.w32(v + 0x233, c.rng.choice([0, rf(c, 0, 1)]))
    return v


S(0x5157d0, 'ZVehicle::CreateFrontOfVehicleSystem', 'thiscall', gen=lambda c: [veh(c)])
S(0x515850, 'ZVehicle::CreateWarnSystem', 'thiscall', gen=lambda c: [veh(c, {0x80: _stub(c, 2)})])


def g_front(c):
    off = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(off + 4 * k, rf(c, -500, 500))
    return [veh(c, {0x84: _stub(c, 1, adds=((0, off, 3),))})]


S(0x514c70, 'ZVehicle::CalcVehicleFront', 'thiscall', gen=g_front)
S(0x515950, 'ZVehicle keep path going (inferred)', 'thiscall', gen=lambda c: [veh(c)])


def g_aif(c):
    for a in (0x515850, 0x5157d0, 0x514c70):
        hookrec(c, a, 0)
    hookrec(c, 0x514cf0, 0, ret=1)
    g = _rnd(c, 0x600)
    n = c.rng.choice([0, 1, 3, 25])
    c.emu.w32(g + 0x4b0, n)
    for i in range(min(n, 30)):
        a = _rnd(c, 0x10)
        geo = obj(c, 0x40, {0x630: _stub(c, 1)})
        c.emu.w32(a + 4, geo)
        c.emu.w32(g + 0x4b4 + 4 * i, a)
    c.emu.w32(0x7003b8, g)
    v = veh(c)
    c.emu.w8(v + 0x21a, c.rng.choice([0, 1, 1]))
    c.emu.w32(v + 0x2a7, c.rng.randint(0, max(n, 1) - 1))
    return [v]


S(0x515d00, 'ZVehicle::UpdateActorInFront', 'thiscall', gen=g_aif)


def g_su(c):
    s = _rnd(c, 0x200)
    grp = _rnd(c, 0x40)
    c.emu.w32(grp + 0x3c, c.rng.choice([0, 0x1000]))
    g = _rnd(c, 0x20)
    c.emu.w32(g + 8, grp)
    c.emu.w32(s + 0x9b, obj(c, 0x40, {0x58: idstub(c, [0, g, g, g])}))
    c.emu.w32(s + 0x48, rf(c, 0, 0.1))
    c.emu.w32(0x70039c, s)
    for a in (0x515950, 0x515d00, 0x523180):
        hookrec(c, a, 0)
    v = veh(c)
    c.emu.w8(v + 0x133, c.rng.choice([0, 0, 1]))
    c.emu.w32(v + 0x123, c.rng.randint(0, 3))
    return [v]


S(0x515c70, 'ZVehicle::SplineUpdate', 'thiscall', gen=g_su)

HIT = [(0, 'd'), (4, 'd'), (8, 'd'), (0x10, 'd'), (0x14, 'd'), (0x18, 'd'), (0x28, 'd')]


def g_hit(c):
    s = _rnd(c, 0x200)
    wpn = obj(c, 0x40, {0x330: _stub(c, 0, ret=c.rng.choice([7, 7, 4]))})
    c.emu.w32(s + 0x9b, obj(c, 0x40, {0x58: idstub(c, [0, wpn, wpn, wpn])}))
    c.emu.w32(0x70039c, s)
    v = obj(c, 0x400, {0x130: _stub(c, 3, skip=(2,), copy=(2, HIT))})
    h = c.emu.alloc(0x20, 4)
    c.emu.w32(h, _rnd(c, 0x40))
    for k in (8, 0xc, 0x10):
        c.emu.w32(h + k, c.rng.randint(0, 3))
    return [v, h]


S(0x515ab0, 'ZVehicle::ProcessProjectileHit', 'thiscall', gen=g_hit)
