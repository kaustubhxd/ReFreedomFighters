"""specs_s2448.py - decomp area 24, batch 2448 (gap band).
0x45ae10 (GUESS, ZSTDOBJ-derived constructor), thiscall, ret 12, eax = this: base 0x43de40 (recorder, three arguments),
then vtable 0x684068.
0x445180 (GUESS, unnamed), thiscall, ret 4: the argument's bytes are rearranged (byte 2 to byte 0, byte 0 to byte 2, and
bytes 1 and 3 kept) and stored at +0xa0.
0x45c080 ZBloodSplatters::NotifyMarkUV and 0x45c0b0 ZBloodStains::NotifyMarkUV (unsigned, const float*, unsigned), thiscall,
ret 12: cdecl 0x634d22 (recorder, three arguments, the caller pops) is called with the destination self+0x508 (or +0x3fc)
+ index*0x300, the pointer, and count*0x18."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _ctor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43de40, 3, this=True)
    return [rnd(c, 0x100), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _shuffle(c):
    clear_hooks(c)
    r = c.rng
    return [rnd(c, 0x100), r.getrandbits(32)]


def _notify(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634d22, 3, pop=0)
    return [rnd(c, 0x2000), r.randint(0, 3), rnd(c, 0x40), r.randint(0, 4)]


S(0x45ae10, 'GUESS: ZSTDOBJ-derived constructor (0x45ae10)', 'thiscall', None, ret='eax', gen=_ctor, note='batch2448')
S(0x445180, 'GUESS: byte rearrangement store at +0xa0 (0x445180)', 'thiscall', None, ret=None, gen=_shuffle, note='batch2448')
S(0x45c080, 'ZBloodSplatters::NotifyMarkUV', 'thiscall', None, ret=None, gen=_notify, note='batch2448')
S(0x45c0b0, 'ZBloodStains::NotifyMarkUV', 'thiscall', None, ret=None, gen=_notify, note='batch2448')
