"""specs_s909.py - unclaimed-09 (docs/20-unclaimed-09.md): ZFFActor small accessors and ZFFHeroMovementBaseMove::GotControl.
Each function is thiscall. The object is 0x1000 random bytes (the first spec used 0x800 and missed four mutants: offsets 0x907 to 0x929 lay past
the object, so reads saw zeros and the store fell outside the compared heap). Every read and store lands inside it. The getters
that return an int compare eax; GetKnockedOut returns a byte and compares al (ret='al', as the pilot does for bool)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x1000)]


def _obj_u32(c):
    return [_rnd(c, 0x1000), c.rng.getrandbits(32)]


S(0x59fce0, 'ZFFActor::GetAmmoFor (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj_u32,
  note='unclaimed-09; returns 999, argument ignored')
S(0x59fe10, 'ZFFActor::GetHitsOnObstacle (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-09; dword at +0x90b')
S(0x59fe70, 'ZFFActor::GetKnockedOut (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj,
  note='unclaimed-09; byte at +0x929 to al')
S(0x59feb0, 'ZFFActor::GetLastHitRef (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-09; dword at +0x907')
S(0x5a2970, 'ZFFActor::ResetHitsOnObstacle (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-09; zero dword at +0x90b')
S(0x5e48f0, 'ZFFHeroMovementBaseMove::GotControl (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-09; byte 1 to +0x54b')
