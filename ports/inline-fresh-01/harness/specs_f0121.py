"""specs_f0121.py - fresh-01 batch 21 (docs/20-fresh-01.md)."""
from pilot import S
from helpers01 import rnd, hk, obj


def _cstr(c, n):
    a = rnd(c, n + 1)
    c.emu.wbytes(a, bytes(c.rng.choice(b'abcdefXYZ_0189') for _ in range(n)) + b'\0')
    return a


def _copy(c):
    src = rnd(c, 0xe0)
    ok = c.rng.random() < 0.8
    c.emu.w32(src, c.emu.logging_vtable('src', 0x80, {0x1e0: lambda e, a: (0x500 | int(ok), None)}, {0x1e0: 1}))
    for o in (0x55, 0x4d):
        c.emu.w32(src + o, 0 if c.rng.random() < 0.25 else _cstr(c, c.rng.randint(0, 12)))
    hk(c, 0x45d5b0, 'ZGEOM::CopyData', 1)
    bufs = [rnd(c, 0x20), rnd(c, 0x20)]

    def new(e, r):
        k = sum(1 for x in e.calllog if x[0] == 'new')
        e.calllog.append(('new', e.arg32(0)))
        e.ret(eax=bufs[k % 2])
    c.emu.hook(0x41e290, new)
    return [rnd(c, 0xe0), src]


def _swz(c):
    n = c.rng.choice([0, 1, 2, 3])
    ents = rnd(c, 0x14 * n + 4)
    for k in range(n):
        w = c.rng.choice([1, 2, 4, 8, 3, 0, 0xffffffff])
        h = c.rng.choice([1, 2, 4, 8, 5, 0, 0xfffffffe])
        if w >= 0x80000000 and h >= 0x80000000:
            h = 2
        c.emu.w32(ents + 0x14 * k + 4, w)
        c.emu.w32(ents + 0x14 * k + 8, h)
        c.emu.w32(ents + 0x14 * k + 0x10, rnd(c, 0x100))
    self_ = rnd(c, 0x20)
    c.emu.w32(self_ + 0x10, n if c.rng.random() < 0.9 else 0xffffffff)
    c.emu.w32(self_ + 0x14, ents)
    bufs = [c.emu.alloc(0x1000, 4) for _ in range(n)]

    def new(e, r):
        k = sum(1 for x in e.calllog if x[0] == 'new')
        e.calllog.append(('new', e.arg32(0)))
        e.ret(eax=bufs[k])
    c.emu.hook(0x41e290, new)

    def mc(e, r):
        d, s_, k = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memcpy', d, s_, k))
        if k <= 0x100:
            e.wbytes(d, e.rbytes(s_, k))
        e.ret(eax=d)
    c.emu.stub_import('VCRUNTIME140.dll!memcpy', mc)
    hk(c, 0x634273, 'delete', 2, regs=(), pop=False)
    return [self_]


S(0x4559d0, 'ZParticleTemplate::CopyData', 'thiscall', None, ret=None, gen=_copy)
S(0x639e90, 'texture swizzle 0x639e90', 'thiscall', None, ret=None, gen=_swz)
