"""specs_s35179.py - 0x61bf10 (cdecl(s, n, flag), ret='eax'). s: 0x300 random bytes; s[0x110] = callback stub (cdecl, 4 args recorded, returns zero in half, else non-zero), s[0x8c] = object with a callback pointer at +0x34 (cdecl, 4 args recorded). n: small, large and wrapping values; flag: zero in half."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub


def _g61bf10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = rnd(c, 0x300)
    e.w32(s + 0x110, pystub(c, 4, pop=0, ret=0 if r.random() < 0.5 else r.getrandbits(32) | 1))
    o = rnd(c, 0x40)
    e.w32(o + 0x34, pystub(c, 4, pop=0))
    e.w32(s + 0x8c, o)
    n = r.choice([0, 1, 5, 0x1000, 0xffffffff, r.getrandbits(32)])
    return [s, n, 0 if r.random() < 0.5 else r.choice([1, 2, r.getrandbits(32)])]


S(0x61bf10, 'GUESS advance decoder window and call refill callback', 'cdecl', None, ret='eax', gen=_g61bf10, note='batch35179')
