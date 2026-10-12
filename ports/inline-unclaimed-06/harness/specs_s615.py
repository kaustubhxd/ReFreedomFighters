"""specs_s615.py - unclaimed-06 claims 16 to 18 (docs/20-unclaimed-06.md): three pure leaves. Thiscall, no callees.
0x4837d0 ZPlayer::GetActiveMovementType: the object's +0x455 holds a valid 0x40-byte block (random), returns its +0x10.
0x4364d0 GUESS: stores into a random 0x1000-byte object. 0x560310 GUESS: writes the global at 0x71419c (no argument used)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj_ptr(c):
    self = _rnd(c, 0x1000)
    c.emu.w32(self + 0x455, _rnd(c, 0x40))
    return [self]


def _obj(c):
    return [_rnd(c, 0x1000)]


S(0x4837d0, 'ZPlayer::GetActiveMovementType (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj_ptr,
  note='unclaimed-06 claim 16; pointer at +0x455, dword at +0x10 of it')
S(0x4364d0, 'GUESS FUN_4364d0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06 claim 17; GUESS name; stores 0 at +4 and byte 0 at +8, returns this')
S(0x560310, 'GUESS FUN_560310 (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-06 claim 18; GUESS name; stores 0 to global 0x71419c')
