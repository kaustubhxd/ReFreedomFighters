"""specs_s33032.py - h3 batch 33032: call wrappers (tier B)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

def _g4db2a0(c):
    clear_hooks(c)
    # Hook the external call - stdcall with 1 arg
    hook_rec(c, 0x4de420, 0, this=False)
    # Generate argument
    arg = c.rng.getrandbits(32)
    return [arg]

def _g466340(c):
    clear_hooks(c)
    # Hook both external calls - stdcall with 1 arg each
    hook_rec(c, 0x462040, 0, this=False)
    hook_rec(c, 0x4e1b30, 0, this=False)
    # Generate argument
    arg = c.rng.getrandbits(32)
    return [arg]

S(0x4db2a0, 'call_wrapper_1', 'stdcall', None, ret=None, gen=_g4db2a0)
S(0x466340, 'call_wrapper_2', 'stdcall', None, ret=None, gen=_g466340)
