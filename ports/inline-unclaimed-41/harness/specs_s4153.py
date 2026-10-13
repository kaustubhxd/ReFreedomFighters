"""specs_s4153.py - unclaimed-41 batch 49 (residue 0): 0x468200 (getter of the dword at +0x1d2). self is 0x800 random bytes; thiscall, no stack arguments."""
from pilot import S


def _layout(c):
    a = c.emu.alloc(0x800, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    return [a]


S(0x468200, 'FUN_468200', 'thiscall', None, ret='eax', gen=_layout, note='unclaimed-41 batch 49; getter of the dword at +0x1d2')
