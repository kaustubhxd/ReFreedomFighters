"""specs_s34090.py - five call wrappers; callees are recorders (this recorded); 0x4d2700 may rewrite the argument slot it is given the address of."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec
from unicorn.x86_const import UC_X86_REG_ECX


def _g5d3640(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5d3520, 0, this=True, pop=0, ret=r.getrandbits(32), side=lambda em, k: em.mu.reg_write(UC_X86_REG_ECX, r.getrandbits(32)))
    hook_rec(c, 0x5d3780, 0, this=True, pop=0, ret=r.getrandbits(32))
    me = rnd(c, 0x60)
    c.emu.wbytes(me + 0x54, bytes([r.choice([0, 1, 5])]))
    return [me]


def _g497390(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x497320, 1, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x20), 0 if r.random() < 0.25 else rnd(c, 0x20)]


def _g4d3ad0(c):
    clear_hooks(c)
    r = c.rng

    def side(em, k):
        if r.random() < 0.5:
            em.w32(em.arg32(3), r.getrandbits(32))
    hook_rec(c, 0x4d2700, 5, this=True, ret=r.getrandbits(32), deref={3: 1}, side=side)
    return [rnd(c, 0x20), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g5273b0(c):
    clear_hooks(c)
    hook_rec(c, 0x526ef0, 0, this=True, pop=0)
    return [rnd(c, 0x40)]


def _g602240(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x20)
    c.emu.wbytes(me + 0x14, bytes([r.choice([0, 0, 1, 7])]))
    if r.random() < 0.3:
        c.emu.w32(me + 4, 0)
    return [me]


S(0x5d3640, 'GUESS call then conditional tail', 'thiscall', None, ret='eax', gen=_g5d3640, note='batch34090')
S(0x497390, 'GUESS forward member value', 'thiscall', None, ret='eax', gen=_g497390, note='batch34090')
S(0x4d3ad0, 'GUESS forward with constants and slot address', 'thiscall', None, ret='eax', gen=_g4d3ad0, note='batch34090')
S(0x5273b0, 'GUESS constructor with sub-object', 'thiscall', None, ret='eax', gen=_g5273b0, note='batch34090')
S(0x602240, 'GUESS release buffer unless owned', 'thiscall', None, ret=None, gen=_g602240, note='batch34090')
