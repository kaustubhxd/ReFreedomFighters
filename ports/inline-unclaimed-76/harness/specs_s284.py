"""specs_s284.py - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15: 0x5ed2b0. A list of element pointers at this+0xcb
(start) and this+0xcf (end). c = -1 walks the whole list; c = an index selects one entry."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _pairs(c):
    e = c.emu
    n = c.rng.randrange(1, 5)
    self_ = _rnd(c, 0x100)
    arr = _rnd(c, 4 * n + 8)
    els = []
    for i in range(n):
        el = _rnd(c, 0x20)
        els.append(el)
        e.w32(arr + 4 * i, el)
    e.w32(self_ + 0xcb, arr)
    e.w32(self_ + 0xcf, arr + 4 * n)
    e.w8(self_ + 0xa6, 0)
    a = c.rng.choice([c.rng.getrandbits(16), c.rng.getrandbits(32)])
    b = c.rng.choice([c.rng.getrandbits(16), c.rng.getrandbits(32)])
    if c.rng.random() < 0.5:                   # make the first element match, so the flag test is exercised both ways
        e.w16(els[0], a)
        e.w16(els[0] + 2, b)
    if c.rng.random() < 0.5:
        c_arg = 0xffffffff
    else:
        c_arg = c.rng.randrange(0, n)            # an index into the array (the c != -1 branch)
    return [self_, a & 0xffffffff, b & 0xffffffff, c_arg]


S(0x5ed2b0, 'setPairs (GUESS)', 'thiscall', None, ret=None, gen=_pairs, note='batch284; ret 0xc')
