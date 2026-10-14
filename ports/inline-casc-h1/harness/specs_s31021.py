"""specs_s31021.py - batch 31021: final batch."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj

def _g61c5c0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]

def _g45e900(c):
    clear_hooks(c)
    o = obj(c, 0x200, {0x14: 0})
    val = c.rng.choice([0, 1, 0xff])
    return [o, val]

def _g524660(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    return [o]

def _g59a8d0(c):
    clear_hooks(c)
    hook_rec(c, 0x59a8d0, 0)
    inner = obj(c, 0x100, {})
    o = obj(c, 0x4000, {0x1d0f: inner})
    return [o]

S(0x61c5c0, 'set_two_34_38', 'thiscall', None, ret=None, gen=_g61c5c0)
S(0x45e900, 'cond_or_flag_10', 'thiscall', None, ret=None, gen=_g45e900)
S(0x524660, 'zero_fill_multi', 'thiscall', None, ret=None, gen=_g524660)
S(0x59a8d0, 'load_cond_jmp', 'thiscall', None, ret=None, gen=_g59a8d0)
