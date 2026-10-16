"""specs_s213057.py - single-byte name scanner with callbacks and a white space run, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub

OFFS = (0x158, 0x15c, 0x160, 0x14c, 0x150, 0x154)


def g62b040(c):
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
        seq = r.choice([[1], [1], [1], [0], [1, 0], [0, 1], [r.getrandbits(32)]])
        e.w32(base + off, pystub(c, 2, ret=lambda emu, k, seq=seq: seq[min(k, len(seq) - 1)], pop=0))
    out = bytearray()

    def ch(k):
        return 0x40 + k

    def anyc():
        return ch(r.randint(3, 37))

    def start():
        return ch(r.choice([22, 24, 22, 24, 5, 6, 7]))

    mode = r.random()
    if mode < 0.25:
        out += bytes([start(), anyc(), anyc()])
    elif mode < 0.5:
        out.append(start())
        for _ in range(r.randint(1, 3)):
            out.append(ch(r.choice([9, 10, 21])))
        out.append(anyc())
    elif mode < 0.75:
        out += bytes([anyc(), anyc(), anyc()])
    else:
        out.append(ch(r.choice([22, 24, 5, 6, 7, 29, 8, 28, 21, 11, 9, 10, 17, 19, 23, 12, r.randint(3, 37)])))
        for _ in range(r.randint(0, 5)):
            out.append(ch(r.choice([22, 24, 25, 26, 27, 5, 6, 7, 11, 21, r.randint(3, 37)])))
            out += bytes(r.getrandbits(8) for _ in range(r.choice([0, 0, 1, 2])))
    out += bytes(r.getrandbits(8) for _ in range(r.choice([0, 0, 0, 1, 2, 3])))
    n = len(out)
    cut = r.choice([n, n, n, max(1, n - 1), max(1, n - 2), 1, 2, 3])
    cut = min(cut, n)
    if r.random() < 0.04:
        cut = 0
    data = bytes(out) + bytes(40)
    p = rnd(c, len(data) + 8)
    e.wbytes(p, data)
    return [base, p, p + cut, rnd(c, 8)]


S(0x62b040, 'scan_name_ws_bytes_cb', 'cdecl', None, ret='eax', gen=g62b040)
