"""specs_f15b004.py - fresh slice 15 batch 4 (see src/f15b004.cpp)."""
import struct
from pilot import S, F
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED
from f15help import phook, codeaddr, loghook


def _r(c):
    return c.rng.getrandbits(32)


def _seqret(vals):
    """ret callable returning vals[k] on the k-th call (same on both sides: built per case)."""
    st = [0]

    def f(e):
        v = vals[st[0] % len(vals)]
        st[0] += 1
        return v
    return f


def _4d1(c):
    seq = Seq(c); clear_hooks(c)
    n = c.rng.randint(0, 4)
    me = obj(c, 0x20, {0x2c: stub(c, seq, 0, ret=n), 0x40: stub(c, seq, 1, ret=_r(c)), 0x3c: stub(c, seq, 1, ret=_r(c))})
    # p's slot 0x1c records both args; the x/y values differ per call through the count/sequence words
    p = obj(c, 0x20, {0x1c: stub(c, seq, 2)})
    return [me, p]


def _4d3(c):
    seq = Seq(c); clear_hooks(c)
    loghook(c, seq, 0x634273, 2)
    me = rnd(c, 0x20)
    c.emu.w32(me + 0xc, c.rng.choice([0, _r(c)]))
    return [me, c.rng.choice([0, 1, 2, 3, _r(c)])]


def _63d(c):
    seq = Seq(c); clear_hooks(c)
    me = rnd(c, 0x120)
    n = c.rng.randint(0, 5)
    c.emu.w32(me + 0xec, n)
    for i in range(n):
        c.emu.w32(me + 0xf0 + 4 * i, rnd(c, 0x10))
    vals = [c.rng.choice([0, 0, 0, _r(c)]) for _ in range(6)]
    hook(c, seq, 0x64b430, 1, ret=_seqret(vals))
    return [me, _r(c)]


def _572(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x563110, 2, ret=_r(c))
    o = obj(c, 0x10, {0x34c: stub(c, seq, 5, ret=_r(c))})
    me = obj(c, 0x60, {0x84: stub(c, seq, 0, ret=o)})
    return [me, _r(c), _r(c)]


def _4d0(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x4d0fc0, 3, ret=_r(c))
    return [rnd(c, 0x90), _r(c), _r(c), c.rng.choice([0, 1, 7, _r(c)])]


def _57c(c):
    seq = Seq(c); clear_hooks(c)
    s = rnd(c, 0x80)
    c.emu.w8(s + 0x6c, c.rng.choice([0, 0, 0, 1]))
    c.emu.w32(0x70039c, s)
    c.emu.w32(0x70038c, obj(c, 0x10, {0xcc: stub(c, seq, 1)}))
    me = rnd(c, 0x260)
    n = c.rng.choice([0, 1, 2, 3, 0xffffffff, 0x80000000])
    vt = c.emu.alloc(0x40, 4)
    c.emu.w32(vt + 0x14, stub(c, seq, 0, ret=n))
    c.emu.w32(vt + 0x30, stub(c, seq, 1, ret=_r(c)))
    c.emu.w32(me + 0x23c, vt)
    return [me]


def _648(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    k = r.randint(0, 4)
    blocks = [rnd(c, 0x10) for _ in range(k)]
    for i, b in enumerate(blocks):
        c.emu.w16(b + 2, r.choice([0xffff, 0xffff, 0, 5, r.getrandbits(16)]))
        nxt = blocks[i + 1] if i + 1 < len(blocks) else (blocks[0] if r.random() < 0.5 else 0)
        c.emu.w32(b + 8, nxt)
    me = rnd(c, 0x10)
    c.emu.w32(me + 8, blocks[r.randrange(k)] if k else 0)
    hook(c, seq, 0x648d50, 0, ret=r.choice([0, 1, 0x100, 0xffffff01]))
    hook(c, seq, 0x6486e0, 0, ret=_r(c))
    return [me]


def _stricmp(c):
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
            if x == 0:
                break
        e.ret(eax=res & 0xffffffff)
    c.emu.stub_import('_strnicmp', h)


def _str(c, n):
    r = c.rng
    s = c.emu.alloc(n + 4, 1)
    c.emu.wbytes(s, bytes(r.choice(b'abcABC\x00') for _ in range(n)) + bytes(r.choice(b'abcAB\x00') for _ in range(4)))
    return s


def _span(c, base=None, n=None):
    r = c.rng
    n = r.choice([0, 1, 2, 3, 5, 8]) if n is None else n
    s = _str(c, n) if base is None else base
    p = rnd(c, 8)
    c.emu.w32(p, s)
    c.emu.w32(p + 4, (s + n) & 0xffffffff)
    return p


def _5fb2(c):
    clear_hooks(c); _stricmp(c)
    return [_span(c), _span(c)]


def _5fb8(c):
    clear_hooks(c); _stricmp(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3, 5])
    s = c.emu.alloc(n + 4, 1)
    c.emu.wbytes(s, bytes(r.choice(b'abcABC') for _ in range(n)) + b'\0')
    return [_span(c), s]


def _ctor(base, size):
    def g(c):
        seq = Seq(c); clear_hooks(c)
        if base:
            hook(c, seq, base, 0, ret=_r(c))
        return [rnd(c, size)]
    return g


def _572f(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    idv = _r(c)
    ret = r.choice([idv & 0xffff, (idv & 0xffff) | 0x12340000, _r(c)])
    db = obj(c, 0x10, {0x114: stub(c, seq, 4, ret=ret)})
    s = rnd(c, 0x100); c.emu.w32(s + 0x9b, db); c.emu.w32(0x70039c, s)
    hook(c, seq, 0x561cb0, 2, ret=_r(c))
    return [rnd(c, 0x200), idv, _r(c)]


def _fl(c):
    r = c.rng
    k = r.random()
    if k < 0.15:
        return r.choice([0.0, -0.0, float('nan'), float('inf'), -float('inf'), 1e-40])
    return r.uniform(-10, 10)


def _481(c):
    clear_hooks(c)
    a, b, out = c.emu.alloc(12, 4), c.emu.alloc(12, 4), rnd(c, 12)
    for p in (a, b):
        for i in range(3):
            c.emu.wf32(p + 4 * i, _fl(c))
    return [rnd(c, 0x10), out, a, b]


def _63e7(c):
    seq = Seq(c); clear_hooks(c)
    r = c.rng
    g = rnd(c, 0x60)
    h2 = obj(c, 0x10, {0x130: stub(c, seq, 3)})
    swap = r.random() < 0.3
    f0 = codeaddr(c)

    def act(e, args):   # slot 0xf0 may replace [g+0x54]: the port must re-read it, as the exe does
        if swap:
            e.w32(g + 0x54, h2)
    phook(c, seq, f0, 0, ret=_r(c), this=True, pop=True, act=act)
    h = obj(c, 0x10, {0xf0: f0, 0x130: stub(c, seq, 3)})
    c.emu.w32(g + 0x54, h if r.random() < 0.9 else 0)
    e = rnd(c, 0x40)
    c.emu.w8(e + 5, r.choice([0x20, 0x60, 0x60, 0x40, 0, r.getrandbits(8)]))
    if not c.emu.r32(g + 0x54):
        c.emu.w8(e + 5, c.emu.r8(e + 5) & ~0x40)
    c.emu.w32(e + 0x38, g)
    s = rnd(c, 0x80)
    c.emu.w32(s + 0x3c, c.emu.r32(e) if r.random() < 0.7 else _r(c))
    c.emu.w32(0x70039c, s)
    hook(c, seq, 0x4dd8d0, 0, ret=r.choice([0, 1, 0x100, 0xffffff01]))
    return [rnd(c, 0x10), e]


def _427(c):
    seq = Seq(c); clear_hooks(c)
    a1, a2 = codeaddr(c), codeaddr(c)
    log = c.emu.alloc(16 * 4, 4)
    cnt = [0]

    def fill(e, args):
        e.wbytes(args[0], b'save_%08x_%d\0' % (args[1], args[2]))

    def read(e, args):
        e.wbytes(log + 16 * cnt[0], bytes(e.rbytes(args[0], 16)))
        cnt[0] += 1
    phook(c, seq, a1, 3, this=True, pop=True, act=fill)
    phook(c, seq, a2, 1, this=True, pop=True, act=read)
    me = obj(c, 0x20, {0x144: a1, 0x5c: a2})
    return [me, _r(c)]


N = 'f15b004'
S(0x4d1bb0, 'FUN_4d1bb0 (forward entries to p slot 0x1c)', 'thiscall', None, ret=None, gen=_4d1, note=N)
S(0x4d3ff0, 'FUN_4d3ff0 (deleting dtor, vt 0x6965c0)', 'thiscall', None, ret='eax', gen=_4d3, note=N + '; delete hooked')
S(0x63db70, 'FUN_63db70 (first hit over +0xf0 list)', 'thiscall', None, ret='eax', gen=_63d, note=N + '; 0x64b430 hooked')
S(0x5721f0, 'CSoundMenu::OnWindowOpen', 'thiscall', None, ret='al', gen=_572, note=N + '; ZVideoSelector::OnWindowOpen hooked')
S(0x4d0f30, 'FUN_4d0f30 (ZMallocSimple init)', 'thiscall', None, ret='eax', gen=_4d0, note=N + '; AddFreeBlock hooked')
S(0x57cfb0, 'FUN_57cfb0 (+0x23c list to [0x70038c] slot 0xcc)', 'thiscall', None, ret=None, gen=_57c, note=N)
S(0x648430, 'ZDrawArray<ZPrimInstViewEntry>::Add', 'thiscall', None, ret='eax', gen=_648, note=N + '; 0x648d50, 0x6486e0 hooked')
S(0x5fb270, 'FUN_5fb270 (span less-than)', 'stdcall', None, ret='eax', gen=_5fb2, note=N + '; _strnicmp Python stand-in')
S(0x636230, 'FUN_636230 (ctor, DXT1)', 'thiscall', None, ret='eax', gen=_ctor(0, 0x40), note=N)
S(0x572fb0, 'CZoneMenu::Command', 'thiscall', None, ret='eax', gen=_572f, note=N + '; CFileWindow::Command hooked')
S(0x5fb8b0, 'FUN_5fb8b0 (span compare with C string)', 'thiscall', None, ret='eax', gen=_5fb8, note=N + '; _strnicmp Python stand-in')
S(0x481930, 'ZPlayerTest::CheckLineColi', 'thiscall', None, ret='al', gen=_481, nan_heap=True, note=N + '; vadd 0x43e8e0 runs as exe code')
S(0x5492f0, 'FUN_5492f0 (ctor, vt 0x6a3338)', 'thiscall', None, ret='eax', gen=_ctor(0x54cb80, 0xa280), note=N + '; base ctor hooked')
S(0x63e7f0, 'ZDrawBase::GeomDrawEntryUpdate', 'thiscall', None, ret=None, gen=_63e7, note=N + '; WantCameraMsg hooked')
S(0x427f70, 'ZSysFileGC::RemoveSaveGame', 'thiscall', None, ret=None, gen=_427, note=N + '; buffer slots Python, cookie check exe code')
