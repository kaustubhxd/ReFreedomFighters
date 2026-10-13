"""specs_s415.py - residue 2 rows 0x54ada0 (thiscall, one argument flag, ret 4, returns this) and 0x5f0020 (thiscall, no
arguments, returns this). Exe callees 0x549370 (thiscall, no args), 0x5ec720 (thiscall, one arg) and the delete helper 0x634273
(cdecl, two args) are hooked by address and logged (GUESS: bodies not ported, as in batch 381)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E


def _setup_a(c):
    c.emu.hook(0x549370, lambda em, r: (em.calllog.append(('a549370', 0, em.reg('ecx') & 0xffffffff, ())),
                                        em.ret(eax=0, argbytes=0)))
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('delete', 0, 0, (em.arg32(0), em.arg32(1)))),
                                        em.ret(eax=0, argbytes=0)))


def _gen_a(c):
    r = c.rng
    o = E.zero_obj(c, 0x40)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x40)))
    c.emu.mu.ctl_flush_tb()
    return [o, r.getrandbits(32)]


def _setup_b(c):
    c.emu.hook(0x5ec720, lambda em, r: (em.calllog.append(('b5ec720', 0, em.reg('ecx') & 0xffffffff, (em.arg32(0),))),
                                        em.ret(eax=0, argbytes=4)))


def _gen_b(c):
    o = E.zero_obj(c, 0x100)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x54ada0, 'vtable 0x6a36dc, init call, optional free (residue 2) thiscall', 'thiscall', None, ret='eax', gen=_gen_a,
  setup=_setup_a, note='residue 2 batch 415; callees 0x549370 and 0x634273 hooked (GUESS)')
S(0x5f0020, 'vtable 0x6b8214 and two fields (residue 2) thiscall', 'thiscall', None, ret='eax', gen=_gen_b, setup=_setup_b,
  note='residue 2 batch 415; callee 0x5ec720 hooked (GUESS)')
