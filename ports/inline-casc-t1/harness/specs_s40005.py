"""specs_s40005. 0x524810: six floats at this+0..0x14 (EDGE_F included) passed to slot 0x4c, ret al. 0x4fdac0: engine table slot 0x138 returns an object whose slot 0x84 writes a float through arg 2 (zero / non-zero / NaN combos), [this+0x44] block gets the results.
0x5eda70: hooked 0x5ed170, unaligned dwords at +0xd7..+0xf3, slots 0x4c/0x3c/0x44. 0x4f0790: flag bytes +0xa7/+0x20, unaligned object pointer at +0x9f (slot 0x284 returns an int), [this+8] block float at +0x44, p float at +4, hooked CRT floor 0x634dca (st0).
0x57f580: system slot 0xbc object slots 0xac/0xa8 (st0 float), this slot 0x84 -> object slot 0x314, hooked 0x57f6b0, ret al."""
import struct
from pilot import S, EDGE_F, F
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub, hook_rec


def _fb(v):
    try:
        return struct.unpack('<I', struct.pack('<f', v))[0]
    except OverflowError:
        return 0x7f800000 if v > 0 else 0xff800000


def _rf(r):
    k = r.random()
    if k < 0.15:
        return _fb(r.choice(EDGE_F))
    if k < 0.2:
        return r.getrandbits(32)
    return _fb(r.uniform(-1000, 1000))


def _g524810(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x20, {0x4c: pystub(c, 1, this=True)}, nslots=0x50 // 4)
    me = rnd(c, 0x20)
    for i in range(6):
        e.w32(me + 4 * i, _rf(r))
    return [me, o]


def _g4fdac0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [0, 0, 0, 0x80000000, 0x3f800000, 0x7fc00000, _rf(r)]

    def put(em, k):
        em.w32(em.arg32(1), r.choice(vals) if k >= 0 else 0)
    ob = obj(c, 0x20, {0x84: pystub(c, 2, this=True, stackmark=(1,), side=put)}, nslots=0x88 // 4)
    sysobj(c, table_slots={0x138: pystub(c, 0, ret=ob, this=True)})
    me = rnd(c, 0x60)
    e.w32(me + 0x44, rnd(c, 0x90))
    return [me]


def _g5eda70(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5ed170, 1, this=True)
    o = obj(c, 0x20, {0x4c: pystub(c, 1, this=True), 0x3c: pystub(c, 1, this=True), 0x44: pystub(c, 1, this=True)}, nslots=0x50 // 4)
    me = rnd(c, 0x100)
    return [me, o]


def _g4f0790(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634dca, 2, pop=0, st0=lambda em, k: r.choice([0.0, 3.0, -7.5, 1234.75, 2.5e9, -2.5e9, 1e30, float('nan')]))
    ob = obj(c, 0x20, {0x284: pystub(c, 0, ret=r.choice([0, 1, 100, -7 & 0xffffffff, r.getrandbits(32)]), this=True)}, nslots=0x288 // 4)
    me = rnd(c, 0xb0)
    e.wbytes(me + 0x9f, ob.to_bytes(4, 'little'))
    e.wbytes(me + 0xa7, bytes([r.choice([0, 1, 1, 7])]))
    e.wbytes(me + 0x20, bytes([r.choice([0, 0x10, 0x20, 0x30, 0x40, 0x11, 0xf0, 0x01, r.getrandbits(8)])]))
    inner = rnd(c, 0x60)
    e.w32(inner + 0x44, _rf(r))
    e.w32(me + 8, inner)
    p = rnd(c, 0x10)
    e.w32(p + 4, _rf(r))
    return [me, p]


def _g57f580(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x57f6b0, 0, this=True)
    fv = [0.0, 1.0, -2.5, 77.125, r.uniform(-10, 10)]
    o = obj(c, 0x20, {0xac: pystub(c, 1, this=True), 0xa8: pystub(c, 0, this=True, st0=lambda em, k: r.choice(fv))}, nslots=0xb0 // 4)
    sysobj(c, slots={0xbc: pystub(c, 0, ret=o, this=True)})
    ee = obj(c, 0x20, {0x314: pystub(c, 1, this=True)}, nslots=0x318 // 4)
    me = obj(c, 0x40, {0x84: pystub(c, 0, ret=ee, this=True)}, nslots=0x88 // 4)
    n = r.choice([0, 1, 100, 0x7fffffff, 0x80000000, 0xffffffff, -5 & 0xffffffff, 123456789, r.getrandbits(32)])
    return [me, r.getrandbits(32), n]


S(0x524810, 'GUESS send six floats', 'thiscall', None, ret='al', gen=_g524810, note='batch40005')
S(0x4fdac0, 'GUESS load two config floats', 'thiscall', None, ret=None, gen=_g4fdac0, note='batch40005')
S(0x5eda70, 'GUESS send settings block', 'thiscall', None, ret=None, gen=_g5eda70, note='batch40005')
S(0x4f0790, 'GUESS compute floor offset', 'thiscall', None, ret=None, gen=_g4f0790, note='batch40005')
S(0x57f580, 'GUESS apply scaled value', 'thiscall', None, ret='al', gen=_g57f580, note='batch40005')
