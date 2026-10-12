"""specs_s7272.py - area 73 batch 72 (gap band, GUESS name). FUN_4ee570 (ret 4, returns this): 0x43ea20 on this (thiscall, no
arguments, hooked by address; its chain ends in a plain ret, so no arguments are popped); then, when the flag's low bit is set:
with bit 2 set, 0x4690b0(this, 0x60), otherwise 0x45c510(this) (both cdecl, hooked and logged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu

    def h_43ea20(em, r):
        em.calllog.append(('43ea20', 0, em.reg('ecx'), ()))
        em.ret(argbytes=0)

    def h_45c510(em, r):
        em.calllog.append(('45c510', 0, None, (em.arg32(0),)))
        em.ret(argbytes=0)

    def h_4690(em, r):
        em.calllog.append(('4690b0', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)
    e.hook(0x43ea20, h_43ea20)
    e.hook(0x45c510, h_45c510)
    e.hook(0x4690b0, h_4690)
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


S(0x4ee570, 'GUESS FUN_4ee570 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='area 73 batch 72; 0x43ea20(this); if flag&1: flag&4 ? 0x4690b0(this,0x60) : 0x45c510(this); returns this')
