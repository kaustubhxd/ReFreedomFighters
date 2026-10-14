"""specs_s33015.py - cascade h3 tier B batch 33015: four 6-instruction functions, mostly parameter setters."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x200):
    return rnd(c, n)


def _g6461c0(c):
    """Load from offset, tail jump."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x641c90, 0, this=True)
    return [_me(c)]


def _g446780(c):
    """Stdcall parameter setter (stdcall ret 4)."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c), c.rng.getrandbits(32)]


def _g4682d0(c):
    """Stdcall parameter setter (stdcall ret 4)."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c), c.rng.getrandbits(32)]


def _g470c80(c):
    """Stdcall parameter setter (stdcall ret 4)."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    return [_me(c), c.rng.getrandbits(32)]


S(0x6461c0, 'load_offset_291_jmp', 'thiscall', None, ret=None, gen=_g6461c0)
S(0x446780, 'stdcall_set_0x6c', 'stdcall', None, ret=None, gen=_g446780)
S(0x4682d0, 'stdcall_set_0x1d6', 'stdcall', None, ret=None, gen=_g4682d0)
S(0x470c80, 'stdcall_set_0x64', 'stdcall', None, ret=None, gen=_g470c80)
