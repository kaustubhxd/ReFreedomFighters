"""specs_s49004.py - cascade u2 batch 49004: 0x527d10 (thiscall(a, b, c, d, e, f, g) ret 0x1c). `this` is a random block (byte +0x84 zero 15%, byte +0x21cd 50/50, int at +0x85 around the engine counter
at [0x70039c]+0x40, object pointer at +0x89 with slots 0x7c and 0x80). The ten update steps and 0x4e0030 (float in st0) and 0x446ee0 (output vector with a random sign in its second float) are hooked
and record `this` (and edx where it is an input); 0x4de420 (36-byte copy) runs as exe code."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

STEPS = [0x527bd0, 0x529660, 0x5279f0, 0x529130, 0x529450, 0x529020, 0x528b60, 0x528ae0, 0x5292c0, 0x5295d0]


def _g527d10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    fv = c.fv
    so = sysobj(c)
    cnt = r.randrange(-5, 50)
    e.wbytes(so + 0x40, struct.pack('<i', cnt))
    e.wbytes(so + 0x48, struct.pack('<f', fv(-10, 10, 0.1) or 1.0))
    me = rnd(c, 0x2200)
    e.wbytes(me + 0x84, bytes([0 if r.random() < 0.15 else r.randrange(1, 256)]))
    e.wbytes(me + 0x21cd, bytes([r.choice([0, 0, 1, 7])]))
    e.wbytes(me + 0x85, struct.pack('<i', cnt + r.choice([-3, -1, 0, 1, 2, 30])))
    o = obj(c, 0x20, {0x7c: pystub(c, 2, this=True, pop=8, stackmark=(0, 1)), 0x80: pystub(c, 2, this=True, pop=8, stackmark=(0, 1))}, nslots=0x40)
    e.wbytes(me + 0x89, struct.pack('<I', o))
    for a in STEPS:
        hook_rec(c, a, 0, pop=0, this=True)

    def side46(em, k):
        em.calllog.append(('edx', em.reg('edx')))
        em.wbytes(em.reg('ecx'), struct.pack('<fff', fv(-5, 5, 0.1), r.choice([-2.0, -0.5, 0.0, 0.5, 3.0, fv(-5, 5, 0.1)]), fv(-5, 5, 0.1)))
    hook_rec(c, 0x446ee0, 1, pop=4, this='mark', side=side46)

    def side4e(em, k):
        em.calllog.append(('4e0030', em.reg('ecx'), em.reg('edx')))
    hook_rec(c, 0x4e0030, 0, pop=0, this=True, side=side4e, st0=lambda em, k: fv(-10, 10, 0.1))
    a = rnd(c, 0x30)
    b = rnd(c, 0x20)
    cc = c.fbuf(3)
    d = c.fbuf(3)
    return [me, a, b, cc, d, F(fv(-5, 5, 0.1)), F(fv(-5, 5, 0.1)), F(fv(-5, 5, 0.1))]


S(0x527d10, 'GUESS view pose update', 'thiscall', None, ret=None, gen=_g527d10, note='batch49004')
