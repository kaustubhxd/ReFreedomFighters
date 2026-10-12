"""specs_s1129.py - collision thread batch 1129: UnlockCollisionBox (0x4ede70). The exe callee 0x4eb340 runs as exe code
(one store). Random object bytes and a random box pointer."""
from pilot import S, F


def _unlock(c):
    e, r = c.emu, c.rng
    o = e.alloc(0x200, 4)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x200)))
    box = e.alloc(0x40, 4)
    return [o, box]


S(0x4ede70, 'ZCollisionBase::UnlockCollisionBox', 'thiscall', None, gen=_unlock, note='batch1129')
