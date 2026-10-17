"""specs_f0117.py - fresh-01 batch 17 (docs/20-fresh-01.md)."""
import struct
from pilot import S
from helpers01 import rnd, hk, obj


def _handler(c):
    def hnd(e, r):
        e.calllog.append(('handler',))
        e.ret(eax=0xbad)
    c.emu.w32(0x7003b0, c.emu.stub_fn('handler', hnd))


def _logmgr(c, n):
    def s2c(e, r):
        e.calllog.append(('log',) + tuple(e.arg32(k) for k in range(n)))
        e.ret(eax=0x10910000)
    o = rnd(c, 0x20)
    c.emu.w32(o, c.emu.fake_vtable('logger', 0x10, {0x2c: s2c}))
    c.emu.w32(0x700390, obj(c, 0x20, 'mgr', 0x10, {0x20: lambda e, a: (o, None)}, {0x20: 2}))


def _ctor(c):
    eng = rnd(c, 0x1b00)
    c.emu.w32(0x70039c, eng)
    h = rnd(c, 0x30)
    c.emu.w32(eng + 0x1aa3, h)
    pool = rnd(c, 0x400)
    c.emu.w32(h + 0x20, pool)
    b = rnd(c, 0x20)
    q = rnd(c, 0x10)
    p = rnd(c, 0x20)
    c.emu.w32(b + 0x10, q)
    c.emu.w32(q + 8, p)
    n = c.rng.randint(0, 6)
    c.emu.w16(p + 0xe, n)
    c.emu.w32(p + 0x14, c.rng.randint(0, 0x100))
    cc = c.emu.alloc(0xb9b0, 4)
    c.emu.w32(cc + 0xb9a8, c.rng.getrandbits(32))
    hold = rnd(c, 0x1400)
    c.emu.w32(cc + 0xb9a4, hold)
    dst = rnd(c, 0x800)
    src = obj(c, 0x40, 'src', 4, {4: lambda e, a: (dst, None)}, {4: 2})
    if c.rng.random() < 0.4:
        c.emu.w32(src + 0x30, 0)
    else:
        c.emu.w32(src + 0x30, rnd(c, 0x800))
    c.emu.w32(hold + 0x13fa, src)
    idx = c.rng.choice([0, 0, 1, 5, 12])

    def tbl(e, r):
        e.calllog.append(('table', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.w32(e.reg('ecx') + 4, idx)
        e.ret(argbytes=8)
    c.emu.hook(0x659330, tbl)

    def mc(e, r):
        d, s_, k = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memcpy', d, s_, k))
        e.wbytes(d, e.rbytes(s_, k))
        e.ret(eax=d)
    c.emu.stub_import('VCRUNTIME140.dll!memcpy', mc)
    return [rnd(c, 0x20), c.rng.getrandbits(32), b, cc]


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _settm(c):
    eng = rnd(c, 0x200)
    c.emu.w32(0x70039c, eng)
    geoms = {}
    ids = [c.rng.getrandbits(32) for _ in range(3)]
    for i in ids:
        geoms[i] = 0 if c.rng.random() < 0.2 else rnd(c, 0x60)
    r = obj(c, 0x20, 'render', 0x40, {0x54: lambda e, a: (geoms.get(a[0], 0), None)}, {0x54: 1})
    c.emu.w32(eng + 0x9b, r)

    def wr(e, p, n, salt):
        for k in range(n):
            e.w32(p + 4 * k, _fb(((e.reg('ecx') >> 4) + salt * 13 + k * 7) % 997 / 7.0))

    def rootTM(e, _):
        e.calllog.append(('GetRootTM', e.reg('ecx')))
        wr(e, e.arg32(0), 9, 1)
        wr(e, e.arg32(1), 3, 2)
        e.ret(argbytes=8)

    def getMat(e, _):
        e.calllog.append(('GetMat', e.reg('ecx')))
        wr(e, e.arg32(0), 9, 3)
        e.ret(argbytes=4)

    def getPos(e, _):
        e.calllog.append(('GetPos', e.reg('ecx')))
        wr(e, e.arg32(0), 3, 4)
        e.ret(argbytes=4)

    def rootMatPos(e, _):
        m, p = e.arg32(0), e.arg32(1)
        e.calllog.append(('GetRootMatPos', e.reg('ecx'), bytes(e.rbytes(m, 36)).hex(), bytes(e.rbytes(p, 12)).hex()))
        e.w32(m, e.r32(p) ^ 0x100)
        e.w32(p + 8, e.r32(m + 0x20) ^ 0x200)
        e.ret(argbytes=8)

    def mk(name):
        def s(e, _):
            m, p = e.arg32(0), e.arg32(1)
            e.calllog.append((name, e.reg('ecx'), bytes(e.rbytes(m, 36)).hex(), bytes(e.rbytes(p, 12)).hex()))
            e.ret(argbytes=8)
        return s
    c.emu.hook(0x4db6c0, rootTM)
    c.emu.hook(0x4db2a0, getMat)
    c.emu.hook(0x4db500, getPos)
    c.emu.hook(0x4db600, rootMatPos)
    c.emu.hook(0x4dcf80, mk('SetRootTM'))
    lnk = 0 if c.rng.random() < 0.5 else rnd(c, 0x10)
    if lnk:
        c.emu.w32(lnk, c.emu.fake_vtable('lnk', 0xe0, {0x370: mk('lnk 0x370')}))
    hk(c, 0x4b48c0, 'GetIKLnkObj', 1, eax=lnk)
    self_ = rnd(c, 0x90)
    c.emu.w32(self_ + 0x80, c.rng.choice([0, ids[2]]))
    return [self_, ids[0], ids[1]]


def _native(c):
    eng = rnd(c, 0x200)
    c.emu.w32(0x70039c, eng)
    r = rnd(c, 0xae0)
    c.emu.w32(r, c.emu.logging_vtable('render', 0x40, {0x4c: lambda e, a: (a[0] ^ 0x4c4c, None)}, {0x4c: 1}))
    c.emu.w32(eng + 0x9b, r)
    c.emu.w32(r + 0xadc, obj(c, 0x10, 'names', 0xa0, {0x25c: lambda e, a: (a[0] * 5 + 1, None)}, {0x25c: 2}))
    arr4, arr8 = c.rng.getrandbits(32), c.rng.getrandbits(32)
    e4, e8 = rnd(c, 8), rnd(c, 8)
    c.emu.w8(e4 + 4, c.rng.choice([3, 3, 4, 4, 0, 5]))
    c.emu.w32(e4, obj(c, 0x10, 'val', 0x10, {0x34: lambda e, a: (0x3434, None)}, {}))
    c.emu.w8(e8 + 4, c.rng.choice([0, 1, 1, 2, 0xff]))
    hk(c, 0x5003d0, 'elem', 1, eax=lambda e: e4 if e.reg('ecx') == arr4 else e8)
    _logmgr(c, 3)
    _handler(c)
    p = rnd(c, 0x10)
    c.emu.w32(p + 4, arr4)
    c.emu.w32(p + 8, arr8)
    return [rnd(c, 0x10), p]


S(0x616490, 'constructor 0x616490', 'thiscall', None, ret='eax', gen=_ctor)
S(0x4b7f90, 'CCutSequenceList::SetObjectTM', 'thiscall', None, ret=None, gen=_settm)
S(0x50dd50, 'script native 0x50dd50', 'thiscall', None, ret=None, gen=_native)
