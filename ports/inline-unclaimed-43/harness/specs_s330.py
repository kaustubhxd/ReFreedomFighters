"""specs_s330.py - area 71 batch 330: 0x43f9e0, stdcall with one argument (obj), ret 4, returns bool in al. DBLK::Get (0x4e11e0)
is hooked: it writes a value (drawn in gen, so both builds see it) to its out pointer and returns. The result is compared as
al, so the zero and nonzero outcomes are both exercised."""
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x

VAL = [0]   # set in gen, read by the hook at call time


def _hook(c):
    def h(em, rr):
        em.calllog.append(('dblk_get', 0, em.reg('ecx'), (_nostack(em.arg32(0)), em.arg32(1))))
        em.w32(em.arg32(0), VAL[0])
        em.ret(eax=0, argbytes=8)
    c.emu.hook(0x4e11e0, h)


def _gen(c):
    VAL[0] = 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32) | 1
    o = E.zero_obj(c, 0x40)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x43f9e0, 'DBLK value is zero (unknown) stdcall', 'stdcall', None, ret='al', gen=_gen, setup=_hook,
  note='area 71 batch 330 (leaf, residue 10); DBLK::Get hooked and logged')
