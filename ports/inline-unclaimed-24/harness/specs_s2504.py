"""specs_s2504.py - decomp area 24, batch 2504.
0x40f8b0 (GUESS: FFT factorisation + twiddle table builder): cdecl(n, twid, fac). Factors n by the table at 0x6f2400,
stores factors at fac[2..] (a 2 moved to the front), fac[0] = n, fac[1] = count, then writes cos/sin twiddle pairs (x87 fsin/fcos).
Inputs: n in 2..400, smooth numbers and primes; buffers random-filled with padding."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    k = r.random()
    if k < 0.6:
        n = 1
        for _ in range(r.randint(1, 5)):
            n *= r.choice([2, 2, 3, 4, 5])
        n = max(2, min(n, 400))
    elif k < 0.8:
        n = r.choice([2, 3, 4, 5, 6, 7, 9, 11, 13, 17, 19, 23, 29, 31, 49, 77, 97, 121, 169, 211])
    else:
        n = r.randint(2, 400)
    fac = rnd(c, 4 * 40)
    twid = rnd(c, 4 * (4 * n + 64))
    return [n, twid, fac]


S(0x40f8b0, 'GUESS FFT factor and twiddle builder', 'cdecl', None, ret=None, gen=_gen, note='batch2504')
