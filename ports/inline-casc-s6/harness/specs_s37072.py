"""specs_s37072.py - cascade s6 batch 37072 (0x49ca30, thiscall block-record bookkeeping, ret 0x10). split == 0: p points into a spec buffer of tag words (with a marked word
within reach, previous word writable); the bin table pointer at +0x1d is placed just below / above p. split != 0: lo/hi/size are chosen around the 0x70 step and the 0xe0 threshold
so every branch runs. The per-step callee 0x49c310 is a recording hook (it logs the position dword it is passed)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g49ca30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x49c310, 3, pop=12, this=True, deref={1: 1})
    t = rnd(c, 0x40)
    buf = e.alloc(0x80, 4)
    e.wbytes(buf, bytes(r.getrandbits(8) for _ in range(0x80)))
    p = buf + 8
    idx = r.choice([0, 1, 2, 5, 0x10])
    if r.random() < 0.4:
        # copy loop: leading unmarked words, then a marked one within the buffer
        k = r.randint(0, 6)
        for i in range(k):
            _w(c, p + 4 * i, r.getrandbits(32) & ~1)
        _w(c, p + 4 * k, r.getrandbits(32) | 1)
        for i in range(k + 1, 12):
            _w(c, p + 4 * i, r.getrandbits(32))
        split = 0
    else:
        split = r.choice([0, 1, 1, 7, 0x100, 0x80])
    if split == 0:
        if r.random() < 0.5:
            _w(c, p, r.getrandbits(32) | 1)
        bins = p - idx * 4 - 4 + r.choice([-8, -4, -1, 0, 1, 4, 8])
        _w(c, t + 0x1d, bins)
        return [t, idx, p, r.getrandbits(32), split]
    lo = r.randrange(1, 0x40) * 0x70 * 2
    m = r.randint(1, 6)
    hi = lo + 0x70 * m + r.choice([0, 0, 0, 8, 0x10])
    pick = r.random()
    off = r.choice([0, 1, 0x70, 0x6f, 0x71, 0xe0, 0x150, 0x14f, 0x151, 0x1c0, 0x1c1, 0x1c2, 0x230, 0x2a0, r.randrange(0, 0x400)])
    if pick < 0.45:
        size = lo + off
    elif pick < 0.9:
        size = hi - off
    else:
        size = r.randrange(0, hi + 0x200)
    _w(c, p, lo | r.getrandbits(3))
    _w(c, p + 4, hi | r.getrandbits(3))
    _w(c, t + 0x1d, r.getrandbits(32))
    return [t, idx, p, size & 0xffffffff, split]


S(0x49ca30, 'GUESS block_record_split', 'thiscall', None, ret='eax', gen=_g49ca30, note='batch37072')
