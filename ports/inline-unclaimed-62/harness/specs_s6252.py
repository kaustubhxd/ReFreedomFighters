"""specs_s6252.py - hit-reaction hand-off (claim 45): 0x644400 CRagdoll2::Hit (thiscall, pos pointer, dir pointer, float strength; ret 0xc). The particle
helpers BlowDirBomb 0x5438f0, GetParticlePos 0x545c80 and FixParticle 0x641c90 are recording stubs by address (GUESS: each is verified in its own batch). The
collision object (message table +0xadc) has a logged slot 0x2e0 (six arguments) returning a random byte. The engine's object (+0x1aa3) has a logged slot 0x94
returning a block whose float at +0xc is either above or below the threshold 0x67a284. The COLI constructor 0x4e1b60 and the vector helpers are real exe
code. The direction is kept away from zero (its normalisation is the subject). Records 0x400 random bytes. No faulting cases."""
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

    def stub(name, argbytes, nargs, fill=None, peek=()):
        # peek: argument positions that are pointers into the caller's stack; their contents are logged, not the (layout-dependent) address
        def h(em, rr):
            vals = []
            for k in range(nargs):
                a = em.arg32(k)
                vals.append(('mem', bytes(em.rbytes(a, 12))) if k in peek else a)
            if fill is not None:
                fill(em, em.arg32(1) if nargs >= 2 else 0)
                if 1 in peek:
                    vals[1] = ('mem', bytes(em.rbytes(em.arg32(1), 12)))
            em.calllog.append((name, em.reg('ecx')) + tuple(vals))
            em.ret(argbytes=argbytes)
        return h

    def fill_out(em, out):
        for k in range(3):
            em.wf32(out + 4 * k, sf(c.fv(-30, 30)))
    e.hook(0x5438f0, stub('5438f0', 12, 3, peek=(2,)))
    e.hook(0x641c90, stub('641c90', 8, 2, peek=(1,)))
    e.hook(0x545c80, stub('545c80', 8, 2, fill=fill_out, peek=(1,)))

    msg = e.alloc(0xb00)
    coll = e.alloc(0x40)
    retb = r.random() < 0.5
    hitp = [sf(c.fv(-30, 30)) for _ in range(3)]

    def coll_query(em, a):
        # the hit point is written into the COLI object (its +0x28..+0x30) when the query succeeds
        if retb:
            for k in range(3):
                em.wf32(a[0] + 0x28 + 4 * k, hitp[k])
        return 1 if retb else 0
    e.w32(coll, vtable(c, 'coll644400', 0x400, impl={0x2e0: coll_query}, argwords={0x2e0: 6}))
    e.w32(msg + 0xadc, coll)
    eng = e.alloc(0x2000)
    e.w32(eng + 0x9b, msg)
    e.w32(0x70039c, eng)
    blk = e.alloc(0x40)
    e.wf32(blk + 8, sf(c.fv(-2, 2)))
    pick = r.random()
    e.wf32(blk + 0xc, sf(kthr if pick < 0.25 else kthr + (0.5 if pick < 0.6 else -0.5)))   # 25%: exactly the threshold
    obj = e.alloc(0x40)
    e.w32(obj, vtable(c, 'obj644400', 0x400, impl={0x94: lambda em, a: blk}, argwords={0x94: 0}))
    e.w32(eng + 0x1aa3, obj)
    ps = rnd(c, 0x400)
    e.w32(ps + 0x17f, rnd(c, 0x100))
    pos = e.alloc(16)
    dirb = e.alloc(16)
    for k in range(3):
        e.wf32(pos + 4 * k, sf(c.fv(-30, 30)))
    while True:
        d = [c.fv(-1, 1) for _ in range(3)]
        if sum(v * v for v in d) > 0.04:
            break
    for k in range(3):
        e.wf32(dirb + 4 * k, sf(d[k]))
    strength = c.fv(0.1, 3)
    return [ps, pos, dirb, F(strength)]


S(0x644400, 'unnamed 0x644400', 'thiscall', None, gen=_x, n=1000)
