"""specs_s66025.py - cascade s4 batch 66025: 0x47bff0 (/GS-protected: build two transforms of an entry and hand them to a service)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g47bff0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    logger(c, 2)

    def dw(em, p, n):
        return bytes(em.rbytes(p, 4 * n))

    def mk(em_ecx, v):
        return None

    def h7c0(em, rr):                     # 0x4db7c0: thiscall (&v) ret 4
        v = em.arg32(0)
        em.calllog.append(('h4db7c0', em.reg('ecx')))
        for i in range(3):
            em.w32(v + 4 * i, (em.reg('ecx') + 0x1111 * (i + 1)) & 0xffffffff)
        em.ret(eax=0, argbytes=4)
    e.hook(0x4db7c0, h7c0)

    def s80(em, rr):                      # o->slot 0x80 (&p1, &p2) ret 8
        p1, p2 = em.arg32(0), em.arg32(1)
        em.calllog.append(('s80', em.reg('ecx')))
        for i in range(9):
            em.w32(p1 + 4 * i, 0xa0 + i)
        for i in range(3):
            em.w32(p2 + 4 * i, 0xb0 + i)
        em.ret(eax=0, argbytes=8)

    def s21c(em, rr):                     # d->slot 0x21c (&p2, &v, b) ret 12
        em.calllog.append(('s21c', em.reg('ecx'), dw(em, em.arg32(0), 3), dw(em, em.arg32(1), 3), em.arg32(2)))
        em.ret(eax=0, argbytes=12)
    d = obj(c, 0x20, {0x21c: e.stub_fn('s21c', s21c)})
    ctx = rnd(c, 0x10)
    ent = obj(c, 0x20, {0x80: e.stub_fn('s80', s80)})
    e.w32(ent + 8, ctx)
    found = {}
    aid = r.getrandbits(32) | 1
    if r.random() < 0.8:
        found[aid] = ent

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(found.get(v, 0), 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    me = obj(c, 0x20 + 0x600, {0x5d0: pystub(c, 0, this=True, ret=(d if r.random() < 0.8 else 0))})
    return [me, aid, r.getrandbits(32)]


S(0x47bff0, 'GUESS /GS hand two transforms of an entry to a service', 'thiscall', None, ret=None, gen=_g47bff0, note='batch66025')
