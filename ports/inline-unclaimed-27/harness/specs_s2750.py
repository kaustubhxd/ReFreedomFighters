"""specs_s2750.py - unclaimed-27 batch 50: Simple setter function 0x4d7520 (GUESS name).
Takes this and argument, sets member at +0x1d, returns 4."""
from pilot import S


def _gen(c):
    # Allocate a random object (needs to be large enough for member at +0x1d)
    obj = c.emu.alloc(0x100, 16)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [obj, c.rng.getrandbits(32)]


S(0x4d7520, 'FUN_SetMember1d (GUESS) thiscall', 'thiscall', None, gen=_gen,
  note='unclaimed-27 batch 50; simple setter at +0x1d')
