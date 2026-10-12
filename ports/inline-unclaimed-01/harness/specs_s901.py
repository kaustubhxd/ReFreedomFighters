"""specs_s901.py - unclaimed-01 (docs/20-unclaimed-01.md): ZActor small setters, 0x479610 to 0x47bef0.
Each function is thiscall with one argument and no return value (ret 4). The object is 0x800 random bytes, so each
store lands inside it and an overrun shows as a heap difference. Float setters take random float bit patterns (edge
values included, NaN included) and compare the stored bits, not a float operation."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj_u32(c):
    return [_rnd(c, 0x800), c.rng.getrandbits(32)]


def _obj_float(c):
    return [_rnd(c, 0x800), F(c.fv(-100.0, 100.0))]


S(0x479610, 'ZActor::LookAt (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-01; stores arg at +0x648')
S(0x47bd50, 'ZActor::SetCage (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-01; stores arg at +0x6bf')
S(0x47bd80, 'ZActor::SetDisableIdleAnimation (unknown) thiscall', 'thiscall', None, ret=None,
  gen=_obj_u32, note='unclaimed-01; low byte of arg to +0x771')
S(0x47bdf0, 'ZActor::SetHero (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-01; stores arg at +0x492')
S(0x47be90, 'ZActor::SetMaxPathLen (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_float,
  note='unclaimed-01; float bits to +0x6b6')
S(0x47beb0, 'ZActor::SetMovePoolWeight (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_float,
  note='unclaimed-01; float bits to +0x60f')
S(0x47bef0, 'ZActor::SetMoveSpeedMultiplier (unknown) thiscall', 'thiscall', None, ret=None,
  gen=_obj_float, note='unclaimed-01; float bits to +0x688')
