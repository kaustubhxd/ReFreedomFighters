"""specs_s6258.py - ragdoll side: 0x641340 CRagdoll2::ComputeParticlePositionsSub (thiscall, no arguments, plain ret, no result).
The record is 0x400 random bytes; the sixteen bone dwords (+0x187..+0x1cf) are random and only logged, and ps (+0x17f) is a separate block.
GetLinkMatPos_global (0x641d90) is a recording stub by address (GUESS): it logs (this, bone), returns a random al (upper eax bits random), and on a
true return writes M (9 floats), P, Q and R (3 floats each) through its four pointer arguments. R[1] is drawn around the 10.0 clamp of particles
5 and 6. The setters 0x547760 / 0x547730 / 0x547830 are recording stubs by address (GUESS) that log (ps, index, the 12 vector bytes); the
velocity setter receives the zero vector. 0x4419f0 and 0x441940 run as exe code. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, sf


def _x(c):
    e = c.emu
    r = c.rng
    ptrue = r.choice([0.3, 0.7, 1.0])

    def query(em, rr):
        em.calllog.append(('641d90', em.reg('ecx'), em.arg32(0)))
        ok = r.random() < ptrue
        if ok:
            m, p, q, rv = em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4)
            for k in range(9):
                em.wf32(m + 4 * k, sf(c.fv(-2, 2)))
            for k in range(3):
                em.wf32(p + 4 * k, sf(c.fv(-30, 30)))
                em.wf32(q + 4 * k, sf(c.fv(-5, 5)))
                em.wf32(rv + 4 * k, sf(c.fv(-5, 5)))
            if r.random() < 0.6:
                em.wf32(rv + 4, sf(10.0 + r.choice([-3.0, -1e-6, 0.0, 1e-6, 3.0, r.uniform(-20, 20)])))
        al = r.randint(1, 255) if ok else 0
        em.ret(eax=(r.getrandbits(24) << 8) | al, argbytes=0x14)

    def setter(tag):
        def h(em, rr):
            em.calllog.append((tag, em.reg('ecx'), em.arg32(0), bytes(em.rbytes(em.arg32(1), 12))))
            em.ret(argbytes=8)
        return h

    e.hook(0x641d90, query)
    e.hook(0x547760, setter('547760'))
    e.hook(0x547730, setter('547730'))
    e.hook(0x547830, setter('547830'))

    ps = e.alloc(0x40)
    rec = rnd(c, 0x400)
    e.w32(rec + 0x17f, ps)
    return [rec]


S(0x641340, 'CRagdoll2::ComputeParticlePositionsSub', 'thiscall', None, gen=_x, n=1000)
