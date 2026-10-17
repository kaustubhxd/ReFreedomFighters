"""specs_s31032.py - batch 31032: thunks with tail jumps."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj, pystub

def _g628ed0(c):
    clear_hooks(c)
    hook_rec(c, 0x622ad0, 0)  # Hook tail jump target (void return, stdcall has arg on stack)
    return [c.rng.choice([0, 1, 0x6be728, c.rng.getrandbits(32)])]

def _g5f23f0(c):
    clear_hooks(c)
    hook_rec(c, 0x5fd120, 0, this=True)  # Hook tail jump target (void return, thiscall)
    child_ptr = obj(c, 0x100, {4: c.rng.choice([0, c.rng.getrandbits(32)])})
    self_obj = obj(c, 0x200, {0xc: child_ptr})
    return [self_obj]

S(0x628ed0, 'arg_setter_jump', 'stdcall', None, ret=None, gen=_g628ed0)
