"""specs_s419.py - residue 2 row 0x5571e0 (stdcall, one argument obj). Exe callees, all hooked by address and logged (GUESS):
0x5003d0 (thiscall, one argument; returns a pointer: the argument 1 returns block A, 0 returns block B), 0x589c20 (thiscall, three
arguments; ECX = the global object at 0x7003b8; returns a block), 0x597fc0 (thiscall, no arguments). Block A holds a random dword
(so the flag is 0 or 1), block B holds a random value. The row's object holds a non-null pointer at +4."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'A': 0, 'B': 0, 'R': 0}


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _setup(c):
    def h5003(em, r):
        a = em.arg32(0)
        em.calllog.append(('a5003d0', 0, em.reg('ecx') & 0xffffffff, (a,)))
        em.ret(eax=SHARED['A'] if a == 1 else SHARED['B'], argbytes=4)

    def h589c(em, r):
        em.calllog.append(('b589c20', 0, em.reg('ecx') & 0xffffffff, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=SHARED['R'], argbytes=12)

    def h597f(em, r):
        em.calllog.append(('c597fc0', 0, em.reg('ecx') & 0xffffffff, ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x5003d0, h5003)
    c.emu.hook(0x589c20, h589c)
    c.emu.hook(0x597fc0, h597f)


def _gen(c):
    r = c.rng
    blockA = E.zero_obj(c, 0x20)
    c.emu.w32(blockA, r.getrandbits(32))
    blockB = E.zero_obj(c, 0x20)
    c.emu.w32(blockB, r.getrandbits(32))
    SHARED['A'] = blockA
    SHARED['B'] = blockB
    SHARED['R'] = E.zero_obj(c, 0x20)
    obj = E.zero_obj(c, 0x20)
    c.emu.w32(obj + 4, E.zero_obj(c, 0x20))
    E.set_global(c, 0x7003b8, E.zero_obj(c, 0x20))
    c.emu.mu.ctl_flush_tb()
    return [obj]


S(0x5571e0, 'two lookups then call on the global object (residue 2) stdcall', 'stdcall', None, ret=None, gen=_gen, setup=_setup,
  note='residue 2 batch 419; callees 0x5003d0, 0x589c20, 0x597fc0 hooked (GUESS)')
