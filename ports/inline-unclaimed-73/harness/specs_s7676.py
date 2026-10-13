"""specs_s7676.py - area 73 batch 76 (unmentioned band rows, GUESS names). Both: ret 4, return this, zero-argument base call (no
pushes at the call site), then flag bit 0: bit 2 -> 0x4690b0(this, size), else 0x45c510(this) (both cdecl, hooked by address).
FUN_4f4a70: base 0x43ea20, size 0x97. FUN_4f6280: base 0x4ee4e0, size 0xa3."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu

    def h0(name):
        def h(em, r):
            em.calllog.append((name, 0, em.reg('ecx'), ()))
            em.ret(argbytes=0)
        return h

    def h_c(em, r):
        em.calllog.append(('45c510', 0, None, (em.arg32(0),)))
        em.ret(argbytes=0)

    def h_d(em, r):
        em.calllog.append(('4690b0', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)
    e.hook(0x43ea20, h0('43ea20'))
    e.hook(0x4ee4e0, h0('4ee4e0'))
    e.hook(0x45c510, h_c)
    e.hook(0x4690b0, h_d)
    return [_rnd(c, 0x100), c.rng.choice([0, 1, 5, c.rng.getrandbits(8)])]


S(0x4f4a70, 'GUESS FUN_4f4a70 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='area 73 batch 76; 0x43ea20(this); flag&1: flag&4 ? 0x4690b0(this,0x97) : 0x45c510(this); returns this')
S(0x4f6280, 'GUESS FUN_4f6280 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='area 73 batch 76; 0x4ee4e0(this); flag&1: flag&4 ? 0x4690b0(this,0xa3) : 0x45c510(this); returns this')
