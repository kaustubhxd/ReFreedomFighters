"""specs_s33120.py - h3 (Sonnet) batch 33120: tier H float/SSE functions."""
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


def _g4c29a0(c):
    clear_hooks(c)
    stubs = {off: pystub(c, 1, this=True) for off in (0x40, 0x60, 0x4c)}
    s = obj(c, 0x80, stubs)
    return [rnd(c, 0x70), s]


def _g5db4f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    m = r.choice([0, 1, 2, 3])

    def s4c_side(em, k):
        em.w32(em.arg32(0), 1)

    def s5c_side(em, k):
        em.w32(em.arg32(0), 1 if k < m else 0)
    s14 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    s4c = pystub(c, 1, this=True, stackmark=(0,), side=s4c_side)
    elems = [rnd(c, 0x20) for _ in range(4)]
    s5c = pystub(c, 1, this=True, stackmark=(0,), side=s5c_side, ret=lambda em, k: elems[min(k, 3)])
    kids = obj(c, 0x80, {0x14: s14, 0x4c: s4c, 0x5c: s5c})
    stubs = {off: pystub(c, 1, this=True) for off in (0x64, 0x4c, 0x3c)}
    s = obj(c, 0x80, stubs)
    me = rnd(c, 0x90)
    e.w32(me + 0x84, kids)
    return [me, s]


def _g5023b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _setlog(c, 3)
    _hook(c)
    ps = [rnd(c, 8) for _ in range(4)]
    st = r.choice([3, 4, 3, 4, 0, 1, 2, 5, 0xff])
    e.wbytes(ps[2] + 4, bytes([st]))
    s34 = pystub(c, 0, this=True, ret=lambda em, k: _w(c))
    inner = obj(c, 0x40, {0x34: s34})
    if st == 4:
        e.w32(ps[2], inner)
    order = {2: ps[0], 3: ps[1], 1: ps[2], 0: ps[3]}
    # 5003d0 is called with which = 2, 3, 1, 0 in that order
    seq = [ps[0], ps[1], ps[2], ps[3]]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: seq[min(k, 3)])
    s114 = pystub(c, 4, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x114: s114})
    s12c = pystub(c, 3, this=True, deref={2: 2})
    tgt = obj(c, 0x140, {0x12c: s12c})
    me = rnd(c, 0x20)
    e.w32(me + 0xc, tgt)
    arg = rnd(c, 0x10)
    return [me, arg]


S(0x4c29a0, 'GUESS write record fields to stream (c)', 'thiscall', None, ret='al', gen=_g4c29a0, note='batch33120')
S(0x5db4f0, 'GUESS write record and child list to stream', 'thiscall', None, ret='al', gen=_g5db4f0, note='batch33120')
S(0x5023b0, 'GUESS resolve id and forward values to slot 0x12c', 'thiscall', None, ret=None, gen=_g5023b0, note='batch33120')
