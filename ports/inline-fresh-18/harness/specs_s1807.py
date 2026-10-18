"""specs_s1807.py - fresh-18 batch 7 (src/batch1807.cpp). 0x7003b0 is a logging stub where the code can assert."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import h18 as h

R = lambda c: c.rng.getrandbits(32)
FC = ('ecx', 'edx')


def logger(c, nargs):
    lg = h.obj(c, {0x2c: h.L(c, 'log2c', nargs, regs=(), pops=0)})
    c.emu.w32(0x700390, h.obj(c, {0x20: h.L(c, 'log20', 2, ret=lg)}))


def assert_stub(c):
    c.emu.w32(0x7003b0, h.L(c, 'assert', 0, regs=()))


def memcpy(c):
    def cp(e, rv, a):
        if a[2]:
            e.wbytes(a[0], e.rbytes(a[1], a[2]))
    h.hk(c, 0x634d22, 'memcpy', 3, pops=0, regs=(), wr=cp, ret=lambda e, rv, a: a[0])


def fwd_or_build(fwd, size, ctor):
    def g(c):
        h.hk(c, fwd, 'fwd', 2, regs=FC, ret=R(c))
        buf = h.rnd(c, size + 8)
        h.hk(c, 0x45c4b0, 'alloc', 1, pops=0, regs=(), ret=c.rng.choice([0, buf, buf]))
        h.hk(c, ctor, 'ctor', 3, ret=R(c))
        return [R(c), R(c), R(c), c.rng.choice([0, R(c)])]
    return g
S(0x452a20, 'GUESS forward or build (fastcall)', 'fastcall', None, ret='eax', gen=fwd_or_build(0x4528f0, 0x24, 0x447640))
S(0x4f4460, 'GUESS forward or build (fastcall)', 'fastcall', None, ret='eax', gen=fwd_or_build(0x4f42f0, 0xb4, 0x4ee1b0))


def g5a58a0(c):
    h.hk(c, 0x5ec5a0, 'SetDrawCount', 1)
    return [h.rnd(c, 0x640)]
S(0x5a58a0, 'GUESS sprites SetDrawCount(0)', 'thiscall', None, gen=g5a58a0)


def g4d16e0(c):
    memcpy(c)
    nb = h.rnd(c, 0x20)
    sb = h.rnd(c, 0x40)
    h.hk(c, 0x41e290, 'new', 1, pops=0, regs=(), ret=[c.rng.choice([0, nb, nb, nb]), sb])
    name = h.rnd(c, 0x30)
    c.emu.w8(name + c.rng.randint(0, 0x20), 0)
    s = h.rnd(c, 0x30)
    c.emu.w32(s + 0x1c, c.rng.choice([0, h.rnd(c, 0x20)]))
    return [s, name]
S(0x4d16e0, 'GUESS name list append', 'thiscall', None, gen=g4d16e0)


def g57d8a0(c):
    h.hk(c, 0x562440, 'CBaseWindow::Init', 0)
    h.hk(c, 0x57dd10, 'f57dd10', 0)
    h.hk(c, 0x4db500, 'GetPos', 1, wr=lambda e, rv, a: e.wbytes(a[0], c.rng.randbytes(12)))
    h.hk(c, 0x43e8e0, 'f43e8e0', 1, regs=FC, wr=lambda e, rv, a: e.wbytes(rv[0], c.rng.randbytes(12)))
    s = h.rnd(c, 0x360)
    for off in (0x310, 0x314, 0x54):
        o = h.obj(c, {0x70: h.L(c, 'o70_%x' % off, 1)})
        c.emu.w32(o + 8, R(c))
        c.emu.w32(s + off, o)
    return [s]
S(0x57d8a0, 'GUESS window Init (aim children)', 'thiscall', None, gen=g57d8a0, stack_arg_bytes=12)


def g63f220(c):
    assert_stub(c)
    h.hk(c, 0x63ef90, 'LightEnter', 1)
    h.hk(c, 0x4db6c0, 'GetRootTM', 2)
    h.hk(c, 0x4ce7b0, 'ZAllocIndex::New', 0, ret=c.rng.choice([0xfff, 0x1fff, c.rng.randint(0, 0xffe), R(c)]))
    tab = h.rnd(c, 0x4000)
    e = h.rnd(c, 0x40)
    idx = c.rng.choice([0, 0, R(c) & 0xffff])
    c.emu.w32(tab + 4 * (idx & 0xfff), e)
    g = h.rnd(c, 0x60)
    c.emu.w16(g + 0x5a, idx)
    s = h.rnd(c, 0xb9a0)
    c.emu.w32(s + 0x68, tab)
    c.emu.w32(s + 0x230, h.obj(c, {8: h.L(c, 'newentry', 0, ret=c.rng.choice([0, h.rnd(c, 0x40)]))}))
    return [s, g]
S(0x63f220, 'ZDrawBase::OnLightNotify', 'thiscall', None, ret='eax', gen=g63f220)


def g555c60(c):
    assert_stub(c)
    logger(c, 3)
    p = h.rnd(c, 8)
    c.emu.w8(p + 4, c.rng.choice([0, 1, 1, c.rng.randint(2, 255)]))
    q = h.rnd(c, 8)
    h.hk(c, 0x5003d0, 'param', 1, ret=[p, q])
    h.hk(c, 0x5002f0, 'setint', 1)
    gi = h.rnd(c, 0x40)
    hh = h.rnd(c, 0x10)
    c.emu.w32(hh + 8, gi)
    h.engine(c, 0x9b, h.obj(c, {0x58: h.L(c, 'e58', 1, ret=c.rng.choice([0, hh]))}))
    prm = h.rnd(c, 0x10)
    return [R(c), prm]
S(0x555c60, 'GUESS script call (geom flag 0x1000)', 'thiscall', None, gen=g555c60)


def gfactory(ctor, extra=None):
    def g(c):
        buf = h.rnd(c, 0x60)
        h.hk(c, 0x45c4f0, 'alloc', 2, pops=0, regs=(), ret=c.rng.choice([0, buf, buf]))
        h.hk(c, ctor, 'ctor', 3)
        if extra:
            extra(c)
        return [R(c), R(c), R(c), R(c)]
    return g
S(0x5734e0, 'GUESS ZSTDOBJ factory', 'fastcall', None, ret='eax', gen=gfactory(0x43de40))


def e446(c):
    db = h.rnd(c, 0xc00)
    c.emu.w8(db + 0xbad, c.rng.choice([0, 1]))
    h.engine(c, 0x9b, db)
S(0x446fe0, 'GUESS ZGEOM factory', 'fastcall', None, ret='eax', gen=gfactory(0x45c3a0, e446))


def g5d60e0(c):
    assert_stub(c)
    h.hk(c, 0x4690b0, 'SetState', 2, pops=0, regs=())
    h.engine(c, 0x9b, h.obj(c, {0x34: h.L(c, 'e34', 1)}))
    return [h.rnd(c, 0x50), c.rng.choice([0, 1, 4, 5, 7, R(c)])]
S(0x5d60e0, 'CLensFlareControl::~CLensFlareControl', 'thiscall', None, ret='eax', gen=g5d60e0)


def g435920(c):
    t = h.rnd(c, 0x30)
    n = h.rnd(c, 0x20)
    h.hk(c, 0x41e290, 'new', 1, pops=0, regs=(), ret=lambda e, rv, a: t if a[0] == 0x28 else c.rng.choice([0, n, n]))
    # a failed table new crashes in the exe (null vtable); not generated
    tab = h.obj(c, {0x84: h.L(c, 't84', 1)})
    h.hk(c, 0x4cca60, 'LINKREFTAB', 2, ret=tab)
    h.hk(c, 0x4d4c90, 'f4d4c90', 2, ret=R(c))
    s = h.rnd(c, 0x10)
    c.emu.w32(s + 4, c.rng.choice([0, tab]))
    return [s, R(c), R(c)]
S(0x435920, 'ZSysFile::UseBig', 'thiscall', None, ret='al', gen=g435920)


def g490d20(c):
    pat = c.rng.randbytes(0x80)
    h.hk(c, 0x48c4b0, 'CalcCacheFileName', 2, wr=lambda e, rv, a: e.wbytes(a[0], pat), ret=lambda e, rv, a: a[0])
    # 0x4cc1d0 (MYSTR::c_str: mov eax,[ecx]; ret) runs as exe code on both sides
    h.hk(c, 0x4cbec0, '~MYSTR', 0)
    c.emu.w32(0x700394, h.obj(c, {0x60: h.L(c, 'db60', 5)}))
    def s90(e, r):
        e.calllog.append(('s90', (e.reg('ecx'),), tuple(e.arg32(k) for k in range(3))))
        e.ret(eax=0, argbytes=12, st0=c.fv())
    s = h.obj(c, {0x90: c.emu.stub_fn('s90', s90)})
    return [s, R(c), R(c)]
S(0x490d20, 'ZEngineDataBase::GetSoundData', 'thiscall', None, gen=g490d20)


def g5bc0a0(c):
    x = h.obj(c, {0x60: h.L(c, 'x60', 3)})
    h.engine(c, 0x9b, h.obj(c, {0x58: h.L(c, 'e58', 1, ret=R(c)), 0x138: h.L(c, 'e138', 0, ret=x),
                                0x4c: h.L(c, 'e4c', 1, ret=R(c))}, size=0x140))
    def wr40(e, rv, a):
        e.w32(a[0], R(c))
    lg = h.obj(c, {0x40: h.L(c, 'l40', 1, wr=wr40), 0x68: h.L(c, 'l68', 1), 0x50: h.L(c, 'l50', 1)})
    return [h.rnd(c, 0x70), lg]
S(0x5bc0a0, 'ZFFCareTaker_C03A::Load', 'thiscall', None, ret='al', gen=g5bc0a0)


def g5f9720(c):
    h.hk(c, 0x41e290, 'new', 1, pops=0, regs=(), ret=R(c))
    h.hk(c, 0x6014a0, 'alloc', 1, ret=h.rnd(c, 0x10))
    return [h.rnd(c, 0x20)]
S(0x5f9720, 'GUESS constructor (two buffers)', 'thiscall', None, ret='eax', gen=g5f9720)
