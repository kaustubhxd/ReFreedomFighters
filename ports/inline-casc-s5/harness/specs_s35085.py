"""specs_s35085.py - 0x61be80 (cdecl(s, data, n, c), ret='eax'). s: random 0x130 bytes with a callback pointer at +0x110 (cdecl recorder stub, four args, returning zero in a third); n zero in half (0..40 otherwise), c zero in a third;
0x61bd20 (cdecl, 2 args, returns a heap block), 0x634d22 (cdecl, 3 args) and 0x61bf10 (cdecl, 3 args, random result) hooked."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def _g61be80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = rnd(c, 0x80)
    hook_rec(c, 0x61bd20, 2, pop=0, ret=blk)
    hook_rec(c, 0x634d22, 3, pop=0)
    hook_rec(c, 0x61bf10, 3, pop=0, ret=r.getrandbits(32))
    s = rnd(c, 0x130)
    cbv = 0 if r.random() < 1 / 3 else r.getrandbits(32) | 1
    e.w32(s + 0x110, pystub(c, 4, pop=0, ret=cbv))
    n = 0 if r.random() < 0.5 else r.randint(1, 40)
    cc = 0 if r.random() < 1 / 3 else r.getrandbits(32) | 1
    return [s, rnd(c, 0x40), n, cc]


S(0x61be80, 'GUESS buffered write or flush via callback', 'cdecl', None, ret='eax', gen=_g61be80, note='batch35085')
