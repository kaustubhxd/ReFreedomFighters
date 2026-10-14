"""specs_s31017.py - batch 31017: bool compare, global chains, array indexing."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj

def _g465850(c):
    clear_hooks(c)
    val = c.rng.choice([0x465710, 0x465700, 0x465720, c.rng.getrandbits(32)])
    return [val]

def _g48f460(c):
    clear_hooks(c)
    return []

def _g512f80(c):
    clear_hooks(c)
    hook_rec(c, 0x512f80, 0)
    o = obj(c, 0x300, {0x12f: 0x1234})
    return [o]

def _g537090(c):
    clear_hooks(c)
    o = obj(c, 0x8000, {})
    idx = c.rng.choice([0, 1, 2, c.rng.randint(0, 20)])
    return [o, idx]

S(0x465850, 'compare_const_bool', 'stdcall', None, ret='al', gen=_g465850)
S(0x48f460, 'global_chain_cond_jmp', 'cdecl', None, ret=None, gen=_g48f460)
S(0x512f80, 'global_chain_cond_read', 'cdecl', None, ret='eax', gen=_g512f80)
S(0x537090, 'array_idx_complex_offset', 'stdcall', None, ret='eax', gen=_g537090)
