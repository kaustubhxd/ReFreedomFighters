"""specs_s501.py - weapons batch 501: ZLNKWHANDS hand layer and ZItemAmmo counts."""
from pilot import S
from wkit import rnd, stub, obj, b, sysobj


def _logger(c, n=3):
    s = obj(c, 0x10, {0x2c: stub(c, n, cdecl=True)})
    l = obj(c, 0x10, {0x20: stub(c, 2, ret=s)})
    c.emu.w32(0x700390, l)


def _ammo(c):
    return [obj(c, 0x100, {}), c.rng.choice((0, 1, -1 & 0xffffffff, 30, c.rng.getrandbits(32)))]


def _ammo0(c):
    return [obj(c, 0x100, {})]


def _hands(c):
    """A ZLNKWHANDS object with right/left hand slot objects embedded at +0x34f / +0x2e7 (their own vtables)."""
    r = c.rng
    self = obj(c, 0x600, {})
    for off in (0x34f, 0x2e7):
        it = 0 if r.random() < 0.2 else obj(c, 0x40, {0x1e0: stub(c, 1, ret=b(c, 0.4))})
        vt = c.emu.alloc(0x20, 4)
        c.emu.w32(vt + 0x10, stub(c, 0, ret=it))
        c.emu.w32(vt + 0x14, stub(c, 0, ret=r.getrandbits(32)))
        c.emu.w32(self + off, vt)
    return self


def _hand(c):
    return [_hands(c)]


def _state(c):
    r = c.rng
    it = obj(c, 0x40, {0x2d0: stub(c, 2)})
    self = obj(c, 0x600, {0x504: stub(c, 0, ret=it if r.random() < 0.8 else 0),
                          0x500: stub(c, 0, ret=it if r.random() < 0.8 else 0)})
    return [self, r.getrandbits(32)]


def _tmpl(c, p_null=0.15):
    r = c.rng
    if r.random() < p_null:
        return 0
    return obj(c, 0x20, {0x328: stub(c, 0, ret=b(c, 0.3)), 0x340: stub(c, 1, ret=r.getrandbits(32))})


def _weapon(c, t):
    return obj(c, 0x100, {0x350: stub(c, 0, ret=t)})


def _ammo_item(c):
    r = c.rng
    if r.random() < 0.15:
        return 0
    return obj(c, 0x100, {0x1e0: stub(c, 1, ret=b(c, 0.25)), 0x320: stub(c, 0, ret=r.getrandbits(32))})


def _invammo(c):
    r = c.rng
    _logger(c, 2)
    a = _ammo_item(c)
    rm = sysobj(c, {0x58: stub(c, 1, ret=a)})
    inv = obj(c, 0x20, {0x98: stub(c, 2, ret=0 if r.random() < 0.15 else r.getrandbits(32))})
    self = obj(c, 0x600, {})
    c.emu.w32(self + 0x2e3, 0 if r.random() < 0.1 else inv)
    return [self, _weapon(c, _tmpl(c))]


def _ammofor(c):
    r = c.rng
    rm = sysobj(c, {})
    c.emu.w8(rm + 0xbac, 0 if r.random() < 0.8 else r.randint(1, 255))
    self = obj(c, 0x600, {0x55c: stub(c, 1, ret=_ammo_item(c))})
    return [self, _weapon(c, _tmpl(c))]


def _reload_self(c, item):
    r = c.rng
    sysobj(c, {0x4c: stub(c, 1, ret=r.getrandbits(32))})
    other = obj(c, 0x40, {})
    rh = item if r.random() < 0.45 else other
    lh = item if r.random() < 0.6 else other
    return obj(c, 0x600, {0x560: stub(c, 1, ret=r.choice((0, 0, 5, 999, r.getrandbits(32)))),
                          0x504: stub(c, 0, ret=rh), 0x500: stub(c, 0, ret=lh),
                          0x3f0: stub(c, 0, ret=r.choice((0, 0xc, 0xd, 0xe, 0xf, 2))),
                          0x45c: stub(c, 2)})


def _reload(c):
    item = obj(c, 0x40, {})
    return [_reload_self(c, item), item]


def _reloaditem(c):
    r = c.rng
    _logger(c)
    clip = r.choice((30, 8, 1, 0, -1 & 0xffffffff, r.getrandbits(32)))
    cur = r.choice((0, 3, 30, clip, r.getrandbits(32)))
    item = obj(c, 0x100, {0x364: stub(c, 0, ret=clip), 0x35c: stub(c, 0, ret=cur), 0x360: stub(c, 1),
                          0x358: stub(c, 1)})
    self = obj(c, 0x600, {0x560: stub(c, 1, ret=r.choice((0, 5, 999, 60, r.getrandbits(32)))), 0x564: stub(c, 2)})
    return [self, item]


S(0x46ed00, 'ZItemAmmo::GetNrProjectiles', 'thiscall', None, ret='eax', gen=_ammo0)
S(0x46ac30, 'ZItemAmmo::AddNrProjectiles', 'thiscall', None, ret=None, gen=_ammo)
S(0x4711d0, 'ZItemAmmo::SetNrProjectiles', 'thiscall', None, ret=None, gen=_ammo)
S(0x471840, 'ZItemAmmo::SubNrProjectiles', 'thiscall', None, ret=None, gen=_ammo)
S(0x474670, 'ZLNKWHANDS::GetRHandItem', 'thiscall', None, ret='eax', gen=_hand)
S(0x474680, 'ZLNKWHANDS::GetRHandItemType', 'thiscall', None, ret='eax', gen=_hand)
S(0x474450, 'ZLNKWHANDS::GetLHandItem', 'thiscall', None, ret='eax', gen=_hand)
S(0x474460, 'ZLNKWHANDS::GetLHandItemType', 'thiscall', None, ret='eax', gen=_hand)
S(0x474690, 'ZLNKWHANDS::GetRHandWeapon', 'thiscall', None, ret='eax', gen=_hand)
S(0x474470, 'ZLNKWHANDS::GetLHandWeapon', 'thiscall', None, ret='eax', gen=_hand)
S(0x4759f0, 'ZLNKWHANDS::SetRHandItemState', 'thiscall', None, ret=None, gen=_state)
S(0x475980, 'ZLNKWHANDS::SetLHandItemState', 'thiscall', None, ret=None, gen=_state)
S(0x474320, 'ZLNKWHANDS::GetInventoryAmmoFor', 'thiscall', None, ret='eax', gen=_invammo)
S(0x473fe0, 'ZLNKWHANDS::GetAmmoFor', 'thiscall', None, ret='eax', gen=_ammofor)
S(0x475010, 'ZLNKWHANDS::Reload', 'thiscall', None, ret=None, gen=_reload)
S(0x4728a0, 'ZLNKWHANDS::Chamber', 'thiscall', None, ret=None, gen=_reload)
S(0x4750b0, 'ZLNKWHANDS::ReloadItem', 'thiscall', None, ret=None, gen=_reloaditem)
