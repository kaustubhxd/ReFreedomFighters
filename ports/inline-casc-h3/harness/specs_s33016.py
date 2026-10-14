"""specs_s33016.py - h3 batch 33016: simple pointer arithmetic functions."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _me(c, n=0x80):
    return rnd(c, n)

def _g4744e0(c):
    clear_hooks(c)
    return [_me(c)]

def _g486e20(c):
    clear_hooks(c)
    return []

S(0x4744e0, 'thunk_offset_34f', 'thiscall', None, ret='eax', gen=_g4744e0)
S(0x486e20, 'const_addr_68ccb4', 'cdecl', None, ret='eax', gen=_g486e20)
