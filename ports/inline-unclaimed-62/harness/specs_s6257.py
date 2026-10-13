"""specs_s6257.py - ragdoll side (claim 50): 0x644630 CRagdoll2::Init (thiscall, one stack argument, ret 4). The setup 0x645000 and ComputeParticlePositions
0x6411b0 are recording stubs by address (GUESS: their bodies are not part of this batch). The record is 0x100 random bytes; the dword at +0x2e is compared.
No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _x(c):
    e = c.emu
    r = c.rng

    def setup(em, rr):
        em.calllog.append(('645000', em.reg('ecx'), em.arg32(0)))
        em.ret(argbytes=4)

    def cpp(em, rr):
        em.calllog.append(('6411b0', em.reg('ecx')))
        em.ret(argbytes=0)
    e.hook(0x645000, setup)
    e.hook(0x6411b0, cpp)
    return [rnd(c, 0x100), r.getrandbits(32)]


S(0x644630, 'unnamed 0x644630', 'thiscall', None, gen=_x, n=1000)
