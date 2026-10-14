"""specs_s34110.py - seven items; callees are recorders (this recorded). 0x626ac0: hooked 0x628c10 returns -1 in a third (the exe's own name table is not used here)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec
from unicorn.x86_const import UC_X86_REG_ECX


def _g5d8880(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x41e2c0, 1, pop=0, ret=r.getrandbits(32))
    hook_rec(c, 0x634273, 2, pop=0, ret=r.getrandbits(32), side=lambda em, k: em.mu.reg_write(UC_X86_REG_ECX, r.getrandbits(32)))
    hook_rec(c, 0x43de70, 0, this=True, pop=0, ret=r.getrandbits(32))
    me = rnd(c, 0x40)
    if r.random() < 0.3:
        c.emu.w32(me + 0x20, 0)
    if r.random() < 0.3:
        c.emu.w32(me + 0x24, 0)
    return [me]


def _g626ac0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x628c10, 1, pop=0, ret=lambda em, k: r.choice([0xffffffff, 0xffffffff, 0, 1, 5, 0x100]))
    return [rnd(c, 0x60), rnd(c, 0x10), rnd(c, 0x10)]


def _ctor3(callee, nbytes):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, callee, 3, this=True, ret=r.getrandbits(32))
        return [rnd(c, nbytes), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]
    return g


def _g51eab0(c):
    clear_hooks(c)
    r = c.rng
    cell0 = rnd(c, 0x10)
    cell1 = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: (cell0, cell1)[min(k, 1)])
    me = rnd(c, 0x30)
    c.emu.w32(me + 0x18, rnd(c, 0x240))
    return [me, rnd(c, 0x20)]


def _g5f4d80(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5ffd70, 2, this=True, ret=lambda em, k: r.choice([0xffffffff, 0xffffffff, 0, 1, 7]))
    hook_rec(c, 0x5f5620, 1, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0xb0), r.getrandbits(32)]


def _g4eb350(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e8bd0, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x1c0), r.getrandbits(32)]


S(0x5d8880, 'GUESS release two buffers then tail', 'thiscall', None, ret='eax', gen=_g5d8880, note='batch34110')
S(0x626ac0, 'GUESS bind handler by name', 'cdecl', None, ret='eax', gen=_g626ac0, note='batch34110')
S(0x4764b0, 'GUESS constructor with base args 4', 'thiscall', None, ret='eax', gen=_ctor3(0x43e990, 0x80), note='batch34110')
S(0x51eab0, 'GUESS copy two cell values', 'thiscall', None, ret='eax', gen=_g51eab0, note='batch34110')
S(0x5f4d80, 'GUESS look up and store offset', 'thiscall', None, ret='eax', gen=_g5f4d80, note='batch34110')
S(0x4eb350, 'GUESS constructor with member', 'thiscall', None, ret='eax', gen=_g4eb350, note='batch34110')
S(0x5d5730, 'GUESS constructor with base args 5', 'thiscall', None, ret='eax', gen=_ctor3(0x43de40, 0x40), note='batch34110')
