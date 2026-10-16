"""specs_s213033.py - batch 213033: wide-character comment scanner, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks


def g629580(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = rnd(c, 0x4c + 0x100 + 4)
    hot = [0, 1, 5, 6, 7, 8, 9, 0x10, 0x1b, 0x1c, 0x1d, 0x14, 0x1a, 5, 6, 7]
    tab = [(r.choice(hot) if r.random() < 0.8 else r.getrandbits(8)) for _ in range(256)]
    tab[0] = 0      # (0,0) pairs and the zero padding end the scan
    tab[0x2d] = 0x1b
    tab[0x41] = 5
    tab[0x42] = 6
    tab[0x43] = 7
    tab[0x3e] = r.choice([9, 5, 0x1b])
    e.wbytes(base + 0x4c, bytes(tab))
    out = bytearray()
    if r.random() < 0.9:
        out += bytes([0x2d, 0])
    for _ in range(r.randint(0, 10)):
        x = r.random()
        if x < 0.25:
            out += bytes([0x2d, 0])
        elif x < 0.3:
            out += bytes([0x3e, 0])
        elif x < 0.7:
            out += bytes([r.choice([r.getrandbits(8), r.randint(1, 20)]), 0])
        elif x < 0.85:
            out += bytes([r.choice([0xfc, 0xfd, 0xfe, 0xff, r.getrandbits(8)]), r.randint(0xd8, 0xff)])
        else:
            out += bytes(r.getrandbits(8) for _ in range(r.choice([1, 2, 3])))
    mode = r.random()
    if mode < 0.35:
        out += bytes([0x2d, 0, 0x2d, 0, r.choice([0x3e, 0x3e, 0x3f, 0x2d]), 0]) + bytes(r.getrandbits(8) for _ in range(r.randint(0, 4)))
    elif mode < 0.5:
        out += bytes([r.choice([0x41, 0x42, 0x43]), 0])
    n = len(out)
    cut = r.choice([n, n, n, max(0, n - 1), max(0, n - 2), max(0, n - 3)])
    if 0.35 <= mode < 0.5:
        cut = n - r.choice([1, 2, 1, 0, 0, 0, 3, 1])
    data = bytes(out) + bytes(40)
    p = rnd(c, len(data) + 8)
    e.wbytes(p, data)
    outp = rnd(c, 8)
    return [base, p, p + cut, outp]


S(0x629580, 'scan_comment_le', 'cdecl', None, ret='eax', gen=g629580)
