"""specs_s757.py - area 72 gap rows, batch 757: vtable calls on fake objects that log their arguments. Slot 0x3c returns a
pointer to a block holding a double (for 0x4d1db0) or a dword (for 0x4d1e10). The tail jumps (0x4dc420, 0x54c300) log the
argument they receive."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _vobj(c, e, slots):
    o = _rnd(c, 0x400)
    e.w32(o, e.fake_vtable('obj', 0x200, slots))
    return o


def _slot(e, off, nargs, rv=0):
    def f(em, r):
        e.calllog.append(('vobj', off, nostk(e.reg('ecx')), tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=rv, argbytes=4 * nargs)
    return f


def _g_4bbc20(c):
    e = c.emu
    o = _vobj(c, e, {0x210: _slot(e, 0x210, 1)})
    s = _rnd(c, 0x200)
    e.w32(s + 0x44, o)
    return [s]


def _g_4aff30(c):
    e = c.emu
    s = _vobj(c, e, {0x84: _slot(e, 0x84, 1)})
    return [s, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _g_551080(c):
    e = c.emu
    a = _vobj(c, e, {0x18: _slot(e, 0x18, 1)})
    return [_rnd(c, 0x100), a, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _g_54(off, slot):
    def g(c):
        e = c.emu
        s = _rnd(c, 0x200)
        if c.rng.random() < 0.7:
            o = _vobj(c, e, {slot: _slot(e, slot, 1)})
            e.w32(s + off, o)
        else:
            e.w32(s + off, 0)
        return [s, c.rng.getrandbits(32)]
    return g


def _g_3c(kind):
    def g(c):
        e = c.emu
        blk = _rnd(c, 0x40)
        if kind == 'd':
            e.wbytes(blk, struct.pack('<d', c.rng.uniform(-1e6, 1e6)))
        else:
            e.w32(blk, c.rng.getrandbits(32))
        s = _vobj(c, e, {0x3c: _slot(e, 0x3c, 1, blk)})
        return [s, c.rng.getrandbits(32)]
    return g


S(0x4bbc20, 'f_4bbc20', 'thiscall', None, ret=None, gen=_g_4bbc20, note='b757 area 72 gap row')
S(0x4aff30, 'f_4aff30', 'thiscall', None, ret=None, gen=_g_4aff30, note='b757 area 72 gap row')
S(0x551080, 'f_551080', 'thiscall', None, ret=None, gen=_g_551080, note='b757 area 72 gap row')
S(0x4dc420, 'f_4dc420', 'thiscall', None, ret=None, gen=_g_54(0x54, 0xc), note='b757 area 72 gap row (tail, arity 1)')
S(0x54c300, 'f_54c300', 'thiscall', None, ret=None, gen=_g_54(0x50, 0x18), note='b757 area 72 gap row (tail, arity 1)')
S(0x4d1db0, 'f_4d1db0', 'thiscall', None, ret='st0', gen=_g_3c('d'), note='b757 area 72 gap row')
S(0x4d1e10, 'f_4d1e10', 'thiscall', None, ret='eax', gen=_g_3c('w'), note='b757 area 72 gap row')
