"""specs_s1001.py - unclaimed-10 (docs/20-unclaimed-10.md), batch 1: ZActor leaf accessors.
Each getter is thiscall with no stack arguments; the object is 0x800 random bytes, so every read lands inside it.
Getters return a dword (or an address), compared as EAX. NoCageCheck is a void setter."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x800)]


S(0x478630, 'ZActor::EndDir (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10; returns this+0x69a')
S(0x4789e0, 'ZActor::GetActiveMoveSet (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10; returns dword at +0x4ae')
S(0x4789f0, 'ZActor::GetActorList (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10; returns dword at +0x73a')
S(0x478a60, 'ZActor::GetActorState (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10; returns dword at +0x65c')
S(0x478b30, 'ZActor::GetAudibleRoomList (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10; returns dword at +0x5ca')
S(0x478b40, 'ZActor::GetCage (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10; returns dword at +0x6bf')
S(0x478b50, 'ZActor::GetCurrentMoveType (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10; returns dword at +0x650')
S(0x478b60, 'ZActor::GetCurrentRoom (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10; returns dword at +0x736')
S(0x47c530, 'ZActor::TrackObjPos (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10; returns this+0x660')
S(0x479740, 'ZActor::NoCageCheck (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-10; byte 1 to +0x6c3')

# Batch 2: Name() returns a constant string address; the object is not read.
S(0x486e10, 'ZActionChamberItem::Name (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10 batch 2; returns 0x68cdb0')
S(0x486e50, 'ZActionPushButton::Name (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10 batch 2; returns 0x68cd24')
S(0x486e70, 'ZActionReloadItem::Name (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10 batch 2; returns 0x68cd74')

# Batch 3: medium and low name confidence (GUESS on class and name for the CMAINCAMERACONTROL and ZActorIf entries).
S(0x4eb340, 'ZCollisionBox::Unlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-10 batch 3; byte 0 to +0xa5')
S(0x4ecb30, 'ZCollisionBase::GetCollisionPack (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10 batch 3; dword at +0x1ad')
S(0x4edca0, 'ZCollisionBase::IsCollisionBoxLocked (unknown) thiscall const', 'thiscall', None, ret='al', gen=_obj,
  note='unclaimed-10 batch 3; byte at +0xa9')
S(0x4fc680, 'CMAINCAMERACONTROL::GetOldCam (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10 batch 3; dword at +0x74')
S(0x4fdd10, 'CMAINCAMERACONTROL::ToggleFreeCam (GUESS) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-10 batch 3; byte 1 to +0x69')
S(0x5095e0, 'ZActorIf::getTypeName (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-10 batch 3; returns 0x69c75c')

# Batch 4: call-free leaves (medium name confidence). The src object for CopyData is a second random buffer.
def _obj_u32_pair(c):
    return [_rnd(c, 0x800), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _obj_src(c):
    return [_rnd(c, 0x800), _rnd(c, 0x800)]


S(0x4edce0, 'ZCollisionBase::LoadUniqueSubStripInfo (GUESS) thiscall', 'thiscall', None, ret=None,
  gen=_obj_u32_pair, note='unclaimed-10 batch 4; stores arg1 at +0x190, arg2>>3 at +0x194, byte 1 at +0x19c')
S(0x53e800, 'CRigidBody::CopyData (GUESS) thiscall', 'thiscall', None, ret=None, gen=_obj_src,
  note='unclaimed-10 batch 4; copies byte +0x149 and dwords +0x145, +0x141 from the source')
