"""specs_s210000.py - Sonnet-w3a: jmp thunks; the target is hooked (call count, ECX, order compared, random return)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

def g45b900(c):
    clear_hooks(c)
    hook_rec(c, 0x45c180, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x45b900, 'thunk_45c180', 'thiscall', None, ret='eax', gen=g45b900, note='batch210000')

def g472ff0(c):
    clear_hooks(c)
    hook_rec(c, 0x466040, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x472ff0, 'thunk_466040', 'thiscall', None, ret='eax', gen=g472ff0, note='batch210000')

def g480010(c):
    clear_hooks(c)
    hook_rec(c, 0x4805a0, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x480010, 'thunk_4805a0', 'thiscall', None, ret='eax', gen=g480010, note='batch210000')

def g4ba1f0(c):
    clear_hooks(c)
    hook_rec(c, 0x4ba310, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x4ba1f0, 'thunk_4ba310', 'thiscall', None, ret='eax', gen=g4ba1f0, note='batch210000')

def g513500(c):
    clear_hooks(c)
    hook_rec(c, 0x5124d0, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x513500, 'thunk_5124d0', 'thiscall', None, ret='eax', gen=g513500, note='batch210000')

def g515620(c):
    clear_hooks(c)
    hook_rec(c, 0x5124c0, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x515620, 'thunk_5124c0', 'thiscall', None, ret='eax', gen=g515620, note='batch210000')

def g5626c0(c):
    clear_hooks(c)
    hook_rec(c, 0x562750, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x5626c0, 'thunk_562750', 'thiscall', None, ret='eax', gen=g5626c0, note='batch210000')

def g573da0(c):
    clear_hooks(c)
    hook_rec(c, 0x573dd0, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x573da0, 'thunk_573dd0', 'thiscall', None, ret='eax', gen=g573da0, note='batch210000')

def g5b6cf0(c):
    clear_hooks(c)
    hook_rec(c, 0x5b6d00, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x5b6cf0, 'thunk_5b6d00', 'thiscall', None, ret='eax', gen=g5b6cf0, note='batch210000')

def g5b8330(c):
    clear_hooks(c)
    hook_rec(c, 0x5b8020, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x5b8330, 'thunk_5b8020', 'thiscall', None, ret='eax', gen=g5b8330, note='batch210000')

def g5bd960(c):
    clear_hooks(c)
    hook_rec(c, 0x5bd8e0, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x5bd960, 'thunk_5bd8e0', 'thiscall', None, ret='eax', gen=g5bd960, note='batch210000')

def g5bf930(c):
    clear_hooks(c)
    hook_rec(c, 0x5bf940, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x5bf930, 'thunk_5bf940', 'thiscall', None, ret='eax', gen=g5bf930, note='batch210000')

def g5fb5a0(c):
    clear_hooks(c)
    hook_rec(c, 0x5fd170, 0, ret=c.rng.getrandbits(32), this=True)
    return [rnd(c, 0x80)]

S(0x5fb5a0, 'thunk_5fd170', 'thiscall', None, ret='eax', gen=g5fb5a0, note='batch210000')
