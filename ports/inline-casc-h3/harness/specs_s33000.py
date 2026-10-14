"""specs_s33000.py - cascade h3 batch 33000: four small 2-instruction thiscall functions.
Tail-jump targets hooked (0x43de70, 0x465660); self objects sized 0x200; member offsets filled with random."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x200):
    return rnd(c, n)


def _g445e70(c):
    """Read member at offset 0x192."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)  # assert hook
    return [_me(c)]


def _g45b4d0(c):
    """Set self[0]=vtable, then tail jump."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x43de70, 0, this=True)
    return [_me(c)]


def _g466620(c):
    """Bitwise OR on member at offset 0x136."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


def _g468080(c):
    """Set self[0]=vtable, then tail jump."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x465660, 0, this=True)
    return [_me(c)]


S(0x445e70, 'member_at_192', 'thiscall', None, ret='eax', gen=_g445e70)
S(0x45b4d0, 'vtable_setter_0', 'thiscall', None, ret=None, gen=_g45b4d0)
S(0x466620, 'bitwise_or_136', 'thiscall', None, ret=None, gen=_g466620)
S(0x468080, 'vtable_setter_1', 'thiscall', None, ret=None, gen=_g468080)
