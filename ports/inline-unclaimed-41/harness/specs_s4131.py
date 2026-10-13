"""specs_s4131.py - unclaimed-41 batch 31 (core-todo residue-19): 0x55f9f0 FUN_55f9f0 (GUESS name; thiscall, no arguments; returns eax).

The function is mov eax, 0x6a4b80; ret. There is nothing to vary except the object (self), which the body ignores; the spec gives it
random bytes. Faulting cases must be 0 (JSON)."""
from pilot import S


def _layout(c):
    a = c.emu.alloc(0x40, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    return [a]


S(0x55f9f0, 'FUN_55f9f0 (GUESS name)', 'thiscall', None, ret='eax', gen=_layout,
  note='unclaimed-41 batch 31; mov eax, 0x6a4b80; ret (a constant getter); the /GS cookie check does not apply')
