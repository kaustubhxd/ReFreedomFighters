"""specs_s33109.py - h3 (Sonnet) batch 33109: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g4f7410(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4fa630, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0xff, _w(c)]))
    s4c = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x4c: s4c})
    stubs = {off: pystub(c, n, this=True) for off, n in ((0x3c, 1), (0x10, 2), (0x4c, 1), (0x60, 1))}
    s = obj(c, 0x80, stubs)
    return [rnd(c, 0xb0), s]


def _g5df9f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x467410, 6, this=True)
    hook_rec(c, 0x591f00, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, _w(c)]))
    hook_rec(c, 0x58bc60, 1, this=True)
    s2d0 = pystub(c, 2, this=True)
    sobj = obj(c, 0x2e0, {0x2d0: s2d0})
    s4c = pystub(c, 1, this=True)
    sysobj(c, table_slots={0x4c: s4c})
    s8 = pystub(c, 2, this=True)
    s10 = pystub(c, 0, this=True, ret=lambda em, k: sobj)
    holder = obj(c, 0x20, {8: s8, 0x10: s10})
    me = rnd(c, 0x20)
    e.w32(me + 0xc, holder)
    return [me]


S(0x4f7410, 'GUESS write six fields to stream when 0x4fa630', 'thiscall', None, ret='al', gen=_g4f7410, note='batch33109')
S(0x5df9f0, 'GUESS reset child then notify or recreate', 'thiscall', None, ret='al', gen=_g5df9f0, note='batch33109')
