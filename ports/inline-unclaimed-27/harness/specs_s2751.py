"""specs_s2751.py - unclaimed-27 batch 51: Simple add function 0x5f2c20 (GUESS name).
Takes this and argument, adds argument to member at +8, returns 4."""
from pilot import S


def _gen(c):
    # Allocate a random object (needs to be large enough for member at +8)
    obj = c.emu.alloc(0x100, 16)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [obj, c.rng.getrandbits(32)]


S(0x5f2c20, 'FUN_AddToMember8 (GUESS) thiscall', 'thiscall', None, gen=_gen,
  note='unclaimed-27 batch 51; simple add at +8')
