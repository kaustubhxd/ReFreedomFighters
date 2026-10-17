"""specs_s33014.py - cascade h3 tier B batch 33014: four 5-instruction functions with complex logic."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _me(c, n=0x200):
    return rnd(c, n)


def _g4673d0(c):
    """Read, write, clear bit, tail jump."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x4639f0, 0, this=True)
    return [_me(c)]


def _g47fb90(c):
    """Conditional vtable jump."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    r = c.rng
    if r.random() < 0.5:
        vt = obj(c, 0x20, {0x14: pystub(c, 0, this=True)})
        me = obj(c, 0x20, {0: vt, 4: 1})
    else:
        me = obj(c, 0x20, {4: 0})
    return [me]


def _g4bb2c0(c):
    """Chained reads and write."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    p2 = obj(c, 0x74, {0x70: c.rng.getrandbits(32)})
    p1 = obj(c, 0x20, {0x18: p2})
    me = obj(c, 0x50, {0x44: p1})
    return [me]


def _g535490(c):
    """Add offset, tail jump."""
    clear_hooks(c)
    hook_rec(c, 0x7003b0, 0, this=False)
    hook_rec(c, 0x533da0, 0, this=True)
    return [_me(c)]


S(0x4673d0, 'read_write_clear_bit', 'thiscall', None, ret=None, gen=_g4673d0)
S(0x47fb90, 'conditional_vtable_jump', 'thiscall', None, ret=None, gen=_g47fb90)
S(0x4bb2c0, 'chained_reads_write', 'thiscall', None, ret=None, gen=_g4bb2c0)
S(0x535490, 'add_offset_jmp', 'thiscall', None, ret=None, gen=_g535490)
