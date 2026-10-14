"""specs_s33001.py - cascade h3 batch 33001: four small 2-instruction read-only thiscall functions."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x200):
    return rnd(c, n)


def _g46e570(c):
    """Read byte member at offset 0xbf."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g46e6a0(c):
    """Read dword member at offset 0xa4."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g46e710(c):
    """Return constant."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g46e7f0(c):
    """Read dword member at offset 0x60."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


S(0x46e570, 'member_byte_0xbf', 'thiscall', None, ret='al', gen=_g46e570)
S(0x46e6a0, 'member_0xa4', 'thiscall', None, ret='eax', gen=_g46e6a0)
S(0x46e710, 'constant_0x6864f8', 'thiscall', None, ret='eax', gen=_g46e710)
S(0x46e7f0, 'member_0x60', 'thiscall', None, ret='eax', gen=_g46e7f0)
