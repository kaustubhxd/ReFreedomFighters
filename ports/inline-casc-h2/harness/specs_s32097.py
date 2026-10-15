"""specs_s32097.py - h2 (Sonnet) batch 32097: eight tier H float / SSE functions. Float args F(); NaN-able heap floats use nan_heap=True; slots are recorder stubs."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _fbits(c, lo=-5, hi=5):
    r = c.rng
    return r.choice([_fb(c.fv(lo, hi)), _fb(c.fv(lo, hi)), NAN, 0x7f800000, 0xff800000, 0, 0x80000000])


def g516690(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4690b0, 0, this=True, pop=0, side=_log('b'))
    hook_rec(c, 0x524890, 1, this=True, pop=4, side=_log('c'))
    return [rnd(c, 0x80), F(c.fv(-10, 10))]


def g57f300(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x20, {0xa8: pystub(c, 0, this=True, st0=_f(_fb(c.fv(-100, 100))), side=_log('f'))}, nslots=0xa8 // 4 + 1)
    o2 = obj(c, 0x20, {0xb8: pystub(c, 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True, side=_log('b'))}, nslots=0xb8 // 4 + 1)
    seq = [o, o2]
    so = sysobj(c, slots={0xbc: pystub(c, 0, ret=lambda emu, k: seq[min(k, 1)], this=True)})
    return [rnd(c, 0x1a0)]


def g4217c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    k = e.r32(0x6785d0)
    v = r.choice([k, k, _fb(c.fv(-5, 5)), NAN, 0, 0x80000000])
    e.wbytes(so + 0x9c7, v.to_bytes(4, 'little'))
    me = rnd(c, 0x1b50)
    o = obj(c, 0x20, {0x178: pystub(c, 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True)}, nslots=0x178 // 4 + 1)
    e.wbytes(me + 0x9b, o.to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


def g4df9f0(c):
    clear_hooks(c)
    r = c.rng
    a = r.choice([c.fv(-10, 10), c.fv(-3.2, 3.2), 0.0, _f(NAN), 1e6])
    return [rnd(c, 0x10), rnd(c, 0x10), F(a)]


def g524890(c):
    clear_hooks(c)
    r = c.rng
    a = r.choice([0.0, -0.0, c.fv(-5, 5), c.fv(-5, 5), _f(NAN), float('inf')])
    return [rnd(c, 0x30), F(a)]


def g5ab130(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = e.r32(0x6785d0)
    me = rnd(c, 0x3e0)
    e.wbytes(me + 0x3c6, bytes([r.choice([0, 1, 1, 1])]))
    cur = r.choice([0, 8, 5, r.getrandbits(32)])
    e.wbytes(me + 0x3c2, cur.to_bytes(4, 'little'))
    e.wbytes(me + 0x3d0, r.choice([k, k, _fb(c.fv(-5, 5)), NAN]).to_bytes(4, 'little'))
    return [me, r.choice([8, 8, cur, 5, r.getrandbits(32), 0])]


def g466420(c):
    clear_hooks(c)
    me = obj(c, 0x170, {0x3c8: pystub(c, 5, this=True)}, nslots=0x3c8 // 4 + 1)
    return [me]


def g4f11f0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    me = obj(c, 0x80, {0x70: pystub(c, 1, this=True, deref={0: 3})}, nslots=0x70 // 4 + 1)
    return [me, F(c.fv(-10, 10)), F(c.fv(-10, 10)), F(c.fv(-10, 10))]


S(0x516690, 'GUESS init constants and sub-objects', 'thiscall', None, ret=None, gen=g516690, note='batch32097')
S(0x57f300, 'GUESS copy float and flag from engine object', 'thiscall', None, ret=None, gen=g57f300, note='batch32097')
S(0x4217c0, 'GUESS flag unless value equals constant', 'thiscall', None, ret='al', gen=g4217c0, note='batch32097')
S(0x4df9f0, 'GUESS sin and cos of angle (register ABI)', 'fastcall', None, ret=None, gen=g4df9f0, nan_heap=True, note='batch32097')
S(0x524890, 'GUESS init limits with default float', 'thiscall', None, ret=None, gen=g524890, nan_heap=True, note='batch32097')
S(0x5ab130, 'GUESS state change with float reset', 'thiscall', None, ret=None, gen=g5ab130, nan_heap=True, note='batch32097')
S(0x466420, 'GUESS slot 0x3c8 with zero block', 'thiscall', None, ret=None, gen=g466420, note='batch32097')
S(0x4f11f0, 'GUESS slot 0x70 with vec3 on stack', 'thiscall', None, ret=None, gen=g4f11f0, note='batch32097')
