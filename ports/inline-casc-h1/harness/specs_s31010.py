"""specs_s31010.py - batch 31010: frame setup tail-jumps."""
from pilot import S
from recruits_util import clear_hooks, hook_rec

def _g468310(c):
    # cdecl, frame setup + tail-jump to 0x4702b0
    clear_hooks(c)
    hook_rec(c, 0x4702b0, 0)
    return []

def _g472450(c):
    # cdecl, frame setup + tail-jump to 0x465870
    clear_hooks(c)
    hook_rec(c, 0x465870, 0)
    return []

def _g4bf4b0(c):
    # cdecl, frame setup + tail-jump to 0x4c0e20
    clear_hooks(c)
    hook_rec(c, 0x4c0e20, 0)
    return []

def _g4bf4f0(c):
    # cdecl, frame setup + tail-jump to 0x4c18b0
    clear_hooks(c)
    hook_rec(c, 0x4c18b0, 0)
    return []

S(0x468310, 'frame_jump_4702b0', 'cdecl', None, ret=None, gen=_g468310)
S(0x472450, 'frame_jump_465870', 'cdecl', None, ret=None, gen=_g472450)
S(0x4bf4b0, 'frame_jump_4c0e20', 'cdecl', None, ret=None, gen=_g4bf4b0)
S(0x4bf4f0, 'frame_jump_4c18b0', 'cdecl', None, ret=None, gen=_g4bf4f0)
