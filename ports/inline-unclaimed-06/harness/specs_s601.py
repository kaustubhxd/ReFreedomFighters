"""specs_s601.py - unclaimed-06 (docs/20-unclaimed-06.md): ZActor one-instruction getters, 0x478630 to 0x47c530.
Each function is thiscall with no arguments. The object is 0x800 random bytes, so every load and store lands inside it
and an overrun shows as a heap difference. Getters return the dword at a fixed offset (ret='eax') or an address computed
with lea (also ret='eax', the pointer value must match)."""
from pilot import S


def _obj(c):
    a = c.emu.alloc(0x800, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    return [a]


S(0x478630, 'ZActor::EndDir (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06; returns this+0x69a (lea)')
S(0x4789e0, 'ZActor::GetActiveMoveSet (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06; dword at +0x4ae')
S(0x4789f0, 'ZActor::GetActorList (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06; dword at +0x73a')
S(0x478a60, 'ZActor::GetActorState (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06; dword at +0x65c')
S(0x478b30, 'ZActor::GetAudibleRoomList (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06; dword at +0x5ca')
S(0x478b40, 'ZActor::GetCage (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06; dword at +0x6bf')
S(0x478b50, 'ZActor::GetCurrentMoveType (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06; dword at +0x650')
S(0x478b60, 'ZActor::GetCurrentRoom (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06; dword at +0x736')
S(0x479740, 'ZActor::NoCageCheck (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-06; byte 1 to +0x6c3')
S(0x47c530, 'ZActor::TrackObjPos (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06; returns this+0x660 (lea)')
