"""specs_s33010.py - cascade h3 tier B batch 33010: four simple thunk wrapper functions."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x200):
    return rnd(c, n)


def _g468310(c):
    """Thunk wrapper."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x4702b0, 0, this=True)
    return [_me(c)]


def _g49e670(c):
    """Thunk wrapper."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x4bb7c0, 0, this=True)
    return [_me(c)]


def _g4bf4c0(c):
    """Thunk wrapper."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x4c1060, 0, this=True)
    return [_me(c)]


def _g4c4df0(c):
    """Thunk wrapper."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x4c4e90, 0, this=True)
    return [_me(c)]


S(0x468310, 'thunk_4702b0', 'thiscall', None, ret=None, gen=_g468310)
S(0x49e670, 'thunk_4bb7c0', 'thiscall', None, ret=None, gen=_g49e670)
S(0x4bf4c0, 'thunk_4c1060', 'thiscall', None, ret=None, gen=_g4bf4c0)
S(0x4c4df0, 'thunk_4c4e90', 'thiscall', None, ret=None, gen=_g4c4df0)
