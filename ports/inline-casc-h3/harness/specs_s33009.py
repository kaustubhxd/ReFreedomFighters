"""specs_s33009.py - cascade h3 batch 33009: one simple 4-instruction bit extraction function."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x200):
    return rnd(c, n)


def _g45f8c0(c):
    """Read dword, shift right 5, mask bit 0."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


S(0x45f8c0, 'bit_extract_5_1', 'thiscall', None, ret='al', gen=_g45f8c0)
