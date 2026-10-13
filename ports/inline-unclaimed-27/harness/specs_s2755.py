"""specs_s2755.py - unclaimed-27 batch 55: Byte setter function 0x47bfe0 (GUESS name).
Takes this and byte argument, sets byte at +0x6be."""
from pilot import S


def _gen(c):
    # Allocate a random object (needs to be large enough for member at +0x6be)
    obj = c.emu.alloc(0x700, 16)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x700)))
    return [obj, c.rng.getrandbits(8)]


S(0x47bfe0, 'FUN_SetByte6be (GUESS) thiscall', 'thiscall', None, gen=_gen,
  note='unclaimed-27 batch 55; byte setter at +0x6be')
