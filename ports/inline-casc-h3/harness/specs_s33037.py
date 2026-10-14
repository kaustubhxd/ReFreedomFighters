"""specs_s33037.py - h3 batch 33037: four tier B call+or+init patterns."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x80):
    return rnd(c, n)


def _g_init(c):
    clear_hooks(c)
    hook_rec(c, 0x469870, 0, this=True)
    return [_me(c, 0x100)]


S(0x5bbc00, 'GUESS call + OR flag + vtable set', 'thiscall', None, ret='eax', gen=_g_init, note='batch33037')
S(0x5c5a40, 'GUESS call + OR flag + vtable set', 'thiscall', None, ret='eax', gen=_g_init, note='batch33037')
S(0x5d5570, 'GUESS call + OR flag + vtable set', 'thiscall', None, ret='eax', gen=_g_init, note='batch33037')
S(0x5dac20, 'GUESS call + OR flag + vtable set', 'thiscall', None, ret='eax', gen=_g_init, note='batch33037')
