"""specs_s34161.py - tier H. 0x52a300: hooked 0x52cea0 and 0x52cf60 (ecx, arg), the destination prefilled with random bytes. 0x421810: hooked 0x42d730; s slots 0x54/0x5c; clock import stubbed (random int incl. negative); this slot 0x170. 0x4b0f90: hooked 0x4e5e80 (st0 float per call), pow import stubbed (_libm_sse2_pow_precise). 0x5ab970: unaligned dwords +0x6e/+0x72 (difference below / above 0x10), chain of objects, hooked 0x4db7c0 (writes a vector through its stack pointer argument) and /GS check keeping eax."""
import math
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec
from unicorn.x86_const import UC_X86_REG_XMM0, UC_X86_REG_XMM1


def _f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _fval(r):
    k = r.random()
    if k < 0.2:
        v = r.choice([x for x in EDGE_F if x == x])
    else:
        v = r.uniform(-60, 60)
    return _f32(v) if abs(v) < 3e38 or v != v else v


def _fbits(r):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g52a300(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x52cea0, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x52cf60, 1, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x120), r.getrandbits(32)]


def _g421810(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x42d730, 1, this=True, ret=r.getrandbits(32))

    def clock(em, res_):
        em.calllog.append(('clock',))
        em.ret(eax=r.choice([0, 1, 1000, 123456, 0x7fffffff, 0x80000000, r.getrandbits(32)]), argbytes=0)
    c.emu.stub_import('clock', clock)
    s = obj(c, 0x20, {0x54: pystub(c, 1, this=True), 0x5c: pystub(c, 1, this=True)}, nslots=0x60 // 4)
    me = obj(c, 0x2400, {0x170: pystub(c, 0, this=True)}, nslots=0x174 // 4)
    c.emu.wbytes(me + 0xc, r.getrandbits(64).to_bytes(8, 'little'))
    return [me, s]


def _g4b0f90(c):
    clear_hooks(c)
    r = c.rng

    def pw(em, res_):
        b = struct.unpack('<d', struct.pack('<Q', em.mu.reg_read(UC_X86_REG_XMM0) & (2 ** 64 - 1)))[0]
        e = struct.unpack('<d', struct.pack('<Q', em.mu.reg_read(UC_X86_REG_XMM1) & (2 ** 64 - 1)))[0]
        em.calllog.append(('pow', struct.pack('<d', b), struct.pack('<d', e)))
        try:
            y = math.pow(b, e)
        except (ValueError, OverflowError):
            y = float('nan')
        em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', y))[0])
        em.ret()
    c.emu.stub_import('_libm_sse2_pow_precise', pw)
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=lambda em, k: _fval(r))
    return [rnd(c, 0x80), rnd(c, 0x20)]


def _g5ab970(c):
    clear_hooks(c)
    r = c.rng

    def vec(em, k):
        v = em.arg32(0)
        em.w32(v + 4, _fbits(r))
    hook_rec(c, 0x4db7c0, 1, this=True, stackmark=(0,), side=vec)
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))
    leaf = rnd(c, 0x20)
    mid = rnd(c, 0x20)
    c.emu.w32(mid + 8, leaf)
    top = rnd(c, 0x20)
    c.emu.w32(top + 8, mid)
    me = rnd(c, 0x90)
    base = top
    d = r.choice([0, 1, 0xf, 0x10, 0x11, 0x100, -1 & 0xffffffff, 0xfffffff0, r.getrandbits(32)])
    c.emu.wbytes(me + 0x6e, base.to_bytes(4, 'little') + ((base + d) & 0xffffffff).to_bytes(4, 'little'))
    return [me]


S(0x52a300, 'GUESS reset three blocks from constants', 'thiscall', None, ret='eax', gen=_g52a300, note='batch34161')
S(0x421810, 'GUESS read vector and clock', 'thiscall', None, ret=None, gen=_g421810, note='batch34161')
S(0x4b0f90, 'GUESS read four floats and pow', 'thiscall', None, ret=None, gen=_g4b0f90, note='batch34161')
S(0x5ab970, 'GUESS scaled float of child vector', 'thiscall', None, ret='eax', gen=_g5ab970, note='batch34161')
