"""specs_s5774.py - unclaimed-57, batch 74: 0x5c2ec0 (GUESS name unnamed_5c2ec0). Thiscall, no stack args, plain ret. The engine (global
0x70039c) has a sub-object at +0x9b whose fake slot +0x134 returns object x on its first call and x2 on its second. x has a fake slot
+0x88 (two args: a constant and an out pointer); it writes a per-case dword through the out pointer, zero in about three cases in ten
(the second branch is then skipped). x2 has a fake slot +0x6c (three args): its first argument is a pointer into this (logged as an
offset), the other two are logged as values."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _c2ec0(c):
    e = c.emu
    self_obj = _rnd(c, 0x200)
    calls = [0]
    x_obj = _rnd(c, 0x40)
    x2_obj = _rnd(c, 0x40)
    zero = c.rng.random() < 0.3
    v88 = 0 if zero else (c.rng.getrandbits(32) | 1)

    def h134(em, r):
        calls[0] += 1
        em.calllog.append(('134', 0, None, ()))
        em.ret(eax=x_obj if calls[0] == 1 else x2_obj, argbytes=0)

    def h88(em, r):
        em.calllog.append(('88', 0, None, (em.arg32(0),)))
        if not zero:  # in the zero case the slot leaves the out dword alone, so the caller's initial value is what is read
            em.w32(em.arg32(1), v88)
        em.ret(eax=0, argbytes=8)

    def h6c(em, r):
        p = em.arg32(0)
        rel = p - self_obj if self_obj <= p < self_obj + 0x200 else 'other'
        em.calllog.append(('6c', 0, None, (rel, em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)

    vt_sub = e.fake_vtable('c2ec0_sub', 160, {0x134: h134})
    vt_x = e.fake_vtable('c2ec0_x', 160, {0x88: h88})
    vt_x2 = e.fake_vtable('c2ec0_x2', 160, {0x6c: h6c})
    e.w32(x_obj, vt_x)
    e.w32(x2_obj, vt_x2)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    return [self_obj]


S(0x5c2ec0, 'unnamed_5c2ec0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_c2ec0,
  note='unclaimed-57 batch 74; engine sub slot +0x134 fake (x then x2); x slot +0x88 writes a dword via its out pointer; x2 slot +0x6c logged')
