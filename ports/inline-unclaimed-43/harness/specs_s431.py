"""specs_s431.py - residue 2 row 0x4f9d60 (stdcall, one stack argument a, ret 4; returns bool).
Call 0x4f9c90 (GUESS, hooked), then 0x4e12e0, 0x4e11e0, 0x4e12e0, 0x4e1b30 in sequence with various arguments.
Compare a with 0, set [this+0x8f] = (a == 0)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {}


def _setup(c):
    def h4f9c(em, rr):
        em.calllog.append(('ext_4f9c90', 0, em.reg('ecx') & 0xffffffff, ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x4f9c90, h4f9c)

    def h4e12(em, rr):
        em.calllog.append(('ext_4e12e0', 0, 0, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=0xc)

    def h4e11(em, rr):
        em.calllog.append(('ext_4e11e0', 0, 0, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=0xc)

    def h4e1b(em, rr):
        em.calllog.append(('ext_4e1b30', 0, em.reg('ecx') & 0xffffffff, ()))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x4e12e0, h4e12)
    c.emu.hook(0x4e11e0, h4e11)
    c.emu.hook(0x4e1b30, h4e1b)


def _gen(c):
    r = c.rng
    a = r.getrandbits(32)

    o = E.zero_obj(c, 0x2000)
    for i in range(0x2000 // 4):
        c.emu.w32(o + 4 * i, r.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [o, a]


S(0x4f9d60, 'multi-call sequence (residue 2) stdcall', 'stdcall', None, ret=4, gen=_gen, setup=_setup,
  note='residue 2 batch 431; callees 0x4f9c90, 0x4e12e0, 0x4e11e0, 0x4e1b30 hooked (GUESS); result stored at offset 0x8f')
