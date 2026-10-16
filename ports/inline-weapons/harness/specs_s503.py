"""specs_s503.py - weapons batch 503: weapon and ammo templates."""
from pilot import S
from pe_emu import F
from wkit import rnd, stub, obj, b, sysobj, fedge, seq_stub


def _logger(c, slot, n):
    s = obj(c, 0x40, {slot: stub(c, n, cdecl=True)})
    l = obj(c, 0x10, {0x20: stub(c, 2, ret=s)})
    c.emu.w32(0x700390, l)


def _t(c, extra=None):
    t = obj(c, 0x140, extra or {})
    for off in (0xa8, 0xac, 0xb0, 0xb4, 0xb8, 0xbc, 0xc0, 0x84, 0x88):
        if c.rng.random() < 0.7:
            c.emu.wf32(t + off, fedge(c))
    return t


def _plain(c):
    return [_t(c)]


def _res(c):
    r = c.rng
    sysobj(c, {0x58: stub(c, 1, ret=r.getrandbits(32))})
    return [_t(c)]


def _heavy(c):
    t = _t(c)
    c.emu.w32(t + 0x8c, c.rng.choice((0, 4, 5, 6, -1 & 0xffffffff, c.rng.getrandbits(32))))
    return [t]


def _pinst(c):
    r = c.rng
    g = obj(c, 0x40, {0x2c: stub(c, 0)})
    c.emu.w32(g + 8, rnd(c, 0x40))
    sysobj(c, {0x58: stub(c, 1, ret=g if r.random() < 0.97 else 0)})
    t = _t(c)
    n = r.randint(1, 5)
    arr = rnd(c, 4 * n)
    c.emu.w32(t + 0x98, arr)
    c.emu.w32(t + 0x9c, n)
    c.emu.w32(t + 0xa0, r.randint(0, n - 1))
    return [t]


def _gat(c):
    r = c.rng
    sysobj(c, {0x58: stub(c, 1, ret=r.getrandbits(32))})
    t = _t(c)
    c.emu.w32(t + 0xa0, obj(c, 0x10, {0x30: stub(c, 1, ret=r.getrandbits(32))}))
    return [t, r.choice((0, 1, r.getrandbits(32)))]


def _dist(c, t):
    r = c.rng
    x = r.random()
    n, f = c.emu.rf32(t + 0xb0), c.emu.rf32(t + 0xb4)
    if x < 0.4:
        lo, hi = sorted((r.uniform(0, 50), r.uniform(0, 100)))
        c.emu.wf32(t + 0xb0, lo)
        c.emu.wf32(t + 0xb4, hi)
        return r.choice((lo, hi, r.uniform(lo, hi), r.uniform(-10, 120)))
    return fedge(c)


def _impact(c):
    t = _t(c)
    return [t, 0, F(_dist(c, t))]


def _damage(c):
    r = c.rng
    _logger(c, 0x2c, 2)
    a = obj(c, 0x40, {0x324: stub(c, 0, fldv=fedge(c)), 0x328: stub(c, 0, fldv=fedge(c))})
    w = obj(c, 0x100, {0x328: stub(c, 0, ret=0 if r.random() < 0.15 else a)})
    t = _t(c)
    return [t, w, F(_dist(c, t))]


def _sno(c):
    r = c.rng
    _logger(c, 0x30, 3)
    mask = r.choice((0, 1, 2, 4, 8, 0xf, 0x5, 0xa, 0xc, 0x3, r.getrandbits(32) | 1))
    t = _t(c, {0x334: stub(c, 0, ret=mask)})
    if r.random() < 0.5:
        c.emu.w32(t + 4, 0)
    op = r.choice((0, 1, 2, 3))
    if r.random() < 0.15:
        big = r.randint(4, 300)
        if (mask >> (big & 31)) & 1:
            op = big
    return [t, op]


def _flash(c):
    r = c.rng
    _logger(c, 0x30, 3)
    g = obj(c, 0x40, {0x25c: stub(c, 2, ret=0 if r.random() < 0.3 else r.getrandbits(32))})
    ci = rnd(c, 0x40)
    v = r.getrandbits(32)
    c.emu.w32(ci + 0x23, v | 0x100000 if r.random() < 0.7 else v & ~0x100000)
    c.emu.w32(g + 0xc, ci)
    if r.random() < 0.3:
        c.emu.w32(g + 4, 0)
    sysobj(c, {0x58: stub(c, 1, ret=g if r.random() < 0.85 else 0)})
    return [_t(c)]


for a, n, ret in ((0x46b6e0, 'ZItemTemplateWeapon::CanFireProjectiles', 'al'),
                  (0x46b6f0, 'ZItemTemplateWeapon::CanHaveMagazines', 'al'),
                  (0x46e6a0, 'ZItemTemplateWeapon::GetDefaultProjectilesPerMagazine', 'eax'),
                  (0x46e6c0, 'ZItemTemplateWeapon::GetFarRange', 'st0'),
                  (0x46ecd0, 'ZItemTemplateWeapon::GetMuzzleVelocity', 'st0'),
                  (0x46ecf0, 'ZItemTemplateWeapon::GetNearRange', 'st0'),
                  (0x46ed10, 'ZItemTemplateWeapon::GetPitchChange', 'eax'),
                  (0x46ed20, 'ZItemTemplateWeapon::GetPrecisionDegrees', 'st0'),
                  (0x46eec0, 'ZItemTemplateWeapon::GetSoundSet', 'eax'),
                  (0x46ef60, 'ZItemTemplateWeapon::GetTimeBetweenShots', 'st0'),
                  (0x46efb0, 'ZItemTemplateWeapon::GetWeaponParts', 'eax'),
                  (0x46efd0, 'ZItemTemplateWeapon::GetWeaponType', 'eax'),
                  (0x46efe0, 'ZItemTemplateWeapon::HasSniperMode', 'al'),
                  (0x46e730, 'ZItemTemplateWeapon::GetItemClassName', 'eax'),
                  (0x46e690, 'ZItemTemplateAmmo::GetDefaultProjectilesPerMagazine', 'eax'),
                  (0x46e6b0, 'ZItemTemplateAmmo::GetFarDamage', 'st0'),
                  (0x46ece0, 'ZItemTemplateAmmo::GetNearDamage', 'st0'),
                  (0x46ee00, 'ZItemTemplateAmmo::GetProjectilesPerShot', 'eax'),
                  (0x46e710, 'ZItemTemplateAmmo::GetItemClassName', 'eax'),
                  (0x46ee10, 'ZItemTemplateWeapon::GetRecoil', 'st0')):
    S(a, n, 'thiscall', None, ret=ret, gen=_plain)
S(0x46f500, 'ZItemTemplateAmmo::IsHeavyCaliber', 'thiscall', None, ret='al', gen=_heavy)
S(0x46e590, 'ZItemTemplateAmmo::GetCartridge', 'thiscall', None, ret='eax', gen=_res)
S(0x46ed30, 'ZItemTemplateAmmo::GetProjectile', 'thiscall', None, ret='eax', gen=_res)
S(0x46ed50, 'ZItemTemplateAmmo::GetProjectileInstance', 'thiscall', None, ret='eax', gen=_pinst)
S(0x46e410, 'ZItemTemplateWeapon::GetAmmoTemplate(int)', 'thiscall', None, ret='eax', gen=_gat)
S(0x46b5d0, 'ZItemTemplateWeapon::CalcImpact', 'thiscall', None, ret='st0', gen=_impact)
S(0x46b4c0, 'ZItemTemplateWeapon::CalcDamage', 'thiscall', None, ret='st0', gen=_damage)
S(0x470b00, 'ZItemTemplateWeapon::SelectNextWeaponOperation', 'thiscall', None, ret='eax', gen=_sno)
S(0x46eac0, 'ZItemTemplateWeapon::GetMuzzleFire', 'thiscall', None, ret='eax', gen=_flash)
S(0x46ec20, 'ZItemTemplateWeapon::GetMuzzleSmoke', 'thiscall', None, ret='eax', gen=_flash)
S(0x46e5b0, 'ZItemTemplateWeapon flash Smoke 2 (GetCartridge?)', 'thiscall', None, ret='eax', gen=_flash)
S(0x46eb70, 'ZItemTemplateWeapon::GetMuzzleLight', 'thiscall', None, ret='eax', gen=_flash)
