"""specs_s6350.py - area 73 batch 63 (gap band, GUESS name). FUN_4edc10 (ret 4): when the argument is non-null, p = 0x41e290(0x18)
(operator new, cdecl, hooked by address: returns a fresh 0x40-byte buffer and logs the size), this+0x1a9 = p, then 0x4edeb0 on p
with the argument (thiscall, one argument, hooked and logged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu

    def h_new(em, r):
        em.calllog.append(('41e290', 0, None, (em.arg32(0),)))
        buf = em.alloc(0x40, 4)
        em.ret(eax=buf, argbytes=0)

    def h_deb(em, r):
        em.calllog.append(('4edeb0', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(argbytes=4)
    e.hook(0x41e290, h_new)
    e.hook(0x4edeb0, h_deb)
    o = _rnd(c, 0x200)
    a = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32)
    return [o, a]


S(0x4edc10, 'GUESS FUN_4edc10 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 73 batch 63; if arg: this+0x1a9 = new(0x18); 0x4edeb0(new, arg)')
