"""specs_s421.py - residue 2 row 0x5efda0 (thiscall, two stack arguments a, b; ret 8). Callees 0x5edf70 (thiscall, two arguments) and
0x5eeab0 (thiscall, one float argument) are hooked by address and logged (GUESS: bodies not ported). The float at +0x84 is random
and finite; the logs carry its bits, so the value passed on is checked."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E


def _setup(c):
    c.emu.hook(0x5edf70, lambda em, r: (em.calllog.append(('a5edf70', 0, em.reg('ecx') & 0xffffffff, (em.arg32(0), em.arg32(1)))),
                                        em.ret(eax=0, argbytes=8)))
    c.emu.hook(0x5eeab0, lambda em, r: (em.calllog.append(('b5eeab0', 0, em.reg('ecx') & 0xffffffff, (em.arg32(0),))),
                                        em.ret(eax=0, argbytes=4)))


def _gen(c):
    r = c.rng
    o = E.zero_obj(c, 0x100)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x100)))
    c.emu.wbytes(o + 0x84, struct.pack('<f', r.uniform(-50.0, 50.0)))
    c.emu.mu.ctl_flush_tb()
    return [o, r.getrandbits(32), r.getrandbits(32)]


S(0x5efda0, 'two calls around a float and constant stores (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='residue 2 batch 421; callees 0x5edf70 and 0x5eeab0 hooked (GUESS)')
