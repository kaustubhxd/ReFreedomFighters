"""specs_s905.py - vehicles batch 905: helicopter weapons."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, fconst

PT = [(0, 'd'), (4, 'd'), (8, 'd')]


def vec(c, lo=-100, hi=100):
    v = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(v + 4 * k, rf(c, lo, hi))
    return v


def weapon(c):
    """ZItemWeapon stand-in: random ammo / ready answers, geom at +8 with an x at +0x24."""
    w = obj(c, 0x40, {
        0x33c: _stub(c, 1), 0x35c: _stub(c, 0, ret=c.rng.choice([0, 0, 5])), 0x360: _stub(c, 1),
        0x354: _stub(c, 0, ret=c.rng.getrandbits(8) & c.rng.choice([0, 0xff])), 0x2d0: _stub(c, 2),
        0x32c: _stub(c, 1, skip=(0,), copy=(0, PT)),
    })
    g = _rnd(c, 0x48)
    c.emu.w32(g + 0x24, rf(c, -50, 50))
    c.emu.w32(w + 8, g)
    return w


S(0x4dcb50, 'ZBaseGeom::SetMatPosSimple', 'thiscall', gen=lambda c: [_rnd(c, 0x48), vec(c), vec(c)])


def g_uwfp(c):
    w = weapon(c) if c.rng.random() < 0.9 else 0
    return [_rnd(c, 0x10), w, vec(c), _rnd(c, 36), vec(c), r32(c), r32(c)]


S(0x514890, 'ZMoveOnSpline::UpdateWeaponFireAndPos', 'thiscall', gen=g_uwfp)
S(0x51e700, 'ZHeli::UpdateWeaponFire', 'thiscall', gen=lambda c: [_rnd(c, 0x10), weapon(c), r32(c), vec(c)])


def sysw(c, table):
    s = _rnd(c, 0x200)
    wd = obj(c, 0x40, {0x58: idstub(c, table)})
    c.emu.w32(s + 0x9b, wd)
    c.emu.w32(0x70039c, s)
    vt = c.emu.r32(s)
    return s


def g_aim(c):
    act = obj(c, 0x40, {0x1e0: _stub(c, 1, ret=c.rng.getrandbits(8))})
    s = sysw(c, [0, act, act, act])
    c.emu.w32(s, c.emu.alloc(0x200, 4))
    a = _rnd(c, 0x40)
    c.emu.w32(a + 0x30, rf(c, 0, 3))
    c.emu.w32(a + 0x34, rf(c, 0, 3))
    if c.rng.random() < 0.3:
        c.emu.w32(a, 5)
    return [a, c.rng.choice([5, 6, 7, 0, r32(c)])]


S(0x5138f0, 'AimControl::NewTarget', 'thiscall', gen=g_aim)
S(0x514480, 'AimControl::SetTarget', 'thiscall', gen=g_aim)


def g_st(c):
    a = g_aim(c)
    h = obj(c, 0x600, {0x310: _stub(c, 1, ret=c.rng.getrandbits(8) & c.rng.choice([0, 1]))})
    c.emu.wbytes(h + 0x59b, c.emu.rbytes(a[0], 0x40))
    return [h, a[1]]


S(0x51cfb0, 'ZHeli::SetTarget', 'thiscall', gen=g_st)


def g_hit(c):
    heli = obj(c, 0x600, {0x130: _stub(c, 3)})
    box = obj(c, 0x40, {0x8c: _stub(c, 1), 0x184: _stub(c, 1, ret=c.rng.getrandbits(8))})
    wpn = obj(c, 0x40, {0x330: _stub(c, 0, ret=c.rng.choice([4, 7, 4, 7, 3])), 0x32c: _stub(c, 0, ret=c.rng.getrandbits(8))})
    sysw(c, [c.rng.choice([0, heli, wpn]), heli, wpn, box])
    h = c.emu.alloc(0x20, 4)
    pr = _rnd(c, 0x40)
    c.emu.w32(h, pr)
    for k in (8, 0xc, 0x10):
        c.emu.w32(h + k, c.rng.randint(0, 3) if c.rng.random() < 0.8 else 2)
    c.emu.w32(h + 0x10, c.rng.choice([2, 2, 0, 1]))
    c.emu.w32(heli + 0x479, c.rng.choice([3, 3, 0]))
    return [heli, h]


S(0x51cae0, 'ZHeli::ProcessProjectileHit', 'thiscall', gen=g_hit)


def g_cannon(c):
    off = vec(c, -5, 5)
    dirv = vec(c, -1, 1)
    heli = obj(c, 0x600, {
        0x84: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),)),
        0x8c: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),)),
        0x90: _stub(c, 1, skip=(0,), fills=((0, dirv, 3),)),
        0x384: _stub(c, 3, skip=(2,), copy=(2, PT)),
    })
    tg = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), adds=((0, off, 3),))})
    s = sysw(c, [tg, tg, tg, tg])
    rv = fconst(c, c.rng.random())
    c.emu.w32(s, c.emu.r32(obj(c, 4, {0x1c0: _stub(c, 2, fld=rv)})))   # engine vtable with the random slot
    c.emu.w32(s + 0x40, c.rng.randint(0, 100000))
    for off_ in (0x216, 0x21a, 0x21e, 0x45d, 0x461, 0x465):
        c.emu.w32(heli + off_, rf(c))
    c.emu.w32(heli + 0x3fd, c.rng.choice([0, 1, 2]))
    c.emu.w32(heli + 0x405, weapon(c) if c.rng.random() < 0.5 else 0)
    c.emu.w32(heli + 0x409, 0)
    c.emu.w32(heli + 0x40d, 0)
    c.emu.w32(heli + 0x469, c.rng.choice([0, 1, 1, 1]))
    now = c.emu.r32(s + 0x40)
    for off_ in (0x46d, 0x471, 0x475):
        c.emu.wf32(heli + off_, (now + c.rng.randint(-300, 300)) / 1024.0)
    c.emu.w32(heli + 0x455, c.rng.randint(0, 4))
    c.emu.w32(heli + 0x459, c.rng.randint(0, 4))
    for base in (0x411, 0x425):
        for i in range(5):
            c.emu.w32(heli + base + 4 * i, weapon(c) if c.rng.random() < 0.7 else 0)
    for i in range(4):
        c.emu.w32(heli + 0x439 + 4 * i, weapon(c))
    if c.rng.random() < 0.2:
        c.emu.w32(heli + 0x439, 0)
    return [heli]


S(0x51d120, 'ZHeli::UpdateCannon', 'thiscall', gen=g_cannon)
