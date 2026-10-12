"""specs_s2405.py - decomp area 24, batch 2405: GUESS introsort over 53-byte records (0x4ade70).
The array holds 0..60 records (about 70% of cases have at least 17, the size where the sort does work), each with a
float key at +0: mostly random values, some small integers (equal keys), and a few NaN. Depth budgets 0 (heap-sort
fallback at once) up to 20. The partition (0x4ae320) and the heap-sort fallback (0x4ae0b0) run as exe code."""
import math
from pilot import S
from recruits_util import rnd, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.randint(17, 60) if r.random() < 0.7 else r.randint(0, 16)
    arr = rnd(c, 53 * max(n, 1) + 64)
    for i in range(n):
        x = r.random()
        if x < 0.03:
            key = math.nan
        elif x < 0.35:
            key = float(r.randint(-5, 5))
        else:
            key = r.uniform(-100.0, 100.0)
        e.wf32(arr + 53 * i, key)
    first = arr
    last = arr + 53 * n
    depth = r.choice([0, 1, 2, 3, 4, 6, 8, 20])
    return [first, last, 0, depth]


S(0x4ade70, 'GUESS: introsort of 53-byte records (0x4ade70)', 'fastcall', None, ret=None, gen=_gen, note='batch2405')
