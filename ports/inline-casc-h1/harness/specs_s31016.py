"""specs_s31016.py - batch 31016: setter, chained loads, global pointer."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj, sysobj

def _g639ba0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    val = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, val]

def _g64f850(c):
    clear_hooks(c)
    hook_rec(c, 0x64f850, 0)
    inner = obj(c, 0x100, {})
    o = obj(c, 0x200, {0xbd: inner})
    return [o]

def _g64fae0(c):
    clear_hooks(c)
    hook_rec(c, 0x64fae0, 0)
    inner = obj(c, 0x100, {})
    o = obj(c, 0x200, {0xbd: inner})
    return [o]

def _g445c50(c):
    clear_hooks(c)
    o = obj(c, 0x200, {0x18: 0})
    return [o]

S(0x639ba0, 'set_dword_24', 'thiscall', None, ret=None, gen=_g639ba0)
S(0x64f850, 'chained_load_jmp_4c', 'thiscall', None, ret=None, gen=_g64f850)
S(0x64fae0, 'cond_chained_load_jmp_c', 'thiscall', None, ret=None, gen=_g64fae0)
S(0x445c50, 'cond_read_global_chain', 'cdecl', None, ret=None, gen=_g445c50)
