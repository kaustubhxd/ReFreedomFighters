"""specs_s33086.py - h3 (Sonnet) batch 33086: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g524540(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x20)
    f0 = r.choice([0.0, 1.0, -2.0, c.fv(-5, 5, 0.1)])
    e.w32(me, _b(f0) if f0 == f0 else 0x7fc00000)
    e.w32(me + 4, _b(r.choice([f0, f0 + 1, c.fv(-5, 5, 0.1)])) if f0 == f0 else _w(c))
    e.w32(me + 8, _b(r.choice([0.5, 1.0, 2.0, -1.0, c.fv(-3, 3, 0.1)])))
    e.w32(me + 0x10, _b(r.choice([0.5, 1.0, 2.0, -1.0, c.fv(-3, 3, 0.1)])))
    a = r.choice([0.0, 1.0, 2.0, 0.5, 3.0, -1.0, c.fv(-4, 4, 0.1)])
    if r.random() < 0.35:
        e.w32(me + 4, _b(f0) if f0 == f0 else 0)
        e.w32(me + 8, _b(r.choice([1.0, -1.0])))
        e.w32(me + 0x10, _b(1.0))
        a = r.choice([1.2, 1.1, 1.15, -1.2, 1.0, 1.3, 1.22474, 1.2247])
    return [me, F(a)]


def _g476240(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s64 = pystub(c, 1, this=True)
    me = obj(c, 0x80, {0x64: s64})
    e.wbytes(me + 0x56, bytes([r.choice([0, 1, 0xff, 1])]))
    fl = rnd(c, 0x50)
    e.w32(fl + 0x3c, r.choice([0, 0x400, 0xfffffbff, _w(c), _w(c) | 0x400, _w(c) & ~0x400]))
    mid = rnd(c, 0x10)
    e.w32(mid + 8, fl)
    e.w32(me + 0x44, mid)
    e.w32(me + 0x48, _b(r.choice([c.fv(-1000, 1000, 0.1), 0.0, 1.5, -2.5, 1e9])))
    so = sysobj(c)
    e.w32(so + 0x40, r.choice([_w(c), 0, 1000]))
    return [me]


def _g597f00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x593f40, 1, this=True)
    hook_rec(c, 0x594040, 2, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x596ef0, 2, this=True)
    val = r.choice([0.0, 0.5, 0.5000001, 0.49999997, 1.0, r.uniform(0, 1), r.uniform(0, 1)])
    sysobj(c, rand=lambda em, k: val)
    me = rnd(c, 0x1d20)
    e.w32(me + 0x1d0b, rnd(c, 0x20))
    return [me]


S(0x524540, 'GUESS clamped integration step', 'thiscall', None, ret=None, gen=_g524540, note='batch33086')
S(0x476240, 'GUESS stamp time then slot 0x64(0x10)', 'thiscall', None, ret=None, gen=_g476240, note='batch33086')
S(0x597f00, 'GUESS random pick of two ids then init', 'thiscall', None, ret=None, gen=_g597f00, note='batch33086')
