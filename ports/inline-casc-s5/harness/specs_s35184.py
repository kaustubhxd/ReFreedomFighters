"""specs_s35184.py - 0x5184f0 (thiscall(s) ret 4, ret='al'). this: 0x1700 random bytes. 0x515b70 hooked (thiscall, 1 arg, al false in 1/6, garbage upper bytes), 0x526090 hooked (thiscall, 1 arg). s: stream object with recorder slots 0x68, 0x4c, 0x60, 0x3c, 0x44 (1 arg each) and 0x10 (2 args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5184f0(c):
    clear_hooks(c)
    r = c.rng
    ok = r.random() > 1 / 6
    hook_rec(c, 0x515b70, 1, this=True, pop=4, ret=((r.getrandbits(24) << 8) | 1) if ok else (r.getrandbits(24) << 8))
    hook_rec(c, 0x526090, 1, this=True, pop=4)
    s = obj(c, 0x20, {0x68: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True), 0x60: pystub(c, 1, this=True),
                      0x3c: pystub(c, 1, this=True), 0x44: pystub(c, 1, this=True), 0x10: pystub(c, 2, this=True)}, nslots=0x1a)
    return [rnd(c, 0x1700), s]


S(0x5184f0, 'GUESS write settings block through stream object', 'thiscall', None, ret='al', gen=_g5184f0, note='batch35184')
