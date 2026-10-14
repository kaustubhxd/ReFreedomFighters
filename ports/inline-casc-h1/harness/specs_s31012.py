"""specs_s31012.py - batch 31012: frame jumps and indirect jump."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj

def _g565a30(c):
    clear_hooks(c)
    hook_rec(c, 0x57f350, 0)
    return []

def _g5a7550(c):
    clear_hooks(c)
    hook_rec(c, 0x5a76c0, 0)
    return []

def _g5f0160(c):
    clear_hooks(c)
    hook_rec(c, 0x5ed0b0, 0)
    return []

def _g45d5b0(c):
    clear_hooks(c)
    o = obj(c, 0x100, {})
    return [o]

S(0x565a30, 'frame_jump_57f350', 'cdecl', None, ret=None, gen=_g565a30)
S(0x5a7550, 'frame_jump_5a76c0', 'cdecl', None, ret=None, gen=_g5a7550)
S(0x5f0160, 'frame_jump_5ed0b0', 'cdecl', None, ret=None, gen=_g5f0160)
S(0x45d5b0, 'indirect_jump_48', 'thiscall', None, ret=None, gen=_g45d5b0)
