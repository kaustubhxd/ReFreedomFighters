"""specs_u69_99.py - area 69, residue-8 (batch 99).
0x634a0b: cdecl, no args; calls ext_676160() and returns result (import wrapper, GUESS).
"""
from pilot import S
from ckit import rnd

def _importWrapper(c):
    e = c.emu
    r = c.rng
    result_value = r.getrandbits(32)
    
    def hook(e, res):
        e.calllog.append(('h676160',))
        e.ret(eax=result_value, argbytes=0)
    e.hook(0x676160, hook)
    return []

S(0x634a0b, 'importWrapper634a0b (cdecl, import wrapper)', 'cdecl', None, ret='eax', gen=_importWrapper,
  note='u69 residue-8 batch 99; 0x676160 is an import thunk (GUESS wrapper)')
