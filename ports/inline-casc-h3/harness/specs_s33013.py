"""specs_s33013.py - cascade h3 tier B batch 33013: four thunks with wrapper logic."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _me(c, n=0x200):
    return rnd(c, n)


def _g45edd0(c):
    """Load pointer from offset 8, then tail jump."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x4db1f0, 0, this=True)
    return [_me(c)]


def _g45f050(c):
    """Load pointer from offset 8, then tail jump."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x4db6c0, 0, this=True)
    return [_me(c)]


def _g45faf0(c):
    """Read vtable pointer, then call through slot 0x128."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    vt = obj(c, 0x130, {0x128: pystub(c, 0, this=True)})
    me = obj(c, 0x10, {0: vt})
    return [me]


def _g463930(c):
    """Read vtable pointer, then call through slot 0x7c."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    vt = obj(c, 0x80, {0x7c: pystub(c, 0, this=True)})
    me = obj(c, 0x10, {0: vt})
    return [me]


S(0x45edd0, 'load_offset_8_jmp', 'thiscall', None, ret=None, gen=_g45edd0)
S(0x45f050, 'load_offset_8_jmp_2', 'thiscall', None, ret=None, gen=_g45f050)
S(0x45faf0, 'vtable_call_128', 'thiscall', None, ret=None, gen=_g45faf0)
S(0x463930, 'vtable_call_7c', 'thiscall', None, ret=None, gen=_g463930)
