"""specs_s759.py - area 72 batch 759: call-then-jump rows. Every callee (base and tail target) is hooked by address and logs; all take
zero arguments (their rets are plain). 0x566f10 returns a random eax, stored by the caller at +0x198."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _hook0(c, e, tgt, rv=0):
    def h(em, r):
        e.calllog.append(('cal0', tgt, nostk(e.reg('ecx')), ()))
        em.ret(eax=rv, argbytes=0)
    e.hook(tgt, h)


def _g(targets, rv_for=None):
    def g(c):
        e = c.emu
        for t in targets:
            _hook0(c, e, t, c.rng.getrandbits(32) if t == rv_for else 0)
        s = _rnd(c, 0x400)
        return [s]
    return g


S(0x5aeda0, 'f_5aeda0', 'thiscall', None, ret='eax', gen=_g([0x5aef10]), note='b759 area 72')
S(0x566e40, 'f_566e40', 'thiscall', None, ret=None, gen=_g([0x566f10], rv_for=0x566f10), note='b759 area 72')
S(0x56a080, 'f_56a080', 'thiscall', None, ret=None, gen=_g([0x562440, 0x56a140]), note='b759 area 72')
S(0x56ba00, 'f_56ba00', 'thiscall', None, ret=None, gen=_g([0x564b10, 0x56bd90]), note='b759 area 72')
S(0x57f400, 'f_57f400', 'thiscall', None, ret=None, gen=_g([0x562440, 0x57f420]), note='b759 area 72')
