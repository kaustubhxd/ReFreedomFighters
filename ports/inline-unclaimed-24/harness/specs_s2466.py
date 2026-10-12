"""specs_s2466.py - decomp area 24, batch 2466 (gap band).
0x449e90 ZLIST::~ZLIST: base destructor 0x449d80 (recorder), then with flag bit 0: SetState(this, 0x20) when bit 2 is set,
else operator delete (0x45c510, recorder). Thiscall, ret 4, eax = this.
0x44c8c0 (GUESS constructor): base 0x43de40 (recorder, three arguments), vtable 0x6805dc, zeros at +0x24, +0x38, +0x3c, +0x58,
+0x5c, +0x78, +0x7c, +0x98, +0x9c; ret 12, eax = this."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _dtor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x449d80, 0, this=True)
    hook_rec(c, 0x4690b0, 2, pop=0)
    hook_rec(c, 0x45c510, 1, pop=0)
    return [rnd(c, 0x100), r.getrandbits(32)]


def _ctor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43de40, 3, this=True)
    return [rnd(c, 0x100), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x449e90, 'ZLIST::~ZLIST', 'thiscall', None, ret='eax', gen=_dtor, note='batch2466')
S(0x44c8c0, 'GUESS: ZSTDOBJ-derived constructor (0x44c8c0)', 'thiscall', None, ret='eax', gen=_ctor, note='batch2466')
