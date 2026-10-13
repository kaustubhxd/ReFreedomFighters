"""specs_s4156.py - unclaimed-41 batch 49 (residue 0): 0x483f00 (bit 10 of the dword at +0x417). self is 0x800 random bytes; thiscall, no stack arguments."""
from pilot import S


def _layout(c):
    a = c.emu.alloc(0x800, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    return [a]


S(0x483f00, 'FUN_483f00', 'thiscall', None, ret='al', gen=_layout, note='unclaimed-41 batch 49; bit 10 of the dword at +0x417')
