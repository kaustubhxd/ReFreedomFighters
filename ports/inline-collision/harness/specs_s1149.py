"""specs_s1149.py - collision thread batch 1149 (name GUESS): 0x4e3cc0, the GetEverything thunk into the octree node walk 0x4e3ce0.
The argument is the info record from batch 1123's tree builder (its +0xc is the tree base, which the thunk loads into ECX). The
walk itself runs as exe code, so the spec reuses that generator and its item callback."""
from pilot import S, F
from specs_s1123 import _tree


def _gen(c):
    base, info = _tree(c)
    dummy = c.emu.alloc(0x10, 4)          # ECX is unused by the thunk (it loads [arg+0xc] itself)
    return [dummy, info]


S(0x4e3cc0, 'thunk: ECX = [arg+0xc], arg as the stack argument, into the node walk 0x4e3ce0 (name GUESS)', 'thiscall', None,
  ret='eax', gen=_gen, note='batch1149')
