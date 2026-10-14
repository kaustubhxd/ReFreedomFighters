"""specs_s33035.py - h3 batch 33035: four tier B call+conditional patterns."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _me(c, n=0x80):
    return rnd(c, n)


def _g48ab70(c):
    clear_hooks(c)
    hook_rec(c, 0x48a880, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    me = obj(c, 0x200, {})
    return [me, c.rng.choice([0, 1, 2, 3])]


def _g4e5050(c):
    clear_hooks(c)
    hook_rec(c, 0x634273, 2, pop=0)
    me = obj(c, 0x200, {})
    return [me, c.rng.choice([0, 1, 2, 3])]


def _g51ab40(c):
    clear_hooks(c)
    hook_rec(c, 0x51ab90, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    me = obj(c, 0x200, {})
    return [me, c.rng.choice([0, 1, 2, 3])]


def _g534d00(c):
    clear_hooks(c)
    hook_rec(c, 0x534d50, 1, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    me = obj(c, 0x200, {})
    return [me, c.rng.choice([0, 1, 2, 3])]


S(0x48ab70, 'GUESS call + conditional call', 'thiscall', None, ret='eax', gen=_g48ab70, note='batch33035')
S(0x4e5050, 'GUESS vtable set + conditional call', 'thiscall', None, ret='eax', gen=_g4e5050, note='batch33035')
S(0x51ab40, 'GUESS call + conditional call 2', 'thiscall', None, ret='eax', gen=_g51ab40, note='batch33035')
S(0x534d00, 'GUESS call with arg + conditional call', 'thiscall', None, ret='eax', gen=_g534d00, note='batch33035')
