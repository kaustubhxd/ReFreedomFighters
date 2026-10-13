"""specs_s6256.py - ragdoll side (claim 49): 0x640d40 ZRagdollContainer::ZRagdollContainer(int) (thiscall, one argument; ret 4; returns this). The allocator
(0x41e290) is the real exe code with pfspec's allocator. The array construction 0x634123 (stdcall, five arguments), the element constructor 0x640cc0 (returns
a word, logged) and the init 0x641a40 are recording stubs by address (GUESS: their bodies are not part of this batch). The record is 0x100 random bytes.
Counts are 0..3. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, allocator


def _x(c):
    e = c.emu
    r = c.rng
    allocator(c)
    elem_ret = r.getrandbits(32)

    def arr(em, rr):
        em.calllog.append(('634123', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4)))
        em.ret(argbytes=20)
    def ctor(em, rr):
        em.calllog.append(('640cc0', em.reg('ecx')))
        em.ret(eax=elem_ret, argbytes=0)
    def init(em, rr):
        em.calllog.append(('641a40', em.reg('ecx')))
        em.ret(argbytes=0)
    e.hook(0x634123, arr)
    e.hook(0x640cc0, ctor)
    e.hook(0x641a40, init)
    self_ = rnd(c, 0x100)
    return [self_, r.randint(0, 3)]


S(0x640d40, 'unnamed 0x640d40', 'thiscall', None, ret='eax', gen=_x, n=1000)
