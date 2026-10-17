"""specs_f0120.py - fresh-01 batch 20 (docs/20-fresh-01.md)."""
import struct
from pilot import S
from helpers01 import rnd, hk, obj


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


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


def _native(c):
    eng = rnd(c, 0x200)
    c.emu.w32(0x70039c, eng)
    r = obj(c, 0x20, 'render', 0x50, {0x114: lambda e, a: (0xabcd0000 | (a[3] + 5), None)}, {0x114: 4})
    c.emu.w32(eng + 0x9b, r)
    arr4 = c.rng.getrandbits(32)
    e0, e1 = rnd(c, 8), rnd(c, 8)
    c.emu.w8(e0 + 4, c.rng.choice([3, 3, 4, 4, 0, 5]))
    c.emu.w32(e0, obj(c, 0x10, 'val', 0x10, {0x34: lambda e, a: (0x3434, None)}, {}))
    hk(c, 0x5003d0, 'elem', 1, eax=lambda e: e0 if e.arg32(0) == 0 else e1)
    _logmgr(c, 3)
    _handler(c)
    n = c.rng.choice([0, 1, 2, 5])

    def s4c(e, _):
        e.calllog.append(('begin', e.reg('ecx')))
        e.w32(e.arg32(0), n)
        e.w32(e.arg32(0) + 4, 0x1000)
        e.ret(argbytes=4)

    def s5c(e, _):
        it = e.arg32(0)
        k = e.r32(it)
        e.calllog.append(('next', e.reg('ecx'), k))
        nxt = (k - 1) & 0xffffffff if k else 0
        e.w32(it, nxt)
        e.ret(eax=0x7700 + k, argbytes=4)
    lst = rnd(c, 0x10)
    c.emu.w32(lst, c.emu.fake_vtable('list', 0x20, {0x4c: s4c, 0x5c: s5c}))

    def s12c(e, _):
        d = e.arg32(2)
        e.calllog.append(('SendCommand', e.reg('ecx'), e.arg32(0), e.arg32(1), e.r32(d), e.r32(d + 4)))
        e.ret(argbytes=12)
    o = rnd(c, 0x20)
    c.emu.w32(o, c.emu.fake_vtable('owner', 0x50, {0x12c: s12c}))
    c.emu.w32(o + 0x18, 0 if c.rng.random() < 0.15 else lst)
    self_ = rnd(c, 0x10)
    c.emu.w32(self_ + 0xc, o)
    p = rnd(c, 0x10)
    c.emu.w32(p + 4, arr4)
    return [self_, p]


def _lights(c):
    def ms(e, r):
        d, v, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memset', v, n))
        e.wbytes(d, bytes([v & 0xff]) * n)
        e.ret(eax=d)
    c.emu.stub_import('VCRUNTIME140.dll!memset', ms)

    def b0(e, _):
        e.calllog.append(('SetLight', e.arg32(0), e.arg32(1), bytes(e.rbytes(e.arg32(2), 0x68)).hex()))
        e.ret(eax=0, argbytes=12)

    def b8(e, _):
        e.calllog.append(('LightEnable', e.arg32(0), e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=12)
    dev = rnd(c, 0x10)
    c.emu.w32(dev, c.emu.fake_vtable('d3d', 0x40, {0xb0: b0, 0xb8: b8}))
    c.emu.w32(0x724a00, dev)
    rec = rnd(c, 0x70)
    for i in range(3):
        k = c.rng.random()
        for j in range(3):
            if k < 0.4:
                v = 0.0 if c.rng.random() < 0.8 else c.rng.choice([-0.0, 0.5, -0.5, float('nan')])
                c.emu.w32(rec + 32 * i + 0x10 + 4 * j, _fb(v))
            elif k < 0.6:
                c.emu.w32(rec + 32 * i + 0x10 + 4 * j, _fb(c.rng.uniform(0, 1)))
    return [rec]


def _waves(c):
    vals = []
    for _ in range(10):
        vals.append(c.rng.choice([0.0, 1.0, 3.5, -2.0, 1e-3, c.rng.uniform(-50, 50), float('inf')]))

    def fl(e, r):
        k = len(e.calllog)
        e.calllog.append(('float', e.reg('ecx')))
        e.ret(st0=vals[k % 10])

    def ui(e, r):
        e.calllog.append(('uint', e.reg('ecx')))
        e.ret(eax=0x12345)
    c.emu.hook(0x4e5e80, fl)
    c.emu.hook(0x4e5e60, ui)
    p = 0 if c.rng.random() < 0.15 else rnd(c, 0x1c)
    hk(c, 0x41e290, 'new', 1, eax=p, regs=(), pop=False)
    hk(c, 0x4ccbe0, 'REFTAB', 2, eax=0x7ab0000)
    self_ = rnd(c, 0x80)
    c.emu.w32(self_, c.emu.logging_vtable('waves', 0x30, {}, {0x94: 1}))
    return [self_, c.rng.getrandbits(32), rnd(c, 8)]


S(0x509b10, 'script native 0x509b10', 'thiscall', None, ret=None, gen=_native)
S(0x611710, 'set lights 0x611710', 'stdcall', None, ret=None, gen=_lights)
S(0x4bb050, 'CWaves::Init', 'thiscall', None, ret=None, gen=_waves)
