"""specs_s67521.py - cascade s6 batch 67521 (0x530a40, thiscall(), returns ax). Pure memory function: the pool P with record tables (+0x54 0x16-byte records, +0x5a 12-byte records,
+0x78 10-byte entries), limit word +0x50, a shared u16 cursor, the cursor step, record index, two small words and the mode byte (0..4). Records start with and without allocated slots, the
cursor sits at / near the limit to cover the overflow comparisons (signed for mode 3, unsigned for modes 1 and 2). ret='ax' (only the low half of eax is defined)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g530a40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    P = rnd(c, 0x90)
    n = 4
    t54 = e.alloc(0x16 * n + 8, 4)
    t5a = e.alloc(12 * n + 8, 4)
    t78 = e.alloc(10 * 6 + 8, 4)
    for base, sz in ((t54, 0x16), (t5a, 12), (t78, 10)):
        e.wbytes(base, bytes(r.getrandbits(8) for _ in range(sz * 6 + 8)))
    limit = r.choice([0x10, 0x20, 0x40, 0xffff, 0x8000, 0x7fff, 0])
    for i in range(n):
        _w(c, t54 + 0x16 * i + 2, r.choice([0, 0, 5, 0x1234]), 2)
        _w(c, t54 + 0x16 * i, r.randrange(0, 6), 2)
        _w(c, t5a + 12 * i + 2, r.choice([0, 0, 7, 0x4321]), 2)
        _w(c, t5a + 12 * i + 0xa, r.choice([0, 0, 9, 0x1111]), 2)
        _w(c, t5a + 12 * i, r.randrange(0, 6), 2)
    for i in range(6):
        e.wbytes(t78 + 10 * i, bytes([r.choice([0, 1, 4, 8, 0x10, 0x40, 0xff])]))
    _w(c, P + 0x50, limit, 2)
    _w(c, P + 0x54, t54)
    _w(c, P + 0x5a, t5a)
    _w(c, P + 0x78, t78)
    cur = e.alloc(8, 2)
    _w(c, cur, r.choice([0, 1, limit - 1, limit, limit - 4, 5, 0x1000, 0xfff0]) & 0xffff, 2)
    this = rnd(c, 0x40)
    _w(c, this, P)
    _w(c, this + 4, cur)
    _w(c, this + 8, r.choice([0, 1, 4, 8, 0x10, 0x7fff, 0xffff, 0x80000000, 0xfffffff0]))
    _w(c, this + 0x16, r.randrange(0, n), 2)
    _w(c, this + 0x18, r.getrandbits(16), 2)
    _w(c, this + 0x1a, r.getrandbits(16), 2)
    e.wbytes(this + 0x20, bytes([r.choice([0, 1, 2, 3, 1, 2, 3, 4])]))
    return [this]


S(0x530a40, 'GUESS alloc_slot', 'thiscall', None, ret='ax', gen=_g530a40, note='batch67521')
