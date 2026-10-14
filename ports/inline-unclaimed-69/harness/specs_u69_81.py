"""specs_u69_81.py - area 69, residue-8 forwarder 0x66ee80 (mov ecx,0x6ff938; jmp 0x4d23c0). The target 0x4d23c0 is real (vtable store, ret)."""
from pilot import S
from ckit import rnd


def _obj(c):
    return [rnd(c, 0x10)]   # ECX is overwritten by the forwarder with the fixed global 0x6ff938; the argument is only the ABI's first slot


S(0x66ee80, 'fwd66ee80 (naked forwarder to 0x4d23c0, global object)', 'thiscall', None, ret=None, gen=_obj, note='u69 group 81; target is the real 0x4d23c0')
