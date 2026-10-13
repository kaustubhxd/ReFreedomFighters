"""specs_c1063.py - camera batch 1063: the byte accessor at 0x445e80 (class map name ZCAMERA::ForceLightUpdate; body is
a getter of the byte at +0x170)."""
from pilot import S
from camgen import rnd


def _get(c):
    return [rnd(c, 0x200)]


S(0x445e80, 'ZCAMERA::ForceLightUpdate (getter at +0x170)', 'thiscall', gen=_get)
