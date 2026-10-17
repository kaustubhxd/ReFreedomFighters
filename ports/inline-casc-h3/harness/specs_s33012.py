"""specs_s33012.py - cascade h3 tier B batch 33012: three thunks and one complex read/write/subtract."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, sysobj


def _me(c, n=0x200):
    return rnd(c, n)


def _g563500(c):
    """Read global, copy from +0x6c to +0x70."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    so = sysobj(c)
    global_buf = obj(c, 0x74, {0x6c: c.rng.getrandbits(32)})
    c.emu.w32(0x7003a0, global_buf)
    return [_me(c)]


def _g5827a0(c):
    """Thunk wrapper."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x584bc0, 0, this=True)
    return [_me(c)]


def _g5c1640(c):
    """Thunk wrapper."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x5c1dc0, 0, this=True)
    return [_me(c)]


def _g65f5d0(c):
    """Read pointer from self, then subtract two large offset values."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    buf = obj(c, 0x1006d, {0x10069: c.rng.getrandbits(32), 0x10061: c.rng.getrandbits(32)})
    me = obj(c, 0x10, {0xc: buf})
    return [me]


S(0x563500, 'copy_global_6c_to_70', 'thiscall', None, ret=None, gen=_g563500)
S(0x5827a0, 'thunk_584bc0', 'thiscall', None, ret=None, gen=_g5827a0)
S(0x5c1640, 'thunk_5c1dc0', 'thiscall', None, ret=None, gen=_g5c1640)
S(0x65f5d0, 'subtract_offsets', 'thiscall', None, ret='eax', gen=_g65f5d0)
