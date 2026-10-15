"""specs_s1302.py - inventory thread batch 1302 (src/batch1302.cpp): item destructors, CopyData/CopyDataBlock,
ZItemSpawn load/save/command, EnablePickup, ZActionDropItem::Execute, Item_If see-able items."""
from pilot import S, F
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039c


def _o(c, n=0x100):
    return rnd(c, n)


def _m0(c, p=0.25):
    return 0 if c.rng.random() < p else c.rng.getrandbits(32)


def _flags(c):
    return c.rng.choice([0, 1, 4, 5, 2, 3, 7, c.rng.getrandbits(32)])


def dtor(member):
    def g(c):
        r = Rec(c)
        o = _o(c, 0x100)
        if member is not None:
            c.emu.w32(o + member, 0 if c.rng.random() < 0.3 else r.obj(0x20, {0: r.stub(1, 1, rand=True)}))
        r.hook(0x46a4f0, 2, 0, rand=True)
        r.hook(0x43ea20, 3, 0, rand=True)
        r.hook(0x45c510, 4, 1, pop=False, rand=True)
        r.hook(0x4690b0, 5, 2, pop=False, rand=True)
        return [o, _flags(c)]
    return g


S(0x46a7c0, 'ZItemButton::~ZItemButton', 'thiscall', None, ret='eax', gen=dtor(None), note='batch1302')
S(0x46a810, 'ZItemContainer::~ZItemContainer', 'thiscall', None, ret='eax', gen=dtor(0x94), note='batch1302')
S(0x46a940, 'ZItemTemplate::~ZItemTemplate', 'thiscall', None, ret='eax', gen=dtor(0x70), note='batch1302')


def item_settings(c):
    r = Rec(c)
    r.hook(0x4cc5f0, 1, 0, rets=[_m0(c, 0.4)])
    r.hook(0x4cc1d0, 2, 0, rand=True)
    return [_o(c), r.obj(0x20, {0x20: r.stub(3, 2, rand=True)})]


S(0x4689e0, 'ZItemState::GetItemSettings', 'thiscall', None, ret='eax', gen=item_settings, note='batch1302')


def frame_update(c):
    r = Rec(c)
    o = r.obj(0x100, {0x114: r.stub(1, 1, rand=True), 0x31c: r.stub(2, 0, rand=True),
                      0x318: r.stub(3, 0, rand=True)})
    c.emu.w32(o + 0x74, r.obj(0x20, {0x14: r.stub(4, 0, rets=[_m0(c, 0.5)])}))
    c.emu.w32(o + 0x78, r.obj(0x20, {0x14: r.stub(5, 0, rets=[_m0(c, 0.5)])}))
    return [o]


S(0x46baa0, 'ZItem::ClassFrameUpdate', 'thiscall', None, ret='eax', gen=frame_update, note='batch1302')


def class_init(c):
    r = Rec(c)
    o = r.obj(0x100, {0x210: r.stub(1, 1, rand=True)})
    ci = _o(c, 0x40)
    c.emu.w32(o + 8, ci)
    c.emu.w32(o + 4, _m0(c, 0.3))
    log = r.obj(0x20, {0x2c: r.stub(3, 3, pop=False, rand=True)})
    sink = r.obj(0x40, {0x20: r.stub(2, 2, rets=[log])})
    set_global(c, 0x700390, sink)
    return [o]


S(0x46c7d0, 'ZItemTemplate::ClassInit', 'thiscall', None, ret=None, gen=class_init, note='batch1302')


def copy_data(c):
    r = Rec(c)
    r.hook(0x43f8c0, 1, 1, rand=True)
    src = r.obj(0x100, {0x1e0: r.stub(2, 1, rets=[c.rng.choice([0, 1, 0x100, 0xffffff00, c.rng.getrandbits(32)])])})
    return [_o(c), src]


for a, n in [(0x46c970, 'ZItem::CopyData'), (0x46ca60, 'ZItemSpawn::CopyData'), (0x46caa0, 'ZItemTemplate::CopyData')]:
    S(a, n, 'thiscall', None, ret=None, gen=copy_data, note='batch1302')
S(0x46ca10, 'ZItemContainer::CopyData', 'thiscall', None, ret='eax', gen=copy_data, note='batch1302')


def copy_blk(c):
    r = Rec(c)
    r.hook(0x43f900, 1, 1, rand=True)
    r.hook(0x4e12e0, 2, 2, rand=True)
    r.hook(0x4e11d0, 3, 2, rand=True)
    r.hook(0x4e0fd0, 4, 1, rand=True)
    r.hook(0x4e1b30, 5, 0, rand=True)
    return [_o(c), _o(c, 0x20)]


S(0x46ce40, 'ZItemButton::CopyDataBlock', 'thiscall', None, ret='eax', gen=copy_blk, note='batch1302')
S(0x46cea0, 'ZItemContainer::CopyDataBlock', 'thiscall', None, ret='eax', gen=copy_blk, note='batch1302')


def enable_pickup(c):
    r = Rec(c)
    sysobj = _o(c)
    set_global(c, SYS, sysobj)
    t = r.obj(0x20, {0x300: r.stub(2, 0, rets=[_m0(c, 0.3)])})
    c.emu.w32(sysobj + 0x9b, r.obj(0x20, {0x58: r.stub(1, 1, rets=[t])}))
    g = r.obj(0x20, {0xbc: r.stub(4, 0, rand=True), 0xb8: r.stub(5, 0, rand=True)})
    o = r.obj(0x100, {0x2f8: r.stub(3, 1, rets=[g])})
    c.emu.w32(o + 0x60, _m0(c, 0.2))
    return [o, c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])]


S(0x46d700, 'ZItem::EnablePickup', 'thiscall', None, ret=None, gen=enable_pickup, note='batch1302')


def spawn_cmd(c):
    r = Rec(c)
    o = r.obj(0x100, {0x64: r.stub(1, 1, rand=True)})
    a, b = c.rng.getrandbits(16), c.rng.getrandbits(16)
    k = c.rng.random()
    if k < 0.3:
        b = a
    c.emu.w16(o + 0x48, a)
    c.emu.w16(o + 0x4a, b)
    c.emu.w8(o + 0x50, c.rng.choice([0, 0, 1]))
    set_global(c, 0x7003b8, _o(c, 0x20))
    r.hook(0x470550, 2, 1, rand=True)
    r.hook(0x471680, 3, 0, rand=True)
    cmd = c.rng.choice([a, b, c.rng.getrandbits(16)]) | (c.rng.getrandbits(16) << 16)
    return [o, cmd, c.rng.getrandbits(32)]


S(0x46c910, 'ZItemSpawn::Command', 'thiscall', None, ret='eax', gen=spawn_cmd, note='batch1302')


def _rd_hooks(c, r):
    r.hook(0x4e5e80, 1, 0, ret_st0=c.fv(0, 100))
    r.hook(0x4e5e60, 2, 0, rets=[c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)]),
                                 c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])])


def spawn_copy_event(c):
    r = Rec(c)
    _rd_hooks(c, r)
    return [_o(c), _o(c, 0x10)]


def spawn_load(c):
    r = Rec(c)
    _rd_hooks(c, r)
    g = r.obj(0x40, {0x40: r.stub(3, 1, rand=True, writes={0: c.rng.getrandbits(32)}),
                     0x50: r.stub(4, 1, rand=True)})
    return [_o(c), g]


def spawn_save(c):
    r = Rec(c)
    g = r.obj(0x40, {0x3c: r.stub(3, 1, rand=True), 0x4c: r.stub(4, 1, rand=True)})
    return [_o(c), g]


S(0x46d290, 'ZItemSpawn::CopyEventDataBlock', 'thiscall', None, ret=None, gen=spawn_copy_event, note='batch1302')
S(0x46f600, 'ZItemSpawn::Load', 'thiscall', None, ret='al', gen=spawn_load, note='batch1302')
S(0x470670, 'ZItemSpawn::Save', 'thiscall', None, ret='al', gen=spawn_save, note='batch1302')


def state_notify(c):
    r = Rec(c)
    sysobj = _o(c)
    set_global(c, SYS, sysobj)
    c.emu.w32(sysobj + 0x9b, r.obj(0x20, {0x4c: r.stub(1, 1, rand=True)}))
    slots = _o(c, 0x40)
    lst = r.obj(0x20, {4: r.stub(2, 1, rets=[slots + 4 * i for i in range(8)])})
    o = _o(c)
    c.emu.w32(o + 0x70, lst)
    k = c.rng.random()
    mask = c.rng.getrandbits(8) if k < 0.5 else (c.rng.getrandbits(32) if k < 0.8 else -c.rng.randrange(1, 300))
    return [o, _o(c, 0x10), mask]


S(0x4717f0, 'ZItemTemplate::StateNotify', 'thiscall', None, ret=None, gen=state_notify, note='batch1302')


def drop_exec(c):
    r = Rec(c)
    o = r.obj(0x40, {0xc: r.stub(4, 0, rand=True)})
    c.emu.w32(o + 0xc, r.obj(0x20, {0x10: r.stub(1, 0, rand=True)}))
    c.emu.w32(o + 8, r.obj(0x20, {0x228: r.stub(2, 5, rand=True)}))
    c.emu.w32(o + 0x10, _m0(c, 0.4))
    r.hook(0x4614d0, 3, 3, rand=True)
    return [o]


S(0x486480, 'ZActionDropItem::Execute', 'thiscall', None, ret='eax', gen=drop_exec, note='batch1302')


def see_able(c):
    r = Rec(c)
    sysobj = _o(c)
    set_global(c, SYS, sysobj)
    grp = r.obj(0x20, {0x130: r.stub(4, 2, rand=True)})
    world = _o(c, 0xb00)
    c.emu.w32(world + 0xadc, r.obj(0x20, {0x25c: r.stub(1, 2, rets=[grp])}))
    vt = r.vtable({0x114: r.stub(3, 5, rand=True)})
    c.emu.w32(world, vt)
    c.emu.w32(sysobj + 0x9b, world)
    val = _o(c, 8)
    r.hook(0x5003d0, 2, 1, rets=[val])
    params = _o(c, 0x20)
    return [_o(c, 0x10), params]


S(0x50b7f0, 'ZScriptItemInterface_t::AddSeeAbleItem', 'thiscall', None, ret='eax', gen=see_able, note='batch1302')
S(0x50bef0, 'ZScriptItemInterface_t::DelSeeAbleItem', 'thiscall', None, ret='eax', gen=see_able, note='batch1302')
