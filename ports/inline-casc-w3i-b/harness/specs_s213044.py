"""specs_s213044.py - batch 213044: wide-pair tokenizer with two hooked nested scanners, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g623fa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = rnd(c, 0x4c + 0x100 + 4)
    hot = [3, 4, 5, 6, 7, 8, 9, 10, 12, 4, 4, 5, 6, 7, 4, 9, 10, 30, 11, 14, 0x15]
    tab = [(r.choice(hot) if r.random() < 0.9 else r.getrandbits(8)) for _ in range(256)]
    tab[0] = 3          # zero padding: class 3 as a later pair ends the run
    tab[0x20] = 4
    tab[0x0a] = 10
    tab[0x0d] = 9
    tab[0x30] = 3
    tab[0x31] = 30
    tab[0x41] = 5
    tab[0x42] = 6
    tab[0x43] = 7
    tab[0x32] = 8
    tab[0x33] = 22
    e.wbytes(base + 0x4c, bytes(tab))
    out = bytearray()
    if r.random() < 0.5:
        ch = r.choice([0x0d, 0x0a, 0x30, 0x31, 0x41, 0x42, 0x43, 0x0d, 0x0a, 0x32, 0x33])
        out += bytes([ch, 0])
        if ch == 0x0d and r.random() < 0.5:
            out += bytes([0x0a, 0])
    for _ in range(r.randint(0, 8)):
        x = r.random()
        if x < 0.45:
            out += bytes([r.choice([0x20, 0x61, 0x62, 0x20, r.randint(1, 255)]), 0])
        elif x < 0.9:
            out += bytes([r.choice([0x0d, 0x0a, 0x30, 0x31, 0x41, 0x42, 0x43, 0x32, 0x33]), 0])
        else:
            out += bytes([r.choice([0xfd, 0xfe, 0xff, r.getrandbits(8)]), r.randint(0xd8, 0xff)])
    n = len(out)
    cut = r.choice([n, n, n, max(0, n - 1), max(0, n - 2)]) if n else 0
    if n and r.random() < 0.15:
        cut = 2
    data = bytes(out) + bytes(40)
    p = rnd(c, len(data) + 8)
    e.wbytes(p, data)
    outp = rnd(c, 8)
    hook_rec(c, 0x62a690, 4, ret=r.getrandbits(32), pop=0)
    hook_rec(c, 0x62a030, 4, ret=r.choice([0x16, 0x16, 0, 1, r.getrandbits(32)]), pop=0)
    return [base, p, p + cut, outp]


S(0x623fa0, 'tokenize_wide_pairs', 'cdecl', None, ret='eax', gen=g623fa0)
