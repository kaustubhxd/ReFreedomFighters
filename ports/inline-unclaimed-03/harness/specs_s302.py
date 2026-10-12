"""specs_s302.py - unclaimed-03 batch 2 (docs/20-unclaimed-03.md): CMoveAlongPath getters and SetTargetSpeed, and
ZCollisionBase::GetCollisionPack / IsCollisionBoxLocked. Each object is 0x800 random bytes, so field loads read the
same random data in both runs. Float arguments use the harness float generator (edge values and NaN included),
compared by bit pattern. IsCollisionBoxLocked returns al only, so the spec compares al (ret='al')."""
from pilot import S, F


def _obj(c):
    a = c.emu.alloc(0x800, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    return [a]


def _obj_2f(c):
    # a1 is compared with the float at +0x24 by '>'. One case in three sets +0x24 equal to a1 (the boundary, where '>'
    # and '>=' differ); the rest keep the random bytes, so the comparison goes both ways.
    o = _obj(c)[0]
    a1 = c.fv(-100.0, 100.0)
    a2 = c.fv(-100.0, 100.0)
    if c.rng.random() < 1 / 3:
        c.emu.wf32(o + 0x24, a1)
    return [o, F(a1), F(a2)]


S(0x5231b0, 'CMoveAlongPath::DirFactor (unknown) thiscall const', 'thiscall', None, ret='st0', gen=_obj,
  note='unclaimed-03 batch 2; fld float at +0x20')
S(0x523460, 'CMoveAlongPath::GetPath (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-03 batch 2; dword at +0x4b')
S(0x523980, 'CMoveAlongPath::PathLength (unknown) thiscall const', 'thiscall', None, ret='st0', gen=_obj,
  note='unclaimed-03 batch 2; fld float at +0x53')
S(0x523e80, 'CMoveAlongPath::SetTargetSpeed (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_2f,
  note='unclaimed-03 batch 2; a1 to +0x2c, a2 (negated if +0x24 > a1) to +0x28')
S(0x4ecb30, 'ZCollisionBase::GetCollisionPack (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-03 batch 2; dword at +0x1ad')
S(0x4edca0, 'ZCollisionBase::IsCollisionBoxLocked (unknown) thiscall const', 'thiscall', None, ret='al', gen=_obj,
  note='unclaimed-03 batch 2; byte at +0xa9 in al')
