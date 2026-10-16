"""specs_s1307.py - inventory thread batch 1307 (src/batch1307.cpp)."""
from pilot import S
from inv_helpers import Rec, rnd, set_global, f32bits

SYS = 0x70039c
FMT3 = (0x6889f4, 0x69d5fc, 0x69d650)


def _o(c, n=0x100):
    return rnd(c, n)


def _m0(c, p=0.25):
    return 0 if c.rng.random() < p else c.rng.getrandbits(32)


def _sys(c, r, slots, size=0x200, sys_slots=None):
    sysobj = r.obj(0x2000, sys_slots) if sys_slots else _o(c, 0x2000)
    set_global(c, SYS, sysobj)
    ref = r.obj(size, slots)
    c.emu.w32(sysobj + 0x9b, ref)
    return sysobj, ref


def _logger(c, r):
    s2, s3 = r.stub(91, 2, pop=False, rand=True, log_ecx=False), r.stub(92, 3, pop=False, rand=True, log_ecx=False)

    def printer(emu, res):
        (s3 if emu.r32(emu.reg('esp') + 8) in FMT3 else s2)(emu, res)
    pr = r.obj(0x40, {0x2c: printer})
    set_global(c, 0x700390, r.obj(0x40, {0x20: r.stub(90, 2, rets=[pr])}))


def get_exec(c):
    r = Rec(c)
    _sys(c, r, {}, sys_slots={0x1c0: r.stub(1, 2, ret_st0=c.fv(0, 1))})
    t = r.obj(0x200, {0x1e0: r.stub(2, 1, rets=[c.rng.choice([0, 1, 0x100])])})
    o = r.obj(0x40, {0xc: r.stub(5, 0, rand=True)})
    c.emu.w32(o + 8, r.obj(0x300, {0x2e8: r.stub(3, 0, rets=[t])}))
    c.emu.w32(o + 0xc, r.obj(0x300, {0x228: r.stub(4, 5, rand=True)}))
    c.emu.w32(o + 0x14, _m0(c, 0.4))
    c.emu.w32(o + 0x18, _m0(c, 0.4))
    r.hook(0x461570, 6, 3, rand=True)
    return [o]


S(0x4864e0, 'ZActionGetItem::Execute', 'thiscall', None, ret='al', gen=get_exec, note='batch1307')


def pickup_exec(c):
    r = Rec(c)
    o = _o(c, 0x40)
    c.emu.w32(o + 8, r.obj(0x300, {0x2e0: r.stub(1, 2, rand=True, writes={(1, 4): f32bits(c.fv(-100, 100))}),
                                   0x98: r.stub(2, 2, rand=True)}))
    vy = c.rng.choice([90.0, 60.0, 30.0, 0.0, -70.0, float('nan'), c.fv(-200, 200), 80.0, 50.0, 20.0, -60.0])
    c.emu.w32(o + 0xc, r.obj(0x400, {0x94: r.stub(3, 2, rand=True),
                                     0x3a8: r.stub(5, 1, rand=True, writes={0: f32bits(c.fv()),
                                                                            (0, 4): f32bits(vy),
                                                                            (0, 8): f32bits(c.fv())}),
                                     0x398: r.stub(6, 1, rand=True), 0x228: r.stub(7, 5, rand=True)}))
    c.emu.w32(o + 0x10, r.obj(0x40, {0x1c: r.stub(4, 8, rand=True)}))
    return [o]


S(0x4865a0, 'ZActionPickupItem::Execute', 'thiscall', None, ret='al', gen=pickup_exec, note='batch1307')


def swap_cb(c):
    r = Rec(c)
    _sys(c, r, {0x4c: r.stub(1, 1, rand=True)})
    o = _o(c, 0x40)
    c.emu.w32(o + 0xc, r.obj(0x20, {0x10: r.stub(2, 0, rets=[_m0(c, 0.3)]), 8: r.stub(3, 2, rand=True)}))
    c.emu.w32(o + 0x10, r.obj(0x20, {0x10: r.stub(4, 0, rets=[_m0(c, 0.3)]), 8: r.stub(5, 2, rand=True)}))
    r.hook(0x467410, 6, 6, rand=True)
    return [o]


S(0x4862b0, 'ZActionSwapItems::CallBack', 'thiscall', None, ret='al', gen=swap_cb, note='batch1307')


def get_templ(c):
    r = Rec(c)
    _logger(c, r)
    _sys(c, r, {0x58: r.stub(1, 1, rets=[_m0(c, 0.5)])})
    o = r.obj(0x200, {0x1d8: r.stub(2, 2, rand=True)})
    r.hook(0x4cc1d0, 3, 0, rand=True)
    r.hook(0x4cbec0, 4, 0, rand=True)
    return [o]


S(0x46e800, 'ZItem::GetItemTemplate', 'thiscall', None, ret='eax', gen=get_templ, note='batch1307')


def marked(c):
    r = Rec(c)
    n = c.rng.randrange(0, 5)
    ents = [_o(c, 8) for _ in range(n)]
    g = _o(c, 0x20)
    c.emu.w32(g + 4, _m0(c, 0.3))
    _sys(c, r, {0x58: r.stub(1, 1, rets=[c.rng.choice([0, g, g]) for _ in range(6)])})
    lst = r.obj(0x80, {0x4c: r.stub(10, 1, rand=True), 0x64: r.stub(11, 1, rets=ents + [0]),
                       0x44: r.stub(12, 1, rand=True)})
    o = _o(c)
    c.emu.w32(o + 0x70, 0 if c.rng.random() < 0.1 else lst)
    c.emu.w32(o + 0x6c, r.obj(0x80, {0x40: r.stub(13, 1, rand=True)}))
    c.emu.w32(o + 0x74, r.obj(0x80, {0x40: r.stub(14, 1, rand=True)}))
    set_global(c, 0x676414, r.fn(2, 2, pop=False, rets=[c.rng.choice([0, 1, 0xffffffff]) for _ in range(6)],
                                 log_ecx=False))
    return [o, c.rng.getrandbits(32)]


S(0x46e9e0, 'ZItem::GetMarkedGeom', 'thiscall', None, ret='eax', gen=marked, note='batch1307')


def get_owner(c):
    r = Rec(c)
    _logger(c, r)
    it = r.obj(0x400, {0x1e0: r.stub(2, 1, rets=[c.rng.choice([0, 1, 0x100])]), 0x2f4: r.stub(3, 0, rand=True)})
    _sys(c, r, {0x58: r.stub(1, 1, rets=[0 if c.rng.random() < 0.2 else it]), 0x4c: r.stub(4, 1, rand=True)})
    r.hook(0x5003d0, 5, 1, rets=[_o(c, 8) for _ in range(3)])
    r.hook(0x5002f0, 6, 1, rand=True)
    r.hook(0x50d7b0, 7, 1, rand=True)
    return [_o(c, 0x10), _o(c, 0x20)]


S(0x50c450, 'ZScriptItemInterface_t::GetOwner', 'thiscall', None, ret=None, gen=get_owner, note='batch1307')


def get_name(c):
    r = Rec(c)
    _logger(c, r)
    t = _o(c, 0x20)
    it = r.obj(0x400, {0x1e0: r.stub(2, 1, rets=[c.rng.choice([0, 1, 0x100])]), 0x2e8: r.stub(3, 0, rets=[t])})
    _sys(c, r, {0x58: r.stub(1, 1, rets=[0 if c.rng.random() < 0.2 else it])})
    s = r.obj(0x40, {0x30: r.stub(4, 1, rand=True), 0x24: r.stub(5, 0, rand=True), 0x28: r.stub(6, 0, rand=True)})
    fac = r.obj(0x20, {0: r.stub(7, 2, rets=[s])})
    params = _o(c, 0x20)
    c.emu.w32(params + 0xc, fac)
    v = _o(c, 8)
    c.emu.w8(v + 4, c.rng.choice([0, 4, 4, 1, 2]))
    c.emu.w32(v, r.obj(0x40, {0x28: r.stub(8, 0, rand=True)}))
    r.hook(0x5003d0, 9, 1, rets=[_o(c, 8), v])
    return [_o(c, 0x10), params]


S(0x50c360, 'ZScriptItemInterface_t::GetName', 'thiscall', None, ret=None, gen=get_name, note='batch1307')


def ammo_box(c):
    r = Rec(c)
    lt, ln, st, sn = (_o(c, 8) for _ in range(4))
    r.hook(0x5af5b0, 1, 3, rand=True, writes={0: [c.rng.choice([0, 6, 7]), c.rng.choice([0, 3, 4])],
                                              1: [c.rng.randrange(0, 300), c.rng.randrange(0, 100)]})
    recs = []
    for _ in range(2):
        rec = _o(c, 0x20)
        c.emu.w32(rec + 8, c.rng.choice([0, 30, 90, 100, c.rng.getrandbits(32)]))
        c.emu.w32(rec + 0xc, c.rng.choice([0, 60, 180, 300]))
        recs.append(rec)
    r.hook(0x5af130, 2, 1, rets=recs)
    r.hook(0x5af7c0, 3, 3, rand=True)
    return [_o(c, 0x40), lt, ln, st, sn]


S(0x5afd00, 'ZFFInventoryController::GiveAmmoBox', 'thiscall', None, ret='al', gen=ammo_box, note='batch1307')


def add_list(c):
    r = Rec(c)
    n = c.rng.randrange(0, 4)
    ends = [1] * n + [0]
    lst = 0 if c.rng.random() < 0.1 else r.obj(0x80, {
        0x14: r.stub(1, 0, rets=[c.rng.choice([0, 1, 3])]), 0x4c: r.stub(2, 1, rand=True, writes={0: ends[0]}),
        0x5c: r.stub(3, 1, rand=True, writes={0: ends[1:] or [0]})})
    _sys(c, r, {0x4c: r.stub(4, 1, rand=True)})
    items = []
    for _ in range(3):
        t = r.obj(0x400, {0x300: r.stub(5, 0, rets=[c.rng.choice([0, 1, 2, 2])])})
        it = r.obj(0x400, {0x158: r.stub(6, 0, rand=True), 0x2f0: r.stub(7, 3, rand=True),
                           0x2d0: r.stub(8, 2, rand=True), 0x2e8: r.stub(9, 0, rets=[c.rng.choice([0, t, t])])})
        bg = _o(c, 0x40)
        c.emu.w32(it + 8, bg)
        items.append(it)
    r.hook(0x4acf30, 10, 1, rets=[c.rng.choice([0] + items) for _ in range(4)])
    r.hook(0x4dc630, 11, 2, rand=True)
    o = _o(c, 0x200)
    c.emu.w32(o + 0x44, r.obj(0x600, {0x548: r.stub(12, 2, rand=True)}))
    return [o, lst]


S(0x4ad3a0, 'CInventory::AddListToInventory', 'thiscall', None, ret=None, gen=add_list, note='batch1307')


def wheel_get(c):
    r = Rec(c)
    w = _o(c, 0x400)
    sel = c.rng.choice(list(range(9)) + [c.rng.getrandbits(32)])
    c.emu.w32(w + 0x3c2, sel)
    for off in (0x381, 0x389, 0x3a6, 0x3ae, 0x3b2, 0x3ba, 0x3a2, 0x3be, 0x3b6, 0x3aa, 0x392, 0x37d, 0x396, 0x385):
        if c.rng.random() < 0.3:
            c.emu.w32(w + off, 0)
    if c.rng.random() < 0.3:
        c.emu.w32(w + 0x39a, 2)
    o = _o(c, 0x1e00)
    c.emu.w32(o + 0x1d0f, w)
    c.emu.w32(o + 0x1d47, c.rng.choice([sel, 8, c.rng.randrange(9)]))
    r.hook(0x4f9680, 1, 1, rand=True)
    r.hook(0x5ab230, 2, 1, rand=True)
    r.hook(0x5ab2a0, 3, 1, rand=True)
    return [o]


S(0x5e9b70, 'ZGameOSD::WheelInventoryGetItem', 'thiscall', None, ret='eax', gen=wheel_get, note='batch1307')


def get_ffinv(c):
    r = Rec(c)
    m = r.obj(0x100, {0x88: r.stub(2, 2, rand=True, writes={1: [c.rng.getrandbits(32), c.rng.getrandbits(32)]})})
    _sys(c, r, {0x138: r.stub(1, 0, rets=[m]), 0x58: r.stub(3, 1, rand=True)})
    for a, sid, n in [(0x5aede0, 4, 0), (0x5aee60, 5, 1), (0x65e090, 6, 0), (0x5afbb0, 7, 2), (0x5af350, 8, 1),
                      (0x5af2a0, 9, 2), (0x5af5b0, 10, 3)]:
        r.hook(a, sid, n, rand=True)
    return [_o(c, 0x60)]


S(0x5b0360, 'CPlayerInventory::GetFFInventory', 'thiscall', None, ret=None, gen=get_ffinv, note='batch1307')
