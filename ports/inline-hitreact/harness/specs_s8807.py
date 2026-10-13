"""specs_s8807.py - hitreact batch 8807: GetParticlePos (0x545c80), CRagdoll2::GetLocalPelvis (0x641e20), CRagdoll2::CalcGroundOffset
(0x641010). Exe code in both builds: PSVECSubtract / PSVECAdd / vscalar / vcross / vneg / vscalar3 / vsubInPlace / vangpul / createmat
(all strict elsewhere) and, inside CalcGroundOffset, GetLocalPelvis and GetParticlePos (this batch, exe side). The link object's
slots 0x8c / 0x90 (to local space) add a per-case vector and record what they get."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge
from hkit import rec_stub, fvec

V3 = [(0, 'd'), (4, 'd'), (8, 'd')]


def _particles(c, n=16):
    r = c.rng
    base = c.emu.alloc(0x34 * n + 0x40, 4)
    c.emu.wbytes(base, bytes(r.getrandbits(8) for _ in range(0x34 * n + 0x40)))
    for i in range(n):
        for k in range(3):
            c.emu.wf32(base + i * 0x34 + 0xc + 4 * k, r.choice((r.uniform(-200, 200), 0.0, fedge(c))) if r.random() < 0.1 else r.uniform(-200, 200))
    ps = rnd(c, 0x40)
    c.emu.w32(ps + 0xf, base)
    c.emu.w32(ps + 0x28, n)
    return ps


def _rag(c):
    r = c.rng
    ps = _particles(c)
    if r.random() < 0.5:   # pelvis-feet distance on the 20 / 40 bands (l = 0.9 x the horizontal distance)
        base = c.emu.r32(ps + 0xf)
        P = [r.uniform(-100, 100), r.uniform(50, 120), r.uniform(-100, 100)]
        l = r.choice((10.0, 20.0, 25.0, 30.0, 39.9, 40.0, 60.0))
        D = l / 0.9
        ang = r.uniform(0, 6.283)
        import math
        F = [P[0] + D * math.cos(ang), r.uniform(-10, 10), P[2] + D * math.sin(ang)]
        for i, q in ((8, P), (9, P), (14, F), (15, F)):
            for k in range(3):
                c.emu.wf32(base + i * 0x34 + 0xc + 4 * k, q[k] + (r.uniform(-0.5, 0.5) if i in (9, 15) else 0.0))
    addv = fvec(c, [r.uniform(-30, 30) for _ in range(3)])
    lk = obj(c, 0x100, {0x8c: rec_stub(c, 1, ptrs={0: V3}, adds={0: (addv, 3)}),
                        0x90: rec_stub(c, 1, ptrs={0: V3}, adds={0: (addv, 3)})})
    rag = rnd(c, 0x200)
    c.emu.w32(rag + 0x17f, ps)
    c.emu.w32(rag + 0x36, lk)
    for k in range(3):
        c.emu.wf32(rag + 8 + 4 * k, r.uniform(-100, 100))
    return rag


def _gpp(c):
    ps = _particles(c)
    return [ps, c.rng.randrange(0, 16), c.emu.alloc(16, 4)]


S(0x545c80, 'ConstrainedParticleSystem::GetParticlePos', 'thiscall', ret=None, gen=_gpp)


def _glp(c):
    return [_rag(c), c.emu.alloc(16, 4), c.emu.alloc(16, 4)]


S(0x641e20, 'CRagdoll2::GetLocalPelvis', 'thiscall', ret=None, gen=_glp)


def _cgo(c):
    r = c.rng
    rag = _rag(c)
    eng = rnd(c, 0x80)
    now = r.randrange(0, 1 << 22)
    c.emu.w32(eng + 0x40, now)
    c.emu.wf32(eng + 0x48, r.choice((0.033, 0.016, 0.1, 0.0, r.uniform(0, 0.2))))
    c.emu.w32(0x70039c, eng)
    c.emu.w32(rag + 0x2a, (now - r.choice((0, 1, 512, 1023, 1024, 1025, 5000, r.randrange(0, 4096)))) & 0xffffffff)
    mat = fvec(c, [r.uniform(-1, 1) for _ in range(9)] + [0.0])
    pos = c.emu.alloc(16, 4)
    c.emu.mu.ctl_flush_tb()
    return [rag, mat, pos]


S(0x641010, 'CRagdoll2::CalcGroundOffset', 'thiscall', ret=None, gen=_cgo)
