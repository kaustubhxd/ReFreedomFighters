"""specs_s34104.py - seven call wrappers; callees are recorders (this recorded)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g5cd580(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5cd7f0, 4, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0xe00)
    c.emu.wbytes(me + 0xdd8, bytes([r.choice([0, 1, 5])]))
    return [me]


def _g65a380(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x659070, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x20)]


def _g4d3810(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x20)
    hook_rec(c, 0x4d2b40, 2, this=True, ret=lambda em, k: 0 if r.random() < 0.3 else blk)
    return [rnd(c, 0x20), r.getrandbits(32), r.getrandbits(32)]


def _g5589e0(c):
    clear_hooks(c)
    r = c.rng
    cell = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=cell)
    hook_rec(c, 0x59e650, 1, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x30)
    return [me, rnd(c, 0x20)]


def _g5cfee0(c):
    clear_hooks(c)
    return [rnd(c, 0xcb0), rnd(c, 0x40), rnd(c, 0x20)]


def _dtor(callee, sizeok=True):
    def g(c):
        clear_hooks(c)
        r = c.rng
        if callee:
            hook_rec(c, callee, 0, this=True, pop=0, ret=r.getrandbits(32))
        hook_rec(c, 0x634273, 2, pop=0)
        return [rnd(c, 0x40), r.choice([0, 1, 2, 3, r.getrandbits(32)])]
    return g


S(0x5cd580, 'GUESS clear flags and call', 'thiscall', None, ret=None, gen=_g5cd580, note='batch34104')
S(0x65a380, 'GUESS constructor with base', 'thiscall', None, ret='eax', gen=_g65a380, note='batch34104')
S(0x4d3810, 'GUESS find and clear flag byte', 'thiscall', None, ret='al', gen=_g4d3810, note='batch34104')
S(0x5589e0, 'GUESS forward cell value', 'thiscall', None, ret='eax', gen=_g5589e0, note='batch34104')
S(0x5cfee0, 'GUESS read vector and copy block', 'thiscall', None, ret='eax', gen=_g5cfee0, note='batch34104')
S(0x485f30, 'GUESS scalar deleting destructor E', 'thiscall', None, ret='eax', gen=_dtor(None), note='batch34104')
S(0x4d5730, 'GUESS scalar deleting destructor F', 'thiscall', None, ret='eax', gen=_dtor(0x4d5580), note='batch34104')
