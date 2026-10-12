"""specs_s904.py - unclaimed-01 claim 3 (docs/20-unclaimed-01.md): ZFFActor::SetCloseCombatStrength (0x5a2c90),
SetMinProjectilesWhenDead (0x5a2df0), ZFFActor::ResetLastHitPos (0x5a2980), ZMoveOnSpline::SetStationary (0x514470),
CAction::SetMessage (0x4a1c70), ZOnScreenDisplay::Show (0x5ab040), CMAINCAMERACONTROL::SetBaseViewport (0x4fda20) and
GetBaseViewport (0x4fc4e0), and ZActor::OnViewLeave (0x47aab0). OnViewLeave's vtable is a logging fake vtable (slot
+0xbc logs its call and argument), so the call is compared, not just its effect."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj_u32(c):
    return [_rnd(c, 0x1000), c.rng.getrandbits(32)]


def _obj_ptr16(c):
    return [_rnd(c, 0x1000), _rnd(c, 16)]


def _obj_getvp(c):
    return [_rnd(c, 0x1000), _rnd(c, 16)]


def _onview(c):
    o = _rnd(c, 0x1000)
    c.emu.w32(o + 0x640, c.rng.choice([0, 1, 2, c.rng.getrandbits(32)]))
    owner = _rnd(c, 0x80)
    flags = c.rng.getrandbits(32)
    if c.rng.random() < 0.4:
        flags |= 0x800
    else:
        flags &= ~0x800 & 0xffffffff
    c.emu.w32(owner + 0x3c, flags)
    c.emu.w32(o + 8, owner)
    vt = c.emu.logging_vtable('ZActor', 0x30, argwords={0xbc: 1})
    c.emu.w32(o, vt)
    return [o]


def _obj_only(c):
    return [_rnd(c, 0x1000)]


S(0x5a2c90, 'ZFFActor::SetCloseCombatStrength (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-01 claim 3; low word to +0x7a4')
S(0x5a2df0, 'ZFFActor::SetMinProjectilesWhenDead (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-01 claim 3; low word to +0x788')
S(0x514470, 'ZMoveOnSpline::SetStationary (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-01 claim 3; low byte to +0x133')
S(0x4a1c70, 'CAction::SetMessage (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-01 claim 3; low word to +0x4c')
S(0x5ab040, 'ZOnScreenDisplay::Show (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-01 claim 3; dword to +0x300')
S(0x4fda20, 'CMAINCAMERACONTROL::SetBaseViewport (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_ptr16,
  note='unclaimed-01 claim 3; copies 16 bytes to +0x4e')
S(0x4fc4e0, 'CMAINCAMERACONTROL::GetBaseViewport (unknown) thiscall const', 'thiscall', None, ret=None,
  gen=_obj_getvp, note='unclaimed-01 claim 3; copies 16 bytes from +0x4e')
S(0x5a2980, 'ZFFActor::ResetLastHitPos (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_only,
  note='unclaimed-01 claim 3; three zero dwords at +0x8fb, +0x8ff, +0x903')
S(0x47aab0, 'ZActor::OnViewLeave (unknown) thiscall', 'thiscall', None, ret=None, gen=_onview,
  note='unclaimed-01 claim 3; counter at +0x640; vtable slot +0xbc with arg 1 when owner flag clear')
