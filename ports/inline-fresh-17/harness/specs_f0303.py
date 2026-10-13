"""specs_f0303.py - fresh slice 17, batch 3."""
from pilot import S
from specs_f0101 import _rnd, _vt, _hook, _obj
from specs_f0202 import _assert_hook


def _g427e50(c):
    e = c.emu
    rv = c.rng.choice([0xffffffff, 0xffffffff, 0, 1, c.rng.getrandbits(32)])

    def cf(e, r):
        e.calllog.append(('CreateFileA',) + tuple(e.arg32(k) for k in range(7)))
        e.ret(eax=rv, argbytes=28)
    e.stub_import('CreateFileA', cf)

    def log2c(e, r):
        e.calllog.append(('log', 0x2c, e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=c.rng.getrandbits(32), argbytes=0)
    log = _obj(c, 0x20, e.fake_vtable('log', 12, {0x2c: log2c}))
    e.w32(0x700390, _obj(c, 0x20, e.fake_vtable('mgr', 10, {0x20: (lambda e, r: (e.calllog.append(('mgr', 0x20, e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=log, argbytes=8)))})))
    return [_rnd(c, 8), _rnd(c, 0x20)]


def _g6139d0(c):
    e = c.emu
    self_o = _rnd(c, 0x20)
    k = c.rng.randint(0, 5)
    blocks = [_rnd(c, 0x20) for _ in range(k)]
    for i, b in enumerate(blocks):
        e.w16(b + 2, 0xffff if c.rng.random() < 0.6 else c.rng.getrandbits(16))
        nxt = blocks[(i + 1) % k] if (i + 1 < k or c.rng.random() < 0.6) else 0
        e.w32(b + 8, nxt)
    e.w32(self_o + 8, blocks[c.rng.randrange(k)] if k else 0)
    newb = _rnd(c, 0x20)
    ok = c.rng.choice([0, 1, 0x100, 0xff01])

    def grow(e, r):
        e.calllog.append(('grow', e.reg('ecx')))
        if ok & 0xff:
            e.w32(self_o + 8, newb)
        e.ret(eax=ok)
    e.hook(0x613c20, grow)
    _hook(c, 0x613ae0, 0, 0)
    return [self_o]


def _g56b2d0(c):
    _hook(c, 0x564460, 0, 0)
    return [_rnd(c, 0xd00)]


def _g56ca90(c):
    e = c.emu
    self_o = _rnd(c, 0x200)
    cmd = c.rng.getrandbits(32)
    idv = (c.rng.getrandbits(16) << 16) | (cmd & 0xffff) if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    db = _obj(c, 0x20, e.fake_vtable('db', 0x50, {0x114: (lambda e, r: (e.calllog.append(('db', 0x114, e.reg('ecx')) + tuple(e.arg32(k) for k in range(4))), e.ret(eax=idv, argbytes=16)))}))
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    _hook(c, 0x561cb0, 2, 8)
    return [self_o, cmd, _rnd(c, 8)]


def _g499f50(c):
    e = c.emu
    n = c.rng.randint(0, 5)
    state = {'left': n}

    def s4c(e, r):
        p = e.arg32(0)
        e.calllog.append(('t4c', e.reg('ecx')))
        e.w32(p, 0x11110000 + n)
        e.w32(p + 4, 0x2222)
        e.w32(p + 8, 0x3333)
        e.ret(eax=c.rng.getrandbits(32), argbytes=4)

    def s5c(e, r):
        p = e.arg32(0)
        w = (e.r32(p), e.r32(p + 4), e.r32(p + 8))
        v = c.rng.getrandbits(32)
        e.w32(p, state['left'] and 0x5550000 + state['left'])
        state['left'] = max(0, state['left'] - 1)
        e.calllog.append(('t5c', e.reg('ecx'), w, v))
        e.ret(eax=v, argbytes=4)
    tab = _obj(c, 0x20, e.fake_vtable('tab', 0x20, {
        0x14: lambda e, r: (e.calllog.append(('t14', e.reg('ecx'))), e.ret(eax=c.rng.getrandbits(32))),
        0x4c: s4c, 0x5c: s5c}))
    self_o = _obj(c, 0x20, _vt(c, 'sg', 8, {0xc: (1, 4, True)}))
    return [self_o, tab]


def _g422f90(c):
    e = c.emu
    _assert_hook(c)
    self_o = _obj(c, 0x2000, _vt(c, 'sys', 0x80, {0x1d0: (1, 4, True), 0x4c: (1, 4, True)}))
    e.w32(self_o + 0x9b, _obj(c, 0x20, _vt(c, 'db', 0x60, {0x16c: (0, 0, True)})))
    e.w32(0x7003a4, 0 if c.rng.random() < 0.3 else _obj(c, 0x20, _vt(c, 'dll', 8, {0x10: (0, 0, True)})))
    _hook(c, 0x4cc1d0, 0, 0)
    return [self_o]


def _g45b9d0(c):
    e = c.emu
    r = _obj(c, 0x20, _vt(c, 'r', 0x20, {0x60: (3, 12, True)}))
    swap = c.rng.random() < 0.5
    r_alt = _vt(c, 'r2', 0x20, {0x60: (3, 12, True)})
    sv = c.rng.getrandbits(32)

    def s4c(e, _):
        e.calllog.append(('db', 0x4c, e.reg('ecx'), e.arg32(0)))
        if swap:
            e.w32(r, r_alt)       # the original keeps the vtable it read before this call
        e.ret(eax=sv, argbytes=4)     # db slot +0x4c = 0x48ff90 -> 0x497390, ret 4
    db = _obj(c, 0x20, e.fake_vtable('db', 0x50, {0x138: (lambda e, _: (e.calllog.append(('db', 0x138, e.reg('ecx'))), e.ret(eax=r))), 0x4c: s4c}))
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    self_o = _obj(c, 0x40, _vt(c, 'bm', 0x86, {0x110: (2, 8, True), 0x214: (0, 0, True)}))
    _hook(c, 0x43e0f0, 0, 0)
    return [self_o]


N = 'fresh 17 batch 3'
S(0x427e50, 'ZSysFileGC::OpenForRandomAccess(char*)', 'thiscall', None, ret='eax', gen=_g427e50, note=N + '; CreateFileA stubbed')
S(0x6139d0, 'ZDrawArray<ZPrimDrawEntryGC, ZPrimDrawEntry, ZArrayBlock>::Add()', 'thiscall', None, ret='eax', gen=_g6139d0, note=N + '; 0x613c20 (grow) and 0x613ae0 hooked')
S(0x56b2d0, 'GUESS FUN_56b2d0 (dialog constructor)', 'thiscall', None, ret='eax', gen=_g56b2d0, note=N + '; base ctor 0x564460 hooked')
S(0x56ca90, 'CMultiplayerKOTH::Command(unsigned short, void*)', 'thiscall', None, ret='eax', gen=_g56ca90, note=N + '; CFileWindow::Command 0x561cb0 hooked')
S(0x499f50, 'ZSaveGame::AddRefTabRaw(LINKSORTREFTAB*)', 'thiscall', None, ret=None, gen=_g499f50, note=N + '; iterator words logged by value')
S(0x422f90, 'ZSysInterfaceGC::ReloadDLLs()', 'thiscall', None, ret='eax', gen=_g422f90, note=N + '; 0x4cc1d0 hooked, assert hook set')
S(0x45b9d0, 'ZBulletMarks::ClassInit()', 'thiscall', None, ret='eax', gen=_g45b9d0, note=N + '; ZSTDOBJ::ClassInit hooked')
