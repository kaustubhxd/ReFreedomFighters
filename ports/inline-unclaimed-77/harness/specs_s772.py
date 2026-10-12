"""specs_s772.py - unclaimed-77 claim 2 (docs/20-unclaimed-77.md): five pure leaves. Thiscall, no arguments, no callees.
The object is 0x1000 random bytes. ZSNDOBJ::GetPitch reads a pointer at +0x18, so that field holds a random 0x80-byte block."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x1000)]


def _obj_ptr(c):
    self = _rnd(c, 0x1000)
    c.emu.w32(self + 0x18, _rnd(c, 0x80))
    return [self]


S(0x4834c0, 'ZPlayer::EnableT1 (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-77 claim 2; byte 0 at +0x5fe')
S(0x483b00, 'ZPlayer::GetGroundContact (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj,
  note='unclaimed-77 claim 2; byte at +0x42c')
S(0x453a40, 'ZGATE::GetGates (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-77 claim 2; dword at +0x52')
S(0x462f40, 'ZItemTemplate::GetPointerContextPicture (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-77 claim 2; dword at +0x6c')
S(0x44c100, 'ZSNDOBJ::GetPitch (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj_ptr,
  note='unclaimed-77 claim 2; pointer at +0x18, dword at +0x64 of it')
