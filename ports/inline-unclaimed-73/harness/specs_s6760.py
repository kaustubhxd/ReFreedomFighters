"""specs_s6760.py - area 73 batch 67 (gap band, GUESS name). FUN_4ef050(a1, a2) (ret 8, returns 0): when the low word of a1 is
0x8000, al = vtable +0x2c8 on this with a2 (one argument), and the byte at a2+0x10 is set to al. Otherwise 0x45d380(a1, a2)
(stdcall, two arguments, hooked by address and logged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    o = _rnd(c, 0x100)
    rv = c.rng.getrandbits(8)
    e.w32(o, e.logging_vtable('f050', 0x300 // 4, impl={0x2c8: (lambda v: (lambda em, a: (v, None)))(rv)},
                              argwords={0x2c8: 1}))

    def h(em, r):
        em.calllog.append(('45d380', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)
    e.hook(0x45d380, h)
    a2 = _rnd(c, 0x40)
    if c.rng.random() < 0.5:
        a1 = (c.rng.getrandbits(16) << 16) | 0x8000
    else:
        a1 = c.rng.getrandbits(32)
    return [o, a1, a2]


S(0x4ef050, 'GUESS FUN_4ef050 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='area 73 batch 67; low word of a1 == 0x8000: [a2+0x10] = vt+0x2c8(a2); else 0x45d380(a1, a2) (stdcall); returns 0')
