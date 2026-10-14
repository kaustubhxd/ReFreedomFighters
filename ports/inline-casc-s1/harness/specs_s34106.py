"""specs_s34106.py - seven constructors / scalar deleting destructors; callees are recorders (this recorded)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _ctor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x469870, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x50)]


def _dtor(callee):
    def g(c):
        clear_hooks(c)
        r = c.rng
        if callee:
            hook_rec(c, callee, 0, this=True, pop=0, ret=r.getrandbits(32))
        hook_rec(c, 0x634273, 2, pop=0)
        return [rnd(c, 0x40), r.choice([0, 1, 2, 3, r.getrandbits(32)])]
    return g


S(0x5bdb00, 'GUESS constructor C', 'thiscall', None, ret='eax', gen=_ctor, note='batch34106')
S(0x5d38a0, 'GUESS constructor D', 'thiscall', None, ret='eax', gen=_ctor, note='batch34106')
S(0x5d6a40, 'GUESS constructor E', 'thiscall', None, ret='eax', gen=_ctor, note='batch34106')
S(0x5df7f0, 'GUESS scalar deleting destructor H', 'thiscall', None, ret='eax', gen=_dtor(None), note='batch34106')
S(0x5eaf50, 'GUESS scalar deleting destructor I', 'thiscall', None, ret='eax', gen=_dtor(None), note='batch34106')
S(0x636470, 'GUESS scalar deleting destructor J', 'thiscall', None, ret='eax', gen=_dtor(0x6363a0), note='batch34106')
S(0x4286b0, 'GUESS scalar deleting destructor K', 'thiscall', None, ret='eax', gen=_dtor(0x435b50), note='batch34106')
