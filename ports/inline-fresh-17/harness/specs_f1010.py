"""specs_f1010.py - fresh slice 17, batch 10."""
import struct
from pilot import S, F
from specs_f0101 import _rnd, _vt, _hook, _obj
from specs_f0202 import _assert_hook


def _rstr(e, a, n=0x100):
    b = e.rbytes(a, n)
    return b.split(b'\0', 1)[0]


def _logger(c, nargs, strs=()):
    """log manager at 0x700390: slot +0x20(file, line) -> log; log slot +0x2c (cdecl) logs nargs words after the log
    object; argument indexes in strs are logged as the string they point to (they may be stack buffers)."""
    e = c.emu

    def log2c(e, r):
        a = tuple(_rstr(e, e.arg32(k)) if k in strs else e.arg32(k) for k in range(1, nargs + 1))
        e.calllog.append(('log', e.arg32(0)) + a)
        e.ret(eax=c.rng.getrandbits(32), argbytes=0)
    log = _obj(c, 0x20, e.fake_vtable('log', 12, {0x2c: log2c}))
    e.w32(0x700390, _obj(c, 0x20, e.fake_vtable('mgr', 10, {0x20: (lambda e, r: (e.calllog.append(('mgr', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=log, argbytes=8)))})))


def _g490a90(c):
    e = c.emu
    name = _rnd(c, 0x10)

    def calc(e, r):
        e.calllog.append(('calc', e.reg('ecx'), e.arg32(1)))
        e.w32(e.arg32(0), name)
        e.ret(eax=e.arg32(0), argbytes=8)
    e.hook(0x48c4b0, calc)
    e.hook(0x4cbec0, lambda e, r: (e.calllog.append(('dtor', e.r32(e.reg('ecx')))), e.ret(eax=c.rng.getrandbits(32))))

    def s60(e, r):
        e.calllog.append(('read', e.reg('ecx')) + tuple(e.arg32(k) for k in range(5)))
        e.ret(eax=c.rng.getrandbits(32), argbytes=20)
    e.w32(0x700394, _obj(c, 0x10, e.fake_vtable('fs', 0x20, {0x60: s60})))
    return [_rnd(c, 0x10), _rnd(c, 8), c.rng.getrandbits(32)]


def _g4267d0(c):
    e = c.emu
    rv = c.rng.choice([0xffffffff, 0xffffffff, 0, 1, c.rng.getrandbits(32)])
    err = c.rng.getrandbits(32)

    def cf(e, r):
        e.calllog.append(('CreateFileA',) + tuple(e.arg32(k) for k in range(7)))
        e.ret(eax=rv, argbytes=28)
    e.stub_import('CreateFileA', cf)
    e.stub_import('GetLastError', lambda e, r: (e.calllog.append(('GetLastError',)), e.ret(eax=err)))
    msg = bytes(c.rng.randrange(0x21, 0x7f) for _ in range(c.rng.randint(0, 40))) + b'\0'

    def fm(e, r):
        e.calllog.append(('FormatMessageA',) + tuple(e.arg32(k) for k in (0, 1, 2, 3, 5, 6)))
        e.wbytes(e.arg32(4), msg)
        e.ret(eax=len(msg) - 1, argbytes=28)
    e.stub_import('FormatMessageA', fm)
    _logger(c, 3, strs=(3,))
    return [_rnd(c, 8), _rnd(c, 0x20)]


def _g434f10(c):
    e = c.emu
    self_o = _rnd(c, 0x10)
    if c.rng.random() < 0.15:
        e.w32(self_o + 4, 0)
        return [self_o]
    n = c.rng.choice([0, 1, 2, 4])
    nodes = []
    for _ in range(n):
        ent = _obj(c, 0x20, _vt(c, 'ent', 8, {0x14: (1, 4, True)}))
        nd = _rnd(c, 8)
        e.w32(nd, ent)
        nodes.append(nd)
    state = {'i': 0}

    def s4c(e, r):
        e.calllog.append(('first', e.reg('ecx')))
        e.wbytes(e.arg32(0), b'\x11' * 12)
        e.ret(eax=c.rng.getrandbits(32), argbytes=4)

    def s64(e, r):
        it = e.arg32(0)
        e.calllog.append(('next', e.reg('ecx'), e.rbytes(it, 12)))
        i = state['i']
        state['i'] = i + 1
        e.w32(it, i)
        e.ret(eax=nodes[i] if i < len(nodes) else 0, argbytes=4)
    e.w32(self_o + 4, _obj(c, 0x10, e.fake_vtable('lst', 0x20, {0x4c: s4c, 0x64: s64})))
    _logger(c, 2)
    return [self_o]


def _g5aab10(c):
    e = c.emu
    self_o = _rnd(c, 0x480)
    e.w32(self_o + 0x474, _rnd(c, 0x40))
    e.w32(self_o + 0x478, _rnd(c, 0x40))
    _hook(c, 0x5ec090, 2, 8)
    _hook(c, 0x5ed1e0, 5, 0x14)
    # v * 120 stays inside the unsigned range: the out-of-range path of 0x633910 (NaN, >= 2^32) stops the emulator.
    v = c.rng.choice([0.0, 0.5, 1.0, 1.0 / 3, c.rng.uniform(0, 3), c.rng.uniform(0, 3), c.rng.uniform(-0.008, 0),
                      c.rng.uniform(0, 3.5e7), 3.5e7])
    return [self_o, F(v)]


def _g64da90(c):
    e = c.emu
    k = c.rng.randint(1, 4)
    blks = [_rnd(c, 0x90) for _ in range(k)]
    if c.rng.random() < 0.1:
        for b in blks:   # broken ring: every block points at itself
            e.w32(b + 8, b)
            e.w32(b + 0xc, b)
    else:
        for i, b in enumerate(blks):
            e.w32(b + 8, blks[(i + 1) % k])
            e.w32(b + 0xc, blks[(i - 1) % k])
    blk = c.rng.choice(blks)
    e.w8(blk, c.rng.choice([1, 1, 2, 3, 0x80]))
    ent = blk + 0x10 + 0x20 * c.rng.randint(0, 3) + c.rng.choice([0, 0, 4, 0x1f - 6])
    rels = []

    def s2c(e, r):
        e.calllog.append(('blk', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=blk, argbytes=4)

    def s34(e, r):
        e.calllog.append(('free', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=c.rng.getrandbits(32), argbytes=4)
    self_o = _obj(c, 0x10, e.fake_vtable('arr', 0x10, {0x2c: s2c, 0x34: s34}))
    e.w32(self_o + 8, c.rng.choice(blks + [blk]))
    return [self_o, ent]


def _g44cc50(c):
    e = c.emu
    pool = 0 if c.rng.random() < 0.4 else c.rng.getrandbits(32)
    for a, nw in ((0x45c4f0, 2), (0x45c4b0, 1)):
        def h(e, r, a=a, nw=nw):
            p = 0 if c.rng.random() < 0.2 else _rnd(c, 0x50)
            e.calllog.append(('alloc', a) + tuple(e.arg32(k) for k in range(nw)) + (p,))
            e.ret(eax=p)
        e.hook(a, h)
    _hook(c, 0x44c930, 3, 12)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), pool]


def _g605a10(c):
    e = c.emu
    _assert_hook(c)
    self_o = _rnd(c, 8)
    e.w8(self_o + 4, c.rng.choice([0, 1, 2, 3, 3, 4, 5, 0xff]))
    out = _obj(c, 0x10, _vt(c, 'ser', 0x10, {0x2c: (1, 4, True), 0x30: (1, 4, True), 0x38: (1, 4, True)}))
    _hook(c, 0x5f4940, 1, 4)
    _hook(c, 0x5fa220, 1, 4)
    proc = 0 if c.rng.random() < 0.3 else _rnd(c, 0x10)
    return [self_o, out, _rnd(c, 0x10), proc]


def _g5bc1d0(c):
    e = c.emu
    _hook(c, 0x469870, 0, 0)
    db = _obj(c, 0x10, e.fake_vtable('db', 0x50, {0x114: lambda e, r: (e.calllog.append(('reg', e.reg('ecx')) + tuple(e.arg32(k) for k in range(4))), e.ret(eax=c.rng.getrandbits(32), argbytes=16))}))
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    return [0 if c.rng.random() < 0.15 else _rnd(c, 0x50)]


def _g63ef90(c):
    e = c.emu

    def lvt(tag):
        return e.fake_vtable('lst' + tag, 4, {8: lambda e, r: (e.calllog.append(('add' + tag, e.reg('ecx'), e.r32(e.arg32(0)))), e.ret(eax=c.rng.getrandbits(32), argbytes=4))})
    self_o = _rnd(c, 0x300)
    e.w32(self_o + 0x204, lvt('a'))
    e.w32(self_o + 0x1b4, lvt('b'))
    eng = _rnd(c, 0x100)
    e.w32(0x70039c, eng)
    l = _rnd(c, 0x40)
    e.w16(l + 6, 0xffff if c.rng.random() < 0.4 else c.rng.randrange(0x20))
    g = _rnd(c, 0x60)
    fl = c.rng.choice([0, 0, 0x40000000, 0x40000, c.rng.getrandbits(32)])
    e.w32(g + 0x3c, fl)
    if fl & 0x40040000 and c.rng.random() < 0.3:
        e.w32(g + 0x54, 0)
    else:
        m = _obj(c, 0x20, _vt(c, 'm', 0x50, {0x130: (3, 12, True)}))
        e.w8(m + 0x18, c.rng.choice([0, 0x10, 0xef, 0xff]))
        e.w32(g + 0x54, m)
    e.w32(l + 0x38, g)
    _hook(c, 0x4dd8d0, 0, 0, rv=c.rng.choice([0, 1, 0x100, 0xffffff00, c.rng.getrandbits(32)]))
    return [self_o, l]


def _g4f0ad0(c):
    e = c.emu
    self_o = _rnd(c, 0x10)
    w = _rnd(c, 0x40)
    e.w32(w + 0x3c, c.rng.choice([0, 0x400, 0x800, 0xc00]) | (c.rng.getrandbits(32) & ~0xc00))
    e.w32(self_o + 8, w)
    e.w32(self_o + 4, 0 if c.rng.random() < 0.3 else _rnd(c, 8))
    e.w32(self_o + 0xc, _rnd(c, 8))
    _logger(c, 6)
    return [self_o, c.rng.choice([-3, 0, 1, 4, 17, 40]) & 0xffffffff, c.rng.getrandbits(32)]


def _g607310(c):
    e = c.emu
    self_o = _rnd(c, 0x10)
    if c.rng.random() < 0.15:
        for k in range(3):
            e.w32(self_o + 4 * k, 0)
        cap = 0
    else:
        cap = c.rng.randint(0, 8)
        cnt = c.rng.randint(0, cap)
        b = _rnd(c, 4 * cap + 4)
        e.w32(self_o, b)
        e.w32(self_o + 4, b + 4 * cnt)
        e.w32(self_o + 8, b + 4 * cap)

    def al(e, r):
        p = _rnd(c, e.arg32(0) + 4)
        e.calllog.append(('alloc', e.reg('ecx'), e.arg32(0), p))
        e.ret(eax=p, argbytes=4)
    e.hook(0x6014a0, al)
    _hook(c, 0x54f870, 2, 8)
    n = c.rng.choice([0, 1, cap, cap + 1, cap + 3, max(cap - 1, 0), 16])
    return [self_o, n]


N = 'fresh 17 batch 10'
S(0x490a90, 'ZEngineDataBase::GetRoomColiTreeData(void*, unsigned int)', 'thiscall', None, ret=None, gen=_g490a90, note=N + '; CalcCacheFileName / ~MYSTR hooked; SEH and /GS not reproduced')
S(0x4267d0, 'ZSysFileGC::Create(const char*)', 'thiscall', None, ret='eax', gen=_g4267d0, note=N + '; Win32 imports stubbed; /GS not reproduced')
S(0x434f10, 'ZSysFile::PrintBigFiles()', 'thiscall', None, ret=None, gen=_g434f10, note=N)
S(0x5aab10, 'GUESS FUN_5aab10 (HUD gauge SetScale(float))', 'thiscall', None, ret=None, gen=_g5aab10, note=N + '; 0x633910 runs natively; Resize / SetPositionScreen hooked')
S(0x64da90, 'ZDrawArray<ZPrimInstViewEntry, ZPrimInstViewEntry, ZArrayBlock>::Remove(ZPrimInstViewEntry*)', 'thiscall', None, ret=None, gen=_g64da90, note=N)
S(0x44cc50, 'GUESS FUN_44cc50 (factory, 0x1348 bytes)', 'fastcall', None, ret='eax', gen=_g44cc50, note=N + '; allocators and ctor 0x44c930 hooked; SEH not reproduced')
S(0x605a10, 'StackData_t::toSerial(SerialInfo_t&, OpaqueObjectSerialBuffer_t&, Process_t*)', 'thiscall', None, ret=None, gen=_g605a10, note=N + '; getCodeAddrOffset / getOpaqueObjectIndex hooked')
S(0x5bc1d0, 'ZFFCareTaker_C03B::ZFFCareTaker_C03B()', 'thiscall', None, ret='eax', gen=_g5bc1d0, note=N + '; base ctor hooked; SEH not reproduced')
S(0x63ef90, 'ZDrawBase::LightEnter(ZLightDrawEntry*)', 'thiscall', None, ret=None, gen=_g63ef90, note=N + '; WantCameraMsg hooked; geom+0x54 slot +0x130 GUESS 3 args')
S(0x4f0ad0, 'ZWINOBJ::PrintStatus(int, int) const', 'thiscall', None, ret=None, gen=_g4f0ad0, note=N + '; InsertSpace runs natively')
S(0x607310, 'GUESS FUN_607310 (vector<4-byte>::reserve)', 'thiscall', None, ret=None, gen=_g607310, note=N + '; alloc / free 0x54f870 hooked')
