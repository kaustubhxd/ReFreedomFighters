"""specs_s372.py - gap band batch 372: 0x40f890, cdecl(n, base, x). 0x40f8b0 is hooked and logged (three arguments, cdecl)."""
from pilot import S
import engine_stubs as E


def _hook(c):
    c.emu.hook(0x40f8b0, lambda em, r: (em.calllog.append(('f8b0', 0, 0, (em.arg32(0), em.arg32(1), em.arg32(2)))),
                                        em.ret(eax=0, argbytes=0)))


def _gen(c):
    r = c.rng
    n = r.choice([1, 2, 3, 5, 0xfffffffe, r.getrandbits(32)])
    base = E.zero_obj(c, 0x80)
    x = r.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [n, base, x]


S(0x40f890, 'recurse half (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_hook,
  note='gap band batch 372; 0x40f8b0 hooked')
