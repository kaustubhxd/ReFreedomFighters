"""specs_s37053.py - cascade s6 batch 37053 (0x52e4f0). Pure memory: this+0x86 count, +0x88 records (12 bytes), +0x8c entries (4 bytes each); box and centre are spec blocks;
coordinates are clustered around the box edges so inside/outside boundaries are hit."""
from pilot import S
from recruits_util import rnd


def _w(c, a, v, n=2):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g52e4f0(c):
    r = c.rng
    e = c.emu
    cx = [r.randint(-50, 50) for _ in range(3)]
    ext = [r.randint(0, 40) for _ in range(3)]
    ctr = e.alloc(8, 2)
    box = e.alloc(8, 2)
    for i in range(3):
        _w(c, ctr + 2 * i, cx[i])
        _w(c, box + 2 * i, ext[i])
    n = r.choice([0, 1, 2, 4, 6])
    recs = e.alloc(12 * 8 + 8, 4)
    ents = e.alloc(4 * 8 + 8, 4)
    for i in range(8):
        for j in range(6):
            ax = j % 3
            lo, hi = ext[ax] - cx[ax], cx[ax] + ext[ax]
            base = r.choice([lo - 1, lo, lo + 1, hi - 1, hi, hi + 1, r.randint(0, 120), r.randint(min(lo, hi), max(lo, hi, 0))])
            _w(c, recs + 12 * i + 2 * j, base & 0xffff)
        _w(c, ents + 4 * i, r.getrandbits(16))
        _w(c, ents + 4 * i + 2, r.getrandbits(16))
    me = rnd(c, 0x100)
    _w(c, me + 0x86, n)
    _w(c, me + 0x88, recs, 4)
    _w(c, me + 0x8c, ents, 4)
    return [me, box, ctr, r.choice([0, 1, 5, 0x100])]


S(0x52e4f0, 'GUESS mark entries whose points lie in box', 'thiscall', None, ret='eax', gen=_g52e4f0, note='batch37053')
