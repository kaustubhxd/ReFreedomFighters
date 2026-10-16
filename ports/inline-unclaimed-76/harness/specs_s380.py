"""specs_s380.py - area 76, residue 17, batch 380: 0x634817 (cdecl, no arguments, plain ret; GUESS).
The import InitializeSListHead (IAT slot 0x676054, stdcall, one argument) is a fixture stub: it zeroes the eight-byte list header at its
argument, as the real routine does, and logs the argument. The header is in .data at 0x725800, so the data compare checks it."""
import struct
from pilot import S


def _gen(c):
    e = c.emu

    def init_slist(em, r):
        p = em.arg32(0)
        em.wbytes(p, bytes(8))
        em.calllog.append(('InitializeSListHead', 0, None, (p,)))
        em.ret(eax=0, argbytes=4)

    e.stub_import('InitializeSListHead', init_slist)
    return []


S(0x634817, 'init634817 (GUESS)', 'cdecl', None, ret=None, gen=_gen,
  note='area 76 batch 380; residue 17; InitializeSListHead import stubbed')
