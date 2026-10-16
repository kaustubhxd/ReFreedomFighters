"""specs_f0116.py - fresh-01 batch 16 (docs/20-fresh-01.md)."""
import struct
from pilot import S
from helpers01 import rnd, hk, obj


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _logmgr(c, n):
    def s2c(e, r):
        e.calllog.append(('log',) + tuple(e.arg32(k) for k in range(n)))
        e.ret(eax=0x10910000)
    o = rnd(c, 0x20)
    c.emu.w32(o, c.emu.fake_vtable('logger', 0x10, {0x2c: s2c}))
    c.emu.w32(0x700390, obj(c, 0x20, 'mgr', 0x10, {0x20: lambda e, a: (o, None)}, {0x20: 2}))


def _zfields(e, z):
    return tuple(e.r32(z + o) for o in (0, 4, 0xc, 0x10, 0x20, 0x24))


def _unzip(c):
    o = rnd(c, 0x20)
    data = rnd(c, 0x80)
    c.emu.w32(o + 1, data)
    c.emu.w32(o + 5, c.rng.randint(0, 0x70))
    c.emu.w32(o + 9, c.rng.choice([c.rng.randint(0, 0x77), c.rng.randint(0, 0x77), 0xfffffff0, 0x80000000]))
    c.emu.w32(o + 0x11, c.rng.choice([1, 1, 0, 2, c.rng.getrandbits(32)]))
    dst = rnd(c, 0x80)
    size = c.rng.randint(0, 0x80)

    def mc(e, r):
        d, s_, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memcpy', d, s_, n))
        if n <= 0x80:                          # a negative (huge) count is only logged, so signedness shows
            e.wbytes(d, e.rbytes(s_, n))
        e.ret(eax=d)
    c.emu.stub_import('VCRUNTIME140.dll!memcpy', mc)
    init_rc = c.rng.choice([0, 0, 0, -2 & 0xffffffff, -6 & 0xffffffff])
    inf_rc = c.rng.choice([1, -5, -5, 0, -3]) & 0xffffffff
    out_left = c.rng.choice([0, 0, 1, 7])

    def init(e, r):
        z = e.arg32(0)
        e.calllog.append(('inflateInit2_', _zfields(e, z), e.arg32(1), e.arg32(2), e.arg32(3)))
        e.ret(eax=init_rc, argbytes=16)

    def inf(e, r):
        z = e.arg32(0)
        e.calllog.append(('inflate', _zfields(e, z), e.arg32(1)))
        e.w32(z + 0x10, out_left)
        e.ret(eax=inf_rc, argbytes=8)

    def end(e, r):
        z = e.arg32(0)
        e.calllog.append(('inflateEnd', _zfields(e, z)))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x62f9d0, init)
    c.emu.hook(0x62f5d0, inf)
    c.emu.hook(0x62f980, end)
    _logmgr(c, 2)
    return [o, dst, size]


def _koth(c):
    eng = obj(c, 0x200, 'engine', 0x70, {}, {})
    c.emu.w32(0x70039c, eng)
    rnd_ = rnd(c, 0xb00)
    c.emu.w32(eng + 0x9b, rnd_)
    loc = obj(c, 0x10, 'loc', 4, {0: lambda e, a: ((a[0] ^ a[1] ^ 0x10000000), None)}, {0: 2})
    c.emu.w32(rnd_ + 0xae4, loc)
    fmt = rnd(c, 0x10)
    rc = c.rng.choice([5, 0, -1 & 0xffffffff, 0x80000000])

    def s198(e, r):
        f, buf, a, b, d, g = (e.arg32(k) for k in range(6))
        e.calllog.append(('format', f, a, b, d, g))
        e.wbytes(buf, ('%08x|%08x|%08x' % (b, d, g)).encode() + b'\0')
        e.ret(eax=rc)
    c.emu.w32(fmt, c.emu.fake_vtable('fmt', 0x70, {0x198: s198}))
    c.emu.w32(eng, c.emu.logging_vtable('engine', 0x70, {0x190: lambda e, a: (fmt, None)}, {}))

    def sett(e, r):
        e.calllog.append(('SetTextOnButton', e.reg('ecx'), e.arg32(0), bytes(e.rbytes(e.arg32(1), 40)).split(b'\0')[0]))
        e.ret(argbytes=8)
    c.emu.hook(0x563710, sett)
    _logmgr(c, 2)
    return [rnd(c, 0x1c0)]


def _q(c):
    a, b = rnd(c, 16), rnd(c, 16)
    for p in (a, b):
        for k in range(4):
            if c.rng.random() < 0.9:
                c.emu.w32(p + 4 * k, _fb(c.rng.uniform(-2, 2) * 10 ** c.rng.uniform(-3, 3)))
    o = c.rng.choice([rnd(c, 16), rnd(c, 16), a, b])
    return [o, a, b]


S(0x4d7610, 'ZPackedDataChunk::unzip', 'thiscall', None, ret='al', gen=_unzip)
S(0x56d750, 'CMultiplayerKOTH::UpdateAmountButton', 'thiscall', None, ret=None, gen=_koth)
S(0x4def50, 'qmul', 'fastcall', None, ret=None, gen=_q)
