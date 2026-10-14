"""specs_s33002.py - cascade h3 batch 33002: four small 2-instruction thiscall functions with vtable lookup."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _me(c, n=0x200):
    return rnd(c, n)


def _g46eda0(c):
    """Read dword member at offset 0xba."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g46eee0(c):
    """Read dword member at offset 0x70."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


S(0x46eda0, 'member_0xba', 'thiscall', None, ret='eax', gen=_g46eda0)
S(0x46eee0, 'member_0x70', 'thiscall', None, ret='eax', gen=_g46eee0)
