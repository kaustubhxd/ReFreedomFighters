"""specs_s33005.py - cascade h3 batch 33005: three small 2-instruction functions."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x200):
    return rnd(c, n)


def _g50d810(c):
    """Return constant."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g533b40(c):
    """Read byte member at offset 0x50a9."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g5422a0(c):
    """Write dword at offset 0."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


S(0x50d810, 'constant_0x69c77c', 'thiscall', None, ret='eax', gen=_g50d810)
S(0x533b40, 'member_byte_0x50a9', 'thiscall', None, ret='al', gen=_g533b40)
S(0x5422a0, 'write_dword_0', 'thiscall', None, ret=None, gen=_g5422a0)
