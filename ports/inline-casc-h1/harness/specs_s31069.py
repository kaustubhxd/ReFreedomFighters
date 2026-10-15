"""specs_s31069.py - Sonnet h1 batch 31069: tier B call-through thunks."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def _clobber(j):
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def _call_tail(first, second):
    def g(c):
        clear_hooks(c)
        hook_rec(c, first, 0, ret=r32(c), pop=0, this=True, side=_clobber(r32(c)))
        hook_rec(c, second, 2, ret=r32(c), pop=0, this=True)
        return [rnd(c, 0x40), r32(c), r32(c)]
    return g


def g4dd8f0(c):
    clear_hooks(c)
    scratch = c.emu.alloc(4, 4)
    hook_rec(c, 0x4419f0, 0, ret=r32(c), pop=0, this=True,
             side=lambda emu, k: emu.w32(scratch, emu.reg('edx')))     # records EDX too
    return [rnd(c, 0x40), r32(c)]


def g5f40a0(c):
    clear_hooks(c)
    c.emu.w32(0x724270, obj(c, 0x80, {0x44: pystub(c, 2, ret=r32(c), this=True)}))
    return [rnd(c, 0x40), r32(c), r32(c)]


def g4c59f0(c):
    clear_hooks(c)
    hook_rec(c, 0x4e6330, 1, ret=r32(c), pop=4, this=True)
    return [rnd(c, 0x80), r32(c)]


def g569410(c):
    clear_hooks(c)
    hook_rec(c, 0x610100, 1, ret=r32(c), pop=4)
    hook_rec(c, 0x4e5e60, 0, ret=r32(c), pop=0, this=True)
    return [rnd(c, 0x40), r32(c)]


def g642120(c):
    clear_hooks(c)
    hook_rec(c, 0x545c80, 2, ret=r32(c), pop=8, this=True)
    me = rnd(c, 0x200)
    c.emu.w32(me + 0x17f, rnd(c, 0x20))
    return [me, r32(c), r32(c)]


def g45f3a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dc630, 2, ret=r32(c), pop=8, this=True)
    inner = rnd(c, 0x80)
    if r.random() < 0.6:
        c.emu.w32(inner + 0x3c, c.emu.r32(inner + 0x3c) | r.choice([0x40000000, 0x40000, 0x40040000]))
    else:
        c.emu.w32(inner + 0x3c, c.emu.r32(inner + 0x3c) & ~0x40040000)
    c.emu.w32(inner + 0x68, r.choice([0, 0, r32(c)]))
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, inner)
    return [me]


def g4dae40(c):
    clear_hooks(c)
    hook_rec(c, 0x4da1d0, 1, ret=r32(c), pop=4, this=True, side=_clobber(r32(c)))
    hook_rec(c, 0x4d96d0, 1, ret=r32(c), pop=4, this=True)
    return [rnd(c, 0x40)]


def g533cc0(c):
    clear_hooks(c)
    blk = rnd(c, 0x40)
    val = c.rng.choice([0, blk])
    hook_rec(c, 0x41e290, 1, ret=val, pop=0)
    hook_rec(c, 0x5328b0, 2, ret=r32(c), pop=0, this=True)
    return [r32(c), r32(c)]


def g42f880(c):
    clear_hooks(c)
    hook_rec(c, 0x42abee, 3, ret=r32(c), pop=0, deref={2: 1})
    return [r32(c), r32(c), r32(c), r32(c)]


S(0x57f400, 'GUESS call 562440 then tail 57f420', 'thiscall', None, ret='eax', gen=_call_tail(0x562440, 0x57f420), note='batch31069')
S(0x60ed60, 'GUESS call 60d610 then tail 608330', 'thiscall', None, ret='eax', gen=_call_tail(0x60d610, 0x608330), note='batch31069')
S(0x4dd8f0, 'GUESS swap this/arg into ECX/EDX, call 4419f0', 'thiscall', None, ret='eax', gen=g4dd8f0, note='batch31069')
S(0x5f40a0, 'GUESS global object vtable tail slot 0x44', 'thiscall', None, ret='eax', gen=g5f40a0, note='batch31069')
S(0x4c59f0, 'GUESS call 4e6330 with this+0x48', 'thiscall', None, ret='eax', gen=g4c59f0, note='batch31069')
S(0x569410, 'GUESS call 610100 then 4e5e60', 'thiscall', None, ret='eax', gen=g569410, note='batch31069')
S(0x642120, 'GUESS call 545c80 on this->[0x17f]', 'thiscall', None, ret='eax', gen=g642120, note='batch31069')
S(0x45f3a0, 'GUESS conditional call 4dc630', 'thiscall', None, ret='eax', gen=g45f3a0, note='batch31069')
S(0x4dae40, 'GUESS call 4da1d0 and 4d96d0', 'thiscall', None, ret='eax', gen=g4dae40, note='batch31069')
S(0x533cc0, 'GUESS alloc 0x548e then construct', 'thiscall', None, ret='eax', gen=g533cc0, note='batch31069')
S(0x42f880, 'GUESS forward varargs to 42abee', 'cdecl', None, ret='eax', gen=g42f880, note='batch31069')
