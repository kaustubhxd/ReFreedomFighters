"""specs_s36078.py - cascade s4 batch 36078: 0x5fefb0 (/GS-protected dump of a record table through the global log object at 0x724270)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5fefb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)

    def fmt(em, rr):
        n = em.arg32(1)
        v = r.getrandbits(32)
        em.calllog.append(('fmt', em.arg32(0), em.arg32(2), em.arg32(3), em.arg32(4), em.arg32(5)))
        em.w32(n, v)
        em.ret(eax=v, argbytes=0)

    def out(em, rr):
        em.calllog.append(('out', em.arg32(0), int.from_bytes(bytes(em.rbytes(em.arg32(1), 4)), 'little')))
        em.ret(eax=0, argbytes=0)
    lg = obj(c, 0x40, {0x14: e.stub_fn('fmt', fmt), 0xc: e.stub_fn('out', out)})
    e.w32(0x724270, lg)
    n = r.choice([0, 0, 1, 2, 3, 5])
    tab = e.alloc(4 * max(n, 1) + 4, 4)
    e.wbytes(tab, bytes(r.getrandbits(8) for _ in range(4 * max(n, 1))))
    s = rnd(c, 0xd0)
    e.w32(s + 0xc0, r.getrandbits(32))
    e.w32(s + 0xc4, n)
    e.w32(s + 0xc8, tab)
    return [s]


S(0x5fefb0, 'GUESS /GS log dump of a record table', 'thiscall', None, ret=None, gen=_g5fefb0, note='batch36078')
