"""specs_s1127.py - collision thread batch 1127: IsCollisionBoxLocked (0x4edca0) and GetCollisionPack (0x4ecb30).
Random object bytes so the byte and dword reads are meaningful."""
from pilot import S, F


def _obj(c):
    e, r = c.emu, c.rng
    o = e.alloc(0x200, 4)
    e.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x200)))
    return [o]


S(0x4edca0, 'ZCollisionBase::IsCollisionBoxLocked', 'thiscall', None, ret='al', gen=_obj, note='batch1127')
S(0x4ecb30, 'ZCollisionBase::GetCollisionPack', 'thiscall', None, ret='eax', gen=_obj, note='batch1127')
