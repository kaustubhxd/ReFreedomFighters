"""specs_s980.py - area 56 band, claim A46 (0x535990): stdcall, three float arguments, returns an int.

a is exactly 0.0 in about one case in four, else a random float in [-5, 5]; b and c are random floats in [-5, 5]. The constants
are read from the loaded image. ret='eax' (the int result)."""
from pilot import S
from pe_emu import F


def _gen(c):
    rng = c.rng
    a = 0.0 if rng.random() < 0.25 else rng.uniform(-5.0, 5.0)
    b = rng.uniform(-5.0, 5.0)
    cc = rng.uniform(-5.0, 5.0)
    return [F(a), F(b), F(cc)]


S(0x535990, 'unnamed 0x535990 (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A46; three float args, int result, no calls')
