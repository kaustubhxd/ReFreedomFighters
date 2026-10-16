"""specs_s1303.py - inventory thread batch 1303 (src/batch1303.cpp): FF inventory model, HUD inventory text, profile
helpers, ZFFItemBomb::Init2, ZFFActionDropC4::Execute, CFFTools_if::GetHeroItem."""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039c


def _o(c, n=0x100):
    return rnd(c, n)


def _m0(c, p=0.25):
    return 0 if c.rng.random() < p else c.rng.getrandbits(32)


def _type(c):
    return c.rng.randrange(0, 20) if c.rng.random() < 0.9 else c.rng.getrandbits(32)


def count_get(c):
    return [_o(c, 0x20), _type(c)]


def count_set(c):
    return [_o(c, 0x20), _type(c), c.rng.choice([0, 1, 2, c.rng.getrandbits(32)])]


S(0x5af1d0, 'ZFFInventoryCount::GetNoOfItem', 'thiscall', None, ret='eax', gen=count_get, note='batch1303')
S(0x5af2a0, 'ZFFInventoryCount::SetNoOfItem', 'thiscall', None, ret=None, gen=count_set, note='batch1303')


def _info_list(c, n=None):
    n = c.rng.randrange(0, 9) if n is None else n
    lst = c.emu.alloc(4 + 4 * 24, 4)
    c.emu.wbytes(lst, bytes(c.rng.getrandbits(8) for _ in range(4 + 4 * 24)))
    c.emu.w32(lst, n)
    recs = []
    for i in range(n):
        rec = _o(c, 0x20)
        c.emu.w32(rec, c.rng.choice([0x1000, 0x2000, 0x3000, 0x4000]))
        c.emu.w32(rec + 0x10, c.rng.randrange(3, 17))
        c.emu.w32(lst + 4 + 4 * i, rec)
        recs.append(rec)
    return lst, recs


def info_by_t(c):
    lst, recs = _info_list(c)
    return [lst, c.rng.choice([0x1000, 0x2000, 0x3000, 0x4000, 0x5000])]


def info_ammo(c):
    lst, recs = _info_list(c)
    return [lst, c.rng.randrange(3, 18)]


def info_remove(c):
    lst, recs = _info_list(c)
    k = c.rng.random()
    v = 0 if k < 0.15 else (c.rng.choice(recs) if recs and k < 0.8 else c.rng.getrandbits(32))
    return [lst, v]


def add_unique(c):
    lst = _o(c, 4 + 4 * 24)
    n = c.rng.choice([0, 1, 5, 19, 20, 21, c.rng.randrange(0, 20)])
    c.emu.w32(lst, n)
    for i in range(min(n, 24)):
        c.emu.w32(lst + 4 + 4 * i, c.rng.randrange(0, 8))
    return [lst, c.rng.randrange(0, 10)]


S(0x5af0f0, 'ZFFInventoryInfoList::GetInventoryInfo(ZItemTemplate*)', 'thiscall', None, ret='eax', gen=info_by_t,
  note='batch1303')
S(0x5aef80, 'ZFFInventoryInfoList::GetAmmo', 'thiscall', None, ret='eax', gen=info_ammo, note='batch1303')
S(0x5af260, 'ZFFInventoryInfoList::RemoveInventoryInfo', 'thiscall', None, ret=None, gen=info_remove, note='batch1303')
S(0x5aedf0, 'type list add-unique (map: ZFFInventorySelector::AddAdditionalWeaponToList)', 'thiscall', None,
  ret=None, gen=add_unique, note='batch1303')
S(0x5af040, 'ZFFAddedWeaponsToRebelBase::GetIndex', 'thiscall', None, ret='eax', gen=count_get, note='batch1303')


def bridge_ammo(c):
    r = Rec(c)
    am = r.obj(0x20, {0x320: r.stub(3, 0, rand=True)})
    hero = r.obj(0x20, {0x55c: r.stub(2, 1, rets=[0 if c.rng.random() < 0.4 else am])})
    o = _o(c, 0x20)
    c.emu.w32(o, hero)
    item = r.obj(0x20, {0x35c: r.stub(1, 0, rand=True)})
    return [o, item]


S(0x5af300, 'ZFFInventoryBridge::GetAmmo', 'thiscall', None, ret='eax', gen=bridge_ammo, note='batch1303')


def _logger(c, r):
    pr = r.obj(0x20, {0x2c: r.stub(91, 2, pop=False, rand=True, log_ecx=False)})
    set_global(c, 0x700390, r.obj(0x40, {0x20: r.stub(90, 2, rets=[pr])}))


def bridge_set(c):
    r = Rec(c)
    _logger(c, r)
    hero = 0 if c.rng.random() < 0.2 else r.obj(0x20, {0x464: r.stub(1, 0, rets=[_m0(c, 0.3)])})
    return [_o(c, 0x20), hero, _m0(c, 0.2)]


S(0x5afbb0, 'ZFFInventoryBridge::SetData', 'thiscall', None, ret=None, gen=bridge_set, note='batch1303')


def ctl_ctor(c):
    r = Rec(c)
    r.hook(0x5aedb0, 1, 0, rand=True)
    r.hook(0x65e090, 2, 0, rand=True)
    r.hook(0x5af2a0, 3, 2, rand=True)
    return [_o(c, 0x40)]


S(0x5afc10, 'ZFFInventoryController::ZFFInventoryController', 'thiscall', None, ret='eax', gen=ctl_ctor,
  note='batch1303')


def ctl_max_ammo(c):
    r = Rec(c)
    rec = _o(c, 0x20)
    r.hook(0x5aeff0, 1, 1, rets=[_type(c)])
    r.hook(0x5af130, 2, 1, rets=[rec])
    r.hook(0x5af1d0, 3, 1, rand=True)
    return [_o(c, 0x40), c.rng.getrandbits(32)]


S(0x5afc70, 'ZFFInventoryController::GetMaxAmmo', 'thiscall', None, ret='eax', gen=ctl_max_ammo, note='batch1303')


def ctl_room(c):
    r = Rec(c)
    _logger(c, r)
    o = _o(c, 0x40)
    c.emu.w32(o + 0x14, _m0(c, 0.25))
    r.hook(0x5aeff0, 1, 1, rand=True)
    r.hook(0x5afe20, 2, 1, rand=True)
    return [o, _m0(c, 0.2)]


S(0x5afdd0, 'ZFFInventoryController::RoomFor(ZItem*)', 'thiscall', None, ret='eax', gen=ctl_room, note='batch1303')


def osd_text(c):
    r = Rec(c)
    o = _o(c, 0x700)
    c.emu.w32(o + 0x470, r.obj(0x20, {8: r.stub(5, 0, rand=True)}))
    c.emu.w8(o + 0x658, c.rng.choice([0, 1]))
    r.hook(0x5abcd0, 1, 0, rets=[c.rng.choice([0, 1, 0x100, 0xff00])])
    r.hook(0x5acac0, 2, 1, rand=True)
    r.hook(0x5ac940, 3, 1, rand=True)
    r.hook(0x5edb00, 4, 1, rand=True)
    t = _o(c, 8)
    if c.rng.random() < 0.5:
        c.emu.w8(t, 0)
    return [o, t]


S(0x5aa060, 'ZOnScreenDisplay::InventoryText', 'thiscall', None, ret=None, gen=osd_text, note='batch1303')


def wheel_cmd(c):
    o = _o(c, 0x400)
    c.emu.w8(o + 0x3c6, c.rng.choice([0, 1, 1, 1]))
    sel = c.rng.randrange(0, 9)
    c.emu.w32(o + 0x3c2, sel)
    c.emu.wf32(o + 0x3d0, c.rng.choice([0.0, -0.0, 0.1, float('nan'), c.fv()]))
    cmd = c.rng.choice([8, 8, sel, c.rng.randrange(0, 9), c.rng.getrandbits(32)])
    return [o, cmd]


S(0x5ab130, 'ZOnScreenDisplay::WheelInventoryCommand', 'thiscall', None, ret=None, gen=wheel_cmd, note='batch1303')


def osd_inv_show(c):
    r = Rec(c)
    o = _o(c, 0x1e00)
    t = _o(c, 0x20)
    c.emu.w32(t + 4, _m0(c, 0.3))
    it = r.obj(0x20, {0x2e8: r.stub(2, 0, rets=[t])})
    c.emu.w32(o + 0x1d0b, r.obj(0x20, {0x504: r.stub(1, 0, rets=[0 if c.rng.random() < 0.4 else it])}))
    c.emu.w32(o + 0x1d0f, _m0(c, 0.3))
    r.hook(0x5a9e20, 3, 1, rand=True)
    r.hook(0x5aa060, 4, 1, rand=True)
    r.hook(0x5b0010, 5, 1, rand=True)
    return [o]


S(0x5b0220, 'ZGameOSD::InventoryShow', 'thiscall', None, ret=None, gen=osd_inv_show, note='batch1303')


def savedev_load(c):
    r = Rec(c)
    r.hook(0x5ae450, 1, 1, rand=True)
    r.hook(0x5ae900, 2, 1, rand=True)
    dev = _o(c, 0x2100 + 0x400 * 4)
    return [dev, _o(c, 0x100), c.rng.randrange(0, 4)]


S(0x56b930, 'save-device LoadProfile (map: CPlayerProfile::SetFileName)', 'thiscall', None, ret=None,
  gen=savedev_load, note='batch1303')


def add_chars(c):
    r = Rec(c)
    o = _o(c, 0x500)
    if c.rng.random() < 0.7:
        c.emu.w8(o + 2, 0x32)
    r.hook(0x5b0b70, 1, 1, rets=[_m0(c, 0.5), _m0(c, 0.5)])
    return [o, _o(c, 0x10)]


S(0x5addc0, 'CPlayerProfile::GetAddCharactersId', 'thiscall', None, ret=None, gen=add_chars, note='batch1303')


def hero_item(c):
    r = Rec(c)
    sysobj = _o(c)
    set_global(c, SYS, sysobj)
    c.emu.w32(sysobj + 0x9b, r.obj(0x20, {0x4c: r.stub(3, 1, rand=True)}))
    gd = _o(c, 0x2d00)
    set_global(c, 0x7003b8, gd)
    v0 = _o(c, 8)
    r.hook(0x5003d0, 1, 1, rets=[v0, _o(c, 8)])
    r.hook(0x591e50, 2, 1, rand=True)
    r.hook(0x5002f0, 4, 1, rand=True)
    return [_o(c, 0x10), _o(c, 0x20)]


S(0x553dd0, 'CFFTools_if::GetHeroItem', 'thiscall', None, ret='eax', gen=hero_item, note='batch1303')


def bomb_init2(c):
    r = Rec(c)
    sysobj = _o(c)
    set_global(c, SYS, sysobj)
    m = r.obj(0x100, {0x88: r.stub(2, 2, rand=True, writes={1: c.rng.getrandbits(32)})})
    c.emu.w32(sysobj + 0x9b, r.obj(0x200, {0x138: r.stub(1, 0, rets=[m])}))
    set_global(c, 0x7003b8, _o(c, 0x40))
    r.hook(0x589c20, 3, 1, rand=True)
    return [_o(c, 0x80)]


S(0x5d4610, 'ZFFItemBomb::Init2', 'thiscall', None, ret=None, gen=bomb_init2, note='batch1303')


def c4_exec(c):
    r = Rec(c)
    o = _o(c, 0x40)
    c.emu.w32(o + 0xc, r.obj(0x20, {0x10: r.stub(1, 0, rand=True)}))
    c.emu.w32(o + 8, r.obj(0x300, {0x228: r.stub(2, 5, rand=True)}))
    r.hook(0x4614d0, 3, 3, rand=True)
    return [o]


S(0x5e0200, 'ZFFActionDropC4::Execute', 'thiscall', None, ret='eax', gen=c4_exec, note='batch1303')
