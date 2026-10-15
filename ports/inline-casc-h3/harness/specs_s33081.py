"""specs_s33081.py - h3 (Sonnet) batch 33081: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _fl(c):
    return F(c.fv(-10.0, 10.0, 0.25))


def _fbits(c):
    return _b(c.fv(-10.0, 10.0, 0.25))


_SET = [0.0, -0.0, 0.25, 0.5, 0.75, 1.0, -0.5, -1.0, 2.0, 1.0000001, float('nan')]


def _sb(r):
    x = r.choice(_SET)
    return 0x7fc00000 if x != x else _b(x)


def _g4f1290(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x300, {0x228: st})
    p = rnd(c, 0x10)
    p0, p1 = _sb(r), _sb(r)
    e.w32(p, p0)
    e.w32(p + 4, p1)
    m = r.random()
    e.w32(me + 0x22, p0 if m < 0.5 else (p0 ^ 0x80000000 if m < 0.65 else _sb(r)))
    m = r.random()
    e.w32(me + 0x26, p1 if m < 0.5 else (p1 ^ 0x80000000 if m < 0.65 else _sb(r)))
    return [me, p, _w(c)]


def _g5bd6d0(c):
    clear_hooks(c)
    hook_rec(c, 0x469870, 0, this=True)
    return [rnd(c, 0x90)]


def _g4d70e0(c):
    clear_hooks(c)
    r = c.rng
    p = rnd(c, 0x40) if r.random() < 0.75 else 0
    hook_rec(c, 0x4d8fc0, 1, this=True, ret=lambda em, k: p)
    return [rnd(c, 0x10), _w(c), rnd(c, 0x20), rnd(c, 8)]


def _g5165d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x516130, 2, this=True, st0=lambda em, k: c.fv(-10.0, 10.0, 0.25))
    hook_rec(c, 0x5244d0, 2, this=True)
    cb = r.choice([0, 1, 0x100, 0x1ff, _w(c), 0xffffff00 | r.getrandbits(8)])
    return [rnd(c, 0x60), _fl(c), cb, _fl(c), _w(c)]


def _g476200(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda em, k: c.fv(-10.0, 10.0, 0.25))
    hook_rec(c, 0x4e5e40, 0, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, _w(c)]))
    return [rnd(c, 0x60), rnd(c, 0x10)]


def _g4f85c0(c):
    clear_hooks(c)
    r = c.rng
    st = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x400, {0x374: st})
    c.emu.w32(me + 0x9f, _sb(r))
    return [me, _sb(r)]


def _g6401f0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x42ab62, 3, pop=0)
    a = r.choice([0, 1, -1, 0x7fffffff, 0x80000000, 0xffffff, 0x1000001, -0x1000001, 0x7fffff01,
                  r.getrandbits(32), r.getrandbits(32), r.getrandbits(20), -r.getrandbits(24)]) & 0xffffffff
    return [rnd(c, 0x20), a]


def _cvtt(x):
    if x != x or abs(x) >= 2147483648.0:
        return -0x80000000
    return int(x)


def _g512e10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = [hook_rec(c, a, 1, this=True, ret=lambda em, k: _w(c)) for a in (0x512be0, 0x512ca0, 0x512db0)]
    so = sysobj(c)
    me = rnd(c, 0x20)
    f1 = c.fv(-300.0, 300.0, 0.25)
    f2 = c.fv(-300.0, 300.0, 0.25)
    e.w32(me + 4, r.choice([0, 1, _w(c)]))
    e.w32(me + 0xc, _b(f1))
    e.w32(me + 0x10, _b(f2))
    k1 = _cvtt(struct.unpack('<f', struct.pack('<f', f1 * 1024.0))[0] if abs(f1 * 1024.0) < 3e38 else float('inf'))
    k2 = _cvtt(struct.unpack('<f', struct.pack('<f', f2 * 1024.0))[0] if abs(f2 * 1024.0) < 3e38 else float('inf'))
    k = r.choice([k1, k2])
    v = (k + r.choice([-1, 0, 1, 0, 2, -2])) if r.random() < 0.85 else r.choice([0, -0x80000000, 0x7fffffff, _w(c) - 0x80000000])
    e.w32(so + 0x40, v & 0xffffffff)
    return [me, _w(c)]


S(0x4f1290, 'GUESS vec2 setter with dirty flag + slot 0x228', 'thiscall', None, ret=None, gen=_g4f1290, note='batch33081')
S(0x5bd6d0, 'GUESS ctor: base 0x469870, zero fields, vtable 0x6b33b4', 'thiscall', None, ret='eax', gen=_g5bd6d0, note='batch33081')
S(0x4d70e0, 'GUESS lookup + copy 0x1a-byte record out', 'thiscall', None, ret='al', gen=_g4d70e0, note='batch33081')
S(0x5165d0, 'GUESS optional 0x516130 then 0x5244d0 with floats', 'thiscall', None, ret=None, gen=_g5165d0, note='batch33081')
S(0x476200, 'GUESS read stream: float, u16, u32, bool', 'thiscall', None, ret=None, gen=_g476200, note='batch33081')
S(0x4f85c0, 'GUESS add to clamped [0,1] float then slot 0x374(1)', 'thiscall', None, ret=None, gen=_g4f85c0, note='batch33081')
S(0x6401f0, 'GUESS log u32 as float and store', 'thiscall', None, ret=None, gen=_g6401f0, note='batch33081')
S(0x512e10, 'GUESS pick one of three handlers by time threshold', 'thiscall', None, ret=None, gen=_g512e10, note='batch33081')
