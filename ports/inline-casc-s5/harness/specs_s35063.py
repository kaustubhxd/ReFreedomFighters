"""specs_s35063.py - 0x405f20 (cdecl(a, b), ret='eax'). a: random block with [a+0x14] = T (tables of 16 signed small dwords: start state T[0][r] and T[4][r], transitions T[0xc], T[0x10] with values in -4..15, key T[8]);
0x410cf0 hooked (cdecl, 2 args) returning an index 0..15 or a negative value; 0x410db0 (cdecl, 2 args) recorder; 0x410ec0 (cdecl, 1 arg) returns a sequence of 0, 1, 2 and -1 (the end after at most 10 calls)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g405f20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    idx = r.choice([-1, 0xfffffffe, 0, 1, 5, 15, r.randint(0, 15)])
    hook_rec(c, 0x410cf0, 2, pop=0, ret=idx)
    hook_rec(c, 0x410db0, 2, pop=0)
    n = r.randint(0, 10)
    seq = [r.choice([0, 1, 0, 1, 2, 5]) for _ in range(n)] + [0xffffffff]
    hook_rec(c, 0x410ec0, 1, pop=0, ret=lambda em, k: seq[min(k, len(seq) - 1)])
    T = rnd(c, 0x20)
    for off in (0, 4, 0xc, 0x10):
        arr = rnd(c, 0x40)
        for i in range(16):
            v = r.randint(-4, 15) & 0xffffffff
            e.w32(arr + 4 * i, v)
        e.w32(T + off, arr)
    e.w32(T + 8, r.getrandbits(32))
    a = rnd(c, 0x40)
    e.w32(a + 0x14, T)
    return [a, r.getrandbits(32)]


S(0x405f20, 'GUESS table-driven automaton step', 'cdecl', None, ret='eax', gen=_g405f20, note='batch35063')
