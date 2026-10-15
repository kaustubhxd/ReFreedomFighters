"""specs_s33119.py - h3 (Sonnet) batch 33119: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g4f8240(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4fa630, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0xff, _w(c)]))
    stubs = {off: pystub(c, n, this=True) for off, n in ((0x44, 1), (0x4c, 1), (0x3c, 1), (0x6c, 1))}
    s = obj(c, 0x80, stubs)
    return [rnd(c, 0xe0), s]


def _g527f80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x516360, 1, this=True, deref={0: 3})

    def side(em, k):
        p = em.arg32(0)
        for i in range(3):
            em.w32(p + 4 * i, _w(c))
    s84 = pystub(c, 1, this=True, deref={0: 3}, side=side)
    tgt = obj(c, 0x90, {0x84: s84})
    me = rnd(c, 0x1831 + 0x133 * 4 + 0x20)
    e.w32(me + 0x89, tgt)
    e.w32(me + 0x8d, r.choice([0, 1, 2, 3, 0xffffffff]))
    e.w32(me + 0x91, r.choice([0, 1, 2, 3, 0xfffffffe]))
    return [me]


S(0x4f8240, 'GUESS write record fields to stream when 0x4fa630', 'thiscall', None, ret='al', gen=_g4f8240, note='batch33119')
S(0x527f80, 'GUESS transform arrays of vectors through slot 0x84 and apply', 'thiscall', None, ret=None, gen=_g527f80, note='batch33119')
