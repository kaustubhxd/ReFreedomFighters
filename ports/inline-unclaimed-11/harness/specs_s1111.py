"""specs_s1111.py - unclaimed-11 batch 12 (slice 10, full function list): six trivial accessors, all thiscall.
0x453b20 ZGATE::IsOpen: al = byte at this+0x5a. 0x463020 (GUESS: the name map says ZLNKOBJ::MoveToMatPos, but the body is a
byte read at +0x70): al = byte at this+0x70. 0x43ed60 ZGROUP::AddSphere (low): returns 0 with five stack arguments (ret 0x14).
0x4b1720 and 0x4fb820 GetActionDefinitions (low): eax = dword at a global (0x6e6734 and 0x6e8d40, data section). 0x511760
getTypeName (low): eax = 0x69c790 (a string address). The objects are 0x100 random bytes."""
from pilot import S


def _obj(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [o]


def _obj5(c):
    return [_obj(c)[0]] + [c.rng.getrandbits(32) for _ in range(5)]


S(0x453b20, 'ZGATE::IsOpen (low) thiscall', 'thiscall', None, ret='al', gen=_obj, note='unclaimed-11 batch 12')
S(0x463020, 'GUESS byte at +0x70 (name map says ZLNKOBJ::MoveToMatPos, body disagrees) thiscall', 'thiscall', None,
  ret='al', gen=_obj, note='unclaimed-11 batch 12; GUESS name')
S(0x43ed60, 'ZGROUP::AddSphere (low) thiscall', 'thiscall', None, ret='eax', gen=_obj5, note='unclaimed-11 batch 12')
S(0x4b1720, 'ZActionMapPushSceneOnKeyStart::GetActionDefinitions (low) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-11 batch 12')
S(0x4fb820, 'ZActionMapMainCameraControl::GetActionDefinitions (low) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-11 batch 12')
S(0x511760, 'ZScriptSoundInterface_t::getTypeName (low) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-11 batch 12')
