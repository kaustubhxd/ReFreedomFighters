"""specs_s2467.py - decomp area 24, batch 2467 (gap band).
0x44e900 (GUESS constructor): base 0x43e990 (recorder, three arguments), vtable 0x680ce4, zeros at +0x5c..+0x78 and a byte at +0x7c.
0x45a530 (GUESS constructor): base 0x43de40 (recorder), vtable 0x683bac, zeros at +0x24, +0x28, 1.0f at +0x18, +0x1c, +0x20, word
0x100 at +0x2c, dword 0 at +0x33, dword 0xffffff at +0x2f, byte 0 at +0x2e (stores in the exe's order).
0x45ae40 ~ZBoxPrimitive: base 0x43de70 (recorder, no arguments), then flag bit 0: SetState(this, 0x24) when bit 2, else delete (0x45c510).
All thiscall, ret 12 (constructors, eax) or ret 4 (destructor, eax)."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _ctor(base):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, base, 3, this=True)
        return [rnd(c, 0x100), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]
    return gen


def _dtor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43de70, 0, this=True)
    hook_rec(c, 0x4690b0, 2, pop=0)
    hook_rec(c, 0x45c510, 1, pop=0)
    return [rnd(c, 0x100), r.getrandbits(32)]


S(0x44e900, 'GUESS: ZGROUP-derived constructor (0x44e900)', 'thiscall', None, ret='eax', gen=_ctor(0x43e990), note='batch2467')
S(0x45a530, 'GUESS: ZSTDOBJ-derived constructor (0x45a530)', 'thiscall', None, ret='eax', gen=_ctor(0x43de40), note='batch2467')
S(0x45ae40, 'ZBoxPrimitive::~ZBoxPrimitive', 'thiscall', None, ret='eax', gen=_dtor, note='batch2467')
