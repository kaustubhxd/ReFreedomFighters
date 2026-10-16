"""specs_f0114.py - fresh-01 batch 14 (docs/20-fresh-01.md)."""
import math
import struct
from unicorn.x86_const import UC_X86_REG_EIP
from pilot import S
from helpers01 import rnd, hk, obj


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _engine(c, n=0x1b00):
    eng = rnd(c, n)
    c.emu.w32(0x70039c, eng)
    return eng


def _handler(c):
    def hnd(e, r):
        e.calllog.append(('handler',))
        e.ret(eax=0xbad)
    c.emu.w32(0x7003b0, c.emu.stub_fn('handler', hnd))


def _flt(c):
    k = c.rng.random()
    if k < 0.05:
        return c.rng.getrandbits(32)
    if k < 0.12:
        return _fb(c.rng.choice([0.0, -0.0, float('inf'), float('nan'), 1e-40]))
    return _fb(c.rng.uniform(-1, 1) * 10 ** c.rng.uniform(-6, 6))


def _scale(c):
    args = [_flt(c) for _ in range(7)]
    if c.rng.random() < 0.15:
        args[6] = _fb(0.0)
    if c.rng.random() < 0.1:
        args[1] = args[0] ^ 0x80000000            # |a| == |b|
    # floor returns a double in st0: a heap trampoline 'fld qword [cell]; ret' (pilot's ret(st0=) is float only)
    cell = c.emu.alloc(16, 8)
    tramp = c.emu.alloc(16, 4)
    c.emu.wbytes(tramp, b'\xdd\x05' + struct.pack('<I', cell) + b'\xc3')
    c.emu.mu.ctl_flush_tb()

    def fl(e, r):
        x = struct.unpack('<d', bytes(e.rbytes(e.reg('esp') + 4, 8)))[0]
        e.calllog.append(('floor', struct.pack('<d', x).hex()))
        y = float(math.floor(x)) if math.isfinite(x) else x
        e.wbytes(cell, struct.pack('<d', y))
        e.mu.reg_write(UC_X86_REG_EIP, tramp)
    c.emu.stub_import('floor', fl)
    return args + [rnd(c, 4), rnd(c, 4)]


def _dtor(c):
    eng = _engine(c, 0x200)
    c.emu.w32(eng + 0x9b, obj(c, 0x20, 'render', 0x40, {}, {0x34: 1}))
    hk(c, 0x4ccf60, 'REFTAB32 dtor', 0)
    hk(c, 0x4690b0, 'sized delete', 2, regs=(), pop=False)
    _handler(c)
    return [rnd(c, 0x120), c.rng.choice([0, 1, 4, 5, c.rng.getrandbits(32)])]


def _upper(c):
    def rstr(n):
        a = rnd(c, n + 1)
        c.emu.wbytes(a, bytes(c.rng.choice(b'abcXYZ09 _-\xe9\x80z') for _ in range(n)) + b'\0')
        return a
    src = rnd(c, 0x20)
    n = c.rng.randint(0, 20)
    c.emu.w32(src + 0xc, rstr(n))
    c.emu.w16(src + 0x10, c.rng.choice([n + 1, n + 5, 0x40, c.rng.getrandbits(16)]))
    r = obj(c, 0x20, 'str', 0x10, {0x24: lambda e, a: (0x24240000, None)}, {})
    m = c.rng.randint(0, 24)
    c.emu.w32(r + 0xc, rstr(m))
    c.emu.w16(r + 0x10, c.rng.choice([0, 1, m + 1, n, n + 1, n + 2, c.rng.getrandbits(16)]))
    hk(c, 0x605400, 'copy', 0, eax=r)
    hk(c, 0x634273, 'delete', 2, regs=(), pop=False)
    nb = rnd(c, 0x10000)
    hk(c, 0x41e290, 'new', 1, eax=nb, regs=(), pop=False)

    def tu(e, r_):
        x = e.arg32(0)
        e.calllog.append(('toupper', x))
        b = x & 0xff
        e.ret(eax=(x & ~0xff) | (b - 32 if 0x61 <= b <= 0x7a else b) if x < 0x80 else 0x5500 | b)
    c.emu.stub_import('toupper', tu)
    el = rnd(c, 8)
    c.emu.w8(el + 4, c.rng.choice([0, 4, 1, 2]))
    c.emu.w32(el, obj(c, 0x10, 'old', 0x10))
    arr = c.rng.getrandbits(32)
    hk(c, 0x5003d0, 'elem', 1, eax=el)
    p = rnd(c, 0x10)
    c.emu.w32(p + 8, arr)
    return [src, p]


def _button(c):
    eng = obj(c, 0x200, 'engine', 0x70, {}, {})
    c.emu.w32(0x70039c, eng)
    rnd_ = rnd(c, 0xb00)
    c.emu.w32(eng + 0x9b, rnd_)
    loc = obj(c, 0x10, 'loc', 4, {0: lambda e, a: ((a[0] ^ a[1] ^ 0x10000000), None)}, {0: 2})
    c.emu.w32(rnd_ + 0xae4, loc)
    fmt = rnd(c, 0x10)

    def s198(e, r):
        f, buf, a, b, d = (e.arg32(k) for k in range(5))
        e.calllog.append(('format', f, a, b, d))
        e.wbytes(buf, ('%08x|%08x|%08x' % (a, b, d)).encode() + b'\0')
        e.ret(argbytes=0)
    c.emu.w32(fmt, c.emu.fake_vtable('fmt', 0x70, {0x198: s198}))
    c.emu.w32(eng, obj(c, 4, 'x', 1) and c.emu.logging_vtable('engine', 0x70, {0x190: lambda e, a: (fmt, None)}, {}))
    on = 0x300 | c.rng.choice([0, 1])
    hk(c, 0x561c40, 'autosave on', 0, eax=on, regs=())

    def sett(e, r):
        e.calllog.append(('SetTextOnButton', e.reg('ecx'), e.arg32(0), bytes(e.rbytes(e.arg32(1), 40)).split(b'\0')[0]))
        e.ret(argbytes=8)
    c.emu.hook(0x5636c0, sett)
    return [rnd(c, 0x190)]


S(0x404fd0, 'cdecl scale 0x404fd0 (x87)', 'cdecl', None, ret=None, gen=_scale)
S(0x4a3bd0, 'ZSoundAmbient scalar deleting destructor', 'thiscall', None, ret='eax', gen=_dtor)
S(0x6057d0, 'OpaqueString_t::toUpper', 'thiscall', None, ret=None, gen=_upper)
S(0x57c390, 'ZFFAutoSave::UpdateButton', 'thiscall', None, ret=None, gen=_button)
