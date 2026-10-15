"""specs_s66060.py - cascade s4 batch 66060: 0x4d1f50 (/GS-protected: log a summary line and notify the children)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4d1f50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True, ret=lambda em, k: em.reg('eax'))

    def alloc(em, rr):
        em.calllog.append(('alloc', em.arg32(0)))
        em.ret(eax=e.alloc(max(em.arg32(0), 8), 8), argbytes=0)

    def ms(em, rr):
        d, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memset', v, n))
        if n:
            em.wbytes(d, bytes([v & 0xff]) * n)
        em.ret(eax=d, argbytes=0)
    e.hook(0x41e290, alloc)
    e.hook(0x634d10, ms)
    hook_rec(c, 0x634273, 2, pop=0)
    e.wbytes(0x67a84c, bytes([r.choice([0x20, 0x21, 0x7f])]))
    e._image_dirty = True

    def pr(em, rr):                       # L->slot 0x2c cdecl (L, fmt, buf, &s, cnt, sum)
        s = em.arg32(3)
        em.calllog.append(('print', em.arg32(1), bytes(em.rbytes(em.arg32(2), 12)), bytes(em.rbytes(s, 5)), em.arg32(4), em.arg32(5)))
        em.ret(eax=0, argbytes=0)
    lo = obj(c, 0x30, {0x2c: e.stub_fn('print', pr)})
    lg = obj(c, 0x30, {0x20: pystub(c, 2, ret=lo)})
    e.w32(0x700390, lg)
    n = r.choice([0, 1, 3])
    vals = [r.choice([0, 5, 0xfffffff0, 100]) for _ in range(4)]
    kids = []
    for i in range(r.choice([0, 1, 2, 3])):
        kids.append(obj(c, 0x40, {0x60: pystub(c, 1, this=True)}))
    for i, k in enumerate(kids):
        e.w32(k + 0x30, kids[i + 1] if i + 1 < len(kids) else 0)
    t = obj(c, 0x40, {0x10: pystub(c, 1, this=True), 0x2c: pystub(c, 0, this=True, ret=n),
                      0x40: pystub(c, 1, this=True, ret=lambda em, k: vals[k % 4])})
    e.w32(t + 0x20, r.getrandbits(32))
    e.w32(t + 0x24, kids[0] if kids else 0)
    return [t, r.choice([0, 0, 1, 5, 12, 40])]


S(0x4d1f50, 'GUESS /GS log a summary line and notify children', 'thiscall', None, ret=None, gen=_g4d1f50, note='batch66060')
