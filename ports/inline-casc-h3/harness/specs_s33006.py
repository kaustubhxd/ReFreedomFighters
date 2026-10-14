"""specs_s33006.py - cascade h3 batch 33006: three small 2-instruction thiscall functions."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x200):
    return rnd(c, n)


def _g59b340(c):
    """Return pointer to offset within self."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g59ca40(c):
    """Return pointer to offset within self."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g600800(c):
    """Read dword member at offset 0x98."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


S(0x59b340, 'lea_0x121a8', 'thiscall', None, ret='eax', gen=_g59b340)
S(0x59ca40, 'lea_0x1210c', 'thiscall', None, ret='eax', gen=_g59ca40)
S(0x600800, 'member_0x98', 'thiscall', None, ret='eax', gen=_g600800)
