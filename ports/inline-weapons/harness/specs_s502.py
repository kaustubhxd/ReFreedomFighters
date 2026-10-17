"""specs_s502.py - weapons batch 502: ZItemWeapon fire/reload/chamber steps, reload sound, sound fade."""
from pilot import S
from wkit import rnd, stub, obj, b, sysobj, patch_jmp, fedge


def _ticks(c, so):
    c.emu.w32(so + 0x40, c.rng.choice((0, 1024, c.rng.randint(0, 1 << 22), c.rng.getrandbits(32))))


def _setstate(c):
    patch_jmp(c, 0x4711f0, stub(c, 2, rec_ecx=True, ret=c.rng.getrandbits(32)))


def _fade(c):
    r = c.rng
    sysobj(c, {})
    _ticks(c, c.emu.r32(0x70039c))
    s = rnd(c, 0x100)
    c.emu.wf32(s + 0x88, fedge(c))
    from pe_emu import F
    d = r.choice((0.0, -0.0, 0.5, -2.0, 1e9, float('nan'), r.uniform(-10, 10)))
    t = r.choice((0.0, -0.0, 0.3, 1.0, float('inf'), float('nan'), r.uniform(-10, 10)))
    return [s, F(d), F(t)]


def _psr(c):
    r = c.rng
    sysobj(c, {0x60: stub(c, 1, ret=0 if r.random() < 0.2 else rnd(c, 0x100))})
    _ticks(c, c.emu.r32(0x70039c))
    w = obj(c, 0x200, {0x304: stub(c, 1, ret=r.getrandbits(32))})
    for off in (0x96, 0x9a):
        if r.random() < 0.3:
            c.emu.w32(w + off, 0)
    return [w]


def _chamber(c):
    r = c.rng
    _setstate(c)
    w = obj(c, 0x200, {0x35c: stub(c, 0, ret=r.choice((0, 0, 1, r.getrandbits(32)))), 0x374: stub(c, 0)})
    return [w]


def _tmpl(c):
    r = c.rng
    tbs = r.choice((0.1, 0.0, 0.25, 1e-40, -0.5, 3e38, float('nan'), r.uniform(0, 2)))
    return obj(c, 0x40, {0x338: stub(c, 0, fldv=tbs), 0x328: stub(c, 0, ret=b(c, 0.3))})


def _reloadend(c):
    so_rm = sysobj(c, {})
    _ticks(c, c.emu.r32(0x70039c))
    w = obj(c, 0x200, {0x358: stub(c, 1), 0x350: stub(c, 0, ret=_tmpl(c))})
    return [w]


def _ready(c):
    r = c.rng
    sysobj(c, {})
    so = c.emu.r32(0x70039c)
    now = r.randint(0, 1 << 20)
    c.emu.w32(so + 0x40, now if r.random() < 0.8 else r.getrandbits(32))
    w = obj(c, 0x200, {0x350: stub(c, 0, ret=_tmpl(c))})
    c.emu.w8(w + 0xbf, 0 if r.random() < 0.25 else r.randint(1, 255))
    x = r.random()
    if x < 0.3:   # exactly on the boundary: (tbs + t) * 1024 == now, with tbs a multiple of 1/1024
        tbs = r.choice((0.0, 0.25, 0.125, 1.0))
        c.emu.w32(w + 0x350 - 0x350, c.emu.r32(w))   # (vtable unchanged)
        t = obj(c, 0x40, {0x338: stub(c, 0, fldv=tbs), 0x328: stub(c, 0, ret=1)})
        c.emu.w32(c.emu.r32(w) + 0x350, stub(c, 0, ret=t))
        c.emu.wf32(w + 0xd1, (now + r.randint(-1, 1)) / 1024.0 - tbs)
    elif x < 0.6:   # next-shot time around now, in 1/1024 s steps
        c.emu.wf32(w + 0xd1, (now + r.randint(-300, 50)) / 1024.0)
    else:
        c.emu.wf32(w + 0xd1, fedge(c))
    return [w]


def _logger(c, n):
    s = obj(c, 0x40, {0x30: stub(c, n, cdecl=True)})
    l = obj(c, 0x10, {0x20: stub(c, 2, ret=s)})
    c.emu.w32(0x700390, l)


def _firestart(c):
    r = c.rng
    _logger(c, 3)
    w = obj(c, 0x200, {0x328: stub(c, 0, ret=0 if r.random() < 0.15 else r.getrandbits(32)),
                       0x110: stub(c, 2), 0x160: stub(c, 0), 0x304: stub(c, 1, ret=r.getrandbits(32))})
    if r.random() < 0.5:
        c.emu.w32(w + 4, 0)
    c.emu.w32(w + 0xd5, r.choice((0, 1, 2, 3, 4, r.getrandbits(32))))
    c.emu.w32(w + 0xba, r.choice((0, 1, 2, 3, 30, -1 & 0xffffffff, r.getrandbits(32))))
    c.emu.w32(w + 0xc4, r.choice((0, 5, r.getrandbits(32))))
    c.emu.w8(w + 0xbf, 0 if r.random() < 0.3 else r.randint(1, 255))
    return [w]


def _geom(c):
    r = c.rng
    g = obj(c, 0x40, {0x128: stub(c, 3), 0x2c: stub(c, 0)})
    gg = rnd(c, 0x40)
    c.emu.w32(g + 8, gg)
    return g


def _reloadstart(c):
    r = c.rng
    _setstate(c)
    g1 = 0 if r.random() < 0.2 else _geom(c)
    g2 = 0 if r.random() < 0.2 else _geom(c)
    h1, h2 = r.getrandbits(32), r.getrandbits(32)
    rm = sysobj(c, {0x58: stub(c, 1, ret=g1)})
    # two different resolves: a stub that answers g1 for h1 and g2 otherwise is overkill; use call order instead
    from wkit import seq_stub
    c.emu.w32(c.emu.r32(rm) + 0x58, seq_stub(c, 1, [g1, g2]))
    owner = 0 if r.random() < 0.3 else obj(c, 0x40, {0x1e0: stub(c, 1, ret=b(c, 0.4)),
                                                     0x420: stub(c, 0, ret=r.choice((0, r.getrandbits(32))))})
    w = obj(c, 0x200, {0x2f4: stub(c, 0, ret=owner), 0x374: stub(c, 0)})
    c.emu.w32(w + 0xfd, h1)
    c.emu.w32(w + 0x101, h2)
    return [w]


S(0x46b440, 'sound fade-out (guess)', 'thiscall', None, ret=None, gen=_fade)
S(0x470250, 'ZItemWeapon::PlaySound_Reload', 'thiscall', None, ret=None, gen=_psr)
S(0x46b730, 'ZItemWeapon::ChamberStart', 'thiscall', None, ret=None, gen=_chamber)
S(0x46b700, 'ZItemWeapon::ChamberEnd', 'thiscall', None, ret=None, gen=_chamber)
S(0x4703b0, 'ZItemWeapon::ReloadEnd', 'thiscall', None, ret=None, gen=_reloadend)
S(0x471ad0, 'ZItemWeapon::WeaponReady', 'thiscall', None, ret='al', gen=_ready)
S(0x46e2d0, 'ZItemWeapon::FireStart', 'thiscall', None, ret=None, gen=_firestart)
S(0x470420, 'ZItemWeapon::ReloadStart', 'thiscall', None, ret=None, gen=_reloadstart)
