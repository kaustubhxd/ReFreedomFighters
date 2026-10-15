"""specs_s33097.py - h3 (Sonnet) batch 33097: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g5142c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [0.0, 0.0001220703125, 0.00012207031, 0.00012207032, 1.0, -1.0, 0.5, float('nan')]
    tv = r.choice(vals)
    s18 = pystub(c, 0, this=True, st0=lambda em, k: tv if k == 0 else r.choice(vals))
    inner = obj(c, 0x40, {0x18: s18})
    s130 = pystub(c, 3, this=True)
    me = obj(c, 0x210, {0x130: s130})
    e.w32(me + 0x5c, inner)
    e.wbytes(me + 0xcc, bytes([r.choice([0, 0, 1]), r.choice([0, 0, 1])]))
    cv = r.choice([tv, tv + 1, tv - 1, 0.0, 1.0, 5.0])
    e.w32(me + 0xc8, _b(cv) if cv == cv else 0x7fc00000)
    return [me]


def _g551720(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    q = [rnd(c, 8) for _ in range(3)]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: q[min(k, 2)])
    hook_rec(c, 0x5002f0, 1, this=True)
    hook_rec(c, 0x500360, 1, this=True)
    s4c = pystub(c, 0, this=True, ret=lambda em, k: rnd(c, 8))
    b = obj(c, 0x60, {0x4c: s4c})
    flag = r.random() < 0.8
    s18 = pystub(c, 1, this=True, ret=lambda em, k: b if flag else 0)
    o = obj(c, 0x40, {0x18: s18})
    return [o, _w(c), rnd(c, 0x10)]


def _g4bd3f0(c):
    clear_hooks(c)
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda em, k: c.fv(-10.0, 10.0, 0.25))
    return [rnd(c, 0x90), _w(c), rnd(c, 0x10)]


S(0x5142c0, 'GUESS fire two one-shot events by time', 'thiscall', None, ret=None, gen=_g5142c0, note='batch33097')
S(0x551720, 'GUESS fill vec3 channels through helper calls', 'stdcall', None, ret='eax', gen=_g551720, note='batch33097')
S(0x4bd3f0, 'GUESS read animation header from stream', 'thiscall', None, ret=None, gen=_g4bd3f0, note='batch33097')
