"""specs_s34088.py - five call wrappers; every callee is a recorder (this recorded)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _t57db40(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5626c0, 0, this=True, pop=0, ret=r.getrandbits(32))
    hook_rec(c, 0x57dd10, 1, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x40), r.getrandbits(32)]


def _t511930(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4690b0, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x100), r.getrandbits(32)]


def _g5e4680(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5e3e90, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x380)]


def _g517030(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x516b60, 3, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x40), r.getrandbits(32), r.getrandbits(32)]


def _g5d4750(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x7003b8, rnd(c, 0x20))
    hook_rec(c, 0x589c20, 1, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x70)]


S(0x57db40, 'GUESS call then tail 0x57dd10', 'thiscall', None, ret='eax', gen=_t57db40, note='batch34088')
S(0x511930, 'GUESS release two sub-objects', 'thiscall', None, ret='eax', gen=_t511930, note='batch34088')
S(0x5e4680, 'GUESS call then set flags', 'thiscall', None, ret=None, gen=_g5e4680, note='batch34088')
S(0x517030, 'GUESS forward with member', 'thiscall', None, ret='eax', gen=_g517030, note='batch34088')
S(0x5d4750, 'GUESS cache engine lookup', 'thiscall', None, ret='eax', gen=_g5d4750, note='batch34088')
