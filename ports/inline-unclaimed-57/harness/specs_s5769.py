"""specs_s5769.py - unclaimed-57, batch 69: 0x5c2f30 (GUESS name unnamed_5c2f30). Thiscall, no stack args, plain ret. The engine
(global 0x70039c) has a sub-object at +0x9b whose fake slot +0x134 (no arguments) returns object x on its first call and object x2
on its second. Object x has a fake slot +0x14 (four arguments): the third argument is a pointer into this (logged as an offset from
this, or a tag when it points elsewhere). Object x2 has a fake slot +0x5c (three arguments, logged). No slot writes through a pointer."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _c2f30(c):
    e = c.emu
    self_obj = _rnd(c, 0x200)
    calls = [0]
    x_obj = _rnd(c, 0x40)
    x2_obj = _rnd(c, 0x40)

    def h134(em, r):
        # the first call swaps the engine global for a second engine, so the original's reload of the global matters
        calls[0] += 1
        em.calllog.append(('134', 0, None, ()))
        if calls[0] == 1:
            em.w32(0x70039c, eng2)
            em.ret(eax=x_obj, argbytes=0)
        else:
            em.ret(eax=x2_obj, argbytes=0)

    def h134b(em, r):
        em.calllog.append(('134b', 0, None, ()))
        em.ret(eax=x2_obj, argbytes=0)

    def h14(em, r):
        p = em.arg32(2)
        rel = p - self_obj if self_obj <= p < self_obj + 0x200 else 'other'
        em.calllog.append(('14', 0, None, (em.arg32(0), em.arg32(1), rel, em.arg32(3))))
        em.ret(eax=0, argbytes=16)

    def h5c(em, r):
        em.calllog.append(('5c', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)

    vt_sub = e.fake_vtable('c2f30_sub', 160, {0x134: h134})
    vt_x = e.fake_vtable('c2f30_x', 160, {0x14: h14})
    vt_x2 = e.fake_vtable('c2f30_x2', 160, {0x5c: h5c})
    e.w32(x_obj, vt_x)
    e.w32(x2_obj, vt_x2)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    vt_sub2 = e.fake_vtable('c2f30_sub2', 160, {0x134: h134b})
    sub2 = _rnd(c, 0x40)
    e.w32(sub2, vt_sub2)
    eng2 = _rnd(c, 0x100)
    e.w32(eng2 + 0x9b, sub2)
    return [self_obj]


S(0x5c2f30, 'unnamed_5c2f30 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_c2f30,
  note='unclaimed-57 batch 69; engine sub slot +0x134 fake (x then x2); x slot +0x14 and x2 slot +0x5c fake (logged)')
