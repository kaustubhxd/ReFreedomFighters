"""specs_s753.py - area 72 gap rows: tail-jump forwarders with the target's arity (its ret / 4). Each target is hooked by
address (logged, argbytes = 4 x arity). The forwarder's own args are the same count."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk

ARITY = {0x4efdd0: 4, 0x43ff00: 5, 0x4fd510: 1, 0x5fa590: 2, 0x5355a0: 3}


def _hook(c, e, tgt, n):
    def h(em, r):
        e.calllog.append(('tgt', tgt, nostk(e.reg('ecx')), tuple(em.arg32(k) for k in range(n))))
        em.ret(eax=0, argbytes=4 * n)
    e.hook(tgt, h)


def _gen(tgt):
    def g(c):
        n = ARITY[tgt]
        _hook(c, c.emu, tgt, n)
        return [_rnd(c, 0x400)] + [c.rng.getrandbits(32) for _ in range(n)]
    return g


S(0x4f5840, 'fwd_4efdd0', 'thiscall', None, ret=None, gen=_gen(0x4efdd0), note='b753 area 72 forwarder to 0x4efdd0 (ZWINOBJ::Draw)')
S(0x4f9e00, 'fwd_43ff00', 'thiscall', None, ret=None, gen=_gen(0x43ff00), note='b753 area 72 forwarder to 0x43ff00 (ZGROUP::Duplicate)')
S(0x4fc130, 'fwd_4fd510', 'thiscall', None, ret=None, gen=_gen(0x4fd510), note='b753 area 72 forwarder to 0x4fd510')
S(0x50b7e0, 'fwd_5fa590', 'thiscall', None, ret=None, gen=_gen(0x5fa590), note='b753 area 72 forwarder to 0x5fa590')
S(0x533100, 'fwd_5355a0', 'thiscall', None, ret=None, gen=_gen(0x5355a0), note='b753 area 72 forwarder to 0x5355a0')
