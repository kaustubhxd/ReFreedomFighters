"""specs_s240025.py - Sonnet-w4a: zlib inflate_fast (0x6332d0) over random Huffman tables, random input and window state."""
import struct
from pilot import S
from recruits_util import clear_hooks


def _w(c):
    return c.rng.getrandbits(32)


def _ent(exop, bits, base):
    return struct.pack('<BBHI', exop, bits, 0, base & 0xffffffff)


def _table(c, bl, kind):
    """a two-level Huffman table: 2**bl first-level entries, up to 4 sub-tables of 2**sb entries each"""
    r = c.rng
    n1 = 1 << bl
    subs = []
    for _ in range(r.choice([0, 1, 2, 3, 4])):
        sb = r.randrange(1, 5)
        subs.append((sb, n1 + sum(1 << s_[0] for s_ in subs)))
    total = n1 + sum(1 << s_[0] for s_ in subs)
    ents = [None] * total

    def leaf(maxbits):
        k = r.random()
        bits = r.randrange(1, maxbits + 1)
        if kind == 'len':
            if k < 0.30:
                return _ent(0, bits, r.getrandbits(8))
            if k < 0.80:
                if r.random() < 0.15:
                    return _ent(16 | 8, bits, r.randrange(3, 5))      # 8 extra bits: tests the 4-bit mask of the extra-bit count
                return _ent(16 | r.randrange(0, 6), bits, r.randrange(3, 259))
            if k < 0.90:
                return _ent(96, bits, 0)          # end of block
            return _ent(64, bits, 0)              # invalid literal/length code
        if k < 0.85:
            return _ent(16 | r.randrange(0, 7), bits, r.randrange(1, 0x700))
        return _ent(64, bits, 0)                  # invalid distance code
    for i in range(n1):
        if subs and r.random() < 0.25:
            sb, start = r.choice(subs)
            ents[i] = _ent(sb, r.randrange(1, bl + 1), start - i)
        else:
            ents[i] = leaf(bl)
    for sb, start in subs:
        for j in range(1 << sb):
            ents[start + j] = leaf(4)
    addr = c.emu.alloc(8 * total, 4)
    c.emu.wbytes(addr, b''.join(ents))
    return addr


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    W = 0x800
    win = c.emu.alloc(W + 0x600, 4)
    e.wbytes(win, bytes(r.getrandbits(8) for _ in range(W + 0x600)))
    end = win + W
    q = win + r.choice([0, 1, 5, 0x40, 0x100, 0x200, r.randrange(0, W - 0x300), W - 258 - r.randrange(0, 60), W - 258 - r.randrange(0, 60)])
    rd = r.choice([end, end, q, q, q + 1 + r.randrange(0x100, 0x400), q + 1 + 258 + r.randrange(0, 40), q + 1 + 258 + r.randrange(0, 40), q - 1 if q > win else end, win + r.randrange(0, W)])
    ib = c.emu.alloc(0x500, 4)
    e.wbytes(ib, bytes(r.getrandbits(8) for _ in range(0x500)))
    n = r.choice([0, 5, 10, 11, 30, 100, r.randrange(10, 0x3e0)])
    s_ = c.emu.alloc(0x40, 4)
    z = c.emu.alloc(0x20, 4)
    e.w32(s_ + 0x1c, r.randrange(0, 32))
    e.w32(s_ + 0x20, _w(c) if r.random() < 0.7 else r.getrandbits(8))
    e.w32(s_ + 0x28, win)
    e.w32(s_ + 0x2c, end)
    e.w32(s_ + 0x30, rd)
    e.w32(s_ + 0x34, q)
    e.w32(z + 0, ib)
    e.w32(z + 4, n)
    e.w32(z + 8, _w(c))
    e.w32(z + 0x18, _w(c))
    bl = r.randrange(1, 10)
    bd = r.randrange(1, 10)
    tl = _table(c, bl, 'len')
    td = _table(c, bd, 'dist')
    if r.random() < 0.4:      # a length code of exactly L bytes and a distance reaching exactly L bytes past the window start: the wrap boundary
        L = r.randrange(3, 40)
        for _ in range(r.randrange(1, 4)):
            e.wbytes(tl + 8 * r.randrange(0, 1 << bl), _ent(16, r.randrange(1, bl + 1), L))
            e.wbytes(td + 8 * r.randrange(0, 1 << bd), _ent(16, r.randrange(1, bd + 1), (q - win) + L + r.choice([0, 0, -1, 1])))
    if r.random() < 0.3:      # a distance exactly as long as the data already in the window
        e.wbytes(td + 8 * r.randrange(0, 1 << bd), _ent(16, r.randrange(1, bd + 1), (q - win) + r.choice([0, 0, -1, 1])))
    return [bl, bd, tl, td, s_, z]



S(0x6332d0, 'GUESS inflate_fast', 'cdecl', None, ret='eax', gen=_gen, note='batch240025')
