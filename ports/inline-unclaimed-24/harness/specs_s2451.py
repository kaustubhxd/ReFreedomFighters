"""specs_s2451.py - decomp area 24, batch 2451 (gap band).
0x44c3d0 (GUESS, ZSTDOBJ-derived ctor): base 0x43de40 (recorder, three arguments), vtable 0x67ff2c, byte +0x18 = 0; ret 12, eax.
0x4545f0 (GUESS, ZGROUP-derived ctor): base 0x43e990 (recorder, three arguments), vtable 0x6820b8, dword +0x5c = 0; ret 12, eax.
0x44b820 ZSNDOBJ::Activate(bool), thiscall, ret 4: ZGEOM::Activate (0x45c680, recorder, the argument), then Start (0x44c2b0)
when the argument's low byte is set, else Stop (0x44c370); both recorders."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _ctor(base):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, base, 3, this=True)
        return [rnd(c, 0x100), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]
    return gen


def _act(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45c680, 1, this=True)
    hook_rec(c, 0x44c2b0, 0, this=True)
    hook_rec(c, 0x44c370, 0, this=True)
    return [rnd(c, 0x100), r.getrandbits(32)]


S(0x44c3d0, 'GUESS: ZSTDOBJ-derived constructor (0x44c3d0)', 'thiscall', None, ret='eax', gen=_ctor(0x43de40), note='batch2451')
S(0x4545f0, 'GUESS: ZGROUP-derived constructor (0x4545f0)', 'thiscall', None, ret='eax', gen=_ctor(0x43e990), note='batch2451')
S(0x44b820, 'ZSNDOBJ::Activate', 'thiscall', None, ret=None, gen=_act, note='batch2451')
