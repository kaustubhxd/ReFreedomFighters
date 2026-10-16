"""specs_c1074.py - camera batch 1074: the empty event readers 0x610100, 0x57f350 (jumps to 0x610100) and 0x565a30 (jumps to
0x57f350). Their bodies do nothing but pop their argument."""
from pilot import S
from camgen import rnd


def _empty(c):
    return [rnd(c, 0x80), c.rng.getrandbits(32)]


S(0x610100, 'ZCamHelper::CopyEventDataBlock (shared empty body)', 'thiscall', gen=_empty)
S(0x57f350, 'ZFFCam::CopyEventDataBlock (jumps to empty body)', 'thiscall', gen=_empty)
S(0x565a30, 'ZFFCamera1::CopyEventDataBlock (jumps to empty body)', 'thiscall', gen=_empty)
