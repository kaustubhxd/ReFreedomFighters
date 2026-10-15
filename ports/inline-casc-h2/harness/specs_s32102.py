"""specs_s32102.py - h2 (Sonnet) batch 32102: three tier H float / SSE functions. NaN-able heap floats use nan_heap=True; callees/slots are recorders."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _fmod_stub(c):
    # guest x87 code for the _CIfmod import (st0 = divisor, st1 = dividend): fxch st1; fprem; fstp st1; ret
    code = bytes([0xd9, 0xc9, 0xd9, 0xf8, 0xdd, 0xd9, 0xc3])
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    c.emu.mu.ctl_flush_tb()
    c.emu.w32(0x676358, a)


def g483aa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _fmod_stub(c)
    so = sysobj(c)
    e.wbytes(so + 0x48, struct.pack('<f', r.uniform(0.0, 0.1)))
    p = rnd(c, 0x80)
    lo = r.randrange(0, 50)
    e.w32(p + 0x60, lo)
    e.w32(p + 0x64, lo + r.choice([1, 2, 30, 100, 1000]) if r.random() > 0.05 else lo)
    e.w32(p + 0x6c, r.randrange(0, 5000))
    o = rnd(c, 0x10)
    e.w32(o, p)
    me = rnd(c, 0x20)
    e.w32(me + 4, o if r.random() > 0.15 else 0)
    return [me, F(r.uniform(-3, 3))]


def g52b390(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.randrange(1, 8)
    arr = rnd(c, 0x32 * n + 0x10)
    me = rnd(c, 0x20)
    e.w32(me, arr)
    e.w32(me + 4, n)
    e.w32(me + 8, r.randrange(0, n))
    e.w32(me + 0xc, r.randrange(0, n))
    return [me, rnd(c, 0x40)]


def g467000(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x466290, 2, this=True, pop=8, ret=r.getrandbits(32))
    hook_rec(c, 0x466f60, 1, this=True, pop=4, ret=r.getrandbits(32))
    o = rnd(c, 0x90)
    sysobj(c, table_slots={0x60: pystub(c, 1, ret=(o if r.random() < 0.8 else 0), this=True)})
    return [rnd(c, 0x20), r.getrandbits(32), r.getrandbits(32), r.choice([0, 1, 100, 0x80000000, 0xffffffff, r.getrandbits(32)]),
            r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x483aa0, 'GUESS fractional progress of a timed record', 'thiscall', None, ret='st0', gen=g483aa0, note='batch32102')
S(0x52b390, 'GUESS pop record from ring buffer', 'thiscall', None, ret='al', gen=g52b390, note='batch32102')
S(0x467000, 'GUESS look up object and retime it', 'thiscall', None, ret='eax', gen=g467000, note='batch32102')
