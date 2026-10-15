"""specs_s33078.py - h3 (Sonnet) batch 33078: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _fl(c):
    return F(c.fv(-10.0, 10.0, 0.25))


def _fbits(c):
    return struct.unpack('<I', struct.pack('<f', c.fv(-10.0, 10.0, 0.25)))[0]


def _g5d6e60(c):
    clear_hooks(c)
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda em, k: c.fv(-10.0, 10.0, 0.25))
    return [rnd(c, 0x60), rnd(c, 0x20)]


def _g4752b0(c):
    clear_hooks(c)
    hook_rec(c, 0x467410, 6, this=True)
    return [rnd(c, 0x380), _fl(c), _fl(c), _fl(c), _fl(c), _fl(c)]


def _g4e0940(c):
    clear_hooks(c)
    e = c.emu

    def vec():
        v = rnd(c, 0x10)
        for i in range(3):
            e.w32(v + 4 * i, _fbits(c))
        return v
    return [rnd(c, 0x10), vec(), vec()]


def _g52c240(c):
    clear_hooks(c)
    hook_rec(c, 0x52c270, 7, this=True, ret=lambda em, k: _w(c))
    return [rnd(c, 0x20)] + [_w(c) for _ in range(7)]


def _g475710(c):
    clear_hooks(c)
    s = pystub(c, 7, this=True, ret=lambda em, k: _w(c))
    return [obj(c, 0x4c0, {0x4ac: s}), _w(c), _fl(c), _fl(c), _fl(c), _fl(c), _fl(c)]


def _g5138c0(c):
    clear_hooks(c)
    s = pystub(c, 2, this=True)
    ch = obj(c, 0x40, {0: s})
    me = rnd(c, 0xd0)
    c.emu.w32(me + 0x5c, ch)
    c.emu.w32(me + 0xcc, _w(c) | 0x10001)
    return [me, _fl(c), _w(c)]


def _g5243a0(c):
    clear_hooks(c)
    me = rnd(c, 0x20)
    c.emu.w32(me + 0x10, _fbits(c))
    return [me]


def _g5c9130(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c)
    c.emu.w32(so + 0x40, r.choice([0, 1, 100, 0x7fffffff, 0x80000000, _w(c), r.randrange(0, 5000)]))
    f = r.choice([F(c.fv(-10.0, 10.0, 0.15)), F(r.uniform(-3000, 3000)), F(r.uniform(-3e9, 3e9)), F(r.uniform(-1e12, 1e12))])
    return [rnd(c, 0x90), _w(c), f]


S(0x5d6e60, 'GUESS two float queries stored', 'thiscall', None, ret=None, gen=_g5d6e60, note='batch33078')
S(0x4752b0, 'GUESS forward float and vec4 with this', 'thiscall', None, ret=None, gen=_g4752b0, note='batch33078')
S(0x4e0940, 'GUESS vec3 component multiply', 'fastcall', None, ret=None, gen=_g4e0940, note='batch33078')
S(0x52c240, 'GUESS seven arg pass-through', 'thiscall', None, ret=None, gen=_g52c240, note='batch33078')
S(0x475710, 'GUESS vcall 4ac with float vec4', 'thiscall', None, ret=None, gen=_g475710, note='batch33078')
S(0x5138c0, 'GUESS child vcall with float then clear', 'thiscall', None, ret=None, gen=_g5138c0, note='batch33078')
S(0x5243a0, 'GUESS reciprocal or large default', 'thiscall', None, ret='st0', gen=_g5243a0, note='batch33078')
S(0x5c9130, 'GUESS fixed point offset to float', 'thiscall', None, ret=None, gen=_g5c9130, note='batch33078')
