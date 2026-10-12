"""specs_s2462.py - decomp area 24, batch 2462 (gap band).
0x4519a0 (GUESS constructor): base 0x43de40 (recorder, three arguments), vtable 0x6813c0, floats 100.0 at +0x18, +0x1c, +0x20,
zeros at +0x24, +0x28, +0x2c, +0x3c, +0x40; ret 12, eax = this.
0x441b90 (GUESS constructor): base 0x43e990 (recorder, three arguments), vtable 0x67cdbc, zeros at +0x7b, +0x71, +0x5d..+0x6c
(16 bytes), +0x5c byte, +0x75 word, +0x77 dword, -1 at +0x7f, +0x6d; ret 12, eax = this.
0x44b5c0 (GUESS destructor body, SEH frame not reproduced): vtable 0x67fc30, ZSNDOBJ::Free (0x44c060, recorder), then the
call 0x43de70 (recorder) on this. The original installs an exception frame on fs:[0]; this port does not."""
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
    hook_rec(c, 0x44c060, 0, this=True)
    hook_rec(c, 0x43de70, 0, this=True)
    return [rnd(c, 0x100)]


S(0x4519a0, 'GUESS: ZSTDOBJ-derived constructor (0x4519a0)', 'thiscall', None, ret='eax', gen=_ctor(0x43de40), note='batch2462')
S(0x441b90, 'GUESS: ZGROUP-derived constructor (0x441b90)', 'thiscall', None, ret='eax', gen=_ctor(0x43e990), note='batch2462')
S(0x44b5c0, 'GUESS: ZSNDOBJ destructor body (SEH frame not reproduced)', 'thiscall', None, ret=None, gen=_dtor, note='batch2462: SEH frame not reproduced')
