"""specs_s355.py - decomp area 64 residue-3 pass: 0x634873, a constant getter (no inputs)."""
from pilot import S


def _const(c):
    e = c.emu
    obj = e.alloc(0x10, 4)
    e.wbytes(obj, bytes(0x10))
    return [obj]


S(0x634873, 'constant (GUESS)', 'thiscall', None, ret='eax', gen=_const,
  note='batch355; returns 0x814244; ecx ignored')
