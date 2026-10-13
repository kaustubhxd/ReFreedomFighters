"""specs_s4155.py - unclaimed-41 batch 49 (residue 0): 0x5ebf00 (sets the byte at +0xa6). self is 0x800 random bytes; thiscall, no stack arguments."""
from pilot import S


def _layout(c):
    a = c.emu.alloc(0x800, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    return [a]


S(0x5ebf00, 'FUN_5ebf00', 'thiscall', None, ret=None, gen=_layout, note='unclaimed-41 batch 49; sets the byte at +0xa6')
