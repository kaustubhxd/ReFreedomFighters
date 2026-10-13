"""specs_f15b008.py - fresh slice 15 batch 8 (see src/f15b008.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED
from f15help import phook, codeaddr, loghook


def _r(c):
    return c.rng.getrandbits(32)


def _sys(c, db=None, extra=None):
    s = rnd(c, 0x200)
    if db is not None:
        c.emu.w32(s + 0x9b, db)
    for k, v in (extra or {}).items():
        c.emu.w32(s + k, v)
    c.emu.w32(0x70039c, s)
    return s


def _seq(vals):
    k = [0]

    def f(e):
        v = vals[k[0] % len(vals)]; k[0] += 1
        return v
    return f


def _5ab(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = rnd(c, 0xb0)
    vlog = c.emu.alloc(16, 4)
    k = [0]

    def seen(e):
        e.w32(vlog + 4 * (k[0] % 4), e.r32(me)); k[0] += 1
        return 0
    loghook(c, seq, 0x634273, 2, ret=seen)
    loghook(c, seq, 0x54f870, 2, this=True, pop=True, ret=seen)
    c.emu.w32(me + 0x6a, obj(c, 0x10, {0: loghook_code(c, seq, 1, seen)}) if r.random() < 0.7 else 0)
    b = _r(c)
    c.emu.w32(me + 0x6e, b)
    c.emu.w32(me + 0x76, (b + r.choice([0, 0, 0x10, 0x30, 0x18, 0xf, -0x20, _r(c)])) & 0xffffffff)
    return [me, r.choice([0, 1, 2, 3, _r(c)])]


def loghook_code(c, seq, n, ret=0):
    a = codeaddr(c)
    loghook(c, seq, a, n, ret=ret, this=True, pop=True)
    return a


def _4fb(c):
    seq = Seq(c); clear_hooks(c)
    o = rnd(c, 0xa0) if c.rng.random() < 0.85 else 0
    a = obj(c, 0x10, {0x44: stub(c, seq, 1, ret=o)})
    d = rnd(c, 0x10); c.emu.w32(d + 8, a)
    _sys(c, db=d)
    hook(c, seq, 0x469870, 0, ret=_r(c))
    loghook(c, seq, 0x4ccba0, 0, this=True, pop=True)
    return [_r(c)]


def _57c(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x610100, 1, ret=_r(c))
    loghook(c, seq, 0x4e5e60, 0, this=True, ret=_seq([_r(c) for _ in range(5)]))
    _sys(c, db=obj(c, 0x60, {0x58: loghook_code(c, seq, 1, _seq([_r(c), _r(c)]))}))
    return [rnd(c, 0x320), rnd(c, 0x10)]


def _cache(c):
    seq = Seq(c); clear_hooks(c)
    tok = _r(c)
    log = c.emu.alloc(16, 4)

    def calc(e, args):
        e.w32(args[0], tok)
        e.w32(log, args[1])
    phook(c, seq, 0x48c4b0, 2, pop=True, act=calc)

    def dt(e, args):
        e.w32(log + 4, e.r32(e.reg('ecx')))
        e.w32(log + 8, e.r32(log + 8) + 1)
    phook(c, seq, 0x4cbec0, 0, this=False, pop=True, act=dt)
    f = obj(c, 0x40, {0x30: loghook_code(c, seq, 2, _r(c))})
    c.emu.w32(0x700394, f)
    return []


def _522(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    p = rnd(c, 0x20) if r.random() < 0.85 else 0
    loghook(c, seq, 0x41e290, 1, ret=p)
    hook(c, seq, 0x51a9f0, 1, ret=_r(c))
    hook(c, seq, 0x522c50, 0, ret=_r(c))
    c.emu.w32(0x701a78, r.choice([0, 0, 1, _r(c)]))
    return [_r(c)]


N = 'f15b008'
S(0x5ab4f0, 'CMessageBasics::~CMessageBasics (deleting)', 'thiscall', None, ret='eax', gen=_5ab, note=N + '; free, delete hooked')
S(0x4fbc30, 'FUN_4fbc30 (factory, vt 0x69c4b0)', 'thiscall', None, ret='eax', gen=_4fb, note=N + '; base ctor, REFTAB32 hooked')
S(0x57cd30, 'FUN_57cd30 (copy data block)', 'thiscall', None, ret=None, gen=_57c, note=N + '; DBREAD, CopyData hooked')
S(0x4910b0, 'ZEngineDataBase::GetStaticSize', 'cdecl', None, ret='eax', gen=_cache, note=N + '; CalcCacheFileName, ~MYSTR hooked')
S(0x491470, 'ZEngineDataBase::GetWaveDataSize', 'cdecl', None, ret='eax', gen=_cache, note=N + '; CalcCacheFileName, ~MYSTR hooked')
S(0x522d30, 'FUN_522d30 (new + ctor, vt 0x6a06f4)', 'thiscall', None, ret='eax', gen=_522, note=N + '; new, 0x51a9f0, 0x522c50 hooked')
