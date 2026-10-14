"""specs_s35015.py - 0x57d160. Object (0x400 random bytes) whose embedded list at +0x23c has a vtable with slots 0x4c, 0x44 (1 arg, flag-recorded), 0x5c (returns a sequence, zeroes the iterator's first
dword after 0..3 calls, and starts with a zero iterator in 1/5); [+0x32c] null in a third; engine object at 0x70038c slot 0xcc returns a heap object or null; 0x634273 cdecl recorder, 0x4cbec0 thiscall recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g57d160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x4cbec0, 0, this=True)
    me = rnd(c, 0x400)
    if r.random() < 1 / 3:
        e.w32(me + 0x32c, 0)
    m = 0 if r.random() < 0.2 else r.choice([1, 2, 3])
    seq = [r.getrandbits(32) for _ in range(5)]

    def s5c(em, k):
        em.w32(em.arg32(0), 0 if k >= m else r.getrandbits(32) | 1)
    vo = obj(c, 4, {0x4c: pystub(c, 1, nullflag=(0,), this=True), 0x44: pystub(c, 1, nullflag=(0,), this=True),
                    0x5c: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: seq[min(k, 4)], side=s5c)}, nslots=0x20)
    e.w32(me + 0x23c, e.r32(vo))
    ents = [0 if r.random() < 0.3 else rnd(c, 0x100) for _ in range(5)]
    eng = obj(c, 0x10, {0xcc: pystub(c, 1, this=True, ret=lambda em, k: ents[min(k, 4)])}, nslots=0x40)
    e.w32(0x70038c, eng)
    return [me]


S(0x57d160, 'GUESS release buffer and list entries', 'thiscall', None, ret=None, gen=_g57d160, note='batch35015')
