"""specs_f0909.py - fresh slice 17, batch 9."""
from pilot import S, F
from specs_f0101 import _rnd, _vt, _hook, _obj
from specs_f0202 import _logmgr


def _new_hook(c, null_p=0.2):
    e = c.emu

    def new(e, r):
        n = e.arg32(0)
        p = 0 if c.rng.random() < null_p else e.alloc(n + 8, 4, 0xab)
        e.calllog.append(('new', n, p))
        e.ret(eax=p)
    e.hook(0x41e290, new)


def _g602090(c):
    e = c.emu
    _new_hook(c)
    _hook(c, 0x600f20, 3, 12)
    self_o = _rnd(c, 0x10)
    cap = c.rng.randint(1, 6)
    e.w32(self_o + 4, _rnd(c, 4 * (cap + 2)))
    e.w32(self_o + 8, cap)
    e.w32(self_o + 0xc, c.rng.randint(0, cap))
    _hook(c, 0x5f4630, 0, 0)
    return [self_o] + [c.rng.getrandbits(32) for _ in range(3)]


def _factory(glob, post):
    def g(c):
        e = c.emu
        _new_hook(c)
        _hook(c, 0x5193c0, 1, 4)
        _hook(c, post, 0, 0)
        e.w32(glob, 0 if c.rng.random() < 0.6 else c.rng.getrandbits(32))
        return [_rnd(c, 0x20)]
    return g


def _g42f290(c):
    e = c.emu
    _logmgr(c)
    size = c.rng.choice([0, -1, 1, 5, 40]) & 0xffffffff
    got = c.rng.choice([size, size, 0, 3])

    def s30(e, r):
        e.calllog.append(('size', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=size, argbytes=8)

    def s60(e, r):
        e.calllog.append(('read', e.reg('ecx')) + tuple(e.arg32(k) for k in range(5)))
        e.ret(eax=got, argbytes=20)
    e.w32(0x700394, _obj(c, 0x10, e.fake_vtable('fs', 0x20, {0x30: s30, 0x60: s60})))
    mgr = e.r32(0x700390)

    def s34(e, r):
        e.calllog.append(('log34', e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=0)
    vt = e.r32(mgr)
    e.w32(vt + 0x34, e.stub_fn('log34', s34))
    return [_rnd(c, 8), _rnd(c, 0x40), _rnd(c, 8)]


def _g64f610(c):
    e = c.emu
    refs = [c.rng.getrandbits(32), c.rng.getrandbits(32)]
    has = c.rng.choice([0, 0, 1, 0x100])

    def lvt(tag):
        return e.fake_vtable('lst' + tag, 0x30, {
            0x28: lambda e, r: (e.calllog.append(('has' + tag, e.reg('ecx'), e.arg32(0))), e.ret(eax=has, argbytes=4)),
            0x98: lambda e, r: (e.calllog.append(('add' + tag, e.reg('ecx'), e.arg32(0), e.arg32(1), e.arg32(2))), e.ret(eax=1, argbytes=12))})
    lst = _obj(c, 0x10, lvt('0'))
    swap = c.rng.random() < 0.5
    alts = [lvt('1'), lvt('2')]

    def s4c(e, r):
        v = refs.pop(0) if refs else 0
        e.calllog.append(('ref', e.reg('ecx'), e.arg32(0), v))
        if swap and alts:
            e.w32(lst, alts.pop(0))       # the original uses the list vtable read before each db call
        e.ret(eax=v, argbytes=4)
    db = _obj(c, 0x10, e.fake_vtable('db', 0x20, {0x4c: s4c}))
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    self_o = _obj(c, 0xc8, _vt(c, 'rnd', 0x30, {0xb0: (1, 4, True)}))
    e.w32(self_o + 0x8c, lst)
    view = 0 if c.rng.random() < 0.3 else _rnd(c, 8)
    if view:
        e.w8(view + 5, c.rng.choice([0, 1, 0x80]))
    e.w32(self_o + 0xbd, view)
    _hook(c, 0x64f6a0, 1, 4)
    return [self_o, _rnd(c, 8), F(c.rng.uniform(-10, 10))]


def _g5f2b90(c):
    e = c.emu
    self_o = _rnd(c, 0x1020)
    cnt = c.rng.choice([0, 0, 2, 5])
    e.w32(self_o + 0x1010, cnt)
    n = c.rng.choice([0, cnt, cnt + 1, cnt + 4, 1])
    msgs = _obj(c, 0x10, e.fake_vtable('msgs', 8, {
        0x0c: lambda e, r: (e.calllog.append(('n', e.reg('ecx'))), e.ret(eax=n)),
        0x08: lambda e, r: (e.calllog.append(('name', e.reg('ecx'), e.arg32(0))), e.ret(eax=0x700000 + e.arg32(0), argbytes=4))}))
    a = _rnd(c, 0x40)
    e.w32(a + 0x3c, msgs)
    b = _rnd(c, 8)
    e.w32(b + 4, a)
    e.w32(self_o + 0xc, b)
    db = _obj(c, 0x10, e.fake_vtable('db', 0x50, {0x114: lambda e, r: (e.calllog.append(('reg', e.reg('ecx')) + tuple(e.arg32(k) for k in range(4))), e.ret(eax=(c.rng.getrandbits(16) << 16) | c.rng.randrange(0x800), argbytes=16))}))
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    return [self_o]


def _g426410(c):
    e = c.emu
    # The function writes the global 0x700394. Set it here so both runs start from the same value: values written by a
    # gen (mem_write) do not mark the image dirty, so an earlier case can leave the global changed (harness gotcha).
    e.w32(0x700394, 0x0bad0bad)
    _new_hook(c)
    _hook(c, 0x433ec0, 0, 0)
    _hook(c, 0x4cca60, 2, 8)
    return [_rnd(c, 0x120)]


def _g43e290(c):
    e = c.emu
    pool = 0 if c.rng.random() < 0.4 else c.rng.getrandbits(32)
    for a, nw in ((0x45c4f0, 2), (0x45c4b0, 1)):
        def h(e, r, a=a, nw=nw):
            p = 0 if c.rng.random() < 0.2 else _rnd(c, 0x50)
            e.calllog.append(('alloc', a) + tuple(e.arg32(k) for k in range(nw)) + (p,))
            e.ret(eax=p)
        e.hook(a, h)
    _hook(c, 0x43e190, 3, 12)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), pool]


N = 'fresh 17 batch 9'
S(0x602090, 'CSdlDataExchange::setExportSymbol(const char*, void*, const char*)', 'thiscall', None, ret=None, gen=_g602090, note=N + '; new / 0x600f20 / grow 0x5f4630 hooked; SEH not reproduced')
S(0x51add0, 'GUESS FUN_51add0 (factory, vtable 0x69f364)', 'thiscall', None, ret='eax', gen=_factory(0x701730, 0x51ace0), note=N + '; SEH not reproduced')
S(0x51f290, 'GUESS FUN_51f290 (factory, vtable 0x69fa64)', 'thiscall', None, ret='eax', gen=_factory(0x7018d8, 0x51f170), note=N + '; same shape')
S(0x42f290, 'ZSysInterface::ReadIniFileToMem(char*, const char*)', 'thiscall', None, ret='al', gen=_g42f290, note=N)
S(0x64f610, 'ZRender::AddCamera(ZCAMERA*, float)', 'thiscall', None, ret=None, gen=_g64f610, note=N + '; db slot +0x4c is ret 4; AddCameraToView hooked')
S(0x5f2b90, 'ZScriptDll::UpdateMsgToEventId()', 'thiscall', None, ret=None, gen=_g5f2b90, note=N + '; RegisterZMsg stubbed (ids < 0x800)')
S(0x426410, 'GUESS FUN_426410 (ZSysFileGC constructor)', 'thiscall', None, ret='eax', gen=_g426410, note=N + '; base ctor / LINKREFTAB ctor hooked; SEH not reproduced')
S(0x43e290, 'GUESS FUN_43e290 (ZHELPER factory)', 'fastcall', None, ret='eax', gen=_g43e290, note=N + '; allocators and ZHELPER ctor hooked; SEH not reproduced')
