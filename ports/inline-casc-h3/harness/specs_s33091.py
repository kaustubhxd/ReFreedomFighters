"""specs_s33091.py - h3 () batch 33091: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _fb(c, lo=-10.0, hi=10.0):
    return _b(c.fv(lo, hi, 0.25))


def _g6500b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sc = pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0xff00, _w(c)]))
    o = obj(c, 0x20, {0xc: sc})
    s1b0 = pystub(c, 0, this=True, ret=lambda em, k: o if r.random() < 0.6 else 0)
    so = sysobj(c, slots={0x1b0: s1b0})
    e.w32(so + 0x9c7, r.choice([0, 0x80000000, 0x7fc00000, _b(1.0), _fb(c), 0, 1]))
    e.wbytes(so + 0x64, bytes([r.choice([0, 1, 0xff, 1])]))
    me = rnd(c, 0x80)
    e.w32(me + 0x74, r.choice([0, 1, _w(c), 1]))
    return [me]


def _g5765c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x574280, 2, this=True)
    hook_rec(c, 0x5738c0, 1, this=True)
    p = rnd(c, 0x100)
    e.w32(p + 0x88, r.choice([_fb(c), 0, 0x80000000, 0x7fc00000, _b(1.0)]))
    flag = r.random() < 0.75
    s60 = pystub(c, 1, this=True, ret=lambda em, k: p if flag else 0)
    so = sysobj(c, table_slots={0x60: s60})
    e.w32(so + 0x40, r.choice([_w(c), 0, 1000, 0xffffff00]))
    sbc = pystub(c, 1, this=True)
    o = obj(c, 0x100, {0xbc: sbc})
    me = rnd(c, 0x240)
    e.w32(me + 0x229, o)
    e.w32(me + 0x21d, _w(c))
    b = r.choice([0, 1, 0x100, 0xff, _w(c), 0x200, 2])
    return [me, _w(c), b]


def _g524460(c):
    clear_hooks(c)
    s4c = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    o = obj(c, 0x80, {0x4c: s4c})
    return [rnd(c, 0x20), o]


S(0x6500b0, 'GUESS can-act predicate over engine state', 'thiscall', None, ret='al', gen=_g6500b0, note='batch33091')
S(0x5765c0, 'GUESS reset state, mark table object, slot 0xbc', 'thiscall', None, ret='al', gen=_g5765c0, note='batch33091')
S(0x524460, 'GUESS write five floats via slot 0x4c', 'thiscall', None, ret='al', gen=_g524460, note='batch33091')
