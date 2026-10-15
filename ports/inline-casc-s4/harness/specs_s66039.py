"""specs_s66039.py - cascade s4 batch 66039: 0x4b84b0 (/GS-protected: advance a round-robin cursor and hand two transforms to a target)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4b84b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))

    def dw(em, p, n):
        return bytes(em.rbytes(p, 4 * n))

    def s80(em, rr):                      # o1->slot 0x80 (&s1, &s2) ret 8
        s1, s2 = em.arg32(0), em.arg32(1)
        em.calllog.append(('s80', em.reg('ecx')))
        for i in range(9):
            em.w32(s1 + 4 * i, 0xa0 + i)
        for i in range(3):
            em.w32(s2 + 4 * i, 0xb0 + i)
        em.ret(eax=0, argbytes=8)

    def mkd(name):
        def h(em, rr):
            em.calllog.append((name, em.reg('ecx'), dw(em, em.arg32(0), 9), dw(em, em.arg32(1), 3)))
            em.ret(eax=r.getrandbits(32), argbytes=8)
        return e.stub_fn(name, h)
    n = r.choice([0, 1, 3, 5])
    ids = [0x100 + i for i in range(max(n, 1))]
    objs = {}
    for i in ids:
        if r.random() < 0.85:
            objs[i] = obj(c, 0x30, {0x80: e.stub_fn('s80', s80)})
    o2 = obj(c, 0x30, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100, 0x101])),
                       0x370: mkd('d370'), 0x7c: mkd('d7c')})
    tid = 0x777
    objs[tid] = o2 if r.random() < 0.85 else 0

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs.get(v, 0) or 0, 4)

    def at(em, rr):
        em.calllog.append(('l.at', em.arg32(0)))
        em.ret(eax=ids[em.arg32(0)] if em.arg32(0) < len(ids) else 0, argbytes=4)
    lst = obj(c, 0x30, {0x14: pystub(c, 0, this=True, ret=n), 0x30: e.stub_fn('l.at', at)})
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    ctl = e.alloc(0x30, 8)
    e.w32(ctl + 0x18, lst)
    t = e.alloc(0x60, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x60)))
    e.w32(t + 0x44, ctl)
    e.w32(t + 0x48, r.choice([0, 1, 4, 7, 0xfffffff0]) if n else 0)
    e.w32(t + 0x50, tid)
    return [t, r.choice([0, 1, 2, 5, 10, 0xfffffff1])]


S(0x4b84b0, 'GUESS /GS advance a cursor and hand two transforms to a target', 'thiscall', None, ret='eax', gen=_g4b84b0, note='batch66039')
