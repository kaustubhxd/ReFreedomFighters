"""specs_s933.py - vehicles batch 933: CPullToValueAccel (hull turner class). The debug print of SetParams is stood in
through the 0x700390 debug object (both runs)."""
from pilot import S, F
from vh import _rnd, _stub, obj, r32, rf, cstub


def pull(c):
    p = _rnd(c, 0x40)
    for off in (0x4, 0x8, 0xc, 0x10, 0x14, 0x1d, 0x21, 0x25):
        c.emu.wf32(p + off, c.rng.choice([0.0, rf(c, -3, 3) and c.rng.uniform(-3, 3)]))
    c.emu.w8(p + 0x18, c.rng.choice([0, 1]))
    c.emu.w8(p + 0x19, c.rng.choice([0, 2]))
    c.emu.w32(p + 0x14, c.rng.choice([0x3f800000, 0xbf800000, 0]))
    return p


def sysx(c):
    s = _rnd(c, 0x200)
    c.emu.wf32(s + 0x48, c.rng.uniform(0.0, 0.1))
    c.emu.w32(0x70039c, s)
    lg = obj(c, 0x40, {0x2c: cstub(c, 1)})
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: _stub(c, 2, ret=lg)}))


def g_sp(c):
    sysx(c)
    p = pull(c)
    z = c.rng.choice([0.0, c.rng.uniform(-1, 3)])
    return [p, F(z), F(c.rng.uniform(-1, 3)), F(c.rng.uniform(-1, 3))]


S(0x527270, 'CPullToValueAccel::SetParams', 'thiscall', gen=g_sp)


def g_ip(c):
    sysx(c)
    p = pull(c)
    return [p, F(c.rng.uniform(-3, 3)), F(c.rng.uniform(-3, 3)), F(c.rng.uniform(-3, 3))]


S(0x527060, 'CPullToValueAccel::InitPull', 'thiscall', ret='al', gen=g_ip)


def g_us(c):
    sysx(c)
    return [pull(c)]


S(0x527360, 'CPullToValueAccel::UpdateSpeed', 'thiscall', gen=g_us)
S(0x5272e0, 'CPullToValueAccel::UpdatePosition', 'thiscall', gen=lambda c: (sysx(c), [pull(c)])[1])
S(0x527250, 'CPullToValueAccel::SetDstVal', 'thiscall', gen=lambda c: [pull(c), F(c.rng.uniform(-3, 3))])
for a, n, rt in ((0x527030, 'GetDistToDest', 'st0'), (0x526fd0, 'CurVal', 'st0'), (0x526fe0, 'DstVal', 'st0'),
                 (0x5272d0, 'Spd', 'st0'), (0x527180, 'ReachedDstVal', 'al')):
    S(a, 'CPullToValueAccel::' + n, 'thiscall', ret=rt, gen=lambda c: [pull(c)])


def g_tur(c):
    sysx(c)
    t = _rnd(c, 0x40)
    c.emu.w32(t, 0x6a0ae8)
    inner = t + 0x28
    c.emu.w32(inner, 0x6a09ec)
    for off in (0x4, 0x8, 0xc, 0x10, 0x14, 0x1d, 0x21, 0x25):
        c.emu.wf32(inner + off, c.rng.uniform(-3, 3))
    c.emu.w8(inner + 0x18, 0)
    return [t, F(c.rng.uniform(-1, 3)), F(c.rng.uniform(-1, 3)), F(c.rng.uniform(-1, 3))]


S(0x527530, 'hull turner SetParams wrapper', 'thiscall', gen=g_tur)
