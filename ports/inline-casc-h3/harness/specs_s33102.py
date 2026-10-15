"""specs_s33102.py - h3 (Sonnet) batch 33102: tier H float/SSE functions."""
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


def _g486900(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s2d0 = pystub(c, 2, this=True)
    s350 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    o = obj(c, 0x360, {0x2d0: s2d0, 0x350: s350})
    s10 = pystub(c, 0, this=True, ret=lambda em, k: o)
    holder = obj(c, 0x20, {0x10: s10})
    s24 = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    me = obj(c, 0x60, {0x24: s24})
    s128 = pystub(c, 1, this=True)
    sub = obj(c, 0x20, {0x128: s128})
    s114 = pystub(c, 6, this=True, ret=lambda em, k: r.choice([0, 1, 0x12345, 0xffff, 0x10000, _w(c)]))
    so = sysobj(c, table_slots={0x114: s114})
    e.w32(so + 0x40, r.choice([0, 1, 0x7fffffff, 0xffffff00, _w(c), 1000]))
    e.w32(me + 0xc, holder)
    e.w32(me + 8, sub)
    return [me]


def _g5198b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _setlog(c, 3)
    _hook(c)
    pa = rnd(c, 8)
    p = rnd(c, 0x10)
    e.wbytes(p + 4, bytes([r.choice([0, 1, 2, 3, 0xff, 2, 0])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: pa if k == 0 else p)
    s304 = pystub(c, 1, this=True, st0=lambda em, k: c.fv(-10.0, 10.0, 0.25))
    inner = obj(c, 0x320, {0x304: s304})
    me = rnd(c, 0x30)
    e.w32(me + 0x14, inner)
    return [me, rnd(c, 0x20)]


def _g50acb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _setlog(c, 3)
    _hook(c)
    val = c.fv(-10.0, 10.0, 0.25)
    sysobj(c, rand=lambda em, k: val)
    p = rnd(c, 0x10)
    e.wbytes(p + 4, bytes([r.choice([0, 1, 2, 3, 0xff, 2, 0])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: p)
    return [rnd(c, 0x30), rnd(c, 0x20)]


S(0x486900, 'GUESS init timed object via slots and table id', 'thiscall', None, ret='al', gen=_g486900, note='batch33102')
S(0x5198b0, 'GUESS evaluate curve into slot with state check', 'thiscall', None, ret=None, gen=_g5198b0, note='batch33102')
S(0x50acb0, 'GUESS store engine random into slot with state check', 'thiscall', None, ret=None, gen=_g50acb0, note='batch33102')
