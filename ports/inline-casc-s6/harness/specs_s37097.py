"""specs_s37097.py - cascade s6 batch 37097 (0x4050f0, cdecl(lens, n), returns array or 0). malloc (0x634d58) hands out a random-filled spec block, free (0x634d52) is a
recording hook. Length sets: designed valid prefix codes, random short lengths (often overflowing), zeros / negatives mixed in, and lengths up to 0x20."""
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4050f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blocks = [e.alloc(0x100, 4) for _ in range(2)]
    for b in blocks:
        e.wbytes(b, bytes(r.getrandbits(8) for _ in range(0x100)))
    hook_rec(c, 0x634d58, 1, pop=0, ret=lambda em, k: blocks[k % 2])
    hook_rec(c, 0x634d52, 1, pop=0)
    mode = r.random()
    if mode < 0.3:
        base = r.choice([[1, 2, 3, 3], [2, 2, 2, 2], [1, 3, 3, 3, 3], [3, 3, 2, 2, 2], [1, 2, 3, 4, 5, 5], [4, 4, 4, 4, 3, 3, 2], [1, 1], [2, 3, 3, 1], [2, 2, 1, 3], [2, 2, 1], [2, 1, 3, 3], [3, 3, 2, 1, 4], [2, 2, 1, 1], [3, 2, 2, 1, 2], [2, 2, 1, 4, 4], [2, 1, 2, 3], [2, 1, 2, 2], [2, 1, 3, 2, 3], [2, 1, 2, 2, 3], [3, 1, 2, 2, 3]])
        lens = list(base)
        if r.random() < 0.4:
            lens.insert(r.randrange(len(lens) + 1), r.choice([0, -1, 0]))
    elif mode < 0.55:
        lens = [r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, -2]) for _ in range(r.randint(0, 10))]
    elif mode < 0.7:
        lens = [r.choice([0x1e, 0x1f, 0x20, 1, 2, 0x10, 0]) for _ in range(r.randint(1, 8))]
    elif mode < 0.85:
        k = r.randint(1, 20)
        lens = [r.randint(1, 5) for _ in range(k)]
    else:
        lens = [r.randint(1, 3) for _ in range(r.randint(1, 5))]
    n = len(lens)
    arr = e.alloc(4 * max(n, 1) + 8, 4)
    for i, v in enumerate(lens):
        _w(c, arr + 4 * i, v)
    return [arr, n]


S(0x4050f0, 'GUESS compute_codewords', 'cdecl', None, ret='eax', gen=_g4050f0, note='batch37097')
