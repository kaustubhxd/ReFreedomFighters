"""specs_s2747.py - unclaimed-27 batch 49: Simple setter function 0x491b60 (GUESS name).
Takes this, sets member at +0xbc5 to 0, returns 8."""
from pilot import S


def _gen(c):
    # Allocate a random object (needs to be large enough for member at +0xbc5)
    obj = c.emu.alloc(0xc00, 16)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0xc00)))
    # Thiscall with 2 arguments
    return [obj, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x491b60, 'SimpleSetter::SimpleSetter (GUESS) thiscall', 'thiscall', None, gen=_gen,
  note='unclaimed-27 batch 49; simple setter at +0xbc5')
