"""specs_s1305.py - inventory thread batch 1305 (src/batch1305.cpp): profile save, default loadout, info-list
lookups, inventory bridge give/set/grenades, ZFFItemBomb event data/save, CInventoryBinding, weapon wheel."""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039c


def _o(c, n=0x100):
    return rnd(c, n)


def _m0(c, p=0.25):
    return 0 if c.rng.random() < p else c.rng.getrandbits(32)


def _sys(c, r, slots, size=0x200):
    sysobj = _o(c)
    set_global(c, SYS, sysobj)
    ref = r.obj(size, slots)
    c.emu.w32(sysobj + 0x9b, ref)
    return ref


def _logger(c, r):
    pr = r.obj(0x20, {0x2c: r.stub(91, 2, pop=False, rand=True, log_ecx=False)})
    set_global(c, 0x700390, r.obj(0x40, {0x20: r.stub(90, 2, rets=[pr])}))


def prof_save(c):
    r = Rec(c)
    o = _o(c, 0x600)
    c.emu.w8(o + 2, c.rng.randrange(0x30, 0x3a))
    if c.rng.random() < 0.4:
        c.emu.w8(o + 3, 0x52)
    r.hook(0x5b1440, 1, 1, rets=[c.rng.choice([0, 1, 0x100, 0xff01])])
    r.hook(0x5ad2b0, 2, 1, rand=True)
    r.hook(0x5c2c80, 3, 0, rand=True)
    r.hook(0x5b1150, 4, 2, rand=True)
    r.hook(0x5ae710, 5, 1, rand=True)
    return [o]


S(0x5ae680, 'CPlayerProfile::Save', 'thiscall', None, ret=None, gen=prof_save, note='batch1305')


def give_default(c):
    r = Rec(c)
    r.hook(0x5af1d0, 1, 1, rets=[_m0(c, 0.5) for _ in range(12)])
    r.hook(0x5af2a0, 2, 2, rand=True)
    return [_o(c, 0x40)] + [c.rng.getrandbits(32) for _ in range(5)]


S(0x5b04e0, 'CPlayerInventory::GiveDefaultAdditional', 'thiscall', None, ret=None, gen=give_default, note='batch1305')


def _info_list(c):
    n = c.rng.randrange(0, 7)
    lst = _o(c, 4 + 4 * 8)
    c.emu.w32(lst, n)
    recs = []
    for i in range(n):
        rec = _o(c, 0x20)
        c.emu.w32(rec, c.rng.choice([0x1000, 0x2000, 0x3000]))
        c.emu.w32(lst + 4 + 4 * i, rec)
        recs.append(rec)
    return lst, recs


def ff_type(c):
    r = Rec(c)
    lst, recs = _info_list(c)
    item = 0 if c.rng.random() < 0.15 else r.obj(0x20, {0x2e8: r.stub(1, 0, rets=[c.rng.choice([0x1000, 0x2000,
                                                                                                 0x3000, 0x4000])])})
    return [lst, item]


def get_next(c):
    lst, recs = _info_list(c)
    k = c.rng.random()
    v = 0 if k < 0.2 else (c.rng.choice(recs) if recs and k < 0.85 else c.rng.getrandbits(32))
    return [lst, v]


S(0x5aeff0, 'ZFFInventoryInfoList::GetFFItemType', 'thiscall', None, ret='eax', gen=ff_type, note='batch1305')
S(0x5af170, 'ZFFInventoryInfoList::GetNext', 'thiscall', None, ret='eax', gen=get_next, note='batch1305')


def grenade(c):
    r = Rec(c)
    _logger(c, r)
    _sys(c, r, {0x58: r.stub(1, 1, rets=[_m0(c, 0.3)])})
    rec = _o(c, 0x20)
    if c.rng.random() < 0.2:
        c.emu.w32(rec, 0)
    r.hook(0x5af130, 2, 1, rets=[0 if c.rng.random() < 0.2 else rec])
    r.hook(0x5af300, 3, 1, rand=True)
    o = _o(c, 0x20)
    c.emu.w32(o, _m0(c, 0.1))
    c.emu.w32(o + 4, _m0(c, 0.1))
    c.emu.w32(o + 8, 0 if c.rng.random() < 0.1 else r.obj(0x20, {0x98: r.stub(4, 2, rand=True)}))
    return [o, c.rng.randrange(0, 20)]


S(0x5af3a0, 'ZFFInventoryBridge::GetNoOfGrenade', 'thiscall', None, ret='eax', gen=grenade, note='batch1305')


def give_items(c):
    r = Rec(c)
    ref = _sys(c, r, {0x4c: r.stub(1, 1, rand=True)}, size=0xb00)
    it = r.obj(0x20, {0x2f0: r.stub(3, 3, rand=True), 0x2d0: r.stub(4, 2, rand=True)})
    tmpl = r.obj(0x20, {0x2c4: r.stub(2, 2, rets=[c.rng.choice([0, it, it]) for _ in range(6)])})
    rec = _o(c, 0x20)
    c.emu.w32(rec, 0 if c.rng.random() < 0.15 else tmpl)
    r.hook(0x5af130, 5, 1, rets=[0 if c.rng.random() < 0.15 else rec])
    return [_o(c, 0x20), c.rng.randrange(0, 20), c.rng.randrange(0, 5)]


S(0x5af8f0, 'ZFFInventoryBridge::GiveNoOfItem', 'thiscall', None, ret=None, gen=give_items, note='batch1305')


def set_ammo(c):
    r = Rec(c)
    am = r.obj(0x400, {0x324: r.stub(2, 1, rand=True)})
    hero = r.obj(0x600, {0x55c: r.stub(1, 1, rets=[am if c.rng.random() < 0.6 else 0])})
    o = _o(c, 0x20)
    c.emu.w32(o, hero)
    item = r.obj(0x400, {0x35c: r.stub(3, 0, rand=True), 0x360: r.stub(4, 1, rand=True)})
    absf = c.rng.choice([0, 1, 0x100])
    if absf & 0xff:
        hero2 = r.obj(0x600, {0x55c: r.stub(1, 1, rets=[am])})
        c.emu.w32(o, hero2)
    return [o, item, c.rng.getrandbits(32), absf]


S(0x5afb40, 'ZFFInventoryBridge::SetAmmo', 'thiscall', None, ret=None, gen=set_ammo, note='batch1305')


def bomb_copy(c):
    r = Rec(c)
    _sys(c, r, {0x58: r.stub(1, 1, rand=True)})
    r.hook(0x4e5e60, 2, 0, rets=[_m0(c, 0.4), _m0(c, 0.4), c.rng.getrandbits(32)])
    return [_o(c, 0x80), _o(c, 0x10)]


def bomb_save(c):
    r = Rec(c)
    m = r.obj(0x100, {0x88: r.stub(2, 2, rand=True, writes={1: c.rng.getrandbits(32)})})
    _sys(c, r, {0x138: r.stub(1, 0, rets=[m])})
    g = r.obj(0x80, {0x3c: r.stub(3, 1, rand=True), 0x4c: r.stub(4, 1, rand=True), 0x60: r.stub(5, 1, rand=True),
                     0x64: r.stub(6, 1, rand=True)})
    return [_o(c, 0x80), g]


S(0x5d4250, 'ZFFItemBomb::CopyEventDataBlock', 'thiscall', None, ret=None, gen=bomb_copy, note='batch1305')
S(0x5d4840, 'ZFFItemBomb::Save', 'thiscall', None, ret='al', gen=bomb_save, note='batch1305')


def binding_dtor(c):
    r = Rec(c)
    _sys(c, r, {0x34: r.stub(1, 1, rand=True)})
    set_global(c, 0x7003b0, r.fn(2, 0, rand=True, log_ecx=False))
    r.hook(0x4690b0, 5, 2, pop=False, rand=True)
    return [_o(c, 0x80), c.rng.choice([0, 1, 4, 5, 2, 3, 7, c.rng.getrandbits(32)])]


def binding_read(c):
    r = Rec(c)
    _sys(c, r, {0x58: r.stub(1, 1, rand=True)})
    r.hook(0x4e5e60, 2, 0, rets=[c.rng.getrandbits(32) for _ in range(5)])
    return [_o(c, 0x80), _o(c, 0x10)]


S(0x5d4920, 'CInventoryBinding::~CInventoryBinding (ICF ZShakeCamera)', 'thiscall', None, ret='eax', gen=binding_dtor,
  note='batch1305')
S(0x5d4a70, 'CInventoryBinding::ReadInput', 'thiscall', None, ret=None, gen=binding_read, note='batch1305')


def wheel_show(c):
    r = Rec(c)
    o = r.obj(0x1e00, {0x90: r.stub(1, 0, rand=True)})
    w = _o(c, 0x400)
    c.emu.w8(w + 0x3c6, c.rng.choice([0, 1]))
    c.emu.w32(o + 0x1d0f, 0 if c.rng.random() < 0.15 else w)
    c.emu.w32(o + 0x1d0b, r.obj(0x20, {0x3dc: r.stub(2, 0, rand=True), 0x4dc: r.stub(3, 2, rand=True)}))
    r.hook(0x4f9680, 4, 1, rand=True)
    r.hook(0x5ab1e0, 5, 1, rand=True)
    r.hook(0x5ab2a0, 6, 1, rand=True)
    r.hook(0x5e9b70, 7, 0, rets=[_m0(c, 0.4)])
    return [o, c.rng.choice([0, 1, 0x100, 0xff])]


S(0x5e9ce0, 'ZGameOSD::WheelInventoryShow', 'thiscall', None, ret=None, gen=wheel_show, note='batch1305')
