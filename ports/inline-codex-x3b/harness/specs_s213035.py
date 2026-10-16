"""specs_s213035.py - batch 213035: delimiter scanner over wide characters, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks


def g627a80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = rnd(c, 0x4c + 0x100 + 4)
    hot = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 13, 12, 13, 14, 0x1b, 5, 6, 7, 20, 25]
    tab = [(r.choice(hot) if r.random() < 0.85 else r.getrandbits(8)) for _ in range(256)]
    tab[0] = 0      # zero padding ends the scan
    tab[0x41] = 5
    tab[0x42] = 6
    tab[0x43] = 7
    tab[0x50] = 12
    tab[0x51] = 13
    for ch in range(0x70, 0x80):
        tab[ch] = r.choice([2, 3, 4, 9, 10, 11, 14, 20, 25])
    e.wbytes(base + 0x4c, bytes(tab))
    delim = r.choice([12, 13, 12, 13, 11, r.randint(0, 15), r.getrandbits(32)])
    out = bytearray()
    mode0 = r.random()
    for _ in range(r.randint(0, 9)):
        x = r.random()
        if x < 0.7 or mode0 <= 0.65:
            out += bytes([0, r.randint(1, 255) if mode0 > 0.65 else r.randint(0x70, 0x7f)])
        elif x < 0.85:
            out += bytes([r.randint(0xd8, 0xff), r.choice([0xfc, 0xfd, 0xfe, 0xff, r.getrandbits(8)])])
        else:
            out += bytes(r.getrandbits(8) for _ in range(r.choice([1, 2, 3])))
    mode = mode0
    if mode < 0.45:
        dch = 0x50 if delim == 12 else 0x51 if delim == 13 else r.choice([0x50, 0x51])
        cc = r.choice([9, 10, 11, 12, 13, 14, 20, 29, 30, 31, 8, 0, 5, 1])
        ch2 = 0x60
        tab[ch2] = cc
        e.wbytes(base + 0x4c, bytes(tab))
        out += bytes([0, dch, 0, ch2]) + bytes(r.getrandbits(8) for _ in range(r.randint(0, 3)))
    elif mode < 0.65:
        out += bytes([0, r.choice([0x41, 0x42, 0x43])]) + (bytes([r.getrandbits(8)]) if r.random() < 0.4 else b'')
    n = len(out)
    cut = r.choice([n, n, n, max(0, n - 1), max(0, n - 2), max(0, n - 3), max(0, n - 4)])
    if 0.45 <= mode < 0.65:
        cut = n - r.choice([0, 0, 1, 2, 3, 1, 0, 2])
    data = bytes(out) + bytes(40)
    p = rnd(c, len(data) + 8)
    e.wbytes(p, data)
    outp = rnd(c, 8)
    return [delim, base, p, p + cut, outp]


S(0x627a80, 'scan_for_delimiter', 'cdecl', None, ret='eax', gen=g627a80)
