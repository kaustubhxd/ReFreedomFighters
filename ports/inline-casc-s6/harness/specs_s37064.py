"""specs_s37064.py - cascade s6 batch 37064 (0x62f430, zlib longest_match). Window over a tiny alphabet so matches are frequent; prev table of 16-bit positions; fields set so the chain
length is at least 1; the byte before the window start is valid."""
from pilot import S
from recruits_util import rnd


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g62f430(c):
    r = c.rng
    e = c.emu
    wsize = 0x200
    alpha = r.choice([1, 2, 3, 4, 256, 256])
    wbase = e.alloc(0xa00 + 16, 4)
    run = bytes(r.randrange(alpha) for _ in range(0x300))
    data = bytearray()
    while len(data) < 0xa00:
        if r.random() < 0.5 and len(data) > 8:
            st = r.randrange(0, len(data) - 4)
            data += data[st:st + (r.choice([3, 4, 5, 6, 8, 16, 32]) if r.random() < 0.7 else r.randint(3, 0x120))]
        else:
            data += run[:r.randint(1, 0x40)]
    window = wbase + 8
    e.wbytes(window - 8, bytes(data[:0xa00]))
    strstart = r.choice([1, 5, 0x40, 0xf9, 0xfa, 0xfb, 0xfb, 0xfb, 0xfc, 0xfc, 0x101, 0x200, 0x300, 0x2f0, 0x1fa, 0x1fb, 0x1fc])
    prev = e.alloc(2 * wsize + 8, 2)
    for i in range(wsize):
        _w(c, prev + 2 * i, (r.randrange(0, 4) if r.random() < 0.3 else r.randrange(0, strstart + 1)) if r.random() < 0.9 else 0, 2)
    s = rnd(c, 0x90)
    best = r.choice([1, 2, 3, 8, 0x20, 0x101])
    look = r.choice([2, 3, 0x20, 0x100, 0x102, 0x105, 0x120])
    for off, v in ((0x24, wsize), (0x2c, wsize - 1), (0x30, window), (0x38, prev), (0x64, strstart), (0x68, r.getrandbits(16)),
                   (0x6c, look), (0x70, best), (0x74, r.choice([4, 5, 8, 32, 128])), (0x84, r.choice([2, 4, 8, 32, 0x100])),
                   (0x88, r.choice([3, 4, 5, 6, 8, 16, 32, 128, 258, 0x400]))):
        _w(c, s + off, v)
    cur = r.randrange(0, strstart)
    lim = strstart - wsize + 0x106 if strstart > wsize - 0x106 else 0
    if r.random() < 0.5:
        _w(c, prev + 2 * (cur & (wsize - 1)), r.choice([lim, lim + 1, max(lim - 1, 0)]), 2)
    L = 0
    while L < 0x102 and strstart + L + 8 < len(data) and data[strstart + L + 8] == data[cur + L + 8]:
        L += 1
    if r.random() < 0.4 and L >= 3:
        _w(c, s + 0x88, L)
        _w(c, s + 0x70, r.randint(1, L - 1))
        _w(c, s + 0x6c, r.choice([L, L + 1, 0x105]))
    elif r.random() < 0.3 and L >= 3:
        _w(c, s + 0x88, 0x400)
        _w(c, s + 0x6c, L)
    return [s, cur]


S(0x62f430, 'GUESS zlib longest_match', 'cdecl', None, ret='eax', gen=_g62f430, note='batch37064')
