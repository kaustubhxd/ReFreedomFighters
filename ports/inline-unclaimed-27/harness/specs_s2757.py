"""specs_s2757.py - unclaimed-27 batch 57: Word setter function 0x47bd60 (GUESS name).
Takes this and byte argument, zero-extends to dword and sets at +0x496."""
from pilot import S


def _gen(c):
    # Allocate a random object (needs to be large enough for member at +0x496)
    obj = c.emu.alloc(0x500, 16)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x500)))
    return [obj, c.rng.getrandbits(8)]


S(0x47bd60, 'FUN_SetWord496 (GUESS) thiscall', 'thiscall', None, gen=_gen,
  note='unclaimed-27 batch 57; word setter with zero-extend at +0x496')
