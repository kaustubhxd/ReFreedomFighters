"""specs_s66026.py - cascade s4 batch 66026: 0x456490 (/GS-protected: walk a table of chained records and notify a listener)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _g456490(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))

    def dw(em, p, n):
        return bytes(em.rbytes(p, 4 * n))

    def s80(em, rr):                      # this->slot 0x80 (&s1, &s2) ret 8
        s1, s2 = em.arg32(0), em.arg32(1)
        em.calllog.append(('s80',))
        for i in range(9):
            em.w32(s1 + 4 * i, 0xa0 + i)
        for i in range(3):
            em.w32(s2 + 4 * i, 0xb0 + i)
        em.ret(eax=0, argbytes=8)

    def notify(em, rr):                   # a->slot 0x28 (v, &p0x90c, &s1, &s2, 0, 0) ret 24
        em.calllog.append(('notify', em.arg32(0), em.arg32(1), dw(em, em.arg32(2), 9), dw(em, em.arg32(3), 3), em.arg32(4), em.arg32(5)))
        em.ret(eax=0, argbytes=24)
    a = obj(c, 0x20, {0x28: e.stub_fn('notify', notify)})
    nrec = 4
    zero = r.random() < 0.1
    recs = e.alloc(0x94c * nrec + 0x20, 8)
    for i in range(nrec):
        base = recs + 0x94c * i
        e.w32(base, r.choice([0, 0] + list(range(i + 2, nrec + 1))))
        e.w32(base + 0x90c, r.choice([0, 5, 7]))
    objs = {}
    ids = [0x200 + i for i in range(3)]
    for i in ids:
        o = e.alloc(0x70, 8)
        e.wbytes(o + 0x51, bytes(r.getrandbits(8) for _ in range(4)))
        objs[i] = o

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs.get(v, 0), 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    this = obj(c, 0x900 + 0x100 * 8, {0x80: e.stub_fn('s80', s80)})
    n = r.choice([0, 1, 2, 3, 5])
    full = r.random() < 0.1
    if full:
        for i in range(0x100):
            e.w32(this + 0x1d + 8 * i, ids[0])
            e.w32(this + 0x21 + 8 * i, 0)
        e.w32(this + 0x81d, recs)
        e.w32(this + 0x821, 1)
        e.w32(recs + 0x90c, 5)
    elif zero:
        e.w32(this + 0x1d, ids[0])
        e.w32(this + 0x21, 2)
        e.w32(this + 0x25, 0)
        e.w32(this + 0x81d, (-0x94c) & 0xffffffff)
    else:
        for i in range(n):
            e.w32(this + 0x1d + 8 * i, r.choice(ids))
            e.w32(this + 0x21 + 8 * i, r.choice([0, 1, 2, 3, 4]))
        e.w32(this + 0x1d + 8 * n, 0)
        e.w32(this + 0x81d, recs)
    return [this, a, r.getrandbits(32)]


S(0x456490, 'GUESS /GS notify a listener for chained table records', 'thiscall', None, ret='al', gen=_g456490, note='batch66026')
