"""specs_s34050.py - cascade escalation batch 34050: 0x4c1ed0. Hooked 0x4c0b00 (thiscall ret 4, returns a random value; it records ECX and its argument), so the wrapper's pass-through of this and b and the
drop of a are observed."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4c0b00, 1, ret=r.getrandbits(32), this=True)
    return [rnd(c, 0x40), r.getrandbits(32), r.getrandbits(32)]


S(0x4c1ed0, 'GUESS thiscall wrapper dropping its first argument', 'thiscall', None, ret='eax', gen=_g, note='batch34050')
