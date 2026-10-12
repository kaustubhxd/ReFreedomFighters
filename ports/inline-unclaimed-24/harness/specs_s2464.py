"""specs_s2464.py - decomp area 24, batch 2464 (gap band). Three destructors with one shape. The base destructor (0x447690,
0x447750, 0x447810; recorders, no arguments) runs first. With the flag byte's bit 0 set: when bit 2 is also set,
ZRenderGC::SetState(this, 0x20) (0x4690b0, recorder, cdecl); otherwise ZGEOM::operator delete(this) (0x45c510, recorder,
cdecl). Returns this (eax). Thiscall, ret 4."""
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


S(0x447980, 'ZGateLightMaster::~ZGateLightMaster', 'thiscall', None, ret='eax', gen=_gen(0x447690), note='batch2464')
S(0x4479c0, 'ZGateLightSpotMaster::~ZGateLightSpotMaster', 'thiscall', None, ret='eax', gen=_gen(0x447750), note='batch2464')
S(0x447a90, 'ZGateLightSquareSpotMaster::~ZGateLightSquareSpotMaster', 'thiscall', None, ret='eax', gen=_gen(0x447810), note='batch2464')
