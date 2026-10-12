"""specs_s1130.py - collision thread batch 1130: LockCollisionBox (0x4edd10). Random object; the caller's two args are
plain values (the port stores them, so no pointers are involved)."""
from pilot import S, F


def _lock(c):
    e, r = c.emu, c.rng
    o = e.alloc(0x200, 4)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x200)))
    return [o, r.getrandbits(32), r.getrandbits(32)]


S(0x4edd10, 'ZCollisionBase::LockCollisionBox', 'thiscall', None, ret='eax', gen=_lock, note='batch1130')
