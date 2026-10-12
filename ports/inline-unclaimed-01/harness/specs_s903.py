"""specs_s903.py - unclaimed-01 claim 2 (docs/20-unclaimed-01.md): ZActor::SetPathNotify (0x47bfc0),
SetPathNotifySyncToCycle (0x47bfe0), SetStayInsidePath (0x47c130), SetStopDistance (0x47c140), SetActorState (0x47bcc0,
returns the old state in eax), SetMoveSet (0x47bed0, index 0..7 into the table at +0x49a), and ZInputAction::SetActive
(0x43afd0). Objects are 0x800 random bytes (ZInputAction: 0x40 bytes). Floats and bools use random bit patterns."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj_u32(c):
    return [_rnd(c, 0x800), c.rng.getrandbits(32)]


def _obj_float(c):
    return [_rnd(c, 0x800), F(c.fv(-100.0, 100.0))]


def _obj_input(c):
    return [_rnd(c, 0x40), c.rng.getrandbits(32)]


def _moveset(c):
    o = _rnd(c, 0x800)
    p = _rnd(c, 0x10)
    c.emu.w32(p, c.rng.randint(0, 7))   # SMoveSet index (table has eight slots at +0x49a)
    return [o, p]


S(0x47bfc0, 'ZActor::SetPathNotify (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_float,
  note='unclaimed-01 claim 2; float bits to +0x6ba')
S(0x47bfe0, 'ZActor::SetPathNotifySyncToCycle (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-01 claim 2; low byte to +0x6be')
S(0x47c130, 'ZActor::SetStayInsidePath (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_u32,
  note='unclaimed-01 claim 2; low byte to +0x6c4')
S(0x47c140, 'ZActor::SetStopDistance (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_float,
  note='unclaimed-01 claim 2; float bits to +0x6b2')
S(0x47bcc0, 'ZActor::SetActorState (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj_u32,
  note='unclaimed-01 claim 2; returns old dword at +0x65c')
S(0x47bed0, 'ZActor::SetMoveSet (unknown) thiscall', 'thiscall', None, ret=None, gen=_moveset,
  note='unclaimed-01 claim 2; index 0..7 into table at +0x49a')
S(0x43afd0, 'ZInputAction::SetActive (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_input,
  note='unclaimed-01 claim 2; low byte to +0x10')
