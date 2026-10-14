"""specs_s33017.py - h3 batch 33017: simple setter and byte read."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _me(c, n=0x80):
    return rnd(c, n)

def _g4d23c0(c):
    clear_hooks(c)
    return [_me(c)]

def _g527180(c):
    clear_hooks(c)
    return [_me(c)]

S(0x4d23c0, 'set_dword_696168', 'thiscall', None, ret=None, gen=_g4d23c0)
S(0x527180, 'read_byte_at_18', 'thiscall', None, ret='al', gen=_g527180)
