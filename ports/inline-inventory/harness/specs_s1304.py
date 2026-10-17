"""specs_s1304.py - inventory thread batch 1304 (src/batch1304.cpp): event ctors/dtors, ZItemTemplateContainer,
ZItem AddActivate/Clear/Load/Save, ZItemState::CopyData, ZItemTemplate CopyDataBlock/CreateItem/SetStateGeometry/
CanContainItem, ZItemButton::ClassCommand, item action callbacks, Item_If checks."""
from pilot import S, F
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039c


def _o(c, n=0x100):
    return rnd(c, n)


def _m0(c, p=0.25):
    return 0 if c.rng.random() < p else c.rng.getrandbits(32)


def _flags(c):
    return c.rng.choice([0, 1, 4, 5, 2, 3, 7, c.rng.getrandbits(32)])


def _sys(c, r, slots):
    sysobj = _o(c)
    set_global(c, SYS, sysobj)
    ref = r.obj(0x200, slots)
    c.emu.w32(sysobj + 0x9b, ref)
    return ref


FMT3 = (0x69d510, 0x69d4a0)   # printf formats with one %s argument


def _logger(c, r):
    s2, s3 = r.stub(91, 2, pop=False, rand=True, log_ecx=False), r.stub(92, 3, pop=False, rand=True, log_ecx=False)

    def printer(emu, res):
        (s3 if emu.r32(emu.reg('esp') + 8) in FMT3 else s2)(emu, res)
    pr = r.obj(0x20, {0x2c: printer})
    set_global(c, 0x700390, r.obj(0x40, {0x20: r.stub(90, 2, rets=[pr])}))


def ev_dtor(c):
    r = Rec(c)
    _sys(c, r, {0x34: r.stub(1, 1, rand=True)})
    set_global(c, 0x7003b0, r.fn(2, 0, rand=True, log_ecx=False))
    for a, sid, n in [(0x4cbec0, 3, 0), (0x4ccf60, 4, 0), (0x4690b0, 5, 2)]:
        r.hook(a, sid, n, pop=(a != 0x4690b0), rand=True)
    return [_o(c, 0x480), _flags(c)]


for a, n in [(0x468cb0, 'ZItemState::~ZItemState'), (0x46a870, 'ZItemSpawn::~ZItemSpawn'),
             (0x49e2e0, 'CInventory::~CInventory'), (0x567820, 'ZFFInventorySelector::~ZFFInventorySelector')]:
    S(a, n, 'thiscall', None, ret='eax', gen=ev_dtor, note='batch1304')


def ev_ctor(c):
    r = Rec(c)
    _sys(c, r, {0x114: r.stub(1, 4, rand=True)})
    for a, sid in [(0x469870, 2), (0x4cbeb0, 3), (0x561020, 4), (0x5aede0, 5), (0x65e090, 6)]:
        r.hook(a, sid, 0, rand=True)
    return [_o(c, 0x480)]


S(0x469c00, 'ZItemSpawn::ZItemSpawn', 'thiscall', None, ret='eax', gen=ev_ctor, note='batch1304')
S(0x469cc0, 'ZItemState::ZItemState', 'thiscall', None, ret='eax', gen=ev_ctor, note='batch1304')
S(0x567720, 'ZFFInventorySelector::ZFFInventorySelector', 'thiscall', None, ret='eax', gen=ev_ctor, note='batch1304')


def tc_dtor(c):
    r = Rec(c)
    o = _o(c)
    for off, sid in [(0x7c, 1), (0x70, 2)]:
        c.emu.w32(o + off, 0 if c.rng.random() < 0.3 else r.obj(0x20, {0: r.stub(sid, 1, rand=True)}))
    r.hook(0x43ea20, 3, 0, rand=True)
    r.hook(0x45c510, 4, 1, pop=False, rand=True)
    r.hook(0x4690b0, 5, 2, pop=False, rand=True)
    return [o, _flags(c)]


S(0x46aa00, 'ZItemTemplateContainer::~ZItemTemplateContainer', 'thiscall', None, ret='eax', gen=tc_dtor,
  note='batch1304')


def add_activate(c):
    r = Rec(c)
    o = r.obj(0x100, {0x110: r.stub(1, 2, rand=True)})
    c.emu.w32(o + 0x78, r.obj(0x20, {0x98: r.stub(2, 3, rand=True)}))
    st = _o(c, 0x40) + 8
    if c.rng.random() < 0.5:
        c.emu.w32(st - 4, 0)
    m = r.obj(0x40, {0x20: r.stub(3, 1, rets=[_m0(c, 0.6)]), 0xac: r.stub(4, 1, rand=True,
                                                                             writes={0: 0})})
    k = c.rng.random()
    c.emu.w32(m + 8, 0 if k < 0.3 else r.fn(5, 0, rand=True))
    lo = st - c.rng.choice([0, 4, 0x100]) if c.rng.random() < 0.7 else st + 4
    c.emu.w32(m + 0xc, lo)
    c.emu.w32(m + 0x10, st + c.rng.choice([0, 1, 0x100]))
    set_global(c, 0x70038c, m)
    return [o, 0 if c.rng.random() < 0.2 else st, F(c.fv())]


S(0x46ab30, 'ZItem::AddActivate', 'thiscall', None, ret=None, gen=add_activate, note='batch1304')


def clear(c):
    r = Rec(c)
    o = r.obj(0x100, {0x294: r.stub(3, 4, rand=True)})
    n = c.rng.randrange(0, 4)
    nodes = [_o(c, 0x10) for _ in range(n)] + [0]
    c.emu.w32(o + 0x50, nodes[0])
    state = {'i': 0}

    def detach(emu, res):
        r._write([1, emu.reg('ecx')])
        state['i'] += 1
        emu.w32(o + 0x50, nodes[min(state['i'], n)])
        emu.ret(eax=0)
    r.emu.hook(0x4d9430, detach)
    from inv_helpers import _HOOKED
    _HOOKED.add(0x4d9430)
    r.hook(0x4d9590, 2, 1, pop=False, rand=True)
    return [o, _m0(c, 0.4)]


S(0x46c8a0, 'ZItem::Clear', 'thiscall', None, ret='eax', gen=clear, note='batch1304')


def _stream(c, r, slots_n):
    g = _o(c, 0x40)
    vt = r.vtable({off: r.stub(sid, 1, rets=[g], writes=({0: c.rng.getrandbits(32)} if off == 0x40 else None))
                   for off, sid in slots_n})
    c.emu.w32(g, vt)
    return g


def item_load(c):
    r = Rec(c)
    r.hook(0x440e10, 1, 1, rand=True)
    return [_o(c), _stream(c, r, [(0x40, 2), (0x70, 3), (0x7c, 4)])]


def item_save(c):
    r = Rec(c)
    r.hook(0x441790, 1, 1, rand=True)
    return [_o(c), _stream(c, r, [(0x3c, 2), (0x6c, 3), (0x78, 4)])]


S(0x46f520, 'ZItem::Load', 'thiscall', None, ret='al', gen=item_load, note='batch1304')
S(0x4705a0, 'ZItem::Save', 'thiscall', None, ret='al', gen=item_save, note='batch1304')


def state_copy(c):
    r = Rec(c)
    r.hook(0x4cbee0, 1, 1, rand=True)
    t = r.obj(0x40, {0x1e0: r.stub(3, 1, rets=[c.rng.choice([0, 1, 0x100])]), 0x2dc: r.stub(4, 2, rand=True)})
    own = r.obj(0x40, {0x20: r.stub(2, 0, rets=[t])})
    o = r.obj(0x100, {0x58: r.stub(5, 0, rand=True)})
    c.emu.w32(o + 0x44, own)
    return [o, _o(c)]


S(0x468420, 'ZItemState::CopyData', 'thiscall', None, ret='eax', gen=state_copy, note='batch1304')


def templ_blk(c):
    r = Rec(c)
    r.hook(0x43f900, 1, 1, rand=True)
    r.hook(0x4e11e0, 2, 2, rand=True)
    r.hook(0x4e12e0, 3, 2, rand=True)
    r.hook(0x4e1600, 4, 0, rets=[c.rng.choice([0xb, 0xb, 0x10b, 0xa, c.rng.getrandbits(32)])])
    r.hook(0x4e1b30, 5, 0, rand=True)
    return [_o(c), _o(c, 0x20)]


S(0x46cee0, 'ZItemTemplate::CopyDataBlock', 'thiscall', None, ret='eax', gen=templ_blk, note='batch1304')


def create_item(c):
    r = Rec(c)
    info = _o(c, 0x40)
    _sys(c, r, {0x154: r.stub(2, 2, rets=[info]), 0x4c: r.stub(4, 1, rand=True)})
    it = r.obj(0x40, {0x2e4: r.stub(5, 1, rand=True), 0x154: r.stub(6, 0, rand=True), 0x158: r.stub(7, 0, rand=True)})
    parent = r.obj(0x40, {0x298: r.stub(3, 5, rets=[0 if c.rng.random() < 0.3 else it])})
    o = r.obj(0x100, {0x2c8: r.stub(1, 0, rand=True)})
    c.emu.w32(o + 4, _m0(c, 0.3))
    r.hook(0x4dc630, 8, 2, rand=True)
    return [o, parent, c.rng.getrandbits(32)]


S(0x46d530, 'ZItemTemplate::CreateItem', 'thiscall', None, ret='eax', gen=create_item, note='batch1304')


def set_state_geom(c):
    r = Rec(c)
    st = r.obj(0x20, {0x5c: r.stub(2, 3, rand=True)})
    g = r.obj(0x40, {0x100: r.stub(1, 1, rets=[0 if c.rng.random() < 0.3 else st])})
    c.emu.w32(g + 8, _o(c, 0x40))
    r.hook(0x4dc630, 3, 2, rand=True)
    return [_o(c), c.rng.getrandbits(32), g]


S(0x4714d0, 'ZItemTemplate::SetStateGeometry', 'thiscall', None, ret=None, gen=set_state_geom, note='batch1304')


def can_contain(c):
    r = Rec(c)
    _sys(c, r, {0x4c: r.stub(1, 1, rets=[c.rng.randrange(4)])})
    n = c.rng.randrange(0, 5)
    ends = [1] * n + [0]
    lst = r.obj(0x40, {0x14: r.stub(2, 0, rets=[_m0(c, 0.3)]), 0x4c: r.stub(3, 1, rand=True, writes={0: ends[0]}),
                       0x5c: r.stub(4, 1, rets=[c.rng.randrange(4) for _ in range(8)], writes={0: ends[1:] or [0]})})
    o = _o(c)
    c.emu.w32(o + 0x7c, lst)
    item = r.obj(0x20, {0x2e8: r.stub(5, 0, rand=True)})
    return [o, item]


S(0x46b650, 'ZItemTemplateContainer::CanContainItem', 'thiscall', None, ret='al', gen=can_contain, note='batch1304')


def button_cmd(c):
    r = Rec(c)
    o = r.obj(0x100, {0x12c: r.stub(1, 3, rand=True), 0x2d0: r.stub(2, 2, rand=True)})
    a, b = c.rng.getrandbits(16), c.rng.getrandbits(16)
    c.emu.w16(o + 0x7c, a)
    c.emu.w16(o + 0x92, b)
    c.emu.w32(o + 0x60, _m0(c, 0.2))
    c.emu.w32(o + 0x8e, _m0(c, 0.3))
    data = r.obj(0x20, {0x88: r.stub(3, 2, rand=True, writes={1: c.rng.choice([3, 3, 0, 2, 0x103])})})
    r.hook(0x41e680, 4, 0, rand=True)
    r.hook(0x46b800, 5, 2, rand=True)
    cmd = c.rng.choice([a, b, c.rng.getrandbits(16)]) | (c.rng.choice([0, c.rng.getrandbits(16)]) << 16)
    return [o, cmd, data]


S(0x46b9d0, 'ZItemButton::ClassCommand', 'thiscall', None, ret='eax', gen=button_cmd, note='batch1304')


def drop_cb(c):
    r = Rec(c)
    it = r.obj(0x20, {0x2d0: r.stub(3, 2, rand=True)})
    o = _o(c, 0x40)
    c.emu.w32(o + 0xc, r.obj(0x20, {0x10: r.stub(1, 0, rets=[it]), 8: r.stub(2, 2, rand=True)}))
    c.emu.w32(o + 8, r.obj(0x600, {0x4f4: r.stub(4, 1, rand=True)}))
    r.hook(0x467410, 5, 6, rand=True)
    return [o]


def get_cb(c):
    r = Rec(c)
    _sys(c, r, {0x4c: r.stub(1, 1, rand=True)})
    o = _o(c, 0x40)
    c.emu.w32(o + 0x10, r.obj(0x20, {8: r.stub(2, 2, rand=True)}))
    c.emu.w32(o + 8, r.obj(0x300, {0x2d0: r.stub(3, 2, rand=True)}))
    r.hook(0x467410, 5, 6, rand=True)
    return [o]


S(0x485f90, 'ZActionDropItem::CallBack', 'thiscall', None, ret='al', gen=drop_cb, note='batch1304')
S(0x486020, 'ZActionGetItem::CallBack', 'thiscall', None, ret='al', gen=get_cb, note='batch1304')


def put_exec(c):
    r = Rec(c)
    t = r.obj(0x20, {0x1e0: r.stub(3, 1, rets=[c.rng.choice([0, 1, 0x100])])})
    it = r.obj(0x300, {0x2e8: r.stub(2, 0, rets=[t])})
    o = r.obj(0x40, {0xc: r.stub(6, 0, rand=True)})
    c.emu.w32(o + 0xc, r.obj(0x20, {0x10: r.stub(1, 0, rets=[it])}))
    c.emu.w32(o + 8, r.obj(0x300, {0x230: r.stub(4, 2, rand=True)}))
    c.emu.w32(o + 0x10, _m0(c, 0.4))
    c.emu.w32(o + 0x14, _m0(c, 0.4))
    r.hook(0x461570, 5, 3, rand=True)
    return [o]


S(0x486890, 'ZActionPutItem::Execute', 'thiscall', None, ret='eax', gen=put_exec, note='batch1304')


def script_enable(c):
    r = Rec(c)
    _logger(c, r)
    it = r.obj(0x400, {0x1e0: r.stub(2, 1, rets=[c.rng.choice([0, 1, 0x100])]), 0x300: r.stub(3, 1, rand=True)})
    _sys(c, r, {0x58: r.stub(1, 1, rets=[0 if c.rng.random() < 0.2 else it])})
    v0, v1 = _o(c, 8), _o(c, 8)
    if c.rng.random() < 0.5:
        c.emu.w32(v1, 0)
    r.hook(0x5003d0, 4, 1, rets=[v0, v1])
    return [_o(c, 0x10), _o(c, 0x20)]


S(0x50c200, 'ZScriptItemInterface_t::EnablePickup', 'thiscall', None, ret=None, gen=script_enable, note='batch1304')


def script_valid(c):
    r = Rec(c)
    _logger(c, r)
    o = r.obj(0x40, {0x1e0: r.stub(2, 1, rets=[c.rng.choice([0, 1, 0x100])])})
    _sys(c, r, {0x58: r.stub(1, 1, rets=[0 if c.rng.random() < 0.3 else o])})
    return [_o(c, 0x10), c.rng.getrandbits(32)]


S(0x50c7e0, 'ZScriptItemInterface_t::GetValidIKLnkObj', 'thiscall', None, ret='eax', gen=script_valid,
  note='batch1304')
S(0x50c870, 'ZScriptItemInterface_t::GetValidItem', 'thiscall', None, ret='eax', gen=script_valid, note='batch1304')
