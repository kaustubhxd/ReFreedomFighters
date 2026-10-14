"""specs_s32094.py - h2 () batch 32094: eight tier H float / SSE functions. Float arguments are F(); float returns ret='st0'; heap floats that can be NaN use nan_heap=True."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _fbits(c, lo=-5, hi=5):
    r = c.rng
    return r.choice([_fb(c.fv(lo, hi)), _fb(c.fv(lo, hi)), NAN, 0x7f800000, 0xff800000, 0, 0x80000000, 0x7fa00001])


def g5244d0(c):
    clear_hooks(c)
    r = c.rng
    k = _f(c.emu.r32(0x67cd48))
    a = r.choice([k, k, c.fv(-5, 5), k + 1e-3, -k, 0.0, float('inf')])
    if r.random() < 0.1:
        a = _f(NAN)
    return [rnd(c, 0x20), F(a), r.getrandbits(32)]


def g467ca0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x80)
    e.wbytes(o + 0x70, _fbits(c, -100, 100).to_bytes(4, 'little'))
    sysobj(c, table_slots={0x60: pystub(c, 1, ret=(o if r.random() < 0.7 else 0), this=True)})
    return [rnd(c, 0x160)]


def g529cd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x60)
    e.wbytes(me + 0x14, _fbits(c, -10, 10).to_bytes(4, 'little'))
    e.wbytes(me + 8, _fbits(c, -10, 10).to_bytes(4, 'little'))
    return [me, F(c.fv(-10, 10) if r.random() > 0.1 else _f(NAN))]


def g5aaa50(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5ef950, 3, this=True, pop=0xc, ret=r.getrandbits(32))
    me = rnd(c, 0x660)
    return [me, r.getrandbits(32), r.getrandbits(32), F(c.fv(-100, 100))]


def g46e3b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x471680, 0, this=True, pop=0, side=_log('call'))
    so = sysobj(c)
    dt = c.fv(0, 2)
    e.wbytes(so + 0x48, _fb(dt).to_bytes(4, 'little'))
    me = rnd(c, 0x60)
    acc = c.fv(0, 2)
    limit = r.choice([acc + dt, acc + dt + 1e-3, acc + dt - 1e-3, c.fv(0, 4), _f(NAN)])
    e.wbytes(me + 0x56, _fb(acc).to_bytes(4, 'little'))
    e.wbytes(me + 0x4c, _fb(limit).to_bytes(4, 'little'))
    return [me]


def g535750(c):
    clear_hooks(c)
    r = c.rng
    k = _f(c.emu.r32(0x67d164))
    a = r.choice([k, k - 1e-3, k + 1e-3, c.fv(-5, 5), c.fv(-1000, 1000), 0.0, _f(NAN), float('inf')])
    return [F(a)]


def g521930(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x515930, 2, this=True, pop=8, side=_log('a'))
    me = rnd(c, 0x300)
    e.wbytes(me + 0x2f8, _fbits(c, -100, 100).to_bytes(4, 'little'))
    return [me]


def g5d3ac0(c):
    clear_hooks(c)
    r = c.rng
    vals = [_f(_fb(c.fv(-100, 100))) for _ in range(1)]
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('a'))
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=vals[0], side=_log('b'))
    return [rnd(c, 0x60), rnd(c, 0x20)]


S(0x5244d0, 'GUESS set float field unless equal to constant', 'thiscall', None, ret=None, gen=g5244d0, nan_heap=True, note='batch32094')
S(0x467ca0, 'GUESS float of looked-up object or zero', 'thiscall', None, ret='st0', gen=g467ca0, note='batch32094')
S(0x529cd0, 'GUESS center plus/minus scaled extent', 'thiscall', None, ret=None, gen=g529cd0, nan_heap=True, note='batch32094')
S(0x5aaa50, 'GUESS forward to member with float arg', 'thiscall', None, ret='eax', gen=g5aaa50, note='batch32094')
S(0x46e3b0, 'GUESS accumulate time and fire at limit', 'thiscall', None, ret=None, gen=g46e3b0, nan_heap=True, note='batch32094')
S(0x535750, 'GUESS thresholded scale', 'stdcall', None, ret='st0', gen=g535750, note='batch32094')
S(0x521930, 'GUESS apply stored float then reset fields', 'thiscall', None, ret=None, gen=g521930, nan_heap=True, note='batch32094')
S(0x5d3ac0, 'GUESS copy int and float from source', 'thiscall', None, ret=None, gen=g5d3ac0, note='batch32094')
