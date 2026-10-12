"""specs_s910.py - unclaimed-09 batch 2 (docs/20-unclaimed-09.md): collision lock bits, UnlockCollisionBox, and
CMoveAlongPath accessors. All thiscall. Objects are 0x1000 random bytes (the batch 1 lesson: keep every offset well
inside the object). Float getters return in st0 (ret='st0'); byte getters compare al (ret='al'); dword getters eax."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x1000)]


def _obj_u32(c):
    return [_rnd(c, 0x1000), c.rng.getrandbits(32)]


S(0x4eb340, 'ZCollisionBox::Unlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-09 b2; byte 0 to +0xa5 (GUESS name)')
S(0x4ecb30, 'ZCollisionBase::GetCollisionPack (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-09 b2; dword at +0x1ad (GUESS name)')
S(0x4edca0, 'ZCollisionBase::IsCollisionBoxLocked (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj,
  note='unclaimed-09 b2; byte at +0xa9 to al (GUESS name)')
S(0x4ede70, 'ZCollisionBase::UnlockCollisionBox (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-09 b2; this+4 to Unlock, arg unused (GUESS name)')
S(0x5231b0, 'CMoveAlongPath::DirFactor (unknown) thiscall', 'thiscall', None, ret='st0', gen=_obj,
  note='unclaimed-09 b2; float at +0x20 to st0 (GUESS name)')
S(0x523460, 'CMoveAlongPath::GetPath (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-09 b2; dword at +0x4b (GUESS name)')
S(0x523980, 'CMoveAlongPath::PathLength (unknown) thiscall', 'thiscall', None, ret='st0', gen=_obj,
  note='unclaimed-09 b2; float at +0x53 to st0 (GUESS name)')
