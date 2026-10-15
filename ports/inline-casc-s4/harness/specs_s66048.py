"""specs_s66048.py - cascade s4 batch 66048: 0x507710 (/GS-protected: resolve an object's two transforms and apply them to a controller)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g507710(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))

    def dw(em, p, n):
        return bytes(em.rbytes(p, 4 * n))
    rec = rnd(c, 8)
    e.w32(rec, 0x4242)
    hook_rec(c, 0x5003d0, 1, this=True, ret=rec)

    def s80(em, rr):
        s1, s2 = em.arg32(0), em.arg32(1)
        em.calllog.append(('s80', em.reg('ecx')))
        for i in range(9):
            em.w32(s1 + 4 * i, 0xa0 + i)
        for i in range(3):
            em.w32(s2 + 4 * i, 0xb0 + i)
        em.ret(eax=0, argbytes=8)

    def p4e(em, rr):                      # 0x4e09b0 (ecx = &s1) plain ret
        s1 = em.reg('ecx')
        em.calllog.append(('h4e09b0', dw(em, s1, 9)))
        em.w32(s1, 0x1234)
        em.ret(eax=0, argbytes=0)

    def p94(em, rr):                      # 0x5094c0 (o, &s1, &s2) ret 0xc
        em.calllog.append(('h5094c0', em.reg('ecx'), em.arg32(0), dw(em, em.arg32(1), 9), dw(em, em.arg32(2), 3)))
        em.ret(eax=0, argbytes=12)
    e.hook(0x4e09b0, p4e)
    e.hook(0x5094c0, p94)

    def s624(em, rr):
        em.calllog.append(('s624', em.arg32(0)))
        em.ret(eax=0, argbytes=4)

    def s634(em, rr):
        em.calllog.append(('s634', dw(em, em.arg32(0), 3), dw(em, em.arg32(1), 9)))
        em.ret(eax=0, argbytes=8)
    ent = rnd(c, 8)
    ctl = obj(c, 0x30, {0x624: e.stub_fn('s624', s624), 0x634: e.stub_fn('s634', s634), 0x20: pystub(c, 0, this=True, ret=ent)})
    o = obj(c, 0x30, {0x80: e.stub_fn('s80', s80), 0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100, 0x101]))})
    found = r.random() < 0.8

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(o if (v == 0x4242 and found) else 0, 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    lo = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)})
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lo)})
    e.w32(0x700390, lg)
    t = rnd(c, 0x30)
    e.w32(t + 0x18, ctl)
    a = rnd(c, 0x10)
    e.w32(a + 4, rnd(c, 8))
    return [t, a]


S(0x507710, 'GUESS /GS apply an object transforms to a controller', 'thiscall', None, ret='eax', gen=_g507710, note='batch66048')
