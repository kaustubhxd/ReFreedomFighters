"""specs_s900.py - vehicles batch 900: ZCar/ZTank/ZHeli setter leaves."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf


def plain(size, nargs):
    def g(c):
        return [obj(c, size)] + [r32(c) for _ in range(nargs)]
    return g


S(0x5186c0, 'ZCar::SetSkidPitch', 'thiscall', gen=plain(0x1700, 1))
S(0x518730, 'ZCar::SetStationary', 'thiscall', gen=plain(0x400, 1))
S(0x521760, 'ZTank::SetStationary', 'thiscall', gen=plain(0x2700, 1))
S(0x520d30, 'ZTank::FireCannon', 'thiscall', gen=plain(0x2700, 1))
S(0x51c520, 'ZHeli::Fire', 'thiscall', gen=plain(0x500, 1))
S(0x51cef0, 'ZHeli::SetJetSoundParams', 'thiscall', gen=plain(0x500, 2))


def g_mg(c):
    st = _stub(c, 1, ret=c.rng.getrandbits(32))
    return [obj(c, 0x2700, {0x310: st}), r32(c)]


S(0x520d50, 'ZTank::FireMachineGun', 'thiscall', gen=g_mg)


def g_start(c):
    st = _stub(c, 1, ret=r32(c))
    o = obj(c, 0x500, {0x2e8: st})
    if c.rng.random() < 0.5:
        c.emu.w32(o + 0x499, 0)
    return [o]


S(0x51d0d0, 'ZHeli::StartJetSound', 'thiscall', gen=g_start)


def g_stop(c):
    return [obj(c, 0x500, {0x2ec: _stub(c, 1)})]


S(0x51d100, 'ZHeli::StopJetSound', 'thiscall', gen=g_stop)


def g_imp(base, n1, n2, p1, s1, p2, s2):
    def g(c):
        s_ = c.emu.alloc(0x100, 4)
        c.emu.w32(s_ + 0x40, r32(c))
        c.emu.w32(0x70039c, s_)
        o = obj(c, base + 0x2400)
        u = o + base
        a, b = c.rng.randint(0, 3), c.rng.randint(0, 3)
        c.emu.w32(u + n1, a)
        c.emu.w32(u + n2, b)
        for cnt, p, st in ((a, p1, s1), (b, p2, s2)):
            for i in range(cnt):
                for k in range(3):
                    c.emu.w32(u + p + i * st + 4 * k, rf(c, -200, 200))
        d = c.emu.alloc(12, 4)
        for k in range(3):
            c.emu.w32(d + 4 * k, rf(c, -200, 200))
        return [o, rf(c, 0, 50), d]
    return g


S(0x5184d0, 'ZCar::ReceiveImpact', 'thiscall', gen=g_imp(0x2d8, 0x8c, 0x90, 0x7c9, 0x163, 0xd55, 0x133))
S(0x5213d0, 'ZTank::ReceiveImpact', 'thiscall', gen=g_imp(0x2fd, 0x8d, 0x91, 0xe91, 0x133, 0x1829, 0x133))
