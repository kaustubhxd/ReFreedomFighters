"""specs_s213040.py - batch 213040: class dispatch over wide characters with a nested scanner call, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks


def g627640(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = rnd(c, 0x4c + 0x100 + 4)
    tab = [r.choice([1, 5, 6, 7, 9, 11, 14, 22, 24, 30, 0x1c, 3, 4]) for _ in range(256)]
    tab[0] = 0
    for k in range(8):
        tab[0x50 + k] = 20 + k       # first character classes 20..27
    tab[0x60] = 30                   # looks one pair ahead
    tab[0x61] = 22                   # continues
    tab[0x62] = 9                    # 0x10
    tab[0x63] = 10                   # 0x10
    tab[0x64] = 21                   # 0x10
    tab[0x65] = 24                   # continues
    tab[0x66] = 15                   # stops with 0
    tab[0x67] = 11
    tab[0x68] = 23
    tab[0x76] = 10
    tab[0x77] = 13
    tab[0x70] = 9                    # next-pair classes for the lookahead
    tab[0x71] = 12
    tab[0x72] = 21
    tab[0x73] = 22
    tab[0x74] = 30
    tab[0x75] = 5
    tab[0x2d] = 0x1b
    tab[0x3e] = 9
    e.wbytes(base + 0x4c, bytes(tab))
    out = bytearray()
    first = r.choice([0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x52, 0x54, 0x57, r.randint(1, 255)])
    out += bytes([0, first])
    if r.random() < 0.04:
        out = bytearray([r.randint(0xd8, 0xff), r.getrandbits(8)])
    for _ in range(r.randint(0, 6)):
        x = r.random()
        if x < 0.7:
            out += bytes([0, r.choice([0x61, 0x61, 0x65, 0x60, 0x62, 0x63, 0x64, 0x66, 0x67, 0x68, 0x70, 0x71, 0x76, 0x77, 0x72, 0x73, 0x74, 0x75, 0x2d, 0x3e, 0x61])])
        elif x < 0.85:
            out += bytes([r.randint(0xd8, 0xff), r.choice([0xfd, 0xfe, 0xff, r.getrandbits(8)])])
        else:
            out += bytes(r.getrandbits(8) for _ in range(2))
    if r.random() < 0.3:
        out += bytes([0, 0x60, 0, r.choice([0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x76])])
    n = len(out)
    cut = r.choice([n, n, n, max(0, n - 2), max(0, n - 1), 0 if r.random() < 0.05 else n])
    data = bytes(out) + bytes(40)
    p = rnd(c, len(data) + 8)
    e.wbytes(p, data)
    outp = rnd(c, 8)
    import os
    if os.environ.get('DBG'): print('DATA', data[:n].hex(), cut, [tab[b] for b in data[:n]])
    return [base, p, p + cut, outp]


S(0x627640, 'class_dispatch_scan', 'cdecl', None, ret='eax', gen=g627640)
