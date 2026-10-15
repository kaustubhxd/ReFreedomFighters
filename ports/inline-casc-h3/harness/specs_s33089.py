"""specs_s33089.py - h3 (Sonnet) batch 33089: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g44ea60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x80)
    p = rnd(c, 0x10)
    for ax in range(3):
        lo = r.choice([-1.0, 0.0, -5.0, c.fv(-5, 0, 0.1)])
        hi = r.choice([1.0, 2.0, 5.0, c.fv(0, 5, 0.1)])
        v = r.choice([lo, hi, (lo + hi) / 2, lo - 1, hi + 1, c.fv(-8, 8, 0.1), float('nan')])
        for v_ in (lo, hi, v):
            pass
        e.w32(me + 0x5c + 4 * ax, _b(lo) if lo == lo else 0x7fc00000)
        e.w32(me + 0x68 + 4 * ax, _b(hi) if hi == hi else 0x7fc00000)
        e.w32(p + 4 * ax, _b(v) if v == v else 0x7fc00000)
    return [me, p]


def _g5df970(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x467410, 6, this=True)
    hook_rec(c, 0x591080, 0, this=True, ret=lambda em, k: _w(c))
    s4c = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x4c: s4c})
    s8 = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    ch = obj(c, 0x20, {8: s8})
    me = rnd(c, 0x20)
    e.w32(me + 0xc, ch)
    return [me]


def _g45b240(c):
    clear_hooks(c)
    hook_rec(c, 0x43de40, 3, this=True, ret=lambda em, k: _w(c))
    return [rnd(c, 0x520), _w(c), _w(c), _w(c)]


S(0x44ea60, 'GUESS point outside-box bitmask', 'thiscall', None, ret='eax', gen=_g44ea60, note='batch33089')
S(0x5df970, 'GUESS reset child and notify via table slot', 'thiscall', None, ret='al', gen=_g5df970, note='batch33089')
S(0x45b240, 'GUESS ctor: base 0x43de40, internal buffer pointers', 'thiscall', None, ret='eax', gen=_g45b240, note='batch33089')
