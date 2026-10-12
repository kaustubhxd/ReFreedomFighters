"""specs_s2480.py - decomp area 24, batch 2480.
0x45b4e0 ~ZBloodSplatters and 0x45b5d0 (unnamed destructor), both: vtable 0x684358, base 0x43de70 (recorder), flag bit 0 then
SetState(this, 0x650c or 0x258) when bit 2 (0x4690b0, recorder, cdecl), else operator delete (0x45c510, recorder). Thiscall, ret 4.
0x454980 (GUESS constructor): base 0x43de40 (recorder, three arguments), vtable 0x6823a4, zeros at +0x18, +0x1c, +0x20, +0x28,
+0x34, +0x2c, +0x30, +0x24, +0x38, +0x3c, +0x40, +0x44, +0x48; ret 12, eax = this."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _dtor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43de70, 0, this=True)
    hook_rec(c, 0x4690b0, 2, pop=0)
    hook_rec(c, 0x45c510, 1, pop=0)
    return [rnd(c, 0x100), r.getrandbits(32)]


def _ctor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43de40, 3, this=True)
    return [rnd(c, 0x100), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x45b4e0, 'ZBloodSplatters::~ZBloodSplatters', 'thiscall', None, ret='eax', gen=_dtor, note='batch2480')
S(0x45b5d0, 'GUESS: destructor (0x45b5d0)', 'thiscall', None, ret='eax', gen=_dtor, note='batch2480')
S(0x454980, 'GUESS: ZSTDOBJ-derived constructor (0x454980)', 'thiscall', None, ret='eax', gen=_ctor, note='batch2480')
