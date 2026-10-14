"""specs_s33004.py - cascade h3 batch 33004: four small 2-instruction thiscall functions."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x200):
    return rnd(c, n)


def _g4f22b0(c):
    """Read dword member at offset 0x1db."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g4f4d20(c):
    """Read byte member at offset 0x88."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g4f9f30(c):
    """Read dword member at offset 0x68."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g506360(c):
    """Set vtable, then tail jump."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x504870, 0, this=True)
    return [_me(c)]


S(0x4f22b0, 'member_0x1db', 'thiscall', None, ret='eax', gen=_g4f22b0)
S(0x4f4d20, 'member_byte_0x88', 'thiscall', None, ret='al', gen=_g4f4d20)
S(0x4f9f30, 'member_0x68', 'thiscall', None, ret='eax', gen=_g4f9f30)
S(0x506360, 'vtable_setter_2', 'thiscall', None, ret=None, gen=_g506360)
