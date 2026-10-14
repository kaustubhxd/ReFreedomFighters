"""specs_c1078.py - camera batch 1078: the view-entry fill 0x60f040 (ecx = out, edx = a, one stack arg b)."""
from pilot import S
from camgen import rnd


def _fill(c):
    out = rnd(c, 0x40)
    a = rnd(c, 0x40)
    b = rnd(c, 0x20)
    return [out, a, b]


S(0x60f040, 'ZCameraViewEntryGC fill (0x60f040)', 'fastcall', gen=_fill)
