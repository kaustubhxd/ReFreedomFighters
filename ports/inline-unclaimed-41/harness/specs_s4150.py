"""specs_s4150.py - unclaimed-41 batch 48 (residue 0): 0x445e80 (thiscall, no arguments; returns al = this[0x170]). self is 0x200 random bytes."""
from pilot import S


def _layout(c):
    a = c.emu.alloc(0x200, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    return [a]


S(0x445e80, 'FUN_445e80 (getter)', 'thiscall', None, ret='al', gen=_layout, note='unclaimed-41 batch 48; getter of the byte at +0x170')
