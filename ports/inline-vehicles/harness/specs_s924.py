"""specs_s924.py - vehicles batch 924: ZCar::SplineUpdate, ZCar::UpdateCarPos (callees stood in)."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, idstub, hookrec


def sysx(c):
    s = _rnd(c, 0x200)
    grp = _rnd(c, 0x40)
    c.emu.w32(grp + 0x3c, c.rng.choice([0, 0x1000, 0xffffffff]))
    g = _rnd(c, 0x20)
    c.emu.w32(g + 8, grp)
    c.emu.w32(s + 0x9b, obj(c, 0x40, {0x58: idstub(c, [c.rng.choice([0, g]), g, g, g])}))
    c.emu.w32(0x70039c, s)


def car(c, slots):
    o = obj(c, 0x1700, slots)
    p = _rnd(c, 0x60)
    for off in (8, 0xc, 0x10, 0x24, 0x28):
        c.emu.w32(p + off, rf(c))
    c.emu.w32(p + 0x39, c.rng.choice([0, 1]))
    c.emu.w32(o + 0x5c, p)
    for off in list(range(0x15d3, 0x1603, 4)) + list(range(0x60, 0x90, 4)):
        c.emu.w32(o + off, rf(c, -2, 2))
    c.emu.w32(o + 0x1650, c.rng.choice([0, 1, 2]))
    c.emu.w8(o + 0x1614, c.rng.choice([0, 1]))
    c.emu.w8(o + 0x133, c.rng.choice([0, 1]))
    c.emu.w32(o + 0x123, c.rng.choice([0, 1, 2]))
    return o


def g_su(c):
    sysx(c)
    for a in (0x515c70, 0x518bc0, 0x519280, 0x518960):
        hookrec(c, a, 0)
    hookrec(c, 0x5251c0, 8)
    return [car(c, {0x80: _stub(c, 2), 0x7c: _stub(c, 2), 0x78: _stub(c, 1)})]


S(0x518850, 'ZCar::SplineUpdate', 'thiscall', gen=g_su)


def g_ucp(c):
    sysx(c)
    pv = c.emu.alloc(24, 4)
    for k in range(6):
        c.emu.w32(pv + 4 * k, rf(c))
    for a in (0x518380, 0x518190):
        # fill pos and dir outputs from pv, record the target values
        def mk(a=a):
            from vh import hookrec as _h
            return _h(c, a, 4, skip=(0, 1, 2), peeks=((0, 0), (0, 4), (0, 8)))
        mk()
    hookrec(c, 0x5251c0, 8, skip=(0, 1, 2), peeks=((2, 0), (2, 4), (2, 8)))
    hookrec(c, 0x5172e0, 4, skip=(2, 3))
    return [car(c, {0x7c: _stub(c, 2, skip=(0, 1))})]


S(0x518960, 'ZCar::UpdateCarPos', 'thiscall', gen=g_ucp)
