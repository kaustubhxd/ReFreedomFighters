"""specs_s424.py - residue 2 row 0x54e720 (thiscall, four stack arguments a1..a4, ret 0x10; returns a3). The import SetEvent
(KERNEL32, IAT 0x67613c) is stubbed by name and logs its handle. a1 is a random block (its dwords at +0x43 and +0x4f are read);
the this block is random, so every stored field shows in the heap compare."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E


def _setup(c):
    def h(em, rr):
        em.calllog.append(('SetEvent', 0, 0, (em.arg32(0),)))
        em.ret(eax=1, argbytes=4)
    c.emu.stub_import('SetEvent', h)


def _gen(c):
    r = c.rng
    o = E.zero_obj(c, 0x300)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x300)))
    a1 = E.zero_obj(c, 0x80)
    c.emu.wbytes(a1, bytes(r.getrandbits(8) for _ in range(0x80)))
    c.emu.mu.ctl_flush_tb()
    return [o, a1, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x54e720, 'store four fields and SetEvent (residue 2) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='residue 2 batch 424; SetEvent stubbed by name')
