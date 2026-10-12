"""specs_s6130.py - unclaimed-68 batch 14 (claim 13): GUESS FUN_4cc130 (0x4cc130), string equality. The two strings come from a
small alphabet ('a', 'b') so equal and unequal pairs are both common; lengths 0..7; the argument is a pointer to a char* cell."""
from pilot import S


def _str(c, s):
    a = c.emu.alloc(len(s) + 1, 1)
    c.emu.wbytes(a, s + b'\x00')
    return a


def _cmp(c):
    n1 = c.rng.randrange(0, 8)
    s1 = bytes(c.rng.choice(b'ab') for _ in range(n1))
    if c.rng.random() < 0.5:
        s2 = s1
    else:
        n2 = c.rng.randrange(0, 8)
        s2 = bytes(c.rng.choice(b'ab') for _ in range(n2))
    obj = c.emu.alloc(8, 4)
    c.emu.w32(obj, _str(c, s1))
    cell = c.emu.alloc(8, 4)
    c.emu.w32(cell, _str(c, s2))
    return [obj, cell]


S(0x4cc130, 'GUESS FUN_4cc130 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_cmp,
  note='unclaimed-68 batch 14; GUESS name; string equality, two bytes per step')
