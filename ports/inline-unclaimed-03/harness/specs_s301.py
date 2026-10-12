"""specs_s301.py - unclaimed-03 batch 1 (docs/20-unclaimed-03.md): ZActor leaf getters, 0x478630 to 0x47c530.
Each function is thiscall with no stack arguments. The object is 0x800 random bytes, so a load from any field reads
the same random data in the exe and in the port, and a store (NoCageCheck) lands inside the object. Getters return
eax; the two address returns (EndDir, TrackObjPos) return the object's own address, so both runs must agree on it."""
from pilot import S


def _obj(c):
    a = c.emu.alloc(0x800, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    return [a]


S(0x478630, 'ZActor::EndDir (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-03 batch 1; returns this+0x69a')
S(0x4789e0, 'ZActor::GetActiveMoveSet (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-03 batch 1; dword at +0x4ae')
S(0x4789f0, 'ZActor::GetActorList (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-03 batch 1; dword at +0x73a')
S(0x478a60, 'ZActor::GetActorState (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-03 batch 1; dword at +0x65c')
S(0x478b30, 'ZActor::GetAudibleRoomList (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-03 batch 1; dword at +0x5ca')
S(0x478b40, 'ZActor::GetCage (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-03 batch 1; dword at +0x6bf')
S(0x478b50, 'ZActor::GetCurrentMoveType (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-03 batch 1; dword at +0x650')
S(0x478b60, 'ZActor::GetCurrentRoom (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-03 batch 1; dword at +0x736')
S(0x479740, 'ZActor::NoCageCheck (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-03 batch 1; byte 1 to +0x6c3')
S(0x47c530, 'ZActor::TrackObjPos (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-03 batch 1; returns this+0x660')
