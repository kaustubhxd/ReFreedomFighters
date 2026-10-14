"""specs_s35149.py - 0x49d220 (thiscall(a, b, c) ret 0xc, ret='eax'). 0x41e290 hooked (cdecl, 1 arg, returns a fresh block, null in a quarter); sizes a and b: small, 0x3fffffff, 0x40000000 and above (saturation), random; logger object at 0x70038c (absent in 1/4) with slot 0x24 (2 args); this: 0x40 random bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g49d220(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blks = [rnd(c, 0x20) for _ in range(2)]
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: 0 if r.random() < 0.25 else blks[min(k, 1)])
    vals = [0, 1, 5, 0x3fffffff, 0x40000000, 0x40000001, 0x80000000, 0xffffffff]

    def pick():
        return r.choice(vals) if r.random() < 0.6 else r.getrandbits(32)
    e.w32(0x70038c, 0 if r.random() < 0.25 else obj(c, 0x20, {0x24: pystub(c, 2, this=True)}, nslots=0xa))
    return [rnd(c, 0x40), pick(), pick(), r.getrandbits(32)]


S(0x49d220, 'GUESS pool constructor with two saturating arrays', 'thiscall', None, ret='eax', gen=_g49d220, note='batch35149')
