"""specs_s230.py - unclaimed area 22, batch230 (src/batch230.cpp): 0x51cad0, 0x582790, 0x5c5590 (residue 01).

The forwarder targets 0x584b40 and 0x5c56f0 are CopyEventDataBlock bodies (x87 readers) owned by other ports; here they
are stubbed with a recorder that stores ecx and the argument and returns 0 (ret 4). The vtable callee of 0x51cad0 is a
logged sparse slot with no arguments.
"""
from pilot import S
from helpers22 import _rnd, _multi_vt, _rec_ecx, _ret_const


def _g_51cad0(c):
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_, _multi_vt(c, {0x360: (_ret_const(c), 0)}))
    return [self_]


def _g_fwd(addr):
    def gen(c):
        _rec_ecx(c, addr, 1)
        return [_rnd(c, 0x40), _rnd(c, 0x40)]
    return gen


S(0x51cad0, 'vtTail360 (GUESS)', 'thiscall', None, ret='eax', gen=_g_51cad0,
  note='batch230; vtable 0x360 tail call, no arguments')
S(0x582790, 'forwardCopy582790 (GUESS)', 'thiscall', None, ret='eax', gen=_g_fwd(0x584b40),
  note='batch230; jmp to 0x584b40 (stubbed, ecx and argument recorded)')
S(0x5c5590, 'forwardCopy5c5590 (GUESS)', 'thiscall', None, ret='eax', gen=_g_fwd(0x5c56f0),
  note='batch230; jmp to 0x5c56f0 (stubbed, ecx and argument recorded)')
