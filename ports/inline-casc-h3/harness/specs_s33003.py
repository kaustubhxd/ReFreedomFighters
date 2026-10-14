"""specs_s33003.py - cascade h3 batch 33003: four small 2-instruction thiscall accessors."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, sysobj


def _me(c, n=0x200):
    return rnd(c, n)


def _g474310(c):
    """Read byte member at offset 0x3bb."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g4743e0(c):
    """Read dword member at offset 0x2e3."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g4744b0(c):
    """Read dword member at offset 0x3b7."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g4808c0(c):
    """Read dword from global address."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    so = sysobj(c)
    c.emu.w32(0x6e5ef8, c.rng.getrandbits(32))
    return [_me(c)]


S(0x474310, 'member_byte_0x3bb', 'thiscall', None, ret='al', gen=_g474310)
S(0x4743e0, 'member_0x2e3', 'thiscall', None, ret='eax', gen=_g4743e0)
S(0x4744b0, 'member_0x3b7', 'thiscall', None, ret='eax', gen=_g4744b0)
S(0x4808c0, 'global_0x6e5ef8', 'thiscall', None, ret='eax', gen=_g4808c0)
