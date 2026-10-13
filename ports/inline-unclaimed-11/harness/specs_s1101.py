"""specs_s1101.py - unclaimed-11 batch 1 (docs/20-unclaimed-11.md): CMoveAlongPath accessors and ZMovementAction::WantControl.
Every function is thiscall. The object is 0x800 random bytes, so each store lands inside it and an overrun shows as a
heap or data difference. Float returns are compared on the 80-bit ST0 value (ret='st0'). WantControl reads a pointer at
this+4 to an owner object; the owner is a random buffer, so the flag bit 0x80000 is set in about half the cases."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x800)]


def _obj_float2(c):
    return [_rnd(c, 0x800), F(c.fv(-100.0, 100.0)), F(c.fv(-100.0, 100.0))]


def _want(c):
    o = _rnd(c, 0x800)
    c.emu.w32(o + 4, _rnd(c, 0x1000))
    return [o, _rnd(c, 0x40), _rnd(c, 0x40), _rnd(c, 0x40)]


S(0x5231b0, 'CMoveAlongPath::DirFactor (GUESS) thiscall const', 'thiscall', None, ret='st0', gen=_obj,
  note='unclaimed-11; fld float at +0x20')
S(0x523460, 'CMoveAlongPath::GetPath (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-11; dword at +0x4b')
S(0x523980, 'CMoveAlongPath::PathLength (GUESS) thiscall const', 'thiscall', None, ret='st0', gen=_obj,
  note='unclaimed-11; fld float at +0x53')
S(0x523e80, 'CMoveAlongPath::SetTargetSpeed (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_float2,
  note='unclaimed-11; arg1 to +0x2c, arg2 to +0x28 with sign flip when +0x24 > arg1')
S(0x489d80, 'ZMovementAction::WantControl (unknown) thiscall', 'thiscall', None, ret='al', gen=_want,
  note='unclaimed-11; owner+0x417 bit 0x80000 then this+0x21 != 0')
