"""specs_s1306.py - inventory thread batch 1306 (src/batch1306.cpp)."""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039c
FMT3 = (0x688ec0, 0x688f08, 0x69d5fc)


def _o(c, n=0x100):
    return rnd(c, n)


def _m0(c, p=0.25):
    return 0 if c.rng.random() < p else c.rng.getrandbits(32)


def _sys(c, r, slots, size=0x200):
    sysobj = _o(c, 0x2000)
    set_global(c, SYS, sysobj)
    ref = r.obj(size, slots)
    c.emu.w32(sysobj + 0x9b, ref)
    return sysobj, ref


def _logger(c, r):
    s2, s3 = r.stub(91, 2, pop=False, rand=True, log_ecx=False), r.stub(92, 3, pop=False, rand=True, log_ecx=False)

    def printer(emu, res):
        (s3 if emu.r32(emu.reg('esp') + 8) in FMT3 else s2)(emu, res)
    pr = r.obj(0x40, {0x2c: printer, 0x30: r.stub(93, 2, pop=False, rand=True, log_ecx=False)})
    set_global(c, 0x700390, r.obj(0x40, {0x20: r.stub(90, 2, rets=[pr])}))


def room_for(c):
    r = Rec(c)
    r.hook(0x5af5b0, 1, 3, rand=True, writes={0: c.rng.choice([0, 0, 3, 7])})
    r.hook(0x5af350, 2, 1, rets=[c.rng.randrange(0, 12)])
    r.hook(0x5af1d0, 3, 1, rets=[c.rng.randrange(0, 12)])
    t = c.rng.randrange(0, 18) if c.rng.random() < 0.9 else c.rng.getrandbits(32)
    return [_o(c, 0x40), t]


S(0x5afe20, 'ZFFInventoryController::RoomFor(EFFItemType)', 'thiscall', None, ret='eax', gen=room_for,
  note='batch1306')


def state_cmd(c):
    r = Rec(c)
    sysobj, _ = _sys(c, r, {0x58: r.stub(1, 1, rets=[0])})
    it = r.obj(0x400, {0x310: r.stub(5, 2, rand=True)})
    _, ref = _sys(c, r, {0x58: r.stub(1, 1, rets=[it])})
    sysobj = c.emu.r32(SYS)
    c.emu.w32(sysobj + 0x40, c.rng.getrandbits(32) if c.rng.random() < 0.3 else c.rng.randrange(0, 10 ** 6))
    o = r.obj(0x100, {0x84: r.stub(2, 1, rand=True), 0x88: r.stub(3, 1, rand=True)})
    c.emu.w32(o + 0x44, r.obj(0x20, {0x20: r.stub(4, 1, rand=True)}))
    c.emu.wf32(o + 0x57, c.fv(-100, 100))
    a, b = c.rng.getrandbits(16), c.rng.getrandbits(16)
    c.emu.w16(o + 0x4a, a)
    c.emu.w16(o + 0x4c, b)
    data = r.obj(0x100, {0x88: r.stub(6, 2, rand=True, writes={1: c.rng.getrandbits(32)})})
    cmd = c.rng.choice([a, b, b, c.rng.getrandbits(16)]) | (c.rng.getrandbits(16) << 16)
    return [o, cmd, data]


S(0x4684c0, 'ZItemState::Command', 'thiscall', None, ret='eax', gen=state_cmd, note='batch1306')


def state_init(c):
    r = Rec(c)
    _logger(c, r)
    t = r.obj(0x400, {0x1e0: r.stub(2, 1, rets=[c.rng.choice([0, 1, 0x100])]), 0x2dc: r.stub(3, 2, rand=True)})
    own = r.obj(0x40, {0x20: r.stub(1, 0, rets=[t])})
    ci = _o(c, 0x40)
    c.emu.w32(own + 8, ci)
    c.emu.w32(own + 4, _m0(c, 0.3))
    o = r.obj(0x100, {0x58: r.stub(4, 0, rand=True)})
    c.emu.w32(o + 0x44, own)
    return [o]


S(0x468320, 'ZItemState::Init', 'thiscall', None, ret='eax', gen=state_init, note='batch1306')


def enable_cam(c):
    r = Rec(c)
    lst = r.obj(0x200, {0x128: r.stub(5, 3, rand=True)})
    m = r.obj(0x100, {0x88: r.stub(2, 2, rand=True, writes={1: _m0(c, 0.4)})})
    sysobj, ref = _sys(c, r, {0x138: r.stub(1, 0, rets=[m]), 0x58: r.stub(3, 1, rets=[lst]),
                              0x114: r.stub(4, 4, rand=True)})
    c.emu.w32(sysobj + 0x190f, r.obj(0x100, {0xac: r.stub(6, 2, rand=True)}))
    r.hook(0x4cc850, 7, 0, log_edx=True, rets=[c.rng.choice([0, 1, 0xffffffff])])
    r.hook(0x41e680, 8, 0, rand=True)
    cam = _o(c, 0x20)
    c.emu.w32(cam + 4, _m0(c, 0.3))
    return [_o(c), cam]


S(0x468a30, 'ZItemState::EnableCamera', 'thiscall', None, ret=None, gen=enable_cam, note='batch1306')


def _state_list(c, r, n, states):
    ents = []
    for i in range(n):
        e = _o(c, 8)
        c.emu.w32(e, c.rng.choice(states))
        ents.append(e)
    lst = r.obj(0x80, {0x4c: r.stub(10, 1, rand=True), 0x64: r.stub(11, 1, rets=ents + [0]),
                       0x44: r.stub(12, 1, rand=True)})
    return lst


def check_state(c):
    r = Rec(c)
    n = c.rng.randrange(0, 5)
    g = _o(c, 0x20)
    c.emu.w32(g + 4, _m0(c, 0.3))
    _sys(c, r, {0x58: r.stub(1, 1, rets=[c.rng.choice([0, g, g]) for _ in range(6)])})
    o = _o(c)
    c.emu.w32(o + 0x70, 0 if c.rng.random() < 0.1 else _state_list(c, r, n, [1, 2, 3]))
    set_global(c, 0x676414, r.fn(2, 2, pop=False, rets=[c.rng.choice([0, 1, 0xffffffff]) for _ in range(6)],
                                 log_ecx=False))
    r.hook(0x4cc850, 3, 0, log_edx=True, rets=[c.rng.choice([0, 1]) for _ in range(6)])
    return [o, c.rng.choice([1, 2, 3, 4]), _m0(c, 0.3)]


def find_geoms(c):
    r = Rec(c)
    a = check_state(c)
    out = r.obj(0x20, {4: r.stub(4, 1, rand=True)})
    return [a[0], out, a[1], a[2]]


def find_main(c):
    r = Rec(c)
    n = c.rng.randrange(0, 5)
    st = r.obj(0x100, {0x90: r.stub(3, 0, rets=[c.rng.choice([0, 1, 0x100]) for _ in range(6)])})
    g = r.obj(0x200, {0x100: r.stub(2, 1, rets=[c.rng.choice([0, st, st]) for _ in range(6)])})
    _sys(c, r, {0x58: r.stub(1, 1, rets=[c.rng.choice([0, g, g]) for _ in range(6)])})
    o = _o(c)
    c.emu.w32(o + 0x70, 0 if c.rng.random() < 0.1 else _state_list(c, r, n, [1, 2]))
    out = r.obj(0x20, {4: r.stub(4, 1, rand=True)})
    return [o, out]


S(0x46b760, 'ZItemTemplate::CheckStateExists', 'thiscall', None, ret='al', gen=check_state, note='batch1306')
S(0x46d810, 'ZItemTemplate::FindStateGeoms', 'thiscall', None, ret=None, gen=find_geoms, note='batch1306')
S(0x46d760, 'ZItemTemplate::FindMainState', 'thiscall', None, ret=None, gen=find_main, note='batch1306')


def tc_copy(c):
    r = Rec(c)
    r.hook(0x43f8c0, 1, 1, rand=True)
    n = c.rng.randrange(0, 4)
    ends = [1] * n + [0]
    sl = r.obj(0x80, {0x4c: r.stub(3, 1, rand=True, writes={0: ends[0]}),
                      0x5c: r.stub(4, 1, rand=True, writes={0: ends[1:] or [0]})})
    src = r.obj(0x100, {0x1e0: r.stub(2, 1, rets=[c.rng.choice([0, 1, 0x100]), c.rng.choice([0, 1, 1])])})
    c.emu.w32(src + 0x7c, 0 if c.rng.random() < 0.15 else sl)
    o = _o(c)
    c.emu.w32(o + 0x7c, r.obj(0x20, {4: r.stub(5, 1, rand=True)}))
    return [o, src]


S(0x46cb70, 'ZItemTemplateContainer::CopyData', 'thiscall', None, ret=None, gen=tc_copy, note='batch1306')


def add_list(c):
    r = Rec(c)
    n = c.rng.choice([0, 1, 3, 5, -1])
    kids = r.obj(0x40, {0x14: r.stub(2, 0, rets=[n]), 0x30: r.stub(3, 1, rand=True)})
    g = _o(c, 0x40)
    c.emu.w32(g + 0x18, kids)
    bs = [_o(c, 0x60) for _ in range(3)]
    o = r.obj(0x200, {0x100: r.stub(4, 1, rets=[c.rng.choice([0] + bs) for _ in range(8)])})
    _sys(c, r, {0x58: r.stub(1, 1, rets=[g] + [o] * 8)})
    lst = _o(c, 4 + 4 * 24)
    m = c.rng.choice([0, 1, 2, 19, 20])
    c.emu.w32(lst, m)
    for i in range(min(m, 20)):
        c.emu.w32(lst + 4 + 4 * i, c.rng.choice(bs) + 0x48 if c.rng.random() < 0.3 else c.rng.getrandbits(32))
    return [lst, c.rng.getrandbits(32)]


S(0x5aee60, 'ZFFInventoryInfoList::AddList', 'thiscall', None, ret=None, gen=add_list, note='batch1306')


def put_cb(c):
    r = Rec(c)
    _logger(c, r)
    _sys(c, r, {0x4c: r.stub(1, 1, rand=True)})
    it = r.obj(0x300, {0x2d0: r.stub(3, 2, rand=True)})
    o = _o(c, 0x40)
    c.emu.w32(o + 0xc, r.obj(0x20, {0x10: r.stub(2, 0, rets=[0 if c.rng.random() < 0.25 else it]),
                                    8: r.stub(4, 2, rand=True)}))
    r.hook(0x467410, 5, 6, rand=True)
    return [o]


def pickup_cb(c):
    r = Rec(c)
    _sys(c, r, {0x4c: r.stub(1, 1, rand=True)})
    o = _o(c, 0x40)
    c.emu.w32(o + 8, r.obj(0x300, {0x144: r.stub(2, 1, rand=True), 0x1e0: r.stub(3, 1, rets=[c.rng.choice(
        [0, 1, 0x100])]), 0x2d0: r.stub(4, 2, rand=True), 0x2f0: r.stub(5, 3, rand=True)}))
    c.emu.w32(o + 0x10, r.obj(0x20, {8: r.stub(6, 2, rand=True)}))
    r.hook(0x467410, 7, 6, rand=True)
    return [o]


S(0x4861f0, 'ZActionPutItem::CallBack', 'thiscall', None, ret='al', gen=put_cb, note='batch1306')
S(0x4860b0, 'ZActionPickupItem::CallBack', 'thiscall', None, ret='al', gen=pickup_cb, note='batch1306')


def bomb_init(c):
    r = Rec(c)
    sysobj, ref = _sys(c, r, {}, size=0xb00)
    g = r.obj(0x300, {0x2c: r.stub(3, 0, rand=True), 0xbc: r.stub(4, 1, rand=True), 0x234: r.stub(5, 1, rand=True),
                      0x23c: r.stub(6, 1, rand=True), 0x240: r.stub(7, 1, rand=True)})
    c.emu.w32(g + 8, _o(c, 0x40))
    o = _o(c, 0x80)
    c.emu.w32(o + 0x6b, 0 if c.rng.random() < 0.2 else r.obj(0x200, {0x1bc: r.stub(2, 7, rets=[g])}))
    r.hook(0x4de7a0, 1, 0, rand=True)
    r.hook(0x4dc630, 8, 2, rand=True)
    r.hook(0x4dbe30, 9, 1, rand=True)
    r.hook(0x4dc440, 10, 1, rand=True)
    return [o]


S(0x5d4660, 'ZFFItemBomb::Init', 'thiscall', None, ret=None, gen=bomb_init, note='batch1306')


def destroy(c):
    r = Rec(c)
    _logger(c, r)
    it = r.obj(0x300, {0x1e0: r.stub(2, 1, rets=[c.rng.choice([0, 1, 0x100])]), 0x210: r.stub(3, 1, rand=True)})
    _sys(c, r, {0x58: r.stub(1, 1, rets=[0 if c.rng.random() < 0.25 else it])})
    v = [_o(c, 8) for _ in range(3)]
    r.hook(0x5003d0, 4, 1, rets=v)
    r.hook(0x5002f0, 5, 1, rand=True)
    return [_o(c, 0x10), _o(c, 0x20)]


S(0x50bf60, 'ZScriptItemInterface_t::DestroyItem', 'thiscall', None, ret=None, gen=destroy, note='batch1306')


def inv_load2(c):
    r = Rec(c)
    n = c.rng.randrange(0, 4)
    ends = [1] * n + [0]
    lst = r.obj(0x80, {0x4c: r.stub(1, 1, rand=True, writes={0: ends[0]}),
                       0x5c: r.stub(2, 1, rand=True, writes={0: ends[1:] or [0]})})
    a = _o(c, 0x20)
    b = _o(c, 0x20)
    c.emu.w32(b + 8, 0 if c.rng.random() < 0.15 else lst)
    c.emu.w32(a + 0x10, b)
    ev = r.obj(0x200, {0x14: r.stub(4, 0, rets=[c.rng.choice([0, 0x5000, 0x6000]) for _ in range(8)])})
    set_global(c, 0x70038c, r.obj(0x200, {0xcc: r.stub(3, 1, rets=[ev])}))
    r.hook(0x4cc850, 5, 0, log_edx=True, rets=[c.rng.choice([0, 0, 1]) for _ in range(8)])
    r.hook(0x41e680, 6, 0, rand=True)
    o = _o(c, 0x200)
    c.emu.w32(o + 0x44, a)
    c.emu.w32(o + 0x11a, r.vtable({0x28: r.stub(7, 1, rets=[c.rng.choice([0, 1]) for _ in range(8)])}))
    c.emu.w32(o + 0x1c6, r.vtable({4: r.stub(8, 1, rand=True)}))
    return [o]


S(0x4acd10, 'CInventory::Load2', 'thiscall', None, ret=None, gen=inv_load2, note='batch1306')
