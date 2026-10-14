"""specs_s33113.py - h3 () batch 33113: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g529130(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5165d0, 4, this=True)
    me = rnd(c, 0x785 + 0xde * 5 + 0x20)
    e.w32(me + 0x8d, r.choice([1, 2, 3, 4]))
    e.w32(me + 0x91, r.choice([1, 2, 3, 4]))
    e.w32(me + 0x40, r.choice([0, 1, 2, 3, 5, 0xffffffff, 0xfffffffe, 0x7fffffff, 100, _w(c)]))
    e.w32(me + 0x44, r.choice([0, 1, 2, 3, 5, 0xffffffff, 0xfffffffe, 0x7fffffff, 100, _w(c)]))
    return [me]


def _g4f7330(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def side(em, k):
        for p, n in ((em.arg32(0), 9), (em.arg32(1), 3)):
            for q in range(n):
                em.w32(p + 4 * q, _b(c.fv(-5, 5, 0.25)) if p == em.arg32(1) else _w(c))
    s80 = pystub(c, 2, this=True, stackmark=(0, 1), side=side)
    cnt = r.choice([0, 1, 5, 10, -3 & 0xffffffff, 7])
    s388 = pystub(c, 0, this=True, ret=lambda em, k: r.choice([cnt, cnt + 1, cnt + 3, 0, 100]) if False else (cnt + k * 2) & 0xffffffff)
    s370 = pystub(c, 1, this=True)
    tgt = obj(c, 0x380, {0x370: s370})
    s7c = pystub(c, 2, this=True, deref={0: 9, 1: 3})
    t93 = obj(c, 0x90, {0x7c: s7c})
    me = obj(c, 0x3a0, {0x80: s80, 0x388: s388})
    e.wbytes(me + 0xa7, bytes([r.choice([0, 1, 1, 1, 0xff])]))
    e.w32(me + 0x93, t93)
    e.w32(me + 0x8f, tgt if r.random() < 0.85 else 0)
    fk = r.choice([0.0, 0.5, 1.5, -1.5, 3.0, 7.9, 100.0, 1e10, float('nan')])
    e.w32(me + 0x9f, _b(fk) if fk == fk else 0x7fc00000)
    e.w32(me + 0xa3, _b(c.fv(-5, 5, 0.25)))
    return [me, r.choice([0, 1, 0x100, 0xff, _w(c)])]


S(0x529130, 'GUESS advance two cyclic selectors and update widgets', 'thiscall', None, ret=None, gen=_g529130, note='batch33113')
S(0x4f7330, 'GUESS update position and playback speed via slots', 'thiscall', None, ret=None, gen=_g4f7330, note='batch33113')
