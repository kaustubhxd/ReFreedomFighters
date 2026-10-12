"""specs_s306.py - unclaimed-03 batch 6 (docs/20-unclaimed-03.md): ZCollisionBase::LoadUniqueSubStripInfo (0x4edce0),
thiscall with two stack arguments and no return value (ret 8). The object is 0x800 random bytes, so each store lands
inside it and any difference shows in the heap compare."""
from pilot import S


def _gen(c):
    a = c.emu.alloc(0x800, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    return [a, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4edce0, 'ZCollisionBase::LoadUniqueSubStripInfo (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-03 batch 6; a2>>3 to +0x194, a1 to +0x190, 1 to +0x19c')
