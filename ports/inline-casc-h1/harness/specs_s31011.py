"""specs_s31011.py - batch 31011: frame jumps and conditional jump."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj

def _g4e11d0(c):
    clear_hooks(c)
    hook_rec(c, 0x4e1110, 0)
    return []

def _g4fc130(c):
    clear_hooks(c)
    hook_rec(c, 0x4fd510, 0)
    return []

def _g513180(c):
    clear_hooks(c)
    hook_rec(c, 0x45f070, 0)
    return []

def _g536260(c):
    clear_hooks(c)
    hook_rec(c, 0x53b100, 0, this=True)
    # Use specific test values to ensure both branches are tested
    val = c.rng.choice([0, 1, 2, 0x100, 0xffffffff, c.rng.getrandbits(32)])
    o = obj(c, 0x5300, {0x52fa: val})
    return [o]

S(0x4e11d0, 'frame_jump_4e1110', 'cdecl', None, ret=None, gen=_g4e11d0)
S(0x4fc130, 'frame_jump_4fd510', 'cdecl', None, ret=None, gen=_g4fc130)
S(0x513180, 'frame_jump_45f070', 'cdecl', None, ret=None, gen=_g513180)
S(0x536260, 'load_test_jump', 'thiscall', None, ret=None, gen=_g536260)
