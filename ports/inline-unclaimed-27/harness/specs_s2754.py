"""specs_s2754.py - unclaimed-27 batch 54: Dual setter function 0x4643e0 (GUESS name).
Takes this and 2 arguments, sets members at +0x5c and +0x64."""
from pilot import S


def _gen(c):
    # Allocate a random object (needs to be large enough for members at +0x64)
    obj = c.emu.alloc(0x100, 16)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [obj, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4643e0, 'FUN_DualSetter (GUESS) thiscall', 'thiscall', None, gen=_gen,
  note='unclaimed-27 batch 54; dual setter at +0x5c and +0x64')
