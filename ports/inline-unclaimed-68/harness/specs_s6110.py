"""specs_s6110.py - unclaimed-68 batch 12 (claim 11): GUESS FUN_516730 (0x516730). The object is zeroed (it holds the four stores
at +0x11..+0x1d and the sub-object at +0x21, which 0x524930 writes into through original code). The float argument is random."""
from pilot import S, F
from engine_stubs import zero_obj


def _gen(c):
    o = zero_obj(c, 0x200)
    return [o, F(c.rng.uniform(-50.0, 50.0))]


S(0x516730, 'GUESS FUN_516730 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-68 batch 12; GUESS name; constants at +0x11..+0x1d; 0x4690b0 no-op; 0x524930 original')
