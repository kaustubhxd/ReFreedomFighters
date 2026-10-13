"""specs_s2502.py - decomp area 24, batch 2502. 0x44a930 (GUESS ZGEOM-derived destructor body): thiscall, plain ret.
0x634273 (cdecl __builtin_delete) is a recorder that logs both arguments (caller pops); +0x18 is 0 in about a fifth of the cases.
0x4609e0 runs as exe code (one vtable store at +0x1c). The tail target 0x45c3e0 is a recorder (thiscall, no argument) whose random
return value is compared as EAX."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _gen(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x45c3e0, 0, ret=r.getrandbits(32), this=True)
    o = rnd(c, 0x40)
    c.emu.w32(o + 0x18, 0 if r.random() < 0.2 else rnd(c, 0x38))
    return [o]


S(0x44a930, 'GUESS ZGEOM-derived destructor body (tail jump to 0x45c3e0)', 'thiscall', None, ret='eax', gen=_gen, note='batch2502')
