"""specs_s32108.py - h2 (Sonnet) batch 32108: three tier H float / SSE functions. Callees/slots are recorders; order pinned with calllog."""
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


def g453090(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4da1d0, 1, this=True, pop=4, side=_log('a'))
    hook_rec(c, 0x4dd060, 1, this=True, pop=4, deref={0: 3}, side=_log('b'))
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    k = _f(e.r32(0x679540))
    o = rnd(c, 0x60)
    for off in (0x40, 0x44, 0x48):
        v = r.choice([k - 1.0, k, k + 1.0, 0.0, -1.0, 5.0, _f(NAN), k + 1e-4, k - 1e-4])
        e.wbytes(o + off, struct.pack('<f', v))
    me = rnd(c, 0x20)
    e.w32(me + 8, o)
    return [me]


def g4e6780(c):
    clear_hooks(c)
    r = c.rng
    vals = [0.0, 1.0, 4.0, 5.0, 5.5, 30.5, 31.9, 32.0, 7.2, 33.0]
    hook_rec(c, 0x4e6910, 1, this=True, pop=4, st0=lambda emu, k: r.choice(vals), side=_log('log'))
    n = r.choice([0, 1, 0x1f, 0x20, 0x21, 100, 1000, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32), r.randrange(0, 5000)])
    return [rnd(c, 0x20), n]


def g650eb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0, side=_log('free'))
    inner = obj(c, 0x20, {0x2c: pystub(c, 2, ret=r.getrandbits(32), pop=0, side=_log('log2'))})
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True, side=_log('log1'))})
    e.w32(0x700390, g)
    p = rnd(c, 0x10)
    a = r.choice([1.0, 0.5, -1.0, 0.0, -0.0, _f(NAN), 1e-30])
    b = r.choice([2.0, 0.25, -2.0, 0.0, _f(NAN)])
    e.wbytes(p, struct.pack('<ff', a, b))
    me = rnd(c, 0xc0)
    e.w32(me + 0x74, r.choice([0, rnd(c, 0x10)]))
    return [me, p]


S(0x453090, 'GUESS clamp tiny vector components and apply (GS frame)', 'thiscall', None, ret=None, gen=g453090, nan_heap=True, note='batch32108')
S(0x4e6780, 'GUESS init power-of-two bucket sizing', 'thiscall', None, ret='eax', gen=g4e6780, note='batch32108')
S(0x650eb0, 'GUESS set size pair or log error', 'thiscall', None, ret=None, gen=g650eb0, nan_heap=True, note='batch32108')
