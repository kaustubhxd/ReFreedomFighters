"""specs_s3023.py - unclaimed-30 claim 2 (residue 10): 0x4778e0 (GUESS name; thiscall, seven stack arguments, ret 0x1c). The callee
0x465a80 is patched to a Python stub that logs all seven arguments (as raw words) and returns a per-case value; the early-return state
(+0x726 != 0 and +0x64c == 0xa) comes up about a third of the time. Returns al. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S, F
import serial_stubs as ss
from pfspec import rnd


def _g(c):
    e = c.emu
    r = c.rng
    ret = r.getrandbits(8)

    def callee(em, rr):
        args = [em.arg32(k) for k in range(7)]
        em.calllog.append(('465a80', tuple(args), em.reg('ecx')))
        em.ret(eax=ret, argbytes=28)
    ss.patch(c, 0x465a80, e.stub_fn('callee465a80', callee))
    self_ = rnd(c, 0x800)
    e.w8(self_ + 0x726, r.choice([0, 1, 1]))
    e.w32(self_ + 0x64c, r.choice([0xa, 0xa, 3, 0]))
    args = [r.getrandbits(32), F(c.fv(-100, 100)), F(c.fv(-100, 100)), r.getrandbits(32),
            r.getrandbits(32), F(c.fv(-100, 100)), F(c.fv(-100, 100))]
    return [self_] + args


S(0x4778e0, 'GUESS 0x4778e0', 'thiscall', None, ret='al', gen=_g, n=300)
