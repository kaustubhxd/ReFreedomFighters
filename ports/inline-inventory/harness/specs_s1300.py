"""specs_s1300.py - inventory thread batch 1300: ZItem / ZItemTemplate / ZItemContainer / ZItemState accessors and
Load/Save/CopyDataBlock wrappers (src/batch1300.cpp). Callees are replaced by inv_helpers.Rec recorders, so every
call's order, this and arguments are compared through the heap log."""
from pilot import S, F
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039c


def _obj(c, n=0x120):
    return rnd(c, n)


def _maybe0(c, p=0.25):
    return 0 if c.rng.random() < p else c.rng.getrandbits(32)


def _sys(c, r):
    """Fake ZSysInterface with a reference table at +0x9b (slots 0x58 id->obj, 0x4c obj->id)."""
    sysobj = _obj(c, 0x100)
    ref = r.obj(0x40, {0x58: r.stub(90, 1, rand=True), 0x4c: r.stub(91, 1, rand=True)})
    c.emu.w32(sysobj + 0x9b, ref)
    set_global(c, SYS, sysobj)
    return sysobj


def leaf(c):
    return [_obj(c)]


def leaf_arg(c):
    return [_obj(c), c.rng.getrandbits(32)]


def verify(c):
    t = 0
    k = c.rng.random()
    if k > 0.15:
        t = _obj(c, 0x40)
        ci = _obj(c, 0x40)
        c.emu.w32(t + 0xc, ci)
        if k < 0.5:
            c.emu.w32(ci + 0x23, c.rng.choice([0x1007d3, 0x1007d9]))
        elif k < 0.6:
            c.emu.w32(ci + 0x23, c.rng.choice([0x1007d3, 0x1007d9]) ^ (1 << c.rng.randrange(32)))
    return [_obj(c), t]


for a, n, conf in [(0x468a20, 'ZItemState::IsMain', 'low'), (0x46e680, 'ZItemContainer::GetContainedItems', 'high'),
                   (0x46e700, 'ZItemTemplate::GetItemClassName', 'low'),
                   (0x46e720, 'ZItemTemplateContainer::GetItemClassName', 'low'),
                   (0x46eaa0, 'ZItemTemplate::GetMaterial', 'medium'), (0x46eee0, 'ZItemTemplate::GetStates', 'low'),
                   (0x486e20, 'ZActionDropItem::Name', 'high'), (0x486e30, 'ZActionGetItem::Name', 'high'),
                   (0x486e40, 'ZActionPickupItem::Name', 'high'), (0x486e60, 'ZActionPutItem::Name', 'high'),
                   (0x486e80, 'ZActionSwapItems::Name', 'high'), (0x4875d0, 'CPathUserProfile::GetUser', 'low'),
                   (0x49eec0, 'CInventory::GetInventoryList', 'high')]:
    S(a, n, 'thiscall', None, ret='al' if a == 0x468a20 else 'eax', gen=leaf, note='batch1300; name %s' % conf)

S(0x470c80, 'ZItemTemplate::SetInventoryPicture', 'thiscall', None, ret=None, gen=leaf_arg, note='batch1300')
S(0x4711c0, 'ZItem::SetMain', 'thiscall', None, ret='eax', gen=leaf_arg, note='batch1300; EAX = old id')
S(0x471a10, 'ZItem::VerifyItemTemplate', 'thiscall', None, ret='al', gen=verify, note='batch1300; type 0x1007d3')
S(0x471a70, 'ZItemContainer::VerifyItemTemplate', 'thiscall', None, ret='al', gen=verify, note='batch1300; 0x1007d9')


def tail_readinput(c):
    r = Rec(c)
    r.hook(0x4702b0, 1, 1, rand=True)
    return [_obj(c), _obj(c, 0x10)]


S(0x468310, 'ZItemState::CopyEventDataBlock', 'thiscall', None, ret='eax', gen=tail_readinput, note='batch1300')


def owner_draw(c):
    r = Rec(c)
    r.hook(0x46f9d0, 1, 7, rand=True)
    return [_obj(c)] + [c.rng.getrandbits(32) for _ in range(7)]


S(0x46fd90, 'ZItemContainer::OwnerDraw', 'thiscall', None, ret='eax', gen=owner_draw, note='batch1300')


def state_load(c):
    r = Rec(c)
    r.hook(0x6352f0, 1, 1, rand=True, writes={0: c.rng.getrandbits(32)})
    r.hook(0x4702b0, 2, 1, rand=True)
    return [_obj(c), _obj(c, 0x10)]


S(0x4683f0, 'ZItemState::Load', 'thiscall', None, ret='al', gen=state_load, note='batch1300')


def spawn_frame(c):
    r = Rec(c)
    sysobj = _obj(c, 0x100)
    set_global(c, SYS, sysobj)
    c.emu.wf32(sysobj + 0x48, c.fv(0, 1))
    o = _obj(c)
    c.emu.wf32(o + 0x56, c.fv(0, 5))
    c.emu.wf32(o + 0x4c, c.fv(0, 5))
    r.hook(0x471680, 1, 0, rand=True)
    return [o]


S(0x46e3b0, 'ZItemSpawn::FrameUpdate', 'thiscall', None, ret=None, gen=spawn_frame, note='batch1300')


def spawn_init2(c):
    r = Rec(c)
    o = _obj(c)
    g = r.obj(0x40, {0xbc: r.stub(1, 1, rand=True), 0x300: r.stub(2, 1, rand=True)})
    c.emu.w32(o + 0x44, g)
    c.emu.w8(o + 0x51, c.rng.choice([0, 0, 1, 0x80]))
    r.hook(0x471680, 3, 0, rand=True)
    return [o]


S(0x46eff0, 'ZItemSpawn::Init2', 'thiscall', None, ret='eax', gen=spawn_init2, note='batch1300')


def resolve_at(off, extra_arg=False):
    def g(c):
        r = Rec(c)
        _sys(c, r)
        o = _obj(c)
        c.emu.w32(o + off, _maybe0(c))
        return [o, _obj(c, 0x10)] if extra_arg else [o]
    return g


S(0x46e740, 'ZItem::GetItemOwner', 'thiscall', None, ret='eax', gen=resolve_at(0x64), note='batch1300')
S(0x46e8c0, 'ZItem::GetMain', 'thiscall', None, ret='eax', gen=resolve_at(0x68), note='batch1300')
S(0x46ef70, 'ZItemState::GetUseGeom', 'thiscall', None, ret='eax', gen=resolve_at(0xe1, True), note='batch1300')


def get_action(c):
    r = Rec(c)
    child = r.obj(0x40, {0x8c: r.stub(2, 4, rand=True)})
    o = r.obj(0x120, {0x100: r.stub(1, 1, rets=[0 if c.rng.random() < 0.3 else child])})
    return [o, c.rng.getrandbits(32)]


S(0x46e3e0, 'ZItem::GetAction', 'thiscall', None, ret='eax', gen=get_action, note='batch1300')


def by_name(c):
    r = Rec(c)
    o = r.obj(0x120, {0x25c: r.stub(1, 2, rets=[_maybe0(c, 0.4)])})
    return [o]


S(0x46e580, 'ZItemTemplate::GetCameraPos', 'thiscall', None, ret='eax', gen=by_name, note='batch1300')
S(0x46e660, 'ZItemTemplate::GetCenterPos', 'thiscall', None, ret='eax', gen=by_name, note='batch1300')


def add_deactivate(c):
    r = Rec(c)
    ctl = r.obj(0x40, {0x98: r.stub(2, 3, rand=True)})
    o = r.obj(0x120, {0x110: r.stub(1, 2, rand=True)})
    c.emu.w32(o + 0x74, ctl)
    return [o, c.rng.getrandbits(32), F(c.fv())]


S(0x46abb0, 'ZItem::AddDeactivate', 'thiscall', None, ret=None, gen=add_deactivate, note='batch1300')


def copy_blk(base):
    def g(c):
        r = Rec(c)
        r.hook(base, 1, 1, rand=True)
        r.hook(0x4e12e0, 2, 2, rand=True)
        r.hook(0x4e0fd0, 3, 1, rand=True)
        r.hook(0x4e1b30, 4, 0, rand=True)
        return [_obj(c), _obj(c, 0x20)]
    return g


S(0x46cdc0, 'ZItem::CopyDataBlock', 'thiscall', None, ret='eax', gen=copy_blk(0x43f900), note='batch1300')
S(0x46d040, 'ZItemTemplateContainer::CopyDataBlock', 'thiscall', None, ret='eax', gen=copy_blk(0x46cee0),
  note='batch1300')


def load_save(base, slot):
    def g(c):
        r = Rec(c)
        r.hook(base, 1, 1, rand=True)
        gm = r.obj(0x40, {slot: r.stub(2, 1, rand=True)})
        return [_obj(c), gm]
    return g


S(0x46f5d0, 'ZItemContainer::Load', 'thiscall', None, ret='al', gen=load_save(0x46f520, 0x70), note='batch1300')
S(0x46f660, 'ZItemTemplate::Load', 'thiscall', None, ret='al', gen=load_save(0x440e10, 0x70), note='batch1300')
S(0x470640, 'ZItemContainer::Save', 'thiscall', None, ret='al', gen=load_save(0x4705a0, 0x6c), note='batch1300')
S(0x4706a0, 'ZItemTemplate::Save', 'thiscall', None, ret='al', gen=load_save(0x441790, 0x6c), note='batch1300')


def remove_item(c):
    r = Rec(c)
    o = _obj(c)
    c.emu.w32(o + 0x94, r.obj(0x40, {0x3c: r.stub(1, 1, rand=True)}))
    return [o, c.rng.getrandbits(32)]


S(0x470540, 'ZItemContainer::RemoveItem', 'thiscall', None, ret='eax', gen=remove_item, note='batch1300')


def dtor(c):
    r = Rec(c)
    r.hook(0x634273, 1, 2, pop=False, rand=True)
    return [_obj(c, 0x40), c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


S(0x485f00, 'ZActionGetItem::~ZActionGetItem', 'thiscall', None, ret='eax', gen=dtor, note='batch1300')


def swap_exec(c):
    r = Rec(c)
    o = r.obj(0x40, {0xc: r.stub(3, 0, rand=True)})
    actor = r.obj(0x40, {0x230: r.stub(1, 2, rand=True)})
    c.emu.w32(o + 8, actor)
    c.emu.w32(o + 0x14, _maybe0(c, 0.4))
    r.hook(0x4614d0, 2, 3, rand=True)
    return [o]


S(0x4869a0, 'ZActionSwapItems::Execute', 'thiscall', None, ret='eax', gen=swap_exec, note='batch1300')


def pickup_load(c):
    r = Rec(c)
    _sys(c, r)
    g = r.obj(0x40, {0x40: r.stub(1, 1, rand=True, writes={0: c.rng.getrandbits(32)})})
    return [_obj(c, 0x40), g]


def pickup_save(c):
    r = Rec(c)
    _sys(c, r)
    g = r.obj(0x40, {0x3c: r.stub(1, 1, rand=True)})
    return [_obj(c, 0x40), g]


S(0x486d90, 'ZFFActionPickupItem::Load', 'thiscall', None, ret='eax', gen=pickup_load, note='batch1300')
S(0x487030, 'ZFFActionPickupItem::Save', 'thiscall', None, ret='eax', gen=pickup_save, note='batch1300')


def main_mat_pos(c):
    r = Rec(c)
    g = _obj(c, 0x20)
    c.emu.w32(g + 8, c.rng.getrandbits(32))
    o = r.obj(0x120, {0x2dc: r.stub(1, 0, rets=[0 if c.rng.random() < 0.5 else g])})
    r.hook(0x4de7a0, 2, 0, rand=True)
    r.hook(0x4db2c0, 3, 2, rand=True)
    return [o, _obj(c, 0x30), _obj(c, 0x10)]


S(0x46e980, 'ZItem::GetMainMatPos', 'thiscall', None, ret='eax', gen=main_mat_pos, note='batch1300')
