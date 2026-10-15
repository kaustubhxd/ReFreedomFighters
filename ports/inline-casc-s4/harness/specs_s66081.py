"""specs_s66081.py - cascade s4 batch 66081: 0x507420 (set a camera from two vectors read from a call record)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g507420(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    recs = []
    for i in range(6):
        rec = e.alloc(0x10, 8)
        e.w32(rec, r.getrandbits(32))
        recs.append(rec)
    order = [2, 1, 0, 5, 4, 3]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: recs[order[min(k, 5)]])

    def dw(em, p, n):
        return bytes(em.rbytes(p, 4 * n))

    def s630(em, rr):
        p = em.arg32(0)
        em.calllog.append(('s630',))
        for i in range(3):
            em.w32(p + 4 * i, 0x70 + i)
        em.ret(eax=0, argbytes=4)

    def s5e8(em, rr):
        em.calllog.append(('s5e8', dw(em, em.arg32(0), 3)))
        em.ret(eax=0, argbytes=4)

    def s5e0(em, rr):
        em.calllog.append(('s5e0', dw(em, em.arg32(0), 3), dw(em, em.arg32(1), 3)))
        em.ret(eax=0, argbytes=8)
    g = obj(c, 0x40, {0x624: pystub(c, 1, this=True), 0x630: e.stub_fn('s630', s630), 0x5e8: e.stub_fn('s5e8', s5e8), 0x5e0: e.stub_fn('s5e0', s5e0)})
    t = rnd(c, 0x40)
    e.w32(t + 0x18, g)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 8))
    return [t, p]


S(0x507420, 'GUESS set a camera from two vectors read from a call record', 'thiscall', None, ret=None, gen=_g507420, note='batch66081')
