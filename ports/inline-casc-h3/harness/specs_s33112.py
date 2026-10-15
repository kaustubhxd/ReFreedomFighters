"""specs_s33112.py - h3 (Sonnet) batch 33112: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g5df8b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x467410, 6, this=True)
    s2d0 = pystub(c, 2, this=True)
    s2f0 = pystub(c, 3, this=True)
    sobj = obj(c, 0x2f8, {0x2d0: s2d0, 0x2f0: s2f0})
    s4c = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x4c: s4c})
    s8 = pystub(c, 2, this=True)
    s10 = pystub(c, 0, this=True, ret=lambda em, k: sobj)
    holder = obj(c, 0x20, {8: s8, 0x10: s10})
    s4f4 = pystub(c, 1, this=True)
    child = obj(c, 0x500, {0x4f4: s4f4})
    me = rnd(c, 0x20)
    e.w32(me + 0xc, holder)
    e.w32(me + 8, child)
    return [me]


def _g4f39f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def side(em, k):
        p = em.arg32(0)
        for i in range(4):
            em.w32(p + 4 * i, _w(c))
    s240 = pystub(c, 1, this=True, stackmark=(0,), side=side)
    obj6f = obj(c, 0x250, {0x240: s240})
    rr = rnd(c, 0x80)
    e.w32(rr + 0x6f, obj6f)
    s2c4 = pystub(c, 0, this=True, ret=lambda em, k: rr)
    owner = obj(c, 0x2d0, {0x2c4: s2c4})
    s27c = pystub(c, 1, this=True)
    s23c = pystub(c, 1, this=True, deref={0: 4})
    s250 = pystub(c, 0, this=True)
    ent = obj(c, 0x280, {0x27c: s27c, 0x23c: s23c, 0x250: s250})
    s58 = pystub(c, 1, this=True, ret=lambda em, k: ent)
    s4c = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x58: s58, 0x4c: s4c})
    sac = pystub(c, 2, this=True)
    eng = obj(c, 0xb0, {0xac: sac})
    e.w32(e.r32(0x70039c) + 0x190f, eng)
    me = rnd(c, 0x60)
    e.w32(me + 0x44, owner)
    return [me]


S(0x5df8b0, 'GUESS reset widget child with table lookups', 'thiscall', None, ret='al', gen=_g5df8b0, note='batch33112')
S(0x4f39f0, 'GUESS flag entry and push its state via slots', 'thiscall', None, ret=None, gen=_g4f39f0, note='batch33112')
