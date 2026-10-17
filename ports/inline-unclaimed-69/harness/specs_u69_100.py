"""specs_u69_100.py - area 69, residue-8 (batch 100).
0x66d300: thiscall, no args; tail-jump forwarder to 0x5fad10 (GUESS stub).
"""
from pilot import S
from ckit import rnd

def _forwarder(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x50)
    
    def hook(e, res):
        e.calllog.append(('h5fad10', int(e.reg('ecx') == self_)))
        # Return normally (no stack args, thiscall ret)
        e.ret(eax=0, argbytes=0)
    e.hook(0x5fad10, hook)
    return [self_]

S(0x66d300, 'forwarder66d300 (thiscall, tail-jump to 0x5fad10)', 'thiscall', None, ret=None, gen=_forwarder,
  note='u69 residue-8 batch 100; 0x5fad10 is a GUESS stub (tail-jump target, ret check needed)')
