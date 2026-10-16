"""specs_s961.py - residue-04, batch 961: ZOctreeCompiled::RemapObjects (0x4e3e40). The recursive remap 0x4e3dc0 is stood in
for the case (hookrec): it records ECX (the node pointer) and the three record fields it is given. The record is a stack
address, so it is not recorded directly (peeks read its fields instead)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import _rnd, hookrec, r32, obj


def g(c):
    hookrec(c, 0x4e3dc0, 1, ret=0, this=True, peeks=((0, 0), (0, 4), (0, 8)), skip=(0,))
    edx = obj(c, 0x40)
    c.emu.w32(edx, r32(c))
    t = obj(c, 0x40)
    c.emu.w32(t + 0x14, edx)
    return [t, r32(c)]


S(0x4e3e40, 'ZOctreeCompiled::RemapObjects', 'thiscall', gen=g)
