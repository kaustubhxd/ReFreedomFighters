"""specs_s33087.py - h3 (Sonnet) batch 33087: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g5d91a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s1 = pystub(c, 0, this=True)
    o = obj(c, 0x20, {0x254: s1})
    s2 = pystub(c, 0, this=True)
    p = obj(c, 0x20, {0x254: s2})
    flag = r.random() < 0.7
    s58 = pystub(c, 1, this=True, ret=lambda em, k: p if flag else 0)
    so = sysobj(c, table_slots={0x58: s58})
    me = rnd(c, 0x60)
    e.w32(me + 0x4c, r.choice([1, 1, 1, 0, 2, 0xffffffff, _w(c)]))
    e.w32(me + 0x44, o)
    base = _w(c) & 0xffff
    e.w32(me + 0x48, base)
    t = r.choice([0, 1, -1, 0x200, 0x201, 0x1ff, 0x400, -0x200, r.getrandbits(12), _w(c)])
    e.w32(so + 0x40, (base + 0x200 + t) & 0xffffffff)
    return [me]


def _setlog(c, argn):
    e = c.emu
    slog = pystub(c, argn, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))


def _g645420(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _setlog(c, 3)
    me = rnd(c, 0x100)
    e.w32(me + 0x65, r.choice([0, 1, 2, 3, 4, 4, 5]))
    return [me, _w(c), _w(c), _w(c), _w(c), _w(c)]


def _g468270(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x467770, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0xff00, _w(c)]))
    s10 = pystub(c, 2, this=True, deref={0: 1})
    s3c = pystub(c, 1, this=True)
    s4c = pystub(c, 1, this=True)
    s = obj(c, 0x20, {0x10: s10, 0x3c: s3c, 0x4c: s4c})
    me = rnd(c, 0x200)
    return [me, s]


S(0x5d91a0, 'GUESS timed state reset with two slot 0x254 calls', 'thiscall', None, ret=None, gen=_g5d91a0, note='batch33087')
S(0x645420, 'GUESS push 5-value record (max 4) or log', 'thiscall', None, ret=None, gen=_g645420, note='batch33087')
S(0x468270, 'GUESS save fields into stream if 0x467770', 'thiscall', None, ret='al', gen=_g468270, note='batch33087')
