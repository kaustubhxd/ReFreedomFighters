"""specs_s6254.py - ragdoll side (claim 47): 0x647140 ZBoneModifyBase::HitRagdoll (thiscall, pos, dir, strength; ret 0xc). The ragdoll pointer at +0x291 is
null in about a third of the cases. CRagdoll2::Hit (0x644400) is a recording stub by address (its own verified port is batch 6252). No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S, F
from pfspec import rnd


def _x(c):
    e = c.emu
    r = c.rng

    def hit(em, rr):
        em.calllog.append(('644400', em.reg('ecx'), em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(argbytes=12)
    e.hook(0x644400, hit)
    rec = rnd(c, 0x400)
    rag = rnd(c, 0x100)
    e.w32(rec + 0x291, rag if r.random() < 0.67 else 0)
    pos = e.alloc(16)
    dirb = e.alloc(16)
    for k in range(3):
        e.wf32(pos + 4 * k, sf_(c.fv(-30, 30)))
        e.wf32(dirb + 4 * k, sf_(c.fv(-1, 1)))
    return [rec, pos, dirb, F(c.fv(0.0, 3.0))]


from pfspec import sf as sf_

S(0x647140, 'unnamed 0x647140', 'thiscall', None, gen=_x, n=1000)
