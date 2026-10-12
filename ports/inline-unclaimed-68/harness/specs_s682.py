"""specs_s682.py - unclaimed-68 batch 2 (claim 2): 0x5ab0b0 (GUESS name). The object is random bytes; the counter at +0x8af
is an unaligned dword, and the flag at +0x300 is set to 0x10000000 in about a third of the cases so both branches run."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    o = _rnd(c, 0x1000)
    if c.rng.random() < 0.33:
        c.emu.w32(o + 0x300, 0x10000000)
    return [o]


S(0x5ab0b0, 'GUESS FUN_5ab0b0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-68 batch 2; GUESS name; counter at +0x8af when +0x300 != 0x10000000')
