"""specs_s760.py - batch 760: 0x4c59f0 forwards to DBREAD::GetRefTab (0x4e6330, ret 4). The callee is hooked by address: it logs
ecx and its one argument and returns 0. Arity: the target's ret 4 (1 arg), argbytes matches."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _gen(c):
    e = c.emu
    def h(em, r):
        e.calllog.append(('db', 0x4e6330, nostk(e.reg('ecx')), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    e.hook(0x4e6330, h)
    return [_rnd(c, 0x200), _rnd(c, 0x100)]


S(0x4c59f0, 'f_4c59f0', 'thiscall', None, ret=None, gen=_gen, note='b760 area 72 forwarder to 0x4e6330 (ret 4)')
