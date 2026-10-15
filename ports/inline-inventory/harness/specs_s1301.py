"""specs_s1301.py - inventory thread batch 1301 (src/batch1301.cpp): CInventory, CInventoryBinding, CPlayerProfile,
CPlayerInventory, ZFFInventory*, ZFFItemBomb, ZScriptItemInterface_t, inventory HUD."""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039c


def _o(c, n=0x100):
    return rnd(c, n)


def _m0(c, p=0.25):
    return 0 if c.rng.random() < p else c.rng.getrandbits(32)


def inv_copy(c):
    r = Rec(c)
    o = _o(c)
    c.emu.w32(o + 0x6e, r.vtable({0xc: r.stub(1, 0, rand=True)}))
    r.hook(0x4e6330, 2, 1, rand=True)
    return [o, _o(c, 0x10)]


def inv_init2(c):
    r = Rec(c)
    o = _o(c)
    c.emu.w32(o + 0x6e, r.vtable({0xc: r.stub(1, 0, rand=True), 0x14: r.stub(2, 0, rets=[_m0(c, 0.4)])}))
    r.hook(0x4ad3a0, 3, 1, rand=True)
    return [o]


def binding_load(c):
    r = Rec(c)
    o = r.obj(0x100, {0x84: r.stub(2, 1, rand=True)})
    r.hook(0x6352f0, 1, 1, rand=True, writes={0: c.rng.getrandbits(32)})
    return [o, _o(c, 0x10)]


def binding_copy(c):
    r = Rec(c)
    return [r.obj(0x100, {0x84: r.stub(1, 1, rand=True)}), _o(c, 0x10)]


S(0x4ab9b0, 'CInventory::CopyEventDataBlock', 'thiscall', None, ret='eax', gen=inv_copy, note='batch1301')
S(0x4abc00, 'CInventory::Init2', 'thiscall', None, ret='eax', gen=inv_init2, note='batch1301')
S(0x4afd90, 'CInventoryBinding::Load', 'thiscall', None, ret='al', gen=binding_load, note='batch1301')
S(0x4c5610, 'CInventoryBinding::CopyEventDataBlock', 'thiscall', None, ret='eax', gen=binding_copy, note='batch1301')
S(0x4f9f30, 'ZItemTemplate::GetPointerPicture', 'thiscall', None, ret='eax', gen=lambda c: [_o(c)], note='batch1301')


def script_clean(c):
    r = Rec(c)
    o = r.obj(0x20, {0: r.stub(1, 1, rand=True), 4: r.stub(2, 1, rand=True)})
    set_global(c, 0x7012cc, 0 if c.rng.random() < 0.3 else o)
    set_global(c, 0x7012c8, c.rng.getrandbits(32))
    r.hook(0x634d10, 3, 3, pop=False, rand=True)
    return [_o(c, 0x10), c.rng.getrandbits(32)]


S(0x50d750, 'ZScriptItemInterface_t::clean', 'thiscall', None, ret=None, gen=script_clean, note='batch1301')
S(0x50d770, 'ZScriptItemInterface_t::consume', 'thiscall', None, ret=None, gen=script_clean, note='batch1301')
S(0x50d810, 'ZScriptItemInterface_t::getTypeName', 'thiscall', None, ret='eax', gen=lambda c: [_o(c)], note='batch1301')


def big(c):
    o = c.emu.alloc(0x121b0, 4)
    c.emu.w32(o + 0x121a8, c.rng.getrandbits(32))
    return [o]


S(0x59b330, 'ZFFSaveDeviceInterface::GetNoOfProfiles', 'thiscall', None, ret='eax', gen=big, note='batch1301')
S(0x59b340, 'ZFFSaveDeviceInterface::GetNoOfProfilesRef', 'thiscall', None, ret='eax', gen=big, note='batch1301')


def prof_fwd(addr, nargs, rets=None):
    def g(c):
        r = Rec(c)
        if rets is None:
            r.hook(addr, 1, nargs, rand=True)
        else:
            r.hook(addr, 1, nargs, rets=[c.rng.choice(rets)])
        return [_o(c, 0x1000)] + [c.rng.getrandbits(32) for _ in range(nargs if addr != 0x5b0b70 or rets else nargs)]
    return g


def first_time(c):
    r = Rec(c)
    r.hook(0x5b0b70, 1, 1, rets=[c.rng.choice([0, 1, 0x100, 0xffffff00, c.rng.getrandbits(32)])])
    return [_o(c, 0x1000)]


def dbg_path(c):
    o = _o(c, 0x10)
    if c.rng.random() < 0.8:
        c.emu.w8(o + 2, c.rng.randrange(0x30, 0x3a))
    return [o]


def lvl_var(c):
    r = Rec(c)
    r.hook(0x5b0b70, 1, 1, rand=True)
    return [_o(c, 0x1000), c.rng.getrandbits(32)]


def subzone(c):
    r = Rec(c)
    r.hook(0x5b0f20, 1, 2, rand=True)
    return [_o(c, 0x1000), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def ffinv(c):
    r = Rec(c)
    r.hook(0x5b0360, 1, 0, rand=True)
    return [_o(c, 0x1000)]


def init_serial(c):
    r = Rec(c)
    dev = r.obj(0x20, {0x6c: r.stub(2, 3, rand=True)})
    sysobj = _o(c, 0x100)
    c.emu.w32(sysobj + 0x9b, r.obj(0x20, {0x134: r.stub(1, 0, rets=[dev])}))
    set_global(c, SYS, sysobj)
    return [_o(c, 0x200)]


S(0x5adda0, 'CPlayerProfile::FirstTimeInZone', 'thiscall', None, ret='eax', gen=first_time, note='batch1301')
S(0x5ade30, 'CPlayerProfile::GetDeBriefingLocalizetPath', 'thiscall', None, ret='eax', gen=dbg_path, note='batch1301')
S(0x5ade90, 'CPlayerProfile::GetFFInventoryFromHero', 'thiscall', None, ret='eax', gen=ffinv, note='batch1301')
S(0x5adeb0, 'CPlayerProfile::GetLevelVar', 'thiscall', None, ret='eax', gen=lvl_var, note='batch1301')
S(0x5adee0, 'CPlayerProfile::GetSubZoneMissionInfo', 'thiscall', None, ret='eax', gen=subzone, note='batch1301')
S(0x5ae240, 'CPlayerProfile::InitSaveDeviceSerialNumberAfterLoad', 'thiscall', None, ret='eax', gen=init_serial,
  note='batch1301')

S(0x5aedb0, 'ZFFInventoryCount::ZFFInventoryCount', 'thiscall', None, ret='eax', gen=lambda c: [_o(c, 0x20)],
  note='batch1301')
S(0x5aede0, 'ZFFInventoryInfoList::ZFFInventoryInfoList', 'thiscall', None, ret='eax', gen=lambda c: [_o(c, 0x20)],
  note='batch1301')
S(0x65e090, 'ZFFInventoryBridge::ZFFInventoryBridge', 'thiscall', None, ret='eax', gen=lambda c: [_o(c, 0x20)],
  note='batch1301')


def rebel(c):
    r = Rec(c)
    r.hook(0x5af040, 1, 1, rets=[c.rng.choice([8, 8, 0, 1, 2, 3, 4, 5, 6, 7])])
    return [_o(c, 0x60), c.rng.getrandbits(32)]


S(0x5aefc0, 'ZFFAddedWeaponsToRebelBase::GetAmmoForItem', 'thiscall', None, ret='eax', gen=rebel, note='batch1301')
S(0x5af230, 'ZFFAddedWeaponsToRebelBase::ItemAvailible', 'thiscall', None, ret='eax', gen=rebel, note='batch1301')


def get_no_of(c):
    r = Rec(c)
    r.hook(0x5af3a0, 1, 1, rand=True)
    r.hook(0x5af430, 2, 1, rand=True)
    t = c.rng.randrange(0, 20) if c.rng.random() < 0.85 else c.rng.getrandbits(32)
    return [_o(c, 0x20), t]


S(0x5af350, 'ZFFInventoryBridge::GetNoOf', 'thiscall', None, ret='eax', gen=get_no_of, note='batch1301')
S(0x5afce0, 'ZFFInventoryController::GetMaxInventory', 'thiscall', None, ret='eax',
  gen=lambda c: [_o(c, 0x40), _o(c, 0x20)], note='batch1301')


def ctl_set(c):
    r = Rec(c)
    r.hook(0x5afbb0, 1, 2, rand=True)
    return [_o(c, 0x40), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5afed0, 'ZFFInventoryController::SetData', 'thiscall', None, ret=None, gen=ctl_set, note='batch1301')


def pinv_ctor(c):
    r = Rec(c)
    r.hook(0x5aedb0, 1, 0, rand=True)
    r.hook(0x5aeda0, 2, 0, rand=True)
    return [_o(c, 0x60)]


S(0x5b02b0, 'CPlayerInventory::CPlayerInventory', 'thiscall', None, ret='eax', gen=pinv_ctor, note='batch1301')
for a, n in [(0x5b04a0, 'GetLargeItem'), (0x5b04c0, 'GetSmallItem')]:
    S(a, 'CPlayerInventory::' + n, 'thiscall', None, ret=None, gen=lambda c: [_o(c, 0x40), _o(c, 8), _o(c, 8)],
      note='batch1301')
for a, n in [(0x5b07d0, 'SetLargeItem'), (0x5b07f0, 'SetSmallItem')]:
    S(a, 'CPlayerInventory::' + n, 'thiscall', None, ret=None,
      gen=lambda c: [_o(c, 0x40), c.rng.getrandbits(32), c.rng.getrandbits(32)], note='batch1301')

S(0x5d4210, 'ZFFItemBomb::CopyData', 'thiscall', None, ret=None, gen=lambda c: [_o(c, 0x80), _o(c, 0x80)],
  note='batch1301')


def bomb_load2(c):
    r = Rec(c)
    set_global(c, 0x7003b8, _o(c, 0x40))
    r.hook(0x589c20, 1, 1, rand=True)
    return [_o(c, 0x80)]


S(0x5d4750, 'ZFFItemBomb::Load2', 'thiscall', None, ret=None, gen=bomb_load2, note='batch1301')


def dtor(c):
    r = Rec(c)
    r.hook(0x634273, 1, 2, pop=False, rand=True)
    return [_o(c, 0x40), c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


S(0x5df850, 'ZFFActionPickupItem::~ZFFActionPickupItem', 'thiscall', None, ret='eax', gen=dtor, note='batch1301')


def osd_show(c):
    r = Rec(c)
    o = _o(c, 0x700)
    c.emu.w32(o + 0x470, r.obj(0x20, {8: r.stub(3, 0, rand=True)}))
    c.emu.w8(o + 0x658, c.rng.choice([0, 1, 0x40]))
    r.hook(0x5acac0, 1, 1, rand=True)
    r.hook(0x5edb00, 2, 1, rand=True)
    return [o, c.rng.choice([0, 1, 0x100, 0xff, c.rng.getrandbits(32)])]


S(0x5aa020, 'ZOnScreenDisplay::InventoryShow', 'thiscall', None, ret=None, gen=osd_show, note='batch1301')


def wheel_show(c):
    o = _o(c, 0x400)
    k = c.rng.random()
    if k < 0.3:
        c.emu.w32(o + 0x3c2, 8)
    elif k < 0.6:
        c.emu.w32(o + 0x3c2, c.rng.randrange(8))
    c.emu.w8(o + 0x3c6, c.rng.choice([0, 1, 2]))
    return [o, c.rng.choice([0, 1, 2, 0x100, c.rng.getrandbits(32)])]


S(0x5ab1e0, 'ZOnScreenDisplay::WheelInventoryShow', 'thiscall', None, ret=None, gen=wheel_show, note='batch1301')


def osd_update(c):
    r = Rec(c)
    r.hook(0x5b0220, 1, 0, rand=True)
    return [_o(c, 0x1e00)]


S(0x5b0290, 'ZGameOSD::InventoryUpdate', 'thiscall', None, ret='eax', gen=osd_update, note='batch1301')


def wheel_cmd(c):
    r = Rec(c)
    o = _o(c, 0x1e00)
    w = 0
    if c.rng.random() > 0.2:
        w = _o(c, 0x400)
        c.emu.w8(w + 0x3c6, c.rng.choice([0, 1, 0x80]))
    c.emu.w32(o + 0x1d0f, w)
    r.hook(0x5ab130, 1, 1, rand=True)
    r.hook(0x5e9b70, 2, 0, rand=True)
    return [o, c.rng.getrandbits(32)]


S(0x5e9b40, 'ZGameOSD::WheelInventoryCommand', 'thiscall', None, ret=None, gen=wheel_cmd, note='batch1301')
