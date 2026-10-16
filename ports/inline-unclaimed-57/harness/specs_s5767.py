"""specs_s5767.py - unclaimed-57, batch 67: 0x5d58e0 (GUESS name unnamed_5d58e0). Thiscall, two stack arguments (a1, a2; ret 8),
no return value. The engine (global 0x70039c) has a sub-object at +0x9b whose fake slot +0x114 (four arguments, logged) returns a word
r with random upper bits. a1 is built so its low word equals r's low word in about half the cases (the branch runs) and differs
otherwise. The object's fake slot +0x110 (two arguments, logged) and the pointer at this+0x25 (a fake object whose slot +0x2c is
logged; null in about three cases in ten) are hooked too. The base 0x45d380 is a logging stub (owned by another area, writes nothing)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d58(c):
    e = c.emu
    r = c.rng.getrandbits(32)
    a1 = c.rng.getrandbits(32)
    if c.rng.random() < 0.5:
        a1 = (a1 & 0xffff0000) | (r & 0xffff)
    a2 = c.rng.getrandbits(32)
    p_null = c.rng.random() < 0.3

    def h114(em, rr):
        em.calllog.append(('114', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3))))
        em.ret(eax=r, argbytes=16)

    def h110(em, rr):
        em.calllog.append(('110', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def h2c(em, rr):
        em.calllog.append(('2c', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x45d380, lambda em, rr: (em.calllog.append(('45d380', 0, None, (em.arg32(0), em.arg32(1)))),
                                     em.ret(eax=0, argbytes=8)))
    vt_sub = e.fake_vtable('d58e0_sub', 160, {0x114: h114})
    vt_self = e.fake_vtable('d58e0_self', 160, {0x110: h110})
    vt_p = e.fake_vtable('d58e0_p', 160, {0x2c: h2c})
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    p = _rnd(c, 0x40)
    e.w32(p, vt_p)
    obj = _rnd(c, 0x80)
    e.w32(obj, vt_self)
    e.w32(obj + 0x25, 0 if p_null else p)
    return [obj, a1, a2]


S(0x5d58e0, 'unnamed_5d58e0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d58,
  note='unclaimed-57 batch 67; engine sub slot +0x114 fake (word result); self slots +0x110 and p +0x2c fake; base 0x45d380 hooked (logs)')
