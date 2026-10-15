"""specs_s33038.py - h3 (Sonnet) batch 33038: dtor shapes (hooked delete 0x634273, base dtor 0x602240) and bool combiner 0x4746d0."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _flags(c):
    return c.rng.getrandbits(32)


def _g_del(c):
    clear_hooks(c)
    hook_rec(c, 0x634273, 2, pop=0)
    return [rnd(c, 0x100), _flags(c)]


def _g_base(c):
    clear_hooks(c)
    hook_rec(c, 0x602240, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    return [rnd(c, 0x100), _flags(c)]


def _g_bool(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x466cd0, 0, this=True, ret=lambda e, k: r.choice([0, 1, 0x100, r.getrandbits(32)]))
    hook_rec(c, 0x467700, 0, this=True, ret=lambda e, k: r.choice([0, 1, 0x100, r.getrandbits(32)]))
    return [rnd(c, 0x300)]


S(0x5df820, 'GUESS scalar deleting dtor (0x15)', 'thiscall', None, ret='eax', gen=_g_del, note='batch33038')
S(0x655a80, 'GUESS scalar deleting dtor (4)', 'thiscall', None, ret='eax', gen=_g_del, note='batch33038')
S(0x5f1460, 'GUESS scalar deleting dtor w/ base (0x19)', 'thiscall', None, ret='eax', gen=_g_base, note='batch33038')
S(0x4746d0, 'GUESS bool a && !b', 'thiscall', None, ret='al', gen=_g_bool, note='batch33038')
