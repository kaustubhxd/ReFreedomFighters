"""specs_s500.py - weapons batch 500: ZItemWeapon accessors."""
from pilot import S
from wkit import rnd, stub, obj, b, fedge, sysobj, vec


def _w(c, extra=None):
    """A ZItemWeapon-shaped object (0x100 random bytes) with a fake vtable."""
    r = c.rng
    slots = {0x35c: stub(c, 0, ret=r.choice((0, 0, 1, 5, 30, r.getrandbits(32))))}
    if extra:
        slots.update(extra)
    o = obj(c, 0x100, slots)
    return o


def _plain(c):
    return [_w(c)]


def _plain_u(c):
    return [_w(c), c.rng.getrandbits(32)]


def _setchamber(c):
    return [_w(c), b(c, 0.5)]


def _ppm(c):
    r = c.rng
    ammo = obj(c, 0x20, {0x31c: stub(c, 0, ret=r.choice((0, 30, 0xffffffff, r.getrandbits(32))))})
    tmpl = obj(c, 0x20, {0x354: stub(c, 0, ret=r.choice((0, 0, 8, r.getrandbits(32))))})
    w = _w(c, {0x350: stub(c, 0, ret=tmpl), 0x328: stub(c, 0, ret=ammo if r.random() < 0.7 else 0)})
    c.emu.w32(w + 0x60, 0 if r.random() < 0.2 else r.getrandbits(32))
    return [w]


def _wt(c):
    return [_w(c, {0x2e8: stub(c, 0, ret=c.rng.getrandbits(32))})]


def _rm(c):
    r = c.rng
    sysobj(c, {0x58: stub(c, 1, ret=r.getrandbits(32)), 0x4c: stub(c, 1, ret=r.getrandbits(32))})
    return _w(c)


def _gat(c):
    return [_rm(c)]


def _sat(c):
    w = _rm(c)
    return [w, c.rng.getrandbits(32)]


def _settarget(c):
    return [_w(c), vec(c, 3, -100.0, 100.0)]


def _gettarget(c):
    w = _w(c)
    for j in range(3):
        c.emu.wf32(w + 0xaa + 4 * j, fedge(c) if c.rng.random() < 0.7 else 0.0)
    out = rnd(c, 0x18)
    return [w, out]


def _sno(c):
    r = c.rng
    tmpl = obj(c, 0x20, {0x358: stub(c, 1, ret=r.getrandbits(32))})
    return [_w(c, {0x350: stub(c, 0, ret=tmpl)})]


def _fireend(c):
    w = _w(c)
    if c.rng.random() < 0.5:
        c.emu.w32(w + 0xba, 0)
    return [w]


S(0x46e570, 'ZItemWeapon::GetBulletInChamber', 'thiscall', None, ret='al', gen=_plain)
S(0x470c50, 'ZItemWeapon::SetBulletInChamber', 'thiscall', None, ret=None, gen=_setchamber)
S(0x46eda0, 'ZItemWeapon::GetProjectilesInMagazine', 'thiscall', None, ret='eax', gen=_plain)
S(0x4711e0, 'ZItemWeapon::SetProjectilesInMagazine', 'thiscall', None, ret=None, gen=_plain_u)
S(0x46edb0, 'ZItemWeapon::GetProjectilesPerMagazine', 'thiscall', None, ret='eax', gen=_ppm)
S(0x46efc0, 'ZItemWeapon::GetWeaponTemplate', 'thiscall', None, ret='eax', gen=_wt)
S(0x46e450, 'ZItemWeapon::GetAmmoTemplate', 'thiscall', None, ret='eax', gen=_gat)
S(0x470c20, 'ZItemWeapon::SetAmmoTemplate', 'thiscall', None, ret=None, gen=_sat)
S(0x46efa0, 'ZItemWeapon::GetWeaponOperation', 'thiscall', None, ret='eax', gen=_plain)
S(0x471670, 'ZItemWeapon::SetWeaponOperation', 'thiscall', None, ret=None, gen=_plain_u)
S(0x471850, 'ZItemWeapon::Target', 'thiscall', None, ret='eax', gen=_plain)
S(0x471640, 'ZItemWeapon::SetTarget', 'thiscall', None, ret=None, gen=_settarget)
S(0x46eef0, 'ZItemWeapon::GetTarget', 'thiscall', None, ret='al', gen=_gettarget)
S(0x470bf0, 'ZItemWeapon::SelectNextWeaponOperation', 'thiscall', None, ret=None, gen=_sno)
S(0x46d8c0, 'ZItemWeapon::FireEnd', 'thiscall', None, ret=None, gen=_fireend)
