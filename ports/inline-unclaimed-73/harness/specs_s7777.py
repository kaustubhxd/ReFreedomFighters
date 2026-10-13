"""specs_s7777.py - area 73 batch 77 (GUESS name). FUN_500500 (stdcall, ret 0xc, three arguments p, a2, a3): esi = vtable +0x18 on p
with a2; when esi is non-null: r = vtable +0x4c on esi; rr = 0x5003d0(this = r, args (0, a3)) (hooked, two arguments);
0x5002f0(this = rr) (hooked, no arguments). Returns esi in both paths."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu

    def h_5003d0(em, r):
        em.calllog.append(('5003d0', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=c.rng.getrandbits(32), argbytes=8)

    def h_5002f0(em, r):
        em.calllog.append(('5002f0', 0, em.reg('ecx'), ()))
        em.ret(argbytes=0)
    e.hook(0x5003d0, h_5003d0)
    e.hook(0x5002f0, h_5002f0)
    objC = _rnd(c, 0x40)
    e.w32(objC, e.logging_vtable('c500500', 0x80 // 4, impl={}, argwords={}))
    objB = _rnd(c, 0x40)
    rC = objC if c.rng.random() < 0.7 else 0
    e.w32(objB, e.logging_vtable('b500500', 0x80 // 4, impl={0x4c: (lambda v: (lambda em, a: (v, None)))(rC)},
                                 argwords={0x4c: 0}))
    p = _rnd(c, 0x40)
    rB = objB if c.rng.random() < 0.7 else 0
    e.w32(p, e.logging_vtable('p500500', 0x80 // 4, impl={0x18: (lambda v: (lambda em, a: (v, None)))(rB)},
                              argwords={0x18: 1}))
    return [p, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x500500, 'GUESS FUN_500500 (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen,
  note='area 73 batch 77; esi = vt+0x18(p, a2); if esi: rr = 0x5003d0(vt+0x4c(esi), 0, a3); 0x5002f0(rr); returns esi')
