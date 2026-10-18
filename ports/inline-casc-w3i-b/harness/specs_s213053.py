"""specs_s213052.py - single-byte name scanner with per-width callbacks in the base object, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub

OFFS = (0x158, 0x15c, 0x160, 0x14c, 0x150, 0x154)


def g62b900(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = rnd(c, 0x200)
    tab = [r.choice([8, 8, 23, 20, 3, 4]) for _ in range(256)]
    tab[0] = 8
    for k in range(3, 38):
        tab[0x40 + k] = k           # one character for every class
    e.wbytes(base + 0x4c, bytes(tab))
    for off in OFFS:
        seq = r.choice([[1], [1], [0], [1, 0], [0, 1], [r.getrandbits(32)]])
        e.w32(base + off, pystub(c, 2, ret=lambda emu, k, seq=seq: seq[min(k, len(seq) - 1)], pop=0))
    out = bytearray()
    first = r.choice([0x40 + 22, 0x40 + 24, 0x40 + 5, 0x40 + 6, 0x40 + 7, 0x40 + 29, 0x40 + r.randint(3, 37), 0x40 + 22, 0x40 + 24])
    if r.random() < 0.4:
        first = 0x40 + r.randint(3, 37)
    out.append(first)
    for _ in range(r.randint(0, 6)):
        x = r.random()
        if x < 0.5:
            out.append(0x40 + r.choice([22, 24, 25, 26, 27, 5, 6, 7, 22, 24]))
        else:
            out.append(0x40 + r.randint(3, 37))
        out += bytes(r.getrandbits(8) for _ in range(r.choice([0, 0, 1, 2])))
    if r.random() < 0.35:
        out = bytearray([0x40 + r.choice([22, 24]), 0x40 + r.choice([18, 18, 22, 24, 25, 26, 27, 5, 6, 7, 29, 9, 10, 21, 30, 11, 32, 36, 17, 28, 19, 20, 23, 8, 12, 13, 14, 15, 16, r.randint(3, 37)])]) + bytes(r.getrandbits(8) for _ in range(r.choice([0, 0, 1, 2, 3])))
    n = len(out)
    cut = r.choice([n, n, n, max(1, n - 1), max(1, n - 2), max(1, n - 3), 1, 2, 3])
    cut = min(cut, n)
    if r.random() < 0.04:
        cut = 0
    data = bytes(out) + bytes(40)
    p = rnd(c, len(data) + 8)
    e.wbytes(p, data)
    return [base, p, p + cut, rnd(c, 8)]


S(0x62b900, 'scan_name_bytes_cb2', 'cdecl', None, ret='eax', gen=g62b900)
