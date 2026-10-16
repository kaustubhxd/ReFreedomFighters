"""specs_s210058.py - Sonnet-w3a: 0x4367b0. Constructor over random packed memory; descriptor fields (+8, +0xc, +0x10, +0x14) are zero or non-zero with the all-zero case common; flags +0x18 cover bits 1 and 4."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _r(c): return c.rng.getrandbits(32)


def g4367b0(c):
    clear_hooks(c)
    hook_rec(c, 0x439e50, 1, ret=_r(c), this=True)
    hook_rec(c, 0x4386a0, 2, ret=_r(c), this=True)
    hook_rec(c, 0x4379f0, 2, ret=_r(c), this=True)
    d = rnd(c, 0x20)
    allzero = c.rng.random() < 0.25
    for off in (8, 0xc, 0x10, 0x14):
        c.emu.w32(d + off, 0 if allzero or c.rng.random() < 0.4 else _r(c) | 1)
    c.emu.w32(d, c.rng.choice([0, _r(c)]))
    c.emu.w32(d + 0x18, c.rng.choice([0, 1, 4, 5, 2, 0xfffffff8, _r(c)]))
    return [rnd(c, 0x60), _r(c), d]


S(0x4367b0, 'ctor_from_descriptor', 'thiscall', None, ret='eax', gen=g4367b0, note='batch210058')
