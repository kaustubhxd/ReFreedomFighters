"""specs_s6253.py - ragdoll side (claim 46): 0x644af0 CRagdoll2::Move (thiscall, three stack arguments: two pointers and a float; ret 0xc; returns al).
The record is 0x400 random bytes: the active flag (+0x15), the timeout counter (+0x16), the timeout run (+0x22), the per-particle flags (+0x3f, 16 dwords)
and targets (+0xbf, 12 bytes each), the ps pointer (+0x17f). The particle array (ps+0xf, 0x34 stride, 16 elements) is a separate block. The engine object
(+0x1aa3) has a logged slot 0x94 returning a block whose fields drive both branches (+4, +0xc near the threshold 0x67a284, +0x10 byte, +0x11 float, +0x29 ->
a block with the byte +0x15). The callees GetParticlePos (0x545c80), SetParticlePos (0x547760), ConstrainedParticleSystem::Move (0x546320; returns a float in
ST0), CalcGroundOffset (0x641010) are recording stubs by address (GUESS). The bool argument of 0x546320 is compared as its low byte. No faulting cases."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S, F
from pfspec import rnd, vtable, sf


def _x(c):
    e = c.emu
    r = c.rng
    kthr = struct.unpack('<f', bytes(e.rbytes(0x67a284, 4)))[0]

    def fin(v):
        return sf(v)

    def get_particle(em, rr):
        em.calllog.append(('545c80', em.reg('ecx'), em.arg32(0)))
        out = em.arg32(1)
        for k in range(3):
            em.wf32(out + 4 * k, fin(c.fv(-30, 30)))
        em.ret(argbytes=8)
    def set_particle(em, rr):
        em.calllog.append(('547760', em.reg('ecx'), em.arg32(0), bytes(em.rbytes(em.arg32(1), 12))))
        em.ret(argbytes=8)
    retf = sf(c.fv(-2, 2))

    def ps_move(em, rr):
        em.calllog.append(('546320', em.reg('ecx'), em.arg32(0), em.arg32(1) & 0xff, em.arg32(2)))
        em.ret(argbytes=12, st0=retf)
    def calc_ground(em, rr):
        em.calllog.append(('641010', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8)
    e.hook(0x545c80, get_particle)
    e.hook(0x547760, set_particle)
    e.hook(0x546320, ps_move)
    e.hook(0x641010, calc_ground)

    # the particle system: element array (16 x 0x34)
    ps = e.alloc(0x400)
    elems = e.alloc(0x34 * 16 + 0x40)
    e.wbytes(elems, bytes(r.getrandbits(8) for _ in range(0x34 * 16 + 0x40)))
    for i in range(16):
        for k in range(3):
            e.wf32(elems + i * 0x34 + 4 * k, fin(c.fv(-30, 30)))
    e.w32(ps + 0xf, elems)

    # the engine object and its block
    qblk = e.alloc(0x40)
    e.w8(qblk + 0x15, 1 if r.random() < 0.6 else 0)
    blk = e.alloc(0x80)
    e.wf32(blk + 4, fin(c.fv(-2, 2)))
    e.wf32(blk + 0xc, fin(kthr + (0.5 if r.random() < 0.5 else -0.5)))
    e.w8(blk + 0x10, r.choice([0, 1]))
    e.wf32(blk + 0x11, fin(c.fv(-2, 2)))
    e.w32(blk + 0x29, qblk)
    obj = e.alloc(0x40)
    e.w32(obj, vtable(c, 'obj644af0', 0x400, impl={0x94: lambda em, a: blk}, argwords={0x94: 0}))
    eng = e.alloc(0x2000)
    e.w32(eng + 0x1aa3, obj)
    e.w32(0x70039c, eng)

    # the ragdoll record
    rec = rnd(c, 0x400)
    e.w8(rec + 0x15, 1 if r.random() < 0.8 else 0)
    e.w8(rec + 0x14, r.choice([0, 1]))
    e.w32(rec + 0x16, r.randint(0, 3))
    e.w32(rec + 0x22, r.randint(0, 25))
    e.wf32(rec + 0x1a, fin(c.fv(-50, 400)) if r.random() < 0.8 else sf(c.fv(0.0, 0.01)))
    e.wf32(rec + 0x1e, fin(c.fv(-20, 20)))
    for i in range(16):
        e.w32(rec + 0x3f + 4 * i, r.choice([0, 1]))
        for k in range(3):
            e.wf32(rec + 0xbf + 12 * i + 4 * k, fin(c.fv(-30, 30)))
    e.w32(rec + 0x17f, ps)

    a1 = e.alloc(16)
    a2 = e.alloc(16)
    for k in range(3):
        e.wf32(a1 + 4 * k, fin(c.fv(-30, 30)))
        e.wf32(a2 + 4 * k, fin(c.fv(-30, 30)))
    return [rec, a1, a2, F(c.fv(0.0, 0.2))]


S(0x644af0, 'unnamed 0x644af0', 'thiscall', None, ret='al', gen=_x, n=1000)
