"""specs_s751.py - area 72 tail-jump forwarders with known arity. Targets hooked by address (logged). 0x4d9230 takes one
argument (ret 4); 0x4cd0e0, 0x4e66a0 and 0x54cd00 take none. The forwarders that store a vtable write 0x6a1a60 / 0x6a3338."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _tgt(c, e, tgt, n):
    rv = c.rng.getrandbits(32)

    def h(em, r):
        e.calllog.append(('tgt', tgt, nostk(e.reg('ecx')), tuple(em.arg32(k) for k in range(n))))
        em.ret(eax=rv, argbytes=4 * n)
    e.hook(tgt, h)


def _g_4d6e70(c):
    _tgt(c, c.emu, 0x4d9230, 1)
    return [_rnd(c, 0x400), c.rng.getrandbits(32)]


def _g_zero(tgt):
    def g(c):
        _tgt(c, c.emu, tgt, 0)
        return [_rnd(c, 0x400)]
    return g


S(0x4d6e70, 'fwd_4d9230', 'thiscall', None, ret='eax', gen=_g_4d6e70, note='b751 area 72 forwarder to 0x4d9230')
S(0x59ad30, 'fwd_4cd0e0', 'thiscall', None, ret=None, gen=_g_zero(0x4cd0e0), note='b751 area 72 forwarder to 0x4cd0e0')
S(0x534cf0, 'fwd_4e66a0', 'thiscall', None, ret=None, gen=_g_zero(0x4e66a0), note='b751 area 72 forwarder to 0x4e66a0')
S(0x549370, 'fwd_54cd00', 'thiscall', None, ret=None, gen=_g_zero(0x54cd00), note='b751 area 72 forwarder to 0x54cd00')
