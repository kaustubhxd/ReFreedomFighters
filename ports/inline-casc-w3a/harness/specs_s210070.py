"""specs_s210070.py - Sonnet-w3a: 0x6038e0 (memset-style call on a global table, then clear a global) and 0x631840 (forward the second argument)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _r(c): return c.rng.getrandbits(32)


def g6038e0(c):
    clear_hooks(c)
    hook_rec(c, 0x634d10, 3, ret=_r(c), pop=0)
    c.emu.w32(0x724698, _r(c))
    return []


def g631840(c):
    clear_hooks(c)
    hook_rec(c, 0x63a700, 1, ret=_r(c), pop=0)
    return [_r(c), _r(c)]


S(0x6038e0, 'clear_global_table', 'cdecl', None, ret='eax', gen=g6038e0, note='batch210070')
S(0x631840, 'forward_second_arg', 'cdecl', None, ret='eax', gen=g631840, note='batch210070')
