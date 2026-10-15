"""specs_s913.py - vehicles batch 913: ZTank leaves."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, hookrec

PT = [(0, 'd'), (4, 'd'), (8, 'd')]


def vec(c, lo=-100, hi=100, zero=0.0):
    v = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(v + 4 * k, 0 if c.rng.random() < zero else rf(c, lo, hi))
    return v


def tank(c, slots=None):
    return obj(c, 0x2800, slots)


def g_stc(c):
    t = tank(c)
    c.emu.w8(t + 0x260b, c.rng.choice([0, 1]))
    return [t, c.rng.choice([0, r32(c)]), r32(c)]


S(0x521780, 'ZTank::SetTargetCannon', 'thiscall', gen=g_stc)
S(0x5217c0, 'ZTank::SetTargetMachineGun', 'thiscall',
  gen=lambda c: [tank(c, {0x310: _stub(c, 1, ret=c.rng.getrandbits(8) & c.rng.choice([0, 1]))}), r32(c)])


def g_ttv(c):
    t = tank(c)
    p = _rnd(c, 0x40)
    c.emu.w32(p + 0x24, rf(c, 0, 100))
    c.emu.w32(t + 0x5c, p)
    vt = c.emu.alloc(8, 4)
    c.emu.w32(vt, _stub(c, 3))
    c.emu.w32(t + 0x2695, vt)
    return [t, vec(c)]


S(0x521a40, 'ZTank::TurnToDir(const float*)', 'thiscall', gen=g_ttv)


def world(c, table):
    s = _rnd(c, 0x1b00)
    c.emu.w32(s + 0x9b, obj(c, 0x40, {0x58: idstub(c, table)}))
    c.emu.w32(0x70039c, s)
    return s


def g_tti(c):
    g = obj(c, 0x40)
    tv = vec(c)
    c.emu.w32(c.emu.r32(g) + 0x84, _stub(c, 1, skip=(0,), fills=((0, tv, 3),)))
    world(c, [g] * 4)
    t = tank(c, {0x378: _stub(c, 1, skip=(0,), copy=(0, PT))})
    return [t, c.rng.choice([0, 1, 2])]


S(0x5219c0, 'ZTank::TurnToDir(unsigned int)', 'thiscall', gen=g_tti)


def g_ss(c):
    hookrec(c, 0x5145e0, 0)
    t = tank(c, {0x2ec: _stub(c, 1)})
    for o in (0x26fa, 0x26ea):
        c.emu.w32(t + o, c.rng.choice([0, r32(c)]))
    return [t]


S(0x521970, 'ZTank::StopSounds', 'thiscall', gen=g_ss)


def g_is(c):
    hookrec(c, 0x513190, 0)
    s = world(c, [0])
    c.emu.w32(s + 0x1a9f, c.rng.choice([0, obj(c, 0x10, {0x60: _stub(c, 2, ret=r32(c))})]))
    return [tank(c)]


S(0x520d90, 'ZTank::InitSound', 'thiscall', gen=g_is)
S(0x521600, 'ZTank::SetNextDir', 'thiscall', gen=lambda c: [tank(c), vec(c, zero=0.3)])


def g_unca(c):
    t = tank(c)
    off = vec(c, -5, 5)
    c.emu.w32(t + 0x25d1, obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), copy=(0, PT), adds=((0, off, 3),))}))
    for o in (0x25e5, 0x25e9, 0x25ed, 0x25fd, 0x2601, 0x2605, 0x78, 0x7c, 0x80):
        c.emu.w32(t + o, rf(c))
    c.emu.w32(t + 0x2610, c.rng.choice([0, 1]))
    return [t]


S(0x521ed0, 'ZTank::UpdateNextCannonAngle', 'thiscall', gen=g_unca)
