"""specs_s34000.py - cascade escalation batch 34000: vtable tail-jump thunks 0x46efc0 (slot 0x2e8) and 0x4cbad0 (slot 0xc), and 0x539c60.
The object has a real vtable whose slot is a recorder stub (thiscall, pops 2 args, returns a random value); the thunk must leave the caller's
stack alone so the slot sees this and the two stack arguments."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _thunk(slot):
    def g(c):
        clear_hooks(c)
        r = c.rng
        me = obj(c, 0x40, {slot: pystub(c, 2, ret=r.getrandbits(32), this=True)})
        return [me, r.getrandbits(32), r.getrandbits(32)]
    return g


S(0x46efc0, 'GUESS vtable tail thunk slot 0x2e8', 'thiscall', None, ret='eax', gen=_thunk(0x2e8), note='batch34000')
S(0x4cbad0, 'GUESS vtable tail thunk slot 0xc', 'thiscall', None, ret='eax', gen=_thunk(0xc), note='batch34000')
S(0x539c60, 'GUESS constant 1, stdcall 1 arg', 'stdcall', None, ret='eax', gen=lambda c: [c.rng.getrandbits(32)], note='batch34000')
