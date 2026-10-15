"""specs_s31072.py - Sonnet h1 batch 31072: tier B destructors, constructors, lookups."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def _dtor(c):
    clear_hooks(c)
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0)
    return [rnd(c, 0x40), c.rng.choice([0, 1, 2, 3, r32(c)])]


def _ctor(c):
    clear_hooks(c)
    j = r32(c)
    hook_rec(c, 0x469870, 0, ret=r32(c), pop=0, this=True, side=lambda emu, k: emu.mu.reg_write(REGS['ecx'], j))
    me = rnd(c, 0x60)
    return [me]


def _lookup_block(c, word):
    blk = rnd(c, 0x10)
    c.emu.w32(blk, word)
    hook_rec(c, 0x5003d0, 1, ret=blk, pop=4, this=True)


def _arg_obj(c):
    arg = rnd(c, 0x20)
    c.emu.w32(arg + 4, rnd(c, 0x20))
    return arg


def g55c8e0(c):
    clear_hooks(c)
    _lookup_block(c, c.rng.choice([0, 1, 0x10000, r32(c)]))
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, rnd(c, 0x940))
    return [me, _arg_obj(c)]


def g55c7a0(c):
    clear_hooks(c)
    _lookup_block(c, r32(c))
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, obj(c, 0x40, {0x6ac: pystub(c, 1, ret=r32(c), this=True)}))
    return [me, _arg_obj(c)]


def g4ea280(c):
    clear_hooks(c)
    scratch = c.emu.alloc(8, 4)
    hook_rec(c, 0x43e920, 1, ret=r32(c), pop=4, this=True,
             side=lambda emu, k: emu.w32(scratch, emu.reg('edx')))
    hook_rec(c, 0x441a60, 0, ret=r32(c), pop=0, this=True,
             side=lambda emu, k: emu.w32(scratch + 4, emu.reg('edx')))
    return [rnd(c, 0x60), r32(c), r32(c)]


S(0x5493f0, 'GUESS vtable 6a3298, optional delete 0x2326', 'thiscall', None, ret='eax', gen=_dtor, note='batch31072')
S(0x5ab4c0, 'GUESS vtable 6b01dc, optional delete 4', 'thiscall', None, ret='eax', gen=_dtor, note='batch31072')
S(0x5b7580, 'GUESS ctor base 469870, vtable 6b2304', 'thiscall', None, ret='eax', gen=_ctor, note='batch31072')
S(0x5bc4b0, 'GUESS ctor base 469870, vtable 6b2f30', 'thiscall', None, ret='eax', gen=_ctor, note='batch31072')
S(0x5c7ac0, 'GUESS ctor base 469870, vtable 6b47b0', 'thiscall', None, ret='eax', gen=_ctor, note='batch31072')
S(0x55c8e0, 'GUESS flag byte from 5003d0 lookup', 'thiscall', None, ret='eax', gen=g55c8e0, note='batch31072')
S(0x55c7a0, 'GUESS pass looked-up word to member vtable slot 0x6ac', 'thiscall', None, ret='eax', gen=g55c7a0, note='batch31072')
S(0x4ea280, 'GUESS call 43e920 and 441a60 with EDX args', 'thiscall', None, ret='eax', gen=g4ea280, note='batch31072')
