"""specs_f15b011.py - fresh slice 15 batch 11 (see src/f15b011.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED
from f15help import phook, codeaddr, loghook, reporter


def _r(c):
    return c.rng.getrandbits(32)


def _seq(vals):
    k = [0]

    def f(e):
        v = vals[k[0] % len(vals)]; k[0] += 1
        return v
    return f


def _code(c, seq, n, ret=0, this=False, pop=False, calls=6):
    a = codeaddr(c)
    loghook(c, seq, a, n, ret=ret, this=this, pop=pop, calls=calls)
    return a


def _sys(c, d=None, size=0x200):
    s = rnd(c, size)
    c.emu.w32(0x70039c, s)
    if d is not None:
        c.emu.w32(s + 0x9b, d)
    return s


def _624(c):
    r = c.rng
    enc = rnd(c, 0x150)
    for i in range(0x100):
        c.emu.w8(enc + 0x4c + i, r.choice([21, 22, 26, 11, 12, 20, 28, 29, 9, 10, 13, 25, 30, 35, 36, 0, 8, r.getrandbits(8)]))
    k = r.choice([0, 1, 2, 5, 12, r.randint(0, 20)])
    buf = rnd(c, 2 * k + 8)
    for i in range(k + 2):
        lo = r.choice([9, 0x24, 0x40, 0x41, 0x7f, 0x80, 0xff, 0x20, r.getrandbits(8)])
        hi = 0 if r.random() < 0.8 else r.choice([0xd8, 0xdc, 0xff, 0xfe, 1, r.getrandbits(8)])
        c.emu.w8(buf + 2 * i, lo); c.emu.w8(buf + 2 * i + 1, hi)
    return [enc, buf, buf + 2 * (k + 2), rnd(c, 4)]


def _455(c):
    seq = Seq(c); clear_hooks(c)
    loghook(c, seq, 0x43de40, 3, this=True, pop=True)
    l = obj(c, 0x10, {4: _code(c, seq, 1, this=True, pop=True)})
    loghook(c, seq, 0x456bf0, 0, ret=l)
    _sys(c, obj(c, 0x60, {0x4c: _code(c, seq, 1, ret=_r(c), this=True, pop=True)}))
    return [rnd(c, 0x100), _r(c), _r(c), _r(c)]


def _601(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x10)
    n = r.choice([0, 1, 2, 4, r.randint(0, 6)])
    arr = rnd(c, 4 * n + 4)
    for i in range(n):
        d = rnd(c, 0x10)
        c.emu.w32(d, r.choice([1, 1, 0, 2, _r(c)]))
        e = rnd(c, 4); c.emu.w32(e, d)
        c.emu.w32(arr + 4 * i, e)
    c.emu.w32(me + 4, arr); c.emu.w32(me + 0xc, n)
    log = c.emu.alloc(4 * 13, 4)
    rv = [r.choice([0, 1, 0, -1 & 0xffffffff, _r(c)]) for _ in range(6)]
    k = [0]

    def cmp(e, rr):
        i = k[0]; k[0] += 1
        if i < 6:
            e.w32(log + 8 * i, e.arg32(0)); e.w32(log + 8 * i + 4, e.arg32(1))
        e.w32(log + 48, k[0])
        e.ret(eax=rv[i % 6])
    c.emu.stub_import('_stricmp', cmp)
    c.emu.w32(0x7003b0, _code(c, seq, 0))
    return [me, _r(c)]


def _5f2(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x10)
    sh = rnd(c, 0x10); c.emu.w32(me + 0xc, sh)
    left = [r.choice([0, 1, 2, 4, r.randint(0, 7)])]

    def st(e, args):
        e.w32(args[1], r.choice([0, _r(c) | 1]))
        if left[0] <= 0:
            return 0
        left[0] -= 1
        return _r(c) | 1
    phook(c, seq, 0x5fc030, 2, this=True, pop=True, act=st)
    loghook(c, seq, 0x4cc1d0, 0, this=True, ret=_r(c), calls=8)
    loghook(c, seq, 0x5f49e0, 0, this=True, ret=_r(c), calls=8)
    edl = c.emu.alloc(4 * 9, 4)
    kk = [0]

    def cmpf(e):
        if kk[0] < 8:
            e.w32(edl + 4 * kk[0], e.reg('edx'))
        kk[0] += 1
        return r.choice([0, 0, 1, -1 & 0xffffffff, 0x100])
    loghook(c, seq, 0x4cc850, 0, this=True, ret=cmpf, calls=8)
    con = obj(c, 0x10, {0x184: _code(c, seq, 4, calls=8)})
    s = obj(c, 0x200, {0x190: _code(c, seq, 0, ret=con, this=True, calls=8)})
    c.emu.w32(0x70039c, s)
    return [me, rnd(c, 0x80)]


def _64d(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    n = r.randint(1, 4)
    bl = []
    for i in range(n):
        reg = rnd(c, 0x400)
        bl.append(reg + 0x100)
    for i, b in enumerate(bl):
        c.emu.w32(b + 8, bl[(i + 1) % n]); c.emu.w32(b + 0xc, bl[(i - 1) % n])
        c.emu.w8(b, r.choice([1, 1, 2, 0, r.getrandbits(8)]))
    b = r.choice(bl)
    me = obj(c, 0x20, {0x2c: _code(c, seq, 1, ret=b, this=True, pop=True),
                       0x34: _code(c, seq, 1, this=True, pop=True)})
    c.emu.w32(me + 8, r.choice(bl + [b]))
    k = r.random()
    e = b + 0x10 + 36 * r.randint(0, 6) if k < 0.6 else (b + r.randint(0x10, 0x2f0) if r.random() < 0.5 else b - r.randint(8, 0xf0))
    return [me, e]


def _64f(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x38, r.choice([0, 0, _r(c)]))
    reporter(c, seq)
    c.emu.w32(0x7003b0, _code(c, seq, 0))
    loghook(c, seq, 0x41e290, 1, ret=rnd(c, 0x34) if r.random() < 0.85 else 0)
    loghook(c, seq, 0x640d40, 1, this=True, pop=True, ret=_r(c))
    return [me]


def _572(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x50)
    w = c.emu.alloc(16, 4)

    def seen(e):
        e.w32(w, e.r32(me)); e.w32(w + 4, e.r32(me + 0x44))
        return 0
    _sys(c, obj(c, 0x40, {0x34: _code(c, seq, 1, ret=seen, this=True, pop=True)}))
    c.emu.w32(0x7003b0, _code(c, seq, 0, ret=_r(c)))
    loghook(c, seq, 0x4690b0, 2, ret=_r(c))
    return [me, r.choice([0, 1, 4, 5, 3, 7, _r(c)])]


def _5db(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    hook(c, seq, 0x469870, 0, ret=_r(c))
    loghook(c, seq, 0x41e290, 1, ret=rnd(c, 0x1c) if r.random() < 0.85 else 0)
    loghook(c, seq, 0x4ccbe0, 2, this=True, pop=True, ret=_r(c))
    _sys(c, obj(c, 0x120, {0x114: _code(c, seq, 4, ret=_r(c), this=True, pop=True)}))
    c.emu.w32(0x714388, _r(c))
    return [rnd(c, 0x50)]


N = 'f15b011'
S(0x624530, 'little2_isPublicId (expat)', 'cdecl', None, ret='eax', gen=_624, note=N + '; 0x62c640 exe code')
S(0x455330, 'FUN_455330 (ZSTDOBJ ctor, vt 0x6828c4)', 'thiscall', None, ret='eax', gen=_455, note=N + '; ZSTDOBJ ctor, template list hooked')
S(0x601670, 'CSdlDataExchange::getExportSymbolFloat', 'thiscall', None, ret='st0', gen=_601, note=N + '; _stricmp Python')
S(0x5f2670, 'ZScriptDll::PlotScripts', 'thiscall', None, ret='eax', gen=_5f2, note=N + '; status, names, striwcmp, console hooked')
S(0x64d930, 'ZDrawArray<ZRoomViewEntry>::Remove', 'thiscall', None, ret=None, gen=_64d, note=N + '; slots 0x2c/0x34 hooked')
S(0x64fd70, 'ZRenderBaseDll::InitBoneModifier', 'thiscall', None, ret=None, gen=_64f, note=N + '; reporter, new, ZRagdollContainer hooked')
S(0x572e70, 'CZoneMenu::~CZoneMenu (deleting)', 'thiscall', None, ret='eax', gen=_572, note=N + '; db slot 0x34, lort hooked')
S(0x5dbfb0, 'FUN_5dbfb0 (ctor, vt 0x6b6ab8)', 'thiscall', None, ret='eax', gen=_5db, note=N + '; base, new, REFTAB, db hooked')
