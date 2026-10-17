"""specs_s33026.py - h3 batch 33026: call and return wrappers."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

def _me(c, n=0x100):
    return rnd(c, n)

def _g465650(c):
    clear_hooks(c)
    hook_rec(c, 0x466220, 0, this=True)
    return [_me(c)]

def _g576320(c):
    clear_hooks(c)
    hook_rec(c, 0x573db0, 0, this=True)
    return [_me(c)]

S(0x465650, 'call_return_this', 'thiscall', None, ret='eax', gen=_g465650)
S(0x576320, 'call_tailjump', 'thiscall', None, ret=None, gen=_g576320)
