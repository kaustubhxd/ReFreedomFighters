"""specs_s6050.py - area 73 batch 60 (gap band, GUESS name). FUN_4f50c0 (plain ret): calls 0x4ef130 on this (hooked, no
args), vtable +0x244 and +0x27c on this (logging, no args), then thiscall 0x4dc630 on the object at this+8 with
(0x800000, 0) (hooked and logged, two arguments)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu

    def h_ef130(em, r):
        em.calllog.append(('4ef130', 0, em.reg('ecx'), ()))
        em.ret(argbytes=0)

    def h_dc630(em, r):
        em.calllog.append(('4dc630', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)
    e.hook(0x4ef130, h_ef130)
    e.hook(0x4dc630, h_dc630)
    o = _rnd(c, 0x100)
    sub = _rnd(c, 0x100)
    e.w32(o + 8, sub)
    e.w32(o, e.logging_vtable('f50c0', 0x280 // 4,
                              impl={0x244: lambda em, a: (0, None), 0x27c: lambda em, a: (0, None)},
                              argwords={0x244: 0, 0x27c: 0}))
    return [o]


S(0x4f50c0, 'GUESS FUN_4f50c0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 73 batch 60; 0x4ef130; vt+0x244(); vt+0x27c(); 0x4dc630 on this+8 with (0x800000, 0)')
