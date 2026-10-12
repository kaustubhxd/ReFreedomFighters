"""specs_s920.py - unclaimed-01 claim 19 (docs/20-unclaimed-01.md): 0x58b740 (GUESS FUN_58b740). The base routine 0x58b5a0 is
a no-op thiscall stub; the deletes 0x4690b0 (two arguments) and 0x45c510 (one argument) are cdecl logging stubs (rings in the
heap, compared). Flag bits 0 and 2 are drawn both ways."""
import serial_stubs as ss
from pilot import S
from specs_s919 import _cdecl_log, _rnd


def _guess(c):
    ss.patch(c, 0x58b5a0, ss.rec(c, 0, ret=0))
    ss.patch(c, 0x4690b0, _cdecl_log(c, 2))
    ss.patch(c, 0x45c510, _cdecl_log(c, 1))
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


S(0x58b740, 'GUESS FUN_58b740 (dtor-like) thiscall', 'thiscall', None, ret='eax', gen=_guess,
  note='unclaimed-01 claim 19; base 0x58b5a0 no-op; sized delete 0xf62 or 0x45c510 by flag bits')
