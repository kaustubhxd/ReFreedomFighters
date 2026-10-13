"""specs_s410.py - residue 2 row 0x579560 (thiscall, no arguments). Three exe callees are hooked by address and logged (GUESS:
bodies not ported): 0x562440 (no arguments), 0x563510 and 0x563610 (one argument each; the constants 0x6a6f98 and 0x6a9b08 are
checked in the log). The object is random bytes."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E


def _setup(c):
    c.emu.hook(0x562440, lambda em, r: (em.calllog.append(('a562440', 0, em.reg('ecx') & 0xffffffff, ())),
                                        em.ret(eax=0, argbytes=0)))
    c.emu.hook(0x563510, lambda em, r: (em.calllog.append(('b563510', 0, em.reg('ecx') & 0xffffffff, (em.arg32(0),))),
                                        em.ret(eax=0, argbytes=4)))
    c.emu.hook(0x563610, lambda em, r: (em.calllog.append(('c563610', 0, em.reg('ecx') & 0xffffffff, (em.arg32(0),))),
                                        em.ret(eax=0, argbytes=4)))


def _gen(c):
    o = E.zero_obj(c, 0x100)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x579560, 'three initialisation calls (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='residue 2 batch 410; callees 0x562440, 0x563510, 0x563610 hooked (GUESS)')
