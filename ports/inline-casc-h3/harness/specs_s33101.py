"""specs_s33101.py - h3 (Sonnet) batch 33101: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


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


def _g4c0d70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda em, k: c.fv(-10.0, 10.0, 0.25))
    hook_rec(c, 0x4e6330, 1, this=True)
    s = rnd(c, 0x20)
    data = rnd(c, 8)
    e.wbytes(data, bytes([r.choice([0xff, 9, 0x49, 0x89, 0xc9, 0x29, 0x69, 0xe9, 0x08, 0x0a, 0x3f, 0, r.getrandbits(8)])]))
    e.w32(s, data)
    return [rnd(c, 0x1d0), s]


def _g51e870(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _setlog(c, 3)
    _hook(c)
    s370 = pystub(c, 0, this=True, st0=lambda em, k: c.fv(-10.0, 10.0, 0.25))
    inner = obj(c, 0x40, {0x370: s370})
    p = rnd(c, 0x10)
    e.wbytes(p + 4, bytes([r.choice([0, 1, 2, 3, 0xff, 2, 0])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: p)
    me = rnd(c, 0x30)
    e.w32(me + 0x18, inner)
    arg = rnd(c, 0x20)
    return [me, arg]


S(0x4c0d70, 'GUESS read record header from stream', 'thiscall', None, ret='al', gen=_g4c0d70, note='batch33101')
S(0x51e870, 'GUESS store float into slot with state check', 'thiscall', None, ret=None, gen=_g51e870, note='batch33101')
