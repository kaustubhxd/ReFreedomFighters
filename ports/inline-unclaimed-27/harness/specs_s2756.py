"""specs_s2756.py - unclaimed-27 batch 56: Byte setter function 0x4bcc20 (GUESS name).
Takes this and byte argument, sets byte at +0xd0."""
from pilot import S


def _gen(c):
    # Allocate a random object (needs to be large enough for member at +0xd0)
    obj = c.emu.alloc(0x200, 16)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    return [obj, c.rng.getrandbits(8)]


S(0x4bcc20, 'FUN_SetByteD0 (GUESS) thiscall', 'thiscall', None, gen=_gen,
  note='unclaimed-27 batch 56; byte setter at +0xd0')
