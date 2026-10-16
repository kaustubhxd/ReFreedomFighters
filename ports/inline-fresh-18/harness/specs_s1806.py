"""specs_s1806.py - fresh-18 batch 6 (src/batch1806.cpp)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import h18 as h

R = lambda c: c.rng.getrandbits(32)
FC = ('ecx', 'edx')


def logger(c, nargs):
    lg = h.obj(c, {0x2c: h.L(c, 'log2c', nargs, regs=(), pops=0)})
    c.emu.w32(0x700390, h.obj(c, {0x20: h.L(c, 'log20', 2, ret=lg)}))


def memcpy(c):
    def cp(e, rv, a):
        if a[2]:
            e.wbytes(a[0], e.rbytes(a[1], a[2]))
    h.hk(c, 0x634d22, 'memcpy', 3, pops=0, regs=(), wr=cp, ret=lambda e, rv, a: a[0])


def g4d5ba0(c):
    t = [c.rng.randbytes(0x1c) for _ in range(2)]
    if c.rng.random() < 0.3:   # same CRC, different size
        t[1] = t[0][:0xa] + t[1][0xa:0xe] + t[0][0xe:]
    def wr(e, rv, a):
        e.wbytes(a[1], c.rng.choice(t))
    h.hk(c, 0x4d6520, 'findFile', 3, wr=wr, ret=lambda e, rv, a: c.rng.choice([0, 1, 1, 1, 0x100, R(c)]))
    return [R(c), R(c), R(c)]
S(0x4d5ba0, 'FsZip_t::Compare', 'thiscall', None, ret='al', gen=g4d5ba0)


def g51af20(c):
    h.hk(c, 0x51a960, 'base', 2)
    h.hk(c, 0x51b530, 'f51b530', 0)
    c.emu.w32(0x701800, c.rng.choice([0, 1]))
    h.engine(c, 0x9b, h.obj(c, {0x58: h.L(c, 'e58', 1, ret=R(c))}))
    def wr(e, rv, a):
        e.w32(a[0], R(c))
    a = h.rnd(c, 0x20)
    c.emu.w32(a + 0x15, h.obj(c, {0x40: h.L(c, 'a40', 1, wr=wr)}))
    return [h.rnd(c, 0x40), a, R(c)]
S(0x51af20, 'GUESS constructor (vtable 0x69f43c)', 'thiscall', None, ret='eax', gen=g51af20)


def g427320(c):
    logger(c, 1)
    f = h.obj(c, {0x10: h.L(c, 'f10', 1, ret=c.rng.choice([0xffffffff, R(c)]))})
    s = h.obj(c, {0x130: h.L(c, 's130', 1, ret=R(c)), 0x70: h.L(c, 's70', 1, ret=c.rng.choice([0, f])),
                  8: h.L(c, 's8', 1, ret=c.rng.choice([0, R(c), R(c)])), 0x1c: h.L(c, 's1c', 1)}, size=0x140)
    c.emu.w32(0x67608c, h.L(c, 'GetFileSize', 2, regs=(), ret=c.rng.choice([0xffffffff, R(c)])))
    return [s, R(c), c.rng.choice([0, 1, 0x100, R(c)])]
S(0x427320, 'GUESS file size (map: ZSysFileGC::FileTimeToSysTime)', 'thiscall', None, ret='eax', gen=g427320)


CL = [0x12, 0x18, 0x19, 5]


def g6279e0(c):
    enc = h.rnd(c, 0x150)
    for i in range(0x100):
        c.emu.w8(enc + 0x4c + i, c.rng.choice(CL))
    def cls(e, rv, a):
        return c.rng.choice(CL)
    def hk(e, r):
        args = (e.arg32(0) & 0xff, e.arg32(1))   # the exe pushes edx with only dl set
        e.calllog.append(('f62c640', (), args))
        e.ret(eax=c.rng.choice(CL), argbytes=0)
    c.emu.hook(0x62c640, hk)
    k = c.rng.randint(0, 7)
    p = h.rnd(c, 2 * k + 2)
    for i in range(k):
        c.emu.w8(p + 2 * i, c.rng.choice([0, 0, 0, c.rng.randint(1, 255)]))
    out = h.rnd(c, 4)
    return [enc, p, p + 2 * k, out]
S(0x6279e0, 'GUESS UTF-16 class scanner', 'cdecl', None, ret='eax', gen=g6279e0)


def gfactory(size, ctor, extra):
    def g(c):
        buf = h.rnd(c, 0x60)
        h.hk(c, 0x45c4f0, 'alloc', 2, pops=0, regs=(), ret=c.rng.choice([0, buf, buf]))
        h.hk(c, ctor, 'ctor', 3)
        for a in extra:
            h.hk(c, a, 'f%x' % a, 0)
        return [R(c), R(c), R(c), R(c)]
    return g
S(0x5d87a0, 'GUESS ZSTDOBJ factory', 'fastcall', None, ret='eax', gen=gfactory(0x48, 0x43de40, []))
S(0x44a820, 'GUESS ZGEOM factory', 'fastcall', None, ret='eax', gen=gfactory(0x30, 0x45c3a0, [0x4609b0]))


def g5f95e0(c):
    h.hk(c, 0x41e290, 'new', 1, pops=0, regs=(), ret=lambda e, rv, a: R(c))
    return [h.rnd(c, 0x20), c.rng.choice([0, 1, 5, 0x3fffffff, 0x40000000, 0x40000001, R(c)])]
S(0x5f95e0, 'GUESS pool constructor', 'thiscall', None, ret='eax', gen=g5f95e0)


def g601e20(c):
    buf = h.rnd(c, 0x40)
    h.hk(c, 0x41e290, 'new', 1, pops=0, regs=(), ret=buf)
    h.hk(c, 0x603500, 'OpaqueUserType_t', 1)
    h.hk(c, c.emu.r32(0x6b97b4 + 0x50), 'ev50', 1)
    return [R(c), R(c), R(c), R(c)]
S(0x601e20, 'CHostInterface::produceScriptEvent', 'thiscall', None, ret='eax', gen=g601e20)


def g421560(c):
    pat = c.rng.randbytes(0x80)
    h.hk(c, 0x4cbe80, 'MYSTR', 1, wr=lambda e, rv, a: e.wbytes(rv[0], pat))
    h.hk(c, 0x4cbee0, 'MYSTR=', 1)
    h.hk(c, 0x4cbec0, '~MYSTR', 0)
    return [h.obj(c, {0x100: h.L(c, 's100', 1)}, size=0x2600)]
S(0x421560, 'ZSysInterfaceGC::~ZSysInterfaceGC', 'thiscall', None, gen=g421560)


def g4ee6a0(c):
    h.hk(c, 0x4ee0e0, 'f4ee0e0', 2, regs=FC, ret=R(c))
    buf = h.rnd(c, 0xb0)
    h.hk(c, 0x45c4b0, 'alloc', 1, pops=0, regs=(), ret=c.rng.choice([0, buf, buf]))
    h.hk(c, 0x4ee1b0, 'ctor', 3, ret=R(c))
    return [R(c), R(c), R(c), c.rng.choice([0, R(c)])]
S(0x4ee6a0, 'GUESS forward or build (fastcall)', 'fastcall', None, ret='eax', gen=g4ee6a0)


def g4acde0(c):
    h.hk(c, 0x469870, 'geombase', 0)
    h.hk(c, 0x4ccba0, 'REFTAB32', 0)
    return [c.rng.choice([0, h.rnd(c, 0x280), h.rnd(c, 0x280)])]
S(0x4acde0, 'GUESS constructor (vtable 0x68f1a0)', 'thiscall', None, ret='eax', gen=g4acde0)


def g617360(c):
    memcpy(c)
    h.hk(c, 0x659330, 'f659330', 2)
    n = c.rng.randint(0, 4)
    idx = c.rng.choice([0, 0, 1, 3])
    src = h.rnd(c, 36 * 5)
    off = c.rng.randint(0, 0x1000)
    a = h.rnd(c, 0x20)
    c.emu.w16(a + 0xe, n)
    c.emu.w32(a + 0x14, off)
    blk2 = h.rnd(c, 0x30)
    c.emu.w32(blk2 + 0x20, (src - off) & 0xffffffff)
    h.engine(c, 0x1aa3, blk2)
    dst = h.rnd(c, 36 * 8)
    t = h.obj(c, {4: h.L(c, 't4', 2, ret=dst)})
    c.emu.w32(t + 0x30, c.rng.choice([0, dst]))
    x = h.rnd(c, 0x1400)
    c.emu.w32(x + 0x13fa, t)
    s = h.rnd(c, 0xb9b0)
    c.emu.w32(s + 0xb9a4, x)
    p4 = h.rnd(c, 0x10)
    c.emu.w32(p4 + 8, a)
    self = h.rnd(c, 0x40)
    c.emu.w32(self + 4, p4)
    c.emu.w32(self + 8, s)
    c.emu.w32(self + 0x28, idx)
    c.emu.w32(self + 0x30, c.rng.choice([0, 0, 1, R(c)]))
    return [self]
S(0x617360, 'GUESS bone block lock', 'thiscall', None, gen=g617360)
