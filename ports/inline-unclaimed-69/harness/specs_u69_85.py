"""specs_u69_85.py - area 69, gameplay-core residue-8 functions from docs/39 (residue-08 todo): 0x489340, 0x47bd80, 0x47c140. Real code, no stubs."""
from pilot import S, F
from ckit import rnd


def _obj_inner(c):
    obj = rnd(c, 0x40)
    inner = rnd(c, 0x800)
    c.emu.w32(obj + 4, inner)
    return [obj]


def _obj_byte(c):
    return [rnd(c, 0x800), c.rng.getrandbits(32)]   # the exe reads only the low byte (bool)


def _obj_float(c):
    return [rnd(c, 0x800), F(c.rng.uniform(-100.0, 100.0))]


S(0x489340, 'ZMovementGuide::GotControl (thiscall, no args, returns the inner pointer)', 'thiscall', None, ret='eax', gen=_obj_inner, note='u69 gameplay-core; naked asm port')
S(0x47bd80, 'ZActor::SetDisableIdleAnimation (thiscall, bool, ret 4)', 'thiscall', None, ret='eax', gen=_obj_byte, note='u69 gameplay-core; naked asm port')
S(0x47c140, 'ZActor::SetStopDistance (thiscall, float, ret 4)', 'thiscall', None, ret='eax', gen=_obj_float, note='u69 gameplay-core; naked asm port')
