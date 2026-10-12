"""specs_s501.py - unclaimed-05 batch 1 (docs/20-unclaimed-05.md): 12 small thiscall functions.
The object is 0x800 random bytes, so every store and load lands inside it and an overrun shows as a heap difference.
Each gen returns [this, stack args...]. Returns that are pointers or bytes are compared as the harness defines them
(EAX whole for dword and pointer returns, AL only for the bool return)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x800)]


def _obj_u32(c):
    return [_rnd(c, 0x800), c.rng.getrandbits(32)]


def _obj_buf(n):
    def gen(c):
        return [_rnd(c, 0x800), _rnd(c, n)]
    return gen


S(0x4ecb30, 'ZCollisionBase::GetCollisionPack (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-05 batch 1; dword at +0x1ad')
S(0x4edca0, 'ZCollisionBase::IsCollisionBoxLocked (unknown) thiscall const', 'thiscall', None, ret='al', gen=_obj,
  note='unclaimed-05 batch 1; byte at +0xa9')
S(0x4eb340, 'ZCollisionBox::Unlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-05 batch 1; byte 0 to +0xa5')
S(0x4ede70, 'ZCollisionBase::UnlockCollisionBox (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-05 batch 1; box argument unused; unlocks this+4 (ret 4)')
S(0x4e3340, 'ZOctree::GetOrigin (unknown) thiscall const', 'thiscall', None, ret=None, gen=_obj_buf(12),
  note='unclaimed-05 batch 1; three dwords from +4 to out')
S(0x4e3360, 'ZOctree::SetOrigin (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_buf(12),
  note='unclaimed-05 batch 1; three dwords from arg to +4')
S(0x486e10, 'ZActionChamberItem::Name (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-05 batch 1; returns exe string 0x68cdb0')
S(0x486e50, 'ZActionPushButton::Name (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-05 batch 1; returns exe string 0x68cd24')
S(0x486e70, 'ZActionReloadItem::Name (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-05 batch 1; returns exe string 0x68cd74')
S(0x51f240, 'ZHeliIf::getTypeName (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-05 batch 1; returns exe string 0x69faac')
S(0x522ce0, 'ZTankIf::getTypeName (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-05 batch 1; returns exe string 0x6a073c')
S(0x4a5fc0, 'ZMatPosAnim::SetRotMat (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_buf(0x24),
  note='unclaimed-05 batch 1; 0x24 bytes from arg to +0x93 (via 0x4de420)')
