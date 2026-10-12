"""specs_s2452.py - decomp area 24, batch 2452 (gap band): GUESS destructor body (0x44ee20), thiscall, plain ret tail jump.
Vtable 0x68110c; __builtin_delete (0x634273, cdecl, two arguments: pointer, size) on +0x8c with 2, on +0xac with 4, on +0xb0
with 0x3c; then the tail jump to 0x43de70 (recorder, no arguments). The delete is a recorder (cdecl, the caller pops 24)."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _gen(c):
    clear_hooks(c)
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x43de70, 0, this=True)
    o = rnd(c, 0x100)
    return [o]


S(0x44ee20, 'GUESS: destructor body (0x44ee20)', 'thiscall', None, ret=None, gen=_gen, note='batch2452')
