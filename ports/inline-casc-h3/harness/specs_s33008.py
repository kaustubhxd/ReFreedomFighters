"""specs_s33008.py - cascade h3 batch 33008: one small 2-instruction setter function."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _me(c, n=0x200):
    return rnd(c, n)


def _g655a70(c):
    """Write dword at offset 0."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c)]


S(0x655a70, 'write_dword_0x6c3be4', 'thiscall', None, ret=None, gen=_g655a70)
