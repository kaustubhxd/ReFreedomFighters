"""specs_s2478.py - decomp area 24, batch 2478: four destructors with one shape. Vtable store, base call (recorder, no arguments:
0x43de70 or 0x43ea20), then flag bit 0: SetState(this, value) when bit 2 (value 0x4c, 0x60, 0x5c or 0x7d), else operator delete
(recorder). Thiscall, ret 4, eax = this."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _gen(base):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, base, 0, this=True)
        hook_rec(c, 0x4690b0, 2, pop=0)
        hook_rec(c, 0x45c510, 1, pop=0)
        return [rnd(c, 0x100), r.getrandbits(32)]
    return gen


S(0x454ac0, 'ZMaterialDesc::~ZMaterialDesc', 'thiscall', None, ret='eax', gen=_gen(0x43de70), note='batch2478')
S(0x454630, 'ZInstance::~ZInstance', 'thiscall', None, ret='eax', gen=_gen(0x43ea20), note='batch2478')
S(0x454670, 'ZTemplate::~ZTemplate', 'thiscall', None, ret='eax', gen=_gen(0x43ea20), note='batch2478')
S(0x44e980, 'ZBOXGATEGROUP::~ZBOXGATEGROUP', 'thiscall', None, ret='eax', gen=_gen(0x43ea20), note='batch2478')
