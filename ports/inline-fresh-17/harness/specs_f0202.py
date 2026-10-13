"""specs_f0202.py - fresh slice 17, batch 2. Stubs log their arguments (never a stack address) and return per-case values."""
from pilot import S
from specs_f0101 import _rnd, _vt, _hook, _obj


def _assert_hook(c):
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('asserthook', lambda e, _: (e.calllog.append(('assert',)), e.ret(eax=c.rng.getrandbits(32)))))


def _logmgr(c):
    e = c.emu
    rv = c.rng.getrandbits(32)

    def log2c(e, r):
        e.calllog.append(('log', 0x2c, e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=rv, argbytes=0)
    log = _obj(c, 0x20, e.fake_vtable('log', 12, {0x2c: log2c}))
    mgr = _obj(c, 0x20, e.fake_vtable('mgr', 10, {0x20: (lambda e, r: (e.calllog.append(('mgr', 0x20, e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=log, argbytes=8)))}))
    e.w32(0x700390, mgr)


def _g6017d0(c):
    _logmgr(c)
    _assert_hook(c)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _g633190(c):
    e = c.emu
    z = _rnd(c, 0x40)
    blk = 0 if c.rng.random() < 0.25 else _rnd(c, 0x20)

    def za(e, r):
        e.calllog.append(('zalloc', e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=blk)
    e.w32(z + 0x20, e.stub_fn('zalloc', za))
    return [c.rng.getrandbits(32) for _ in range(4)] + [z]


def _g54df50(c):
    e = c.emu
    _assert_hook(c)
    self_o = _rnd(c, 0x4100)
    size = c.rng.choice([1, 2, 0x100, 0x4000, c.rng.getrandbits(31)])
    seg = c.rng.randint(-2, 6)
    e.w32(self_o + 0x40a9, size)
    e.w32(self_o + 0x40ad, seg)
    base = (size * seg) & 0xffffffff
    n = (base + c.rng.choice([-1, 0, 1, size - 1, size, size + 1, c.rng.getrandbits(32)])) & 0xffffffff
    e.w32(self_o, e.fake_vtable('sb', 16, {0x34: (lambda e, r: (e.calllog.append(('sb', 0x34, e.reg('ecx'))), e.ret(eax=n)))}))
    return [self_o]


def _g655a10(c):
    e = c.emu
    o1 = _obj(c, 0x200, _vt(c, 'w', 0x81, {0x200: (3, 12, True)}))
    gw = o1 if c.rng.random() < 0.5 else 0
    e.w32(0x725824, 0 if c.rng.random() < 0.4 else _obj(c, 0x200, _vt(c, 'g', 0x81, {0x200: (3, 12, True)})))

    def h(e, r):
        e.calllog.append(('GetWindowLongA', e.arg32(0), e.arg32(1)))
        e.ret(eax=gw, argbytes=8)
    e.stub_import('GetWindowLongA', h)
    return [c.rng.getrandbits(32) for _ in range(4)]


def _g60fdd0(c):
    e = c.emu
    a, b = c.rng.getrandbits(32), c.rng.getrandbits(32)
    e.w32(0x724928, a if c.rng.random() < 0.4 else c.rng.getrandbits(32))
    e.w32(0x72492c, b if c.rng.random() < 0.4 else c.rng.getrandbits(32))

    def h(e, r):
        e.calllog.append(('dev', 0xc8, e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=c.rng.getrandbits(32), argbytes=12)
    e.w32(0x724a00, _obj(c, 0x20, e.fake_vtable('dev', 0x40, {0xc8: h})))
    return [a, b]


def _g423850(c):
    e = c.emu
    self_o = _rnd(c, 0x2600)
    seq = [c.rng.choice([0, 1, 0x100, 0xffffff00]) for _ in range(c.rng.randint(0, 6))]
    ok = c.rng.choice([0, 1, 0x100, 0x2301])

    def s154(e, r):
        a = e.arg32(0)
        v = seq.pop(0) if seq else 0
        if not seq and c.rng.random() < 0.5:
            e.w8(self_o + 0x25ea, 0)
        if not seq and v == 0 and e.r8(self_o + 0x25ea):
            e.w8(self_o + 0x25ea, 0)          # the loop's second exit needs the byte clear; keep it finite
            seq.append(0)
        e.calllog.append(('s154', a, v, e.r8(self_o + 0x25ea)))
        e.ret(eax=v, argbytes=4)
    vt = e.fake_vtable('sys', 0x60, {
        0x14c: lambda e, r: (e.calllog.append(('s14c', e.reg('ecx'), e.arg32(0))), e.ret(eax=c.rng.getrandbits(32), argbytes=4)),
        0x30: lambda e, r: (e.calllog.append(('s30', e.arg32(0))), e.ret(eax=ok, argbytes=4)),
        0x154: s154})
    e.w32(self_o, vt)
    _hook(c, 0x4244a0, 0, 0)
    return [self_o, c.rng.getrandbits(32)]


def _g63ed10(c):
    e = c.emu
    self_o = _obj(c, 0x8300, _vt(c, 'db', 0x20, {4: (0, 0, True), 0x78: (0, 0, True)}))
    e.w32(self_o + 0xec, c.rng.randint(0, 6))
    _hook(c, 0x65f1b0, 0, 0)
    _hook(c, 0x64c8d0, 0, 0)
    return [self_o]


def _g63b110(c):
    e = c.emu
    self_o = _rnd(c, 0x10 + 20 * 40)
    e.w16(self_o + 2, 0xffff if c.rng.random() < 0.2 else c.rng.randint(0, 39))
    return [self_o]


def _g54e950(c):
    e = c.emu
    self_o = _rnd(c, 0x300)
    if c.rng.random() < 0.3:
        e.w32(self_o + 0x2d6, 0)
    if c.rng.random() < 0.3:
        e.w32(self_o + 0x2ca, 0)
    for nm, nw in (('fclose', 1), ('SetEvent', 1), ('WaitForSingleObject', 2)):
        def h(e, r, nm=nm, nw=nw):
            e.calllog.append((nm,) + tuple(e.arg32(k) for k in range(nw)))
            e.ret(eax=c.rng.getrandbits(32), argbytes=0 if nm == 'fclose' else 4 * nw)
        e.stub_import(nm, h)
    return [self_o]


N = 'fresh 17 batch 2'
S(0x6017d0, 'CSdlDataExchange::getExportSymbolNifHandle(const string&, const string&)', 'stdcall', None, ret='eax', gen=_g6017d0, note=N + '; assert hook at 0x7003b0 always set (int3 branch not run)')
S(0x633190, 'inflate_codes_new (zlib)', 'cdecl', None, ret='eax', gen=_g633190, note=N)
S(0x54df50, '_ZSoundBuffer::SegmentSwitch()', 'thiscall', None, ret='al', gen=_g54df50, note=N + '; assert hook always set')
S(0x655a10, 'GUESS FUN_655a10 (window procedure)', 'stdcall', None, ret='eax', gen=_g655a10, note=N + '; GetWindowLongA stubbed')
S(0x60fdd0, 'GUESS FUN_60fdd0 (render states 0x13/0x14 cached)', 'fastcall', None, ret=None, gen=_g60fdd0, note=N + '; EAX not defined by the code')
S(0x423850, 'ZSysInterfaceGC::RunMain(char*)', 'thiscall', None, ret='eax', gen=_g423850, note=N + '; 0x4244a0 hooked')
S(0x63ed10, 'ZDrawBase::Init()', 'thiscall', None, ret=None, gen=_g63ed10, note=N + '; ZGeometryDecal::Init and ZViewBase::Init hooked')
S(0x63b110, 'GUESS FUN_63b110 (free-list pop)', 'thiscall', None, ret='eax', gen=_g63b110, note=N)
S(0x54e950, 'ZSoundStreamerGC::Terminate()', 'thiscall', None, ret=None, gen=_g54e950, note=N + '; fclose/SetEvent/WaitForSingleObject stubbed')
