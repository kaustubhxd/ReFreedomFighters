"""specs_s40000.py - tier H. 0x479090: unaligned float at +0x755 (fraction near 0.25/0.75 boundaries, negatives, NaN/inf), ret al. 0x4d6150: hooked allocator 0x41e290 (cdecl) and 0x4d9350 (ret 8), object with unaligned vtable at +0xa (slot 4). 0x45aff0: hooked 0x4dd060/0x4dce50 (float arg compared), object at [this+8] with floats at +0x40..+0x48. 0x421810: hooked 0x42d730, arg object slots 0x54/0x5c, import clock, this slot 0x170, double at +0xc."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _q(r):
    k = r.random()
    if k < 0.12:
        return r.choice(EDGE_F)
    if k < 0.2:
        return struct.unpack('<f', struct.pack('<I', r.getrandbits(32)))[0]
    base = r.choice([0.25, 0.75, 0.2499, 0.2501, 0.7499, 0.7501, 0.5, 0.0, 0.9999, 0.1, 0.9, r.random()])
    v = r.choice([0, 1, 2, 3, 100, 12345, -1, -2, -77]) + base
    return v


def _fmod_stub(c):
    # guest x87 code for the _CIfmod import (st0 = divisor, st1 = dividend): fxch st1; fprem; fstp st1; ret
    code = bytes([0xd9, 0xc9, 0xd9, 0xf8, 0xdd, 0xd9, 0xc3])
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    c.emu.mu.ctl_flush_tb()
    c.emu.w32(0x676358, a)


def _g479090(c):
    clear_hooks(c)
    _fmod_stub(c)
    r = c.rng
    me = rnd(c, 0x800)
    v = _q(r)
    try:
        w = _fb(v)
    except OverflowError:
        w = 0x7f800000
    c.emu.wbytes(me + 0x755, w.to_bytes(4, 'little'))
    return [me]


def _g4d6150(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x40)
    hook_rec(c, 0x41e290, 1, ret=blk, pop=0)
    hook_rec(c, 0x4d9350, 2, this=True, deref={1: 8})
    stub = pystub(c, 1, this=True)
    vt = c.emu.alloc(0x20, 4)
    c.emu.w32(vt + 4, stub)
    me = rnd(c, 0x40)
    c.emu.wbytes(me + 0xa, vt.to_bytes(4, 'little'))
    p = rnd(c, 0x20)
    return [me, r.getrandbits(32), p, r.getrandbits(32)]


def _g45aff0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dd060, 1, this=True, deref={0: 3})
    hook_rec(c, 0x4dce50, 1, this=True)
    o = rnd(c, 0x80)
    for off in (0x40, 0x44, 0x48):
        k = r.random()
        if k < 0.15:
            v = r.choice(EDGE_F)
        elif k < 0.2:
            c.emu.w32(o + off, r.getrandbits(32))
            continue
        else:
            v = r.uniform(-100, 100)
        c.emu.w32(o + off, _fb(v) if abs(v) < 3.4e38 or v != v else 0x7f800000)
    me = rnd(c, 0x40)
    c.emu.w32(me + 8, o)
    return [me]


def _g421810(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x42d730, 1, this=True)
    p = obj(c, 0x20, {0x54: pystub(c, 1, this=True), 0x5c: pystub(c, 1, this=True)}, nslots=0x60 // 4)
    me_vt = c.emu.alloc(0x180, 4)
    c.emu.w32(me_vt + 0x170, pystub(c, 0, this=True))
    me = rnd(c, 0x2400)
    c.emu.w32(me, me_vt)

    def clock(em, res_):
        t = r.choice([0, 1, 1000, 123456789, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32)])
        em.calllog.append(('clock', t))
        em.ret(eax=t, argbytes=0)
    c.emu.stub_import('clock', clock)
    return [me, p]


S(0x479090, 'GUESS fraction outside band', 'thiscall', None, ret='al', gen=_g479090, note='batch40000')
S(0x4d6150, 'GUESS queue a copied record', 'thiscall', None, ret=None, gen=_g4d6150, note='batch40000')
S(0x45aff0, 'GUESS set length plus one', 'thiscall', None, ret=None, gen=_g45aff0, note='batch40000')
S(0x421810, 'GUESS stamp time', 'thiscall', None, ret=None, gen=_g421810, note='batch40000')
