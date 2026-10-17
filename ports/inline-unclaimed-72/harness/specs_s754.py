"""specs_s754.py - area 72 gap rows round 4. Virtual calls go to logging stubs on fake objects; the chained block for 0x4bb2c0
and the global object at 0x7003a0 hold random dwords. The one-argument functions get a random argument."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _vobj(c, e, slots):
    o = _rnd(c, 0x400)
    e.w32(o, e.fake_vtable('obj', 0x200, slots))
    return o


def _slot(e, off, nargs):
    def f(em, r):
        e.calllog.append(('vobj', off, nostk(e.reg('ecx')), tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=0x2000 + off, argbytes=4 * nargs)
    return f


def _g_4cbdc0(c):
    e = c.emu
    inner = _vobj(c, e, {0x3c: _slot(e, 0x3c, 1)})
    s = _rnd(c, 0x200)
    e.w32(s + 0x44, inner)
    return [s]


def _g_566e30(c):
    e = c.emu
    return [_vobj(c, e, {0xd0: _slot(e, 0xd0, 1)})]


def _g_4d4a30(c):
    e = c.emu
    s = _rnd(c, 0x100)
    blk = _rnd(c, 0x20)
    e.w32(blk, c.rng.getrandbits(32))
    return [s, blk]


def _g_arg1(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32)]


def _g_4bb2c0(c):
    e = c.emu
    x = _rnd(c, 0x200)
    e.w32(x + 0x70, c.rng.getrandbits(32))
    inner = _rnd(c, 0x200)
    e.w32(inner + 0x18, x)
    s = _rnd(c, 0x200)
    e.w32(s + 0x44, inner)
    return [s]


def _g_563500(c):
    e = c.emu
    g = _rnd(c, 0x200)
    e.w32(0x7003a0, g)
    return [_rnd(c, 0x100)]


def _g_4c8340(c):
    e = c.emu
    return [_vobj(c, e, {0x8: _slot(e, 0x8, 0)}), c.rng.getrandbits(32)]


def _g_4afec0(c):
    e = c.emu
    return [_vobj(c, e, {0x84: _slot(e, 0x84, 0)}), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4cbdc0, 'f_4cbdc0', 'thiscall', None, ret=None, gen=_g_4cbdc0, note='b754 area 72 round 4')
S(0x566e30, 'f_566e30', 'thiscall', None, ret=None, gen=_g_566e30, note='b754 area 72 round 4')
S(0x4d4a30, 'f_4d4a30', 'thiscall', None, ret='eax', gen=_g_4d4a30, note='b754 area 72 round 4')
S(0x4b00d0, 'f_4b00d0', 'thiscall', None, ret=None, gen=_g_arg1, note='b754 area 72 round 4')
S(0x4bb2c0, 'f_4bb2c0', 'thiscall', None, ret=None, gen=_g_4bb2c0, note='b754 area 72 round 4')
S(0x4d7530, 'f_4d7530', 'thiscall', None, ret=None, gen=_g_arg1, note='b754 area 72 round 4')
S(0x4be6d0, 'f_4be6d0', 'thiscall', None, ret=None, gen=_g_arg1, note='b754 area 72 round 4')
S(0x563500, 'f_563500', 'thiscall', None, ret=None, gen=_g_563500, note='b754 area 72 round 4')
S(0x4c8340, 'f_4c8340', 'thiscall', None, ret='al', gen=_g_4c8340, note='b754 area 72 round 4')
S(0x4afec0, 'f_4afec0', 'thiscall', None, ret=None, gen=_g_4afec0, note='b754 area 72 round 4')
