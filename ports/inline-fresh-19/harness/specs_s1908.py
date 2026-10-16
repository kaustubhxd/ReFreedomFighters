"""specs_s1908.py - fresh slice 19, batch1908 (src/batch1908.cpp). Exe callees hooked by address with logging handlers;
pointer arguments into the stack are logged by the value they point at. The pow import is stubbed (logged)."""
import math
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _hk
from unicorn.x86_const import UC_X86_REG_XMM0, UC_X86_REG_XMM1


def _r(c):
    return c.rng.getrandbits(32)


def _vh(c, name, nargs, eax=None, log_ecx=True):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx') if log_ecx else None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=_r(c) if eax is None else (eax(em) if callable(eax) else eax), argbytes=4 * nargs)
    return h


def _g_63ee70(c):
    e = c.emu
    self_ = _rnd(c, 0xb9a0)
    n = c.rng.choice([0, 1, 3])
    e.w32(self_ + 0xec, n)
    for i in range(n):
        r = _rnd(c, 0x10080)
        tab = _rnd(c, 0x4000)
        for k in range(0, 0x4000, 4):
            if c.rng.random() < 0.5:
                e.w32(tab + k, 0)
        e.w32(r + 0x10071, tab)
        e.w32(self_ + 0xf0 + 4 * i, r)
    e.w32(self_ + 0x68, _rnd(c, 0x4000))
    _hk(c, 0x64cda0, 'fn_64cda0', 1)
    _hk(c, 0x4ce180, 'FreeDrawId', 1)
    return [self_, c.rng.choice([0, 1, 0x10000, 0xfff, 0x1000, _r(c)])]


def _pow(em, r):
    x = struct.unpack('<d', struct.pack('<Q', em.mu.reg_read(UC_X86_REG_XMM0) & (2 ** 64 - 1)))[0]
    y = struct.unpack('<d', struct.pack('<Q', em.mu.reg_read(UC_X86_REG_XMM1) & (2 ** 64 - 1)))[0]
    em.calllog.append(('pow', 0, None, (struct.pack('<d', x), struct.pack('<d', y))))
    try:
        z = math.pow(x, y)
    except (ValueError, OverflowError):
        z = float('nan')
    em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
    em.ret()


def _g_4c2e70(c):
    e = c.emu
    e.stub_import('_libm_sse2_pow_precise', _pow)
    self_ = _rnd(c, 0x70)
    s = c.rng.choice([0, _rnd(c, 0x20), _rnd(c, 0x20)])
    if s:
        e.w32(s + 0x1c, c.rng.choice([0, 1, _r(c)]))
        e.w32(s + 0x18, _rnd(c, 0x90))
    e.w32(self_ + 0x44, s)
    e.w32(self_ + 0x64, c.rng.choice([0, 1, _r(c)]))
    for o in (0x48, 0x54):
        e.w32(o + self_, c.rng.choice([0, 0x80000000, 0x7fc00000, _r(c),
              struct.unpack('<I', struct.pack('<f', c.rng.uniform(-60, 10)))[0]]))
    _hk(c, 0x44c230, 'SetMinDistance', 1)
    return [self_]


def _g_628f30(c):
    e = c.emu
    words = [b'x\0m\0l\0', b'X\0M\0L\0', b'x\0m\0L\0', b'X\0m\0l\0', b'x\0M\0l\0', b'x\0m\0l\0', b'x\0m\0k\0',
             b'xxm\0l\0', b'x\0mml\0', b'x\0m\0lx', b'y\0m\0l\0', b'x\0n\0l\0']
    wd = c.rng.choice(words)
    if c.rng.random() < 0.2:
        wd = bytes(c.rng.getrandbits(8) for _ in range(6))
    b = _rnd(c, 0x10)
    e.wbytes(b, wd)
    ln = c.rng.choice([6, 6, 6, 5, 7, 0])
    out = _rnd(c, 4)
    return [_r(c), b, b + ln, out]


def _g_601f70(c):
    e = c.emu
    o = c.rng.choice([0, _rnd(c, 4), _rnd(c, 4)])

    def new(em, r):
        em.calllog.append(('new', 0, None, (em.arg32(0),)))
        em.ret(eax=o)
    e.hook(0x41e290, new)
    _hk(c, 0x600d70, 'sym ctor', 2, eax=lambda em: em.reg('ecx'))
    self_ = _rnd(c, 0x10)
    cap = c.rng.choice([1, 4, 8])
    e.w32(self_ + 4, _rnd(c, 4 * (cap + 1)))
    e.w32(self_ + 8, cap)
    e.w32(self_ + 0xc, c.rng.randint(0, cap))
    _hk(c, 0x5f4630, 'grow', 0)
    return [self_, _r(c), _r(c)]


def _g_504730(c):
    e = c.emu
    _hk(c, 0x500900, 'base ctor', 2)
    _hk(c, 0x505d50, 'fn_505d50', 0)
    e.w32(0x700f7c, c.rng.choice([0, 1]))
    m = _rnd(c, 0x10)
    v = _r(c)

    def s40(em, r):
        p = em.arg32(0)
        em.calllog.append(('m.40', 0x40, em.reg('ecx'), (em.r32(p),)))
        em.w32(p, v)
        em.ret(eax=0, argbytes=4)
    e.w32(m, _pyvt(c, {0x40: s40}))
    a = _rnd(c, 0x20)
    e.w32(a + 0x15, m)
    db = _rnd(c, 0x10)
    e.w32(db, _pyvt(c, {0x58: _vh(c, 'db.58', 1)}))
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    return [_rnd(c, 0x20), a, _r(c)]


S(0x63ee70, 'FUN_0063ee70 (free draw id)', 'thiscall', None, ret=None, gen=_g_63ee70, note='batch1908; void')
S(0x4c2e70, 'ZSoundExtend::SetValuesLight', 'thiscall', None, ret=None, gen=_g_4c2e70, nan_heap=True,
  note='batch1908; void; pow import stubbed and logged; +0x88 is a float')
S(0x628f30, 'FUN_00628f30 (xml name check)', 'cdecl', None, ret='eax', gen=_g_628f30, note='batch1908')
S(0x601f70, 'CSdlDataExchange::setExportSymbol', 'thiscall', None, ret=None, gen=_g_601f70, note='batch1908; void')
S(0x504730, 'FUN_00504730 (constructor)', 'thiscall', None, ret='eax', gen=_g_504730, note='batch1908')
