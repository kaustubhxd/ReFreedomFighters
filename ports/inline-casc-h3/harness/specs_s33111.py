"""specs_s33111.py - h3 (Sonnet) batch 33111: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _setlog(c, argn):
    e = c.emu
    slog = pystub(c, argn, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))


def _hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _g50fb70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _setlog(c, 3)
    _hook(c)
    s34 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    inner = obj(c, 0x40, {0x34: s34})
    p0 = rnd(c, 8)
    st = r.choice([3, 4, 3, 4, 0, 1, 2, 5, 0xff])
    e.wbytes(p0 + 4, bytes([st]))
    if st == 4:
        e.w32(p0, inner)
    p1 = rnd(c, 8)
    e.w32(p1, _b(c.fv(-10, 10, 0.25)))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: p1 if k == 0 else p0)
    s58 = pystub(c, 3, this=True)
    s138 = pystub(c, 0, this=True, ret=lambda em, k: ent)
    ent = obj(c, 0x80, {0x58: s58})
    sysobj(c, table_slots={0x138: s138})
    return [rnd(c, 0x10), rnd(c, 0x10)]


def _g511150(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _setlog(c, 3)
    _hook(c)
    p = rnd(c, 8)
    e.wbytes(p + 4, bytes([r.choice([0, 1, 2, 3, 0xff, 0, 1])]))
    e.w32(p, r.choice([0, 1, _w(c)]))
    a = rnd(c, 8)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: p if k == 0 else a)
    hook_rec(c, 0x5002f0, 1, this=True)
    hook_rec(c, 0x500360, 1, this=True)
    q = rnd(c, 0x80)
    flag = r.random() < 0.8
    s60 = pystub(c, 1, this=True, ret=lambda em, k: q if flag else 0)
    so = sysobj(c, table_slots={0x60: s60})
    e.w32(so + 0x1a9f, r.choice([0, 1, _w(c)]))
    return [rnd(c, 0x10), rnd(c, 0x10)]


def _g4451d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x45c3a0, 3, this=True)

    def side(em, k):
        em.wbytes(em.arg32(0), bytes(em.arg32(2)))
    hook_rec(c, 0x634d10, 3, pop=0, side=side)
    holder = rnd(c, 0xae4)
    so = sysobj(c)
    e.w32(so + 0x9b, holder)
    return [rnd(c, 0x1a0), _w(c), _w(c), _w(c)]


S(0x50fb70, 'GUESS resolve value from record state then table slot 0x58', 'thiscall', None, ret=None, gen=_g50fb70, note='batch33111')
S(0x511150, 'GUESS reset slot value and copy table float', 'thiscall', None, ret=None, gen=_g511150, note='batch33111')
S(0x4451d0, 'GUESS ctor: base 0x45c3a0, defaults, memset', 'thiscall', None, ret='eax', gen=_g4451d0, note='batch33111')
