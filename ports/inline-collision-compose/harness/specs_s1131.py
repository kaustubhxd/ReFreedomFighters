"""specs_s1131.py - collision thread batch 1131: LoadUniqueSubStripInfo (0x4edce0). Random object; the data pointer is a
heap block (its value is stored, not read)."""
from pilot import S, F


def _load(c):
    e, r = c.emu, c.rng
    o = e.alloc(0x200, 4)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x200)))
    data = e.alloc(0x40, 4)
    return [o, data, r.getrandbits(32)]


S(0x4edce0, 'ZCollisionBase::LoadUniqueSubStripInfo', 'thiscall', None, gen=_load, note='batch1131')
