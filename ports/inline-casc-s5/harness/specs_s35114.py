"""specs_s35114.py - 0x571690 (thiscall(s) ret 4, ret='al'). 0x563490 hooked (thiscall, 1 arg, AL true in 3/4 with garbage upper bytes); this: random 0x1c0 bytes; s: slots 0x60 and 0x3c (1 arg, recorded)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g571690(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x563490, 1, this=True, ret=((r.getrandbits(24) << 8) | 1) if r.random() < 0.75 else (r.getrandbits(24) << 8))
    s = obj(c, 0x20, {0x60: pystub(c, 1, this=True), 0x3c: pystub(c, 1, this=True)}, nslots=0x19)
    return [rnd(c, 0x1c0), s]


S(0x571690, 'GUESS write record fields to stream', 'thiscall', None, ret='al', gen=_g571690, note='batch35114')
