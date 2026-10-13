"""specs_f15b003.py - fresh slice 15 batch 3 (see src/f15b003.cpp)."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED


def _r(c):
    return c.rng.getrandbits(32)


def _code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _42b(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x5f2d60, 2, ret=_r(c))
    n = c.rng.choice([0, 1, 3, 7, 20])
    s = c.emu.alloc(n + 8, 1)
    c.emu.wbytes(s, bytes(c.rng.randint(1, 255) for _ in range(n)) + b'\0' + bytes(c.rng.getrandbits(8) for _ in range(7)))
    return [rnd(c, 0x20), s]


def _dbl(c):
    r = c.rng
    k = r.random()
    if k < 0.1:
        return r.choice([0.0, -0.0, float('inf'), float('nan'), 1e300, -1e300, 3.5e38, 1e-40, 1e-320])
    if k < 0.2:
        return struct.unpack('<d', struct.pack('<Q', r.getrandbits(64)))[0]
    return r.uniform(-1e6, 1e6)


def _432(c):
    seq = Seq(c); clear_hooks(c)
    d = c.emu.alloc(8, 8)
    c.emu.wbytes(d, struct.pack('<d', _dbl(c)))
    rec = c.emu.alloc(8, 4)
    # atof stand-in: record the string pointer and a call count, return the double at d in ST0 (cdecl)
    code = b'\x8b\x44\x24\x04\xa3' + struct.pack('<I', rec) + b'\xff\x05' + struct.pack('<I', rec + 4) + \
        b'\xdd\x05' + struct.pack('<I', d) + b'\xc3'
    c.emu.w32(0x6762d4, _code(c, code))
    p = _r(c) if c.rng.random() < 0.75 else 0
    me = obj(c, 0x10, {0x54: stub(c, seq, 1, ret=p)})
    k = c.rng.random()
    df = struct.unpack('<f', struct.pack('<I', _r(c)))[0] if k < 0.3 else c.rng.uniform(-100, 100)
    from pilot import F
    return [me, _r(c), F(df)]


def _54c(c):
    seq = Seq(c); clear_hooks(c)
    me = rnd(c, 0x6400)
    c.emu.w32(me + 0x63ec, obj(c, 0x10, {0x30: stub(c, seq, 4, ret=_r(c))}) if c.rng.random() < 0.85 else 0)
    c.emu.w8(me + 0x7b, c.rng.choice([0, 0, 1, 0x80]))
    c.emu.w32(me + 0x75, c.rng.choice([3, 3, 0, 2, 4, _r(c)]))
    return [me]


def _5f4(c):
    seq = Seq(c); clear_hooks(c)
    rec = c.emu.alloc(16, 4)
    ret = _r(c)

    def h(e, r):
        sp = e.reg('esp')
        e.w32(rec, e.reg('ecx'))
        e.w32(rec + 4, e.r32(e.r32(sp + 4)))       # the value behind the stack pointer argument
        e.w32(rec + 8, e.r32(rec + 8) + 1)
        e.ret(eax=ret, argbytes=4)
    HOOKED.add(0x5f5050)
    c.emu.hook(0x5f5050, h)
    c.emu.w32(0x7003b0, stub(c, seq, 0, ret=_r(c), pop=False))
    me = rnd(c, 0x20)
    lim = _r(c)
    c.emu.w32(me + 8, lim)
    p = rnd(c, 4)
    k = c.rng.random()
    c.emu.w32(p, lim if k < 0.15 else ((lim + 1) & 0xffffffff if k < 0.3 else _r(c)))
    return [me, p]


def _4b5(c):
    seq = Seq(c); clear_hooks(c)
    me = obj(c, 0x100, {0x8c: stub(c, seq, 0)})
    vt = c.emu.alloc(0x40, 4)
    c.emu.w32(vt + 0x34, stub(c, seq, 1, ret=_r(c)))
    c.emu.w32(me + 0xaa, vt)
    return [me]


def _4c2(c):
    seq = Seq(c); clear_hooks(c)
    o = obj(c, 0x10, {0x128: stub(c, seq, 3)})
    db = obj(c, 0x10, {0x58: stub(c, seq, 1, ret=o if c.rng.random() < 0.8 else 0)})
    s = rnd(c, 0x100); c.emu.w32(s + 0x9b, db); c.emu.w32(0x70039c, s)
    return [rnd(c, 0x100), _r(c), _r(c)]


def _65c(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x65bfe0, 4, ret=_r(c))
    return [rnd(c, 0x182b0), _r(c), _r(c), _r(c), _r(c)]


def _54ab(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x5492f0, 0, ret=_r(c))
    return [rnd(c, 0xa280)]


def _4cd(c):
    seq = Seq(c); clear_hooks(c)
    buf = rnd(c, 0x40)
    hook(c, seq, 0x4cd540, 1, ret=buf)
    me = rnd(c, 0x30)
    r = c.rng
    c.emu.w32(me + 0x14, r.choice([0, 0, 1, _r(c)]))
    c.emu.w32(me + 0x18, r.randint(2, 15))
    def sv():
        return r.choice([0, 1, -1, 5, -5, 0x7fffffff, -0x80000000, r.randint(-100, 100)]) & 0xffffffff
    c.emu.w32(me + 0x1c, sv()); c.emu.w32(me + 0x20, sv())
    return [me, _r(c), sv()]


def _4f9(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x43ea20, 0, ret=_r(c))
    hook(c, seq, 0x45c510, 1, this=False, pop=False)
    hook(c, seq, 0x4690b0, 2, this=False, pop=False)
    return [rnd(c, 0x60), c.rng.choice([0, 1, 4, 5, 3, 7, _r(c)])]


def _575(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    hook(c, seq, 0x575800, 0, ret=r.choice([0, 1, 0x100, _r(c)]))
    hook(c, seq, 0x574200, 1, ret=_r(c))
    me = obj(c, 0x40, {0xd8: stub(c, seq, 0, ret=r.choice([0, 0, 1, 0x100, _r(c)]))})
    return [me, _r(c)]


def _4ff(c):
    seq = Seq(c); clear_hooks(c)
    for a in (0x50b4b0, 0x50d750, 0x510b70, 0x511700):
        hook(c, seq, a, 0, this=False)
    hook(c, seq, 0x4690b0, 0, this=False, pop=False)
    c.emu.w32(0x7003a4, obj(c, 0x10, {0xc8: stub(c, seq, 1)}) if c.rng.random() < 0.8 else 0)
    return []


def _63e(c):
    seq = Seq(c); clear_hooks(c)
    me = rnd(c, 0xb950)
    n = c.rng.randint(0, 5)
    c.emu.w32(me + 0xec, n)
    for i in range(n):
        c.emu.w32(me + 0xf0 + 4 * i, obj(c, 0x10, {0x38: stub(c, seq, 0, ret=_r(c))}))
    return [me]


def _612(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x634cf8, 1, this=False)
    hook(c, seq, 0x634ce6, 1, this=False)
    hook(c, seq, 0x4690b0, 2, this=False, pop=False)
    return [rnd(c, 0x10), c.rng.choice([0, 1, 4, 5, 3, 7, _r(c)])]


def _54aa(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    o = rnd(c, 0xd0)
    m = r.choice([0, 1, -1, 100, 0x7fffffff, -0x80000000, r.randint(-1000, 1000)]) & 0xffffffff
    c.emu.w32(o + 0xc4, m)
    me = obj(c, 0x8080, {0xa8: stub(c, seq, 0, ret=o)})
    a = r.choice([m, (m + 1) & 0xffffffff, (m - 1) & 0xffffffff, _r(c), r.randint(-1000, 1000) & 0xffffffff])
    return [me, a]


def _4a3(c):
    seq = Seq(c); clear_hooks(c)
    me = rnd(c, 0x60)
    for off, sl in ((0x48, 0x90), (0x4c, 0x94), (0x50, 0x88)):
        c.emu.w32(me + off, obj(c, 0x10, {sl: stub(c, seq, 1)}) if c.rng.random() < 0.7 else 0)
    return [me, _r(c)]


N = 'f15b003'
S(0x42bdf0, 'FUN_42bdf0 (range from C string)', 'thiscall', None, ret='eax', gen=_42b, note=N + '; 0x5f2d60 hooked')
S(0x432470, 'FUN_432470 (float lookup via atof)', 'thiscall', None, ret='st0', gen=_432, note=N + '; atof IAT stub')
S(0x54c270, 'FUN_54c270 (+0x63ec slot 0x30)', 'thiscall', None, ret=None, gen=_54c, note=N)
S(0x5f4fb0, 'FUN_5f4fb0 (bounded span call)', 'thiscall', None, ret='eax', gen=_5f4, note=N + '; 0x5f5050 hooked, null-handler int3 not run')
S(0x4b59b0, 'CCutSequenceList::Load2', 'thiscall', None, ret=None, gen=_4b5, note=N)
S(0x4c2a70, 'ZMusicControl::SendMessage', 'thiscall', None, ret=None, gen=_4c2, note=N)
S(0x65c7f0, 'FUN_65c7f0 (ctor, vt 0x6c47a0)', 'thiscall', None, ret='eax', gen=_65c, note=N + '; base ctor hooked')
S(0x54abf0, 'FUN_54abf0 (ctor, vt 0x6a36dc)', 'thiscall', None, ret='eax', gen=_54ab, note=N + '; base ctor hooked')
S(0x4cd6f0, 'PRIOREFTAB::AddPrio', 'thiscall', None, ret=None, gen=_4cd, note=N + '; REFTAB::Add hooked')
S(0x4f9930, 'ZCONTROL::~ZCONTROL (deleting)', 'thiscall', None, ret='eax', gen=_4f9, note=N + '; base dtor, delete, lort hooked')
S(0x5758f0, 'ZZoneMap::OnCommand', 'thiscall', None, ret='al', gen=_575, note=N + '; NextMap, 0x574200 hooked')
S(0x4ffbf0, 'ZScriptInterfaceDll::End', 'cdecl', None, ret=None, gen=_4ff, note=N + '; clean() x4, lort hooked')
S(0x63ee30, 'ZDrawBase::InitializeGlobalResources', 'thiscall', None, ret=None, gen=_63e, note=N)
S(0x6125b0, 'FUN_6125b0 (deleting dtor, GDI+ image)', 'thiscall', None, ret='eax', gen=_612, note=N + '; Gdip thunks, lort hooked')
S(0x54aab0, 'FUN_54aab0 (clamp to +0xc4)', 'thiscall', None, ret='eax', gen=_54aa, note=N)
S(0x4a3cb0, 'ZSoundAmbient::ActivateEvents', 'thiscall', None, ret=None, gen=_4a3, note=N)
