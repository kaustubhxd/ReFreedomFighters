"""specs_s34092.py - six wrappers; callees are recorders (this recorded)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _cell(c, r, vals):
    cell = rnd(c, 0x10)
    c.emu.w32(cell, r.choice(vals))
    hook_rec(c, 0x5003d0, 1, this=True, ret=cell)


def _g55c770(c):
    clear_hooks(c)
    r = c.rng
    _cell(c, r, [0, 1, r.getrandbits(32)])
    me = rnd(c, 0x30)
    c.emu.w32(me + 0x1c, rnd(c, 0x950))
    return [me, rnd(c, 0x20)]


def _g534d80(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x53b1b0, 1, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x5300)
    c.emu.wbytes(me + 0x52fa, (0 if r.random() < 0.3 else rnd(c, 0x20)).to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


def _dtor(callee, ext=True):
    def g(c):
        clear_hooks(c)
        r = c.rng
        if callee:
            hook_rec(c, callee, 0, this=True, pop=0)
        hook_rec(c, 0x634273, 2, pop=0)
        return [rnd(c, 0x40), r.choice([0, 1, 2, 3, r.getrandbits(32)])]
    return g


def _g51ab40(c):
    clear_hooks(c)
    r = c.rng
    _cell(c, r, [0, 1, r.getrandbits(32)])
    me = rnd(c, 0x30)
    c.emu.w32(me + 0x18, rnd(c, 0x2d0))
    return [me, rnd(c, 0x20)]


S(0x55c770, 'GUESS copy cell value', 'thiscall', None, ret='eax', gen=_g55c770, note='batch34092')
S(0x534d80, 'GUESS forward to member', 'thiscall', None, ret='eax', gen=_g534d80, note='batch34092')
S(0x48ab70, 'GUESS scalar deleting destructor A', 'thiscall', None, ret='eax', gen=_dtor(0x48a880), note='batch34092')
S(0x4e5050, 'GUESS scalar deleting destructor B', 'thiscall', None, ret='eax', gen=_dtor(None), note='batch34092')
S(0x51ab40, 'GUESS store cell flag', 'thiscall', None, ret='eax', gen=_g51ab40, note='batch34092')
S(0x534d00, 'GUESS scalar deleting destructor C', 'thiscall', None, ret='eax', gen=_dtor(0x534be0), note='batch34092')
