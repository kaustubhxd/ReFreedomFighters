"""specs_s34100.py - six call wrappers; callees are recorders (this recorded)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec
from unicorn.x86_const import UC_X86_REG_ECX


def _g4bb9d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4c24b0, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x20), r.getrandbits(32)]


def _g612550(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634cf8, 1, ret=r.getrandbits(32))
    return [rnd(c, 0x20)]


def _g566e40(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x566f10, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x1a0)]


def _g57c1c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x561c40, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x190)]


def _thunk(callee, target):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, callee, 0, this=True, pop=0, ret=r.getrandbits(32), side=lambda em, k: em.mu.reg_write(UC_X86_REG_ECX, r.getrandbits(32)))
        hook_rec(c, target, 1, this=True, ret=r.getrandbits(32))
        return [rnd(c, 0x40), r.getrandbits(32)]
    return g


S(0x4bb9d0, 'GUESS clear flag then refresh', 'thiscall', None, ret='eax', gen=_g4bb9d0, note='batch34100')
S(0x612550, 'GUESS reset vtable and release', 'thiscall', None, ret='eax', gen=_g612550, note='batch34100')
S(0x566e40, 'GUESS store computed value', 'thiscall', None, ret='eax', gen=_g566e40, note='batch34100')
S(0x5761b0, 'GUESS call then tail 0x5772c0', 'thiscall', None, ret='eax', gen=_thunk(0x562260, 0x5772c0), note='batch34100')
S(0x57c1c0, 'GUESS store byte result', 'thiscall', None, ret='eax', gen=_g57c1c0, note='batch34100')
S(0x57f410, 'GUESS call then tail 0x57f420', 'thiscall', None, ret='eax', gen=_thunk(0x5626c0, 0x57f420), note='batch34100')
