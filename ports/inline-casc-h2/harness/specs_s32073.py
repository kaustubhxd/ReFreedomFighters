"""specs_s32073.py - h2 () batch 32073: 0x57c910, 0x45b3a0. Callees hooked as recorders (0x634d10 cdecl)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g57c910(c):
    clear_hooks(c)
    hook_rec(c, 0x4cbee0, 1, this=True, pop=4)
    return [rnd(c, 0xc0), rnd(c, 0xc0)]


def g45b3a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43de40, 3, this=True, pop=12)
    hook_rec(c, 0x634d10, 3, pop=0)
    return [rnd(c, 0x960), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x57c910, 'GUESS copy-assign fields 0x80..0xb3', 'thiscall', None, ret='eax', gen=g57c910, note='batch32073')
S(0x45b3a0, 'GUESS init object with memset', 'thiscall', None, ret='eax', gen=g45b3a0, note='batch32073')
