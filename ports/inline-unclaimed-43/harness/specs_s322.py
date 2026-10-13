"""specs_s322.py - area 71 batch 322: 0x4cf0e0, stdcall with one argument (a pointer), ret 4. Writes dword [p+4] = 1 and
[p] = 0. The block has random bytes around the two dwords."""
from pilot import S
import engine_stubs as E


def _gen(c):
    p = c.bytes_(32)
    c.emu.mu.ctl_flush_tb()
    return [p]


S(0x4cf0e0, 'set [p]=0, [p+4]=1 (unknown) stdcall', 'stdcall', None, ret=None, gen=_gen,
  note='area 71 batch 322 (leaf, residue 10)')
