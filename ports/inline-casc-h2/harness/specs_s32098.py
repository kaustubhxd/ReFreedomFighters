"""specs_s32098.py - h2 (Sonnet) batch 32098: eight tier H float / SSE functions. Float args F(); NaN-able heap floats use nan_heap=True; slots/callees are recorders."""
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


def g5244f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k1 = _f(e.r32(0x67cd44))
    k2 = _f(e.r32(0x6785d0))
    a = r.choice([k1, k2, k2, c.fv(-5, 5), 0.0, -0.0, _f(NAN), float('inf'), 1e-30])
    return [rnd(c, 0x20), F(a)]


def g4c1ee0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4c0d70, 1, this=True, pop=4, side=_log('a'))
    me = obj(c, 0x1e0, {0x60: pystub(c, 1, ret=r.getrandbits(32), this=True, side=_log('b'))}, nslots=0x60 // 4 + 1)
    e.w32(me + 0x1cc, r.choice([0, 0, 1, r.getrandbits(32)]))
    e.wbytes(me + 0x1ac, _fbits(c, -9, 9).to_bytes(4, 'little'))
    return [me, r.getrandbits(32), r.getrandbits(32)]


def g4f7180(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634dca, 2, pop=0, st0=r.choice([0.0, 3.0, -7.5, 1234.75, 2.5e9, -2.5e9, 1e30, float('nan')]), side=_log('crt'))
    inner = rnd(c, 0x60)
    e.wbytes(inner + 0x44, _fbits(c, -100, 100).to_bytes(4, 'little'))
    me = obj(c, 0x20, {0x2d0: pystub(c, 0, this=True, side=_log('slot'))}, nslots=0x2d0 // 4 + 1)
    e.w32(me + 8, inner)
    return [me]


def g466220(c):
    clear_hooks(c)
    hook_rec(c, 0x4de7a0, 0, this=True, pop=0)
    return [rnd(c, 0x60)]


def g4b2890(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x20, {0x84: pystub(c, 1, ret=r.choice([0, 1, 100, 0xffffff00, 0x80000000, r.getrandbits(32)]), this=True, side=_log('a'))}, nslots=0x84 // 4 + 1)
    vt = e.alloc(0xa0, 4)
    e.w32(vt + 0x98, pystub(c, 2, ret=r.getrandbits(32), this=True, side=_log('b')))
    me = rnd(c, 0xc0)
    e.wbytes(me + 0xaa, vt.to_bytes(4, 'little'))
    return [me, o]


def g5d34e0(c):
    clear_hooks(c)
    r = c.rng
    fs = [_f(_fb(c.fv(-100, 100))), _f(_fb(c.fv(-100, 100)))]
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=lambda emu, k: fs[min(k, 1)], side=_log('f'))
    hook_rec(c, 0x4e5e40, 0, this=True, pop=0, ret=r.getrandbits(32), side=_log('w'))
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=r.choice([0, 1, r.getrandbits(32)]), side=_log('i'))
    return [rnd(c, 0x60), rnd(c, 0x20)]


def g46b440(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    e.w32(so + 0x40, r.randrange(-1000, 100000) & 0xffffffff)
    me = rnd(c, 0x100)
    e.wbytes(me + 0x88, _fbits(c, -10, 10).to_bytes(4, 'little'))
    k0 = _f(e.r32(0x6785d0))
    b = r.choice([k0, k0, c.fv(-5, 5), 0.0, _f(NAN), float('inf')])
    a = r.choice([c.fv(-100, 100), 0.5, _f(NAN), 1e10, -1e10])
    return [me, F(a), F(b)]


def g516fd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    p = rnd(c, 0x10)
    for i in range(3):
        e.wbytes(p + 4 * i, _fbits(c, -3.2, 3.2).to_bytes(4, 'little'))
    return [rnd(c, 0x70), p]


S(0x5244f0, 'GUESS reciprocal with special cases', 'thiscall', None, ret=None, gen=g5244f0, nan_heap=True, note='batch32098')
S(0x4c1ee0, 'GUESS reset counters then slot 0x60 with float', 'thiscall', None, ret='eax', gen=g4c1ee0, note='batch32098')
S(0x4f7180, 'GUESS int from CRT of doubled float', 'thiscall', None, ret='eax', gen=g4f7180, note='batch32098')
S(0x466220, 'GUESS reset state record', 'thiscall', None, ret=None, gen=g466220, note='batch32098')
S(0x4b2890, 'GUESS embedded object slot 0x98 with float of int', 'thiscall', None, ret='eax', gen=g4b2890, note='batch32098')
S(0x5d34e0, 'GUESS copy float word flag float from source', 'thiscall', None, ret=None, gen=g5d34e0, note='batch32098')
S(0x46b440, 'GUESS prime timers from elapsed time', 'thiscall', None, ret=None, gen=g46b440, nan_heap=True, note='batch32098')
S(0x516fd0, 'GUESS CRT of three floats', 'thiscall', None, ret=None, gen=g516fd0, nan_heap=True, note='batch32098')
