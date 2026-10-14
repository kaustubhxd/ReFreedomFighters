"""specs_c1059.py - camera batch 1059: CCameraBox::CopyData (0x582730)."""
from pilot import S
from camgen import rnd


def _copy(c):
    return [rnd(c, 0x80), rnd(c, 0x80)]


S(0x582730, 'CCameraBox::CopyData', 'thiscall', gen=_copy)
