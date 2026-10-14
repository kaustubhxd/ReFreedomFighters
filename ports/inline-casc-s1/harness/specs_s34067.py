"""specs_s34067.py - 0x61bc70: ecx = first stack arg (object), tail jump through its vtable slot 0x18."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x40, {0x18: pystub(c, 2, ret=r.getrandbits(32), this=True)})
    return [o, r.getrandbits(32)]


S(0x61bc70, 'GUESS forward to arg object slot 0x18', 'cdecl', None, ret='eax', gen=_g, note='batch34067')
