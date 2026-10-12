"""specs_s602.py - unclaimed-06 batch 2 (docs/20-unclaimed-06.md): ZFFActor small accessors and flag setters.
Object is 0x1000 random bytes (ZFFActor reads reach +0x92d, past 0x800), so every access lands inside it and an overrun shows as a heap difference.
Setters take a random 32-bit argument, so the low byte (the bool) takes every value, and the flag dword at +0x7a6 is
random before each call. GetLastHitPos gets a random 12-byte output buffer."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x1000)]


def _obj_u32(c):
    return [_rnd(c, 0x1000), c.rng.getrandbits(32)]


def _obj_out(c):
    return [_rnd(c, 0x1000), _rnd(c, 12)]


S(0x59fce0, 'ZFFActor::GetAmmoFor (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj_u32,
  note='unclaimed-06 b2; constant 999, ret 4')
S(0x59fcf0, 'ZFFActor::GetCloseCombatStrength (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06 b2; word at +0x7a4 (upper eax from entry 0)')
S(0x59fe10, 'ZFFActor::GetHitsOnObstacle (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06 b2; dword at +0x90b')
S(0x59fe70, 'ZFFActor::GetKnockedOut (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06 b2; byte at +0x929 (upper eax from entry 0)')
S(0x59feb0, 'ZFFActor::GetLastHitRef (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-06 b2; dword at +0x907')
S(0x59fe80, 'ZFFActor::GetLastHitPos (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_out,
  note='unclaimed-06 b2; three dwords from +0x8fb/+0x8ff/+0x903 to out, ret 4')
S(0x5a2970, 'ZFFActor::ResetHitsOnObstacle (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-06 b2; zero dword at +0x90b')
S(0x5a2c30, 'ZFFActor::SetCloseCombatAttack (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-06 b2; flag bit 2 at +0x7a6, bool low byte, ret 4')
S(0x5a2c50, 'ZFFActor::SetCloseCombatEnable (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-06 b2; flag bit 1 at +0x7a6, bool low byte, ret 4')
S(0x5a2c70, 'ZFFActor::SetCloseCombatEvade (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-06 b2; flag bit 4 at +0x7a6, bool low byte, ret 4')
