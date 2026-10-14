"""specs_s33007.py - cascade h3 batch 33007: four small 2-instruction functions."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x200):
    return rnd(c, n)


def _g614ed0(c):
    """Return constant 0x1c."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g626a70(c):
    """Return constant 0x6be898."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g63db30(c):
    """Return constant 0x10."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g64a6f0(c):
    """Read dword member at offset 0xc."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


S(0x614ed0, 'constant_0x1c', 'thiscall', None, ret='eax', gen=_g614ed0)
S(0x626a70, 'constant_0x6be898', 'thiscall', None, ret='eax', gen=_g626a70)
S(0x63db30, 'constant_0x10', 'thiscall', None, ret='eax', gen=_g63db30)
S(0x64a6f0, 'member_0xc', 'thiscall', None, ret='eax', gen=_g64a6f0)
