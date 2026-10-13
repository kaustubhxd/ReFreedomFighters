"""specs_s4151.py - unclaimed-41 batch 48 (residue 0): 0x65f400 (thiscall, three stack arguments, ret 0xc; returns 0). Random self and arguments."""
from pilot import S


def _layout(c):
    a = c.emu.alloc(0x40, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    return [a, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x65f400, 'FUN_65f400 (returns 0)', 'thiscall', None, ret='eax', gen=_layout, note='unclaimed-41 batch 48; three stack arguments, callee pops 12; returns 0')
