"""specs_s911.py - unclaimed-09 batch 3 (docs/20-unclaimed-09.md): CMAINCAMERACONTROL::GetOldCam and ToggleFreeCam.
Both thiscall, objects 0x1000 random bytes. Names are low confidence (GUESS)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x1000)]


S(0x4fc680, 'CMAINCAMERACONTROL::GetOldCam (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-09 b3; dword at +0x74 (GUESS name)')
S(0x4fdd10, 'CMAINCAMERACONTROL::ToggleFreeCam (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-09 b3; byte 1 to +0x69 (GUESS name)')
