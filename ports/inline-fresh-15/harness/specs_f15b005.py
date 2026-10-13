"""specs_f15b005.py - fresh slice 15 batch 5 (see src/f15b005.cpp)."""
import struct
from pilot import S, F
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED
from f15help import phook, codeaddr, loghook


def _r(c):
    return c.rng.getrandbits(32)


def _light(c, fl=False):
    seq = Seq(c); clear_hooks(c)
    rec = bytes(c.rng.getrandbits(8) for _ in range(0x24))
    log = c.emu.alloc(0x28, 4)
    a80, a98 = codeaddr(c), codeaddr(c)

    def rd(e, args):
        e.wbytes(args[1], rec)

    def wr(e, args):
        e.wbytes(log, bytes(e.rbytes(args[1], 0x24)))
    phook(c, seq, a80, 2, this=True, pop=True, act=rd)
    phook(c, seq, a98, 2, this=True, pop=True, act=wr)
    R = obj(c, 0x10, {0x80: a80, 0x98: a98})
    m = rnd(c, 0x20); c.emu.w32(m + 0x18, R)
    s = rnd(c, 0x1b00); c.emu.w32(s + 0x1aa3, m); c.emu.w32(0x70039c, s)
    me = obj(c, 0x20, {0x238: stub(c, seq, 0)})
    c.emu.w32(me + 8, rnd(c, 0x80))
    return [me, F(c.rng.uniform(-1e4, 1e4)) if fl else _r(c)]


def _gate(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    k = r.randint(0, 3)
    blocks = [rnd(c, 0x10 + 0x34 * 4) for _ in range(k)]
    for i, b in enumerate(blocks):
        c.emu.w16(b + 2, r.choice([0xffff, 0xffff, 0, 1, 2, 3]))
        nxt = blocks[i + 1] if i + 1 < len(blocks) else (blocks[0] if r.random() < 0.5 else 0)
        c.emu.w32(b + 8, nxt)
    me = rnd(c, 0x10)
    start = blocks[r.randrange(k)] if k else 0
    c.emu.w32(me + 8, start)
    nb = rnd(c, 0x10 + 0x34 * 4)
    c.emu.w16(nb + 2, r.choice([0, 1, 2, 3, 0xffff]))
    ok = r.choice([0, 1, 1, 0x100, 0xffffff01])

    def grow(e):
        if ok & 0xff:
            e.w32(me + 8, nb)
        return ok
    hook(c, seq, 0x648cd0, 0, ret=grow)
    return [me]


def _memicmp(c):
    def h(e, r):
        a, b, n = e.arg32(0), e.arg32(1), e.arg32(2)
        res = 0
        for i in range(n):
            x, y = e.r8(a + i), e.r8(b + i)
            x = x + 32 if 65 <= x <= 90 else x
            y = y + 32 if 65 <= y <= 90 else y
            if x != y:
                res = x - y
                break
        e.ret(eax=res & 0xffffffff)
    c.emu.stub_import('_memicmp', h)


def _cstr(c, n, al=b'abAB'):
    s = c.emu.alloc(n + 4, 1)
    c.emu.wbytes(s, bytes(c.rng.choice(al) for _ in range(n)) + b'\0')
    return s


def _stristr(c):
    clear_hooks(c); _memicmp(c)
    r = c.rng
    return [_cstr(c, r.choice([0, 1, 3, 6, 12])), _cstr(c, r.choice([0, 1, 2, 3]))]


def _pubid(c):
    clear_hooks(c)
    r = c.rng
    enc = rnd(c, 0x4c + 0x100)
    for i in range(0x100):
        c.emu.w8(enc + 0x4c + i, r.choice([9, 10, 11, 12, 20, 21, 22, 26, 27, 28, 29, 35, 36, 0, 5, 40, r.getrandbits(8)]))
    n = r.randint(0, 12)
    buf = c.emu.alloc(n + 4, 1)
    c.emu.wbytes(buf, bytes(r.choice([9, 0x24, 0x40, 0x41, 0x20, 0x80, 0xc3, r.getrandbits(8)]) for _ in range(n + 4)))
    nxt = rnd(c, 4)
    return [enc, buf, buf + n + 2, nxt]


def _copy(c):
    clear_hooks(c)
    return [rnd(c, 0x90), rnd(c, 0x90)]


def _51a(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x5193c0, 1, ret=_r(c))
    hook(c, seq, 0x51ace0, 0, ret=_r(c))
    c.emu.w32(0x701730, c.rng.choice([0, 0, 1, _r(c)]))
    return [rnd(c, 0x40), _r(c)]


def _569(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    idv = _r(c)
    ret = r.choice([idv & 0xffff, (idv & 0xffff) | 0x12340000, _r(c)])
    db = obj(c, 0x10, {0x114: stub(c, seq, 4, ret=ret)})
    s = rnd(c, 0x100); c.emu.w32(s + 0x9b, db); c.emu.w32(0x70039c, s)
    hook(c, seq, 0x561cb0, 2, ret=_r(c))
    p = rnd(c, 4)
    c.emu.w32(p, r.choice([0, 6, 7, 0xffffffff, 0x80000000, _r(c)]))
    return [rnd(c, 0x200), idv, p]


def _497(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x4ce1c0, 2, ret=_r(c))
    L = obj(c, 0x10, {0x30: stub(c, seq, 3), 0x50: stub(c, seq, 3)})
    c.emu.w32(0x70038c, L)
    pool = rnd(c, 8)
    me = rnd(c, 0x20); c.emu.w32(me + 0x18, pool)
    g = rnd(c, 0x20); m = rnd(c, 0x20); c.emu.w32(g + 0xc, m)
    return [me, g]


def _fact(base):
    def g(c):
        seq = Seq(c); clear_hooks(c)
        o = rnd(c, 0x60) if c.rng.random() < 0.85 else 0
        a = obj(c, 0x10, {0x44: stub(c, seq, 1, ret=o)})
        db = rnd(c, 0x10); c.emu.w32(db + 8, a)
        s = rnd(c, 0x100); c.emu.w32(s + 0x9b, db); c.emu.w32(0x70039c, s)
        hook(c, seq, base, 0, ret=_r(c))
        return [_r(c)]
    return g


def _4cf(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    s0 = rnd(c, 0x20) if r.random() < 0.5 else 0
    snew = rnd(c, 0x20)
    me = rnd(c, 0x200)
    vt = c.emu.alloc(0x10, 4)
    c.emu.w32(vt + 8, stub(c, seq, 2, ret=s0))
    c.emu.w32(vt + 0, stub(c, seq, 1))
    c.emu.w32(me + 0x1cc, vt)
    hook(c, seq, 0x4d0630, 0, ret=snew)
    for s in (s0, snew):
        if s:
            c.emu.w32(s + 0x11, rnd(c, 0x20) if r.random() < 0.6 else 0)
    return [me, rnd(c, 0x20)]


def _5a5(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x560)
    i = r.randint(1, 4)
    for off in (0x540, 0x544, 0x54e, 0x552):
        arr = rnd(c, 0x10)
        for k in range(4):
            c.emu.w32(arr + 4 * k, obj(c, 0x10, {0x28: stub(c, seq, 0, ret=_r(c))}))
        c.emu.w32(me + off, arr)
    return [me, i, r.choice([2, 3, 2, 3, 0, 1, 4, _r(c)])]


def _4b86(c):
    seq = Seq(c); clear_hooks(c)
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x4c, obj(c, 0x10, {0: stub(c, seq, 1)}) if c.rng.random() < 0.7 else 0)
    db = obj(c, 0x40, {0x34: stub(c, seq, 1, ret=_r(c))})
    s = rnd(c, 0x100); c.emu.w32(s + 0x9b, db); c.emu.w32(0x70039c, s)
    return [me]


N = 'f15b005'
S(0x449670, 'ZOMNILIGHT::SetDiffuseColor', 'thiscall', None, ret=None, gen=_light, note=N + '; light slots Python')
S(0x4497b0, 'ZOMNILIGHT::SetFarRange', 'thiscall', None, ret=None, gen=lambda c: _light(c, True), note=N + '; light slots Python')
S(0x6482f0, 'ZDrawArray<ZGateViewEntry>::Add', 'thiscall', None, ret='eax', gen=_gate, note=N + '; grow 0x648cd0 hooked')
S(0x4cc7f0, 'stristr', 'fastcall', None, ret='eax', gen=_stristr, note=N + '; _memicmp Python stand-in')
S(0x626470, 'FUN_626470 (expat isPublicId)', 'cdecl', None, ret='eax', gen=_pubid, note=N)
S(0x4bf370, 'ZSoundExtend::CopyData', 'thiscall', None, ret=None, gen=_copy, note=N)
S(0x51a9f0, 'FUN_51a9f0 (ctor, vt 0x69f364)', 'thiscall', None, ret='eax', gen=_51a, note=N + '; callees hooked')
S(0x569c30, 'CLinkMenu::Command', 'thiscall', None, ret='eax', gen=_569, note=N + '; CFileWindow::Command hooked')
S(0x4970f0, 'ZGeomBuffer::FreeGeom', 'thiscall', None, ret=None, gen=_497, note=N + '; pool free hooked')
S(0x561b70, 'FUN_561b70 (factory, CBaseWindow vt 0x6a63bc)', 'thiscall', None, ret='eax', gen=_fact(0x561020), note=N + '; CBaseWindow ctor hooked')
S(0x49fcf0, 'FUN_49fcf0 (factory, vt 0x68f494)', 'thiscall', None, ret='eax', gen=_fact(0x469870), note=N + '; base ctor hooked')
S(0x4a3530, 'FUN_4a3530 (factory, vt 0x68fa38)', 'thiscall', None, ret='eax', gen=_fact(0x469870), note=N + '; base ctor hooked')
S(0x4b8430, 'FUN_4b8430 (factory, vt 0x68f24c)', 'thiscall', None, ret='eax', gen=_fact(0x469870), note=N + '; base ctor hooked')
S(0x4cfc70, 'FUN_4cfc70 (hash bucket push)', 'thiscall', None, ret='eax', gen=_4cf, note=N + '; 0x4d0630 hooked')
S(0x5a5730, 'FUN_5a5730 (pair slot 0x28 by kind)', 'thiscall', None, ret=None, gen=_5a5, note=N)
S(0x4b86b0, 'FUN_4b86b0 (dtor body, vt 0x686874)', 'thiscall', None, ret=None, gen=_4b86, note=N)
