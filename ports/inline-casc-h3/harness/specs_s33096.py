"""specs_s33096.py - h3 (Sonnet) batch 33096: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g594e30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x59a580, 3, this=True)
    s0 = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    p = obj(c, 0x20, {0: s0})
    holder = rnd(c, 0xaf0)
    e.w32(holder + 0xae4, p)
    so = sysobj(c)
    e.w32(so + 0x9b, holder)
    t = r.choice([0, 1000, 5000, _w(c), 0x7fffffff, 0xffffff00, 0x100])
    e.w32(so + 0x40, t)
    me = rnd(c, 0x970)
    a = _w(c) if r.random() < 0.3 else r.choice([0, 1, 2, 0xffffffff])
    if r.random() < 0.7:
        e.w32(me + 0x953, a)
    ts = struct.unpack('<i', struct.pack('<I', t))[0]
    cand = r.choice([ts, ts - 1, ts + 1, ts + 1024, ts - 1024, 0, 1])
    f = cand / 1024.0
    try:
        e.w32(me + 0x957, _b(f))
    except (OverflowError, struct.error):
        e.w32(me + 0x957, _b(1e30))
    e.w32(me + 0x852, r.choice([0, 1, _w(c), rnd(c, 0x20)]))
    return [me, a]


def _g5d8f40(c):
    clear_hooks(c)
    hook_rec(c, 0x45f960, 1, this=True)
    s3c = pystub(c, 1, this=True)
    s44 = pystub(c, 1, this=True)
    s4c = pystub(c, 1, this=True)
    o = obj(c, 0x60, {0x3c: s3c, 0x44: s44, 0x4c: s4c})
    return [rnd(c, 0x50), o]


def _g5245c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x20)
    f0 = r.choice([0.0, 1.0, -2.0, c.fv(-5, 5, 0.1)])
    vals = [f0, f0 + 1, c.fv(-5, 5, 0.1), 0.0]
    e.w32(me, _b(f0) if f0 == f0 else 0x7fc00000)
    e.w32(me + 4, _b(r.choice(vals)) if f0 == f0 else _w(c))
    e.w32(me + 8, _b(r.choice([0.5, 1.0, 2.0, -1.0, c.fv(-3, 3, 0.1)])))
    e.w32(me + 0x10, _b(r.choice([0.5, 1.0, 2.0, -1.0, c.fv(-3, 3, 0.1)])))
    a = r.choice([0.0, 1.0, 2.0, 0.5, 3.0, -1.0, c.fv(-4, 4, 0.1)])
    f3 = r.choice([f0, f0 + 1, f0 - 1, c.fv(-5, 5, 0.1), f0 + 0.00012207031, f0 + 0.0001, float('nan')])
    e.w32(me + 0xc, _b(f3) if f3 == f3 else 0x7fc00000)
    if r.random() < 0.35 and f0 == f0:
        e.w32(me + 4, _b(f0))
        e.w32(me + 8, _b(r.choice([1.0, -1.0])))
        e.w32(me + 0x10, _b(1.0))
        a = r.choice([1.2, 1.1, 1.15, -1.2, 1.0, 1.3, 1.22474, 1.2247])
    if r.random() < 0.25:
        for off in (0, 4, 0x10):
            e.w32(me + off, 0)
        e.w32(me + 0xc, _b(r.choice([0.0001220, 0.00012205, 0.000122065, 0.00012207031, 0.0001221, 0.00012207])))
        a = r.choice([0.0, 1.0, 2.0])
    return [me, F(a)]


S(0x594e30, 'GUESS refresh timed entry', 'thiscall', None, ret=None, gen=_g594e30, note='batch33096')
S(0x5d8f40, 'GUESS write six fields via stream slots', 'thiscall', None, ret='al', gen=_g5d8f40, note='batch33096')
S(0x5245c0, 'GUESS clamped integration step with target', 'thiscall', None, ret=None, gen=_g5245c0, note='batch33096')
