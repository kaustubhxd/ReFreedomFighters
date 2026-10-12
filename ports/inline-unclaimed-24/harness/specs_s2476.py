"""specs_s2476.py - decomp area 24, batch 2476: two destructors with one shape. Base destructor (recorder, no arguments) first;
then flag bit 0: SetState(this, value) when bit 2 (value 0xf1 for 0x455580, 0x37 for 0x45a640), else operator delete (0x45c510,
recorder). Thiscall, ret 4, eax = this."""
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


S(0x455580, 'ZParticleTemplate::~ZParticleTemplate', 'thiscall', None, ret='eax', gen=_gen(0x4553d0), note='batch2476')
S(0x45a640, 'ZPICOBJ::~ZPICOBJ', 'thiscall', None, ret='eax', gen=_gen(0x45a5a0), note='batch2476')
