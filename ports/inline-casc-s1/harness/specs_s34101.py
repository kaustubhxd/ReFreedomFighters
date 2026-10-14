"""specs_s34101.py - seven call wrappers; callees are recorders (this recorded, register arguments logged where needed)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g4752e0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x466220, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x60)]


def _g4ea2e0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4419f0, 0, this=True, pop=0, ret=r.getrandbits(32),
             side=lambda em, k: em.calllog.append(('edx', em.reg('edx'))))
    return [rnd(c, 0x40), r.getrandbits(32)]


def _g604d30(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634d10, 3, pop=0, ret=r.getrandbits(32))
    c.emu.w32(0x724768, r.getrandbits(32) | 1)
    c.emu.w32(0x72476c, r.getrandbits(32) | 1)
    return []


def _g4cdf50(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x20)]


def _g5adec0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5b0e30, 2, this=True, ret=r.getrandbits(32), stackmark=())
    return [rnd(c, 0x4c0), r.getrandbits(32)]


def _g6493d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x64ea30, 1, this=True, ret=r.getrandbits(32))
    a = rnd(c, 0x20)
    p = rnd(c, 0x20)
    c.emu.w32(a + 0xc, p)
    return [rnd(c, 0x20), a]


def _g473e30(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x466cd0, 0, this=True, pop=0, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)]))
    return [rnd(c, 0x280)]


S(0x4752e0, 'GUESS call then clear field', 'thiscall', None, ret='eax', gen=_g4752e0, note='batch34101')
S(0x4ea2e0, 'GUESS forward with register edx', 'thiscall', None, ret='eax', gen=_g4ea2e0, note='batch34101')
S(0x604d30, 'GUESS reset global buffer', 'cdecl', None, ret='eax', gen=_g604d30, note='batch34101')
S(0x4cdf50, 'GUESS free fixed-size block', 'stdcall', None, ret='eax', gen=_g4cdf50, note='batch34101')
S(0x5adec0, 'GUESS forward to member', 'thiscall', None, ret='eax', gen=_g5adec0, note='batch34101')
S(0x6493d0, 'GUESS forward nested field', 'thiscall', None, ret='eax', gen=_g6493d0, note='batch34101')
S(0x473e30, 'GUESS set flag when byte set', 'thiscall', None, ret='eax', gen=_g473e30, note='batch34101')
