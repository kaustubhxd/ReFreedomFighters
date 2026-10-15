"""specs_s32106.py - h2 (Sonnet) batch 32106: three tier H float / SSE functions. Callees/slots are recorders; the CRT float-to-int helper 0x633910 runs as exe code."""
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


def g527060(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x40)
    a = r.choice([1.0, -2.0, 3.5, 0.0, _f(NAN)])
    b = r.choice([a, a, 1.0, 2.5, -1.0, _f(NAN), a + 1.0])
    cv = r.choice([0.5, 5.0, -3.0, 0.0, _f(NAN)])
    x0 = r.choice([cv + 1.0, cv - 1.0, cv, 7.0, _f(NAN)])
    e.wbytes(me + 0x1d, struct.pack('<f', x0))
    e.wbytes(me + 0x21, struct.pack('<f', r.choice([cv + 2.0, cv - 2.0, cv, 0.25, _f(NAN)])))
    return [me, F(a), F(b), F(cv)]


def g610ea0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    o = obj(c, 0x20, {0xa0: pystub(c, 2, ret=r.getrandbits(32), deref={1: 6})}, nslots=0xa0 // 4 + 1)
    me = rnd(c, 0x1390)
    e.wbytes(me + 0x1377, o.to_bytes(4, 'little'))
    f = lambda: r.choice([r.uniform(-1000, 1000), 0.5, -0.5, 2.9, -2.9, 1e9, -1e9, 0.0, 100.0])
    return [me, F(f()), F(f()), F(f()), F(f())]


def g4c79f0(c):
    clear_hooks(c)
    r = c.rng
    ints = [r.choice([0, 1, r.getrandbits(32)]) for _ in range(5)]
    fl = [_f(_fb(r.uniform(-100, 100))) for _ in range(2)]
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=lambda emu, k: ints[min(k, 4)], side=_log('i'))
    hook_rec(c, 0x4e5e80, 0, this=True, pop=0, st0=lambda emu, k: fl[min(k, 1)], side=_log('f'))
    return [rnd(c, 0x70), rnd(c, 0x20)]


S(0x527060, 'GUESS init interpolation state from endpoints', 'thiscall', None, ret='al', gen=g527060, nan_heap=True, note='batch32106')
S(0x610ea0, 'GUESS pass rounded rectangle to slot 0xa0', 'thiscall', None, ret=None, gen=g610ea0, note='batch32106')
S(0x4c79f0, 'GUESS read record fields from source', 'thiscall', None, ret='al', gen=g4c79f0, note='batch32106')
