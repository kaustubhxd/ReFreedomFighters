"""specs_s213068.py - batch 213068: single-byte markup section end scanner with width callbacks, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub

OFFS = (0x164, 0x168, 0x16c)


def g626850(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = rnd(c, 0x200)
    tab = [r.choice([2, 3, 11, 12, 20, 0, 1, 8]) for _ in range(256)]
    for k in range(11):
        tab[0x40 + k] = k
    tab[0x5d] = r.choice([2, 3, 4, 5, 9, 10, 0, 11])
    tab[0x3e] = r.choice([2, 3, 4, 5, 9, 10, 8, 11])
    e.wbytes(base + 0x4c, bytes(tab))
    for off in OFFS:
        seq = r.choice([[1], [0], [0], [0, 1], [1, 0], [0, 0, 1], [r.getrandbits(32)]])
        e.w32(base + off, pystub(c, 2, ret=lambda emu, k, seq=seq: seq[min(k, len(seq) - 1)], pop=0))

    def tok(k):
        b = bytes([0x40 + k]) if k < 11 else bytes([r.choice([0x60, 0x61, 0x7f, 0x90])])
        if k in (5, 6, 7):
            b += bytes(r.getrandbits(8) for _ in range(k - 4))
        return b
    first = r.choice(list(range(11)) * 2 + [11, 12])
    out = bytearray(tok(first))
    short = r.random() < 0.25
    if short:
        if first == 4 and r.random() < 0.5:
            out += bytes([0x5d])
        if first == 9:
            out += tok(r.choice([3, 10, 9, 5]))
        if first in (5, 6, 7) and r.random() < 0.6:
            out = out[:len(out) - r.randint(1, first - 4)]
        n = len(out)
        p = rnd(c, n + 8)
        e.wbytes(p, bytes(out))
        return [base, p, p + n, rnd(c, 8)]
    if first == 4 and r.random() < 0.7:
        out += bytes([0x5d, 0x3e]) if r.random() < 0.6 else bytes([0x5d, r.choice([0x3d, 0x5d, 0x40])])
    if first == 9 and r.random() < 0.6:
        out += tok(r.choice([10, 10, 3, 9]))
    for _ in range(r.randint(0, 8)):
        k = r.choice([0, 1, 2, 3, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10, 11, 12])
        out += tok(k)
    if r.random() < 0.2:
        out = out[:max(1, len(out) - r.randint(1, 3))]
    n = len(out)
    p = rnd(c, n + 8)
    e.wbytes(p, bytes(out))
    outp = rnd(c, 8)
    if r.random() < 0.04:
        return [base, p, p, outp]
    return [base, p, p + n, outp]


S(0x626850, 'markup_section_end_scanner', 'cdecl', None, ret='eax', gen=g626850)
