"""specs_s2403.py - decomp area 24, batch 2403: the DEFLATE-style bit writer (0x6304f0, cdecl, plain ret).
The writer object A: output buffer (heap, +8) and index (+0x14), accumulator and used bits, symbol count N (+0x1698,
0..40), words W (+0x169c, zero for literals about 40% of the time) and bytes B (+0x1690). The tables T and T2 are heap
blocks of {code word, len word} pairs with lengths 0..16 (every 4-byte slot is a pair, so the +0x400 / +0x402 / +0x404
/ +0x406 reads land on pairs). The global tables (0x6c0738 ... 0x6c1100) are the exe's own data (not patched)."""
from pilot import S
from recruits_util import rnd


def _pairs(c, size):
    r = c.rng
    e = c.emu
    t = c.emu.alloc(size, 16)
    for off in range(0, size, 4):
        e.w16(t + off, r.getrandbits(16))
        e.w16(t + off + 2, r.randint(0, 16))
    return t


def _gen(c):
    r = c.rng
    e = c.emu
    A = rnd(c, 0x1800)
    n = r.randint(0, 40)
    e.w32(A + 0x1698, n)
    W = c.emu.alloc(2 * max(n, 1) + 4, 4)
    B = c.emu.alloc(max(n, 1) + 4, 4)
    for i in range(n):
        w = 0 if r.random() < 0.4 else r.randint(1, 0x7fff)
        e.w16(W + 2 * i, w)
        e.wbytes(B + i, bytes([r.getrandbits(8)]))
    e.w32(A + 0x169c, W)
    e.w32(A + 0x1690, B)
    buf = c.emu.alloc(0x800, 16)
    e.w32(A + 8, buf)
    e.w32(A + 0x14, r.randint(0, 8))
    e.w16(A + 0x16b0, r.getrandbits(16))
    e.w32(A + 0x16b4, r.randint(0, 16))
    T = _pairs(c, 0x1000)
    T2 = _pairs(c, 0x1000)
    return [A, T, T2]


S(0x6304f0, 'DEFLATE-style bit writer over a symbol list (GUESS name)', 'cdecl', None, gen=_gen, note='batch2403')
