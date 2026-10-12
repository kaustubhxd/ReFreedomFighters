"""specs_s2445.py - decomp area 24, batch 2445 (gap band): three constructors.
0x44e6d0 and 0x44edf0 (ZSTDOBJ-derived), thiscall, ret 12, eax = this: the base constructor 0x43de40 (recorder, three
arguments) is called with the same three arguments, then the vtable is set (0x680abc and 0x68110c).
0x452790 (ZGEOM-derived), thiscall, ret 12, eax = this: base constructor 0x45c3a0 (recorder, three arguments), vtable 0x6815d8."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _ctor(addr):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, addr, 3, this=True)
        return [rnd(c, 0x100), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]
    return gen


S(0x44e6d0, 'GUESS: ZSTDOBJ-derived constructor (0x44e6d0)', 'thiscall', None, ret='eax', gen=_ctor(0x43de40), note='batch2445')
S(0x44edf0, 'GUESS: ZSTDOBJ-derived constructor (0x44edf0)', 'thiscall', None, ret='eax', gen=_ctor(0x43de40), note='batch2445')
S(0x452790, 'GUESS: ZGEOM-derived constructor (0x452790)', 'thiscall', None, ret='eax', gen=_ctor(0x45c3a0), note='batch2445')
