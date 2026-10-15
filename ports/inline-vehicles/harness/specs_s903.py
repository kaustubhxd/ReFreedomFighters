"""specs_s903.py - vehicles batch 903: pull leaves, damper ground probe and init, wheel limits, damper placement."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf


def blk(c, n, floats=()):
    o = _rnd(c, n)
    for off in floats:
        c.emu.w32(o + off, rf(c))
    return o


S(0x5243f0, 'CPullToValueAccel set value (inferred)', 'thiscall', gen=lambda c: [_rnd(c, 0x20), rf(c)])
S(0x5243d0, 'CPullToValueAccel set +0xc (inferred)', 'thiscall', gen=lambda c: [_rnd(c, 0x20), rf(c)])
S(0x524390, 'CPullToValueAccel::Acc', 'thiscall', ret='st0', gen=lambda c: [blk(c, 0x20, (0xc,))])


def g_inv(c):
    o = blk(c, 0x20, (0x10,))
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0x10, rf(c, 0, 1e-3))
    return [o]


S(0x5243a0, 'CPullToValueAccel inverse (inferred)', 'thiscall', ret='st0', gen=g_inv)


def g_dist(init):
    def g(c):
        o = _rnd(c, 0x40)
        a, b = blk(c, 4, (0,)), blk(c, 4, (0,))
        if init:
            return [o, a, b]
        c.emu.w32(o + 0x18, a)
        c.emu.w32(o + 0x1c, b)
        return [o]
    return g


S(0x524980, 'distance tracker init (inferred)', 'thiscall', gen=g_dist(True))
S(0x5247e0, 'distance tracker update (inferred)', 'thiscall', gen=g_dist(False))


def world(c):
    """engine object with +0x9b -> block whose +0xadc is a line-query object (slot 0x2e0 stub)."""
    s = _rnd(c, 0x200)
    p = _rnd(c, 0xb00)
    q = obj(c, 0x40, {0x2e0: _stub(c, 6, ret=c.rng.getrandbits(8))})
    c.emu.w32(p + 0xadc, q)
    c.emu.w32(s + 0x9b, p)
    c.emu.w32(0x70039c, s)


DAMPER_F = (0, 4, 8, 0x11, 0x2d, 0x35, 0x41, 0x45, 0x4d, 0x51, 0x55, 0x59, 0x65, 0x95)


def damper(c, o=None):
    if o is None:
        o = _rnd(c, 0x100)
    for off in DAMPER_F:
        c.emu.w32(o + off, rf(c, -100, 100))
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0x65, rf(c, 0, 0.01))
    return o


def g_ground(c):
    world(c)
    box = 0
    if c.rng.random() < 0.3:
        box = c.emu.alloc(0x200, 4)
        for k in range(0, 0x100, 4):
            if c.rng.random() < 0.5:
                c.emu.w32(box + k, rf(c, -100, 100))
    return [damper(c), rf(c), box]


S(0x516130, 'CDamper ground probe (inferred)', 'thiscall', ret='st0', gen=g_ground)


def g_init(c):
    world(c)
    p = blk(c, 12, (0, 4, 8))
    return [damper(c), p]


S(0x516360, 'CDamper::InitAtGround', 'thiscall', gen=g_init)
S(0x529ca0, 'CSteeringWheel::InitMinMax', 'thiscall', gen=lambda c: [blk(c, 0x80, (8, 0x44)), rf(c, 0, 4)])
S(0x529cd0, 'CWheel::InitMinMax', 'thiscall', gen=lambda c: [blk(c, 0x80, (8, 0x14)), rf(c, 0, 4)])


def uc(c, n1, n2):
    o = _rnd(c, 0x2400)
    c.emu.w32(o + n1, c.rng.randint(0, 4))
    c.emu.w32(o + n2, c.rng.randint(0, 4))
    return o


S(0x5255d0, 'CUnderCarriageCar::InitMinMaxForWheels', 'thiscall', gen=lambda c: [uc(c, 0x8c, 0x90)])
S(0x528090, 'CUnderCarriageTank::InitMinMaxForWheels', 'thiscall', gen=lambda c: [uc(c, 0x8d, 0x91)])


def g_gd(n1, n2, g, a1, s1, d1, a2, s2, d2):
    def gen(c):
        world(c)
        o = uc(c, n1, n2)
        off = c.emu.alloc(12, 4)
        for k in range(3):
            c.emu.w32(off + 4 * k, rf(c, -10, 10))
        grp = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), copy=(0, [(0, 'd'), (4, 'd'), (8, 'd')]), adds=((0, off, 3),))})
        c.emu.w32(o + g, grp)
        for cnt_off, a, s, d in ((n1, a1, s1, d1), (n2, a2, s2, d2)):
            for i in range(c.emu.r32(o + cnt_off)):
                for k in range(3):
                    c.emu.w32(o + a + i * s + 4 * k, rf(c, -100, 100))
                damper(c, o + d + i * 0xde)
        return [o]
    return gen


S(0x5254c0, 'CUnderCarriageCar::InitGlobalDamperPositions', 'thiscall',
  gen=g_gd(0x8c, 0x90, 0x88, 0x7c9, 0x163, 0xbd, 0xd55, 0x133, 0x435))
S(0x527f80, 'CUnderCarriageTank::InitGlobalDamperPositions', 'thiscall',
  gen=g_gd(0x8d, 0x91, 0x89, 0xe91, 0x133, 0x95, 0x1829, 0x133, 0x785))


def g_vsub(c):
    return [blk(c, 12, (0, 4, 8)), blk(c, 12, (0, 4, 8))]


S(0x43e960, 'vector a -= b (x87)', 'fastcall', gen=g_vsub)
