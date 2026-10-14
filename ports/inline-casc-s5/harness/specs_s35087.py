"""specs_s35087.py - 0x6052f0 (thiscall(a, b) ret 8). a: object with slot 0x5c (1 arg: out pointer, flag-recorded; writes a random index through it); 0x5fa090 hooked (thiscall, 1 arg (the index), returns a C string of 0..25
characters, a different pointer per call but with equal content); 0x41e290 (cdecl, 1 arg) returns a 0x40-byte block. this: random 0x20 bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g6052f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    txt = bytes(r.choice(b'abcXYZ019') for _ in range(r.choice([0, 3, 10, 11, 12, 13, 20, 25]))) + b'\0'
    strs = []
    for _ in range(4):
        p = rnd(c, 0x40)
        e.wbytes(p, txt)
        strs.append(p)
    hook_rec(c, 0x5fa090, 1, this=True, ret=lambda em, k: strs[min(k, 3)])
    blk = rnd(c, 0x40)
    hook_rec(c, 0x41e290, 1, pop=0, ret=blk)
    a = obj(c, 0x20, {0x5c: pystub(c, 1, nullflag=(0,), this=True, side=lambda em, k: em.w32(em.arg32(0), r.getrandbits(32)))}, nslots=0x18)
    return [rnd(c, 0x20), a, rnd(c, 0x10)]


S(0x6052f0, 'GUESS copy looked-up name into owned buffer', 'thiscall', None, ret=None, gen=_g6052f0, note='batch35087')
