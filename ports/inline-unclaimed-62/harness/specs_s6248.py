"""specs_s6248.py - ragdoll side (claim 41): 0x641c90, CRagdoll2::FixParticle(int, float*) (thiscall, two stack arguments, ret 8). The particle read
0x545c80 (thiscall, index and out pointer) is a recording stub by address that writes three random floats to out (GUESS: its body belongs to the
ConstrainedParticleSystem area). The engine object at eng+0x1aa3 has slot 0x94 returning a block whose float at +0xc is random in a range that crosses
the threshold 0x67a284. The distance helper 0x4e0870 is the real exe code. The flags and counters at +0x3f and +0x7f are random (the counter near the
limit of 20). The record is 0x400 random bytes. No faulting cases."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable, sf


def _x(c):
    e = c.emu
    r = c.rng
    import struct
    ka = struct.unpack('<f', bytes(e.rbytes(0x67a284, 4)))[0]
    kb = struct.unpack('<f', bytes(e.rbytes(0x680a84, 4)))[0]
    pbuf = e.alloc(16)
    for k in range(3):
        e.wf32(pbuf + 4 * k, sf(c.fv(-40, 40)))
    p = [struct.unpack('<f', bytes(e.rbytes(pbuf + 4 * k, 4)))[0] for k in range(3)]
    # the stub writes out = p + (kb, 0, 0) so that |p - out| equals kb exactly in some cases (the boundary of the d test)
    if r.random() < 0.5:
        outs = [sf(p[0] + kb), sf(p[1]), sf(p[2])]
    else:
        outs = [sf(c.fv(-50, 50)) for _ in range(3)]

    def get_particle(em, rr):
        em.calllog.append(('545c80', em.reg('ecx'), em.arg32(0)))
        out = em.arg32(1)
        for k in range(3):
            em.wf32(out + 4 * k, outs[k])
        em.ret(argbytes=8)
    e.hook(0x545c80, get_particle)
    eng = e.alloc(0x2000)
    blk = e.alloc(0x40)
    # the engine value sits just below the first threshold, so the distance test runs (ka > value)
    e.wf32(blk + 0xc, sf(ka - 1.0) if r.random() < 0.8 else sf(c.fv(-1, 1)))
    obj = e.alloc(0x40)
    e.w32(obj, vtable(c, 'obj641c90', 0x100, impl={0x94: lambda em, a: blk}, argwords={0x94: 0}))
    e.w32(eng + 0x1aa3, obj)
    e.w32(0x70039c, eng)
    rec = rnd(c, 0x400)
    pcs = e.alloc(0x40)
    e.w32(rec + 0x17f, pcs)
    idx = r.randint(0, 7)
    e.w32(rec + 0x3f + idx * 4, r.choice([0, 1, 1]))
    e.w32(rec + 0x7f + idx * 4, r.choice([0, 19, 18, r.randint(0, 25)]))
    return [rec, idx, pbuf]


S(0x641c90, 'unnamed 0x641c90', 'thiscall', None, ret='eax', gen=_x, n=1000)
