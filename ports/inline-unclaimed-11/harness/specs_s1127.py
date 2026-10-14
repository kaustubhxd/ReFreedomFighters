"""specs_s1127.py - unclaimed-11 batch 28 (gap band): 0x5ab190 (GUESS, no name), thiscall with eighteen stack dword args (ret 0x48).
Args 1-4 are stored as 16 bytes at this+0x37d, args 5-8 at +0x38d, args 9-12 at +0x39d, args 13-16 at +0x3ad, arg 17 as a
dword at +0x3bd, and the low byte of arg 18 at +0x3c1. The object is 0x500 random bytes; args are random 32-bit values."""
from pilot import S


def _gen(c):
    o = c.emu.alloc(0x500, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x500)))
    return [o] + [c.rng.getrandbits(32) for _ in range(18)]


S(0x5ab190, 'GUESS (no name) copy eighteen stack args thiscall ret 0x48', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 28 (gap band)')
