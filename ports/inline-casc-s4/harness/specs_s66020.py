"""specs_s66020.py - cascade s4 batch 66020: 0x56d840 (/GS-protected: format two looked-up strings and report them)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g56d840(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)

    def mkstr(n):
        a = e.alloc(0x440, 4)
        e.wbytes(a, bytes(r.randrange(1, 255) for _ in range(n)) + b'\0')
        return a
    lens = [0, 1, 5, 0x1fd, 0x1fe, 0x1ff, 0x200, 0x3fd, 0x3fe]
    s1 = mkstr(r.choice(lens))
    s2 = mkstr(r.choice(lens))
    pool = [s1, s2]

    def look(em, rr):                     # m->slot 0 (name, key) thiscall ret 8
        n, k = em.arg32(0), em.arg32(1)
        em.calllog.append(('look', n, k))
        em.ret(eax=pool[0] if n == 0x6a67e8 else pool[1], argbytes=8)
    m = obj(c, 0x20, {0: e.stub_fn('look', look)})

    def fmt(em, rr):                      # L->slot 0x198 (L, buf, fmt, a, b) cdecl
        em.calllog.append(('fmt', em.arg32(2), em.arg32(3), em.arg32(4)))
        em.wbytes(em.arg32(1), b'fmt-out\0')
        em.ret(eax=0, argbytes=0)
    L = obj(c, 0x40, {0x198: e.stub_fn('fmt', fmt)})
    so = sysobj(c, slots={0x190: pystub(c, 0, this=True, ret=L)})
    tab = int.from_bytes(bytes(e.rbytes(so + 0x9b, 4)), 'little')
    tab2 = rnd(c, 0x10)
    e.w32(tab + 0xae4, m)

    def sink(em, rr):                     # 0x5636c0 (x, buf) thiscall-ish ret 8
        em.calllog.append(('sink', em.reg('ecx'), em.arg32(0), bytes(em.rbytes(em.arg32(1), 8))))
        em.ret(eax=0, argbytes=8)
    e.hook(0x5636c0, sink)
    t = e.alloc(0x200, 8)
    e.w32(t + 0x1be, r.choice([0, 1, 2, 3, 0xffffffff]))
    e.w32(t + 0x184, r.getrandbits(32))
    return [t]


S(0x56d840, 'GUESS /GS format two looked-up strings and report them', 'thiscall', None, ret=None, gen=_g56d840, note='batch66020')
