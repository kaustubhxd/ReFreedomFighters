"""specs_s374.py - gap band batch 374: 0x406cc0, cdecl with one pointer argument (a block of 0x80 bytes; floats at +0x20..+0x7c used).
The block holds random floats (the output is the same block). The callee 0x407140 (exe) runs as original code on two sub-blocks."""
from pilot import S
import engine_stubs as E


def _gen(c):
    blk = c.fbuf(0x20, pad=0)
    c.emu.mu.ctl_flush_tb()
    return [blk]


S(0x406cc0, 'complex butterflies block (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='gap band batch 374; translated from the disassembly; callee 0x407140 is original exe code')
