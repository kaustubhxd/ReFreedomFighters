"""specs_s213021.py - batch 213021: byte-swapped line/column scanner, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _c640(a, b):
    a &= 0xff
    b &= 0xff
    i = a - 0xd8
    if i < 0 or i > 0x27:
        return 0x1d
    if i < 4:
        return 7
    if i < 8:
        return 8
    if i < 39:
        return 0x1d
    return 0x1d if b < 0xfe else 0


def _cls(tab, buf, p):
    if buf[p + 1] == 0:
        return tab[buf[p]]
    return _c640(buf[p + 1], buf[p])


def g625cc0(c):
    clear_hooks(c)
    r = c.rng
    base = rnd(c, 0x4c + 0x100 + 4)
    hot = [5, 6, 7, 8, 9, 0xa, 0xa, 0x20, 0xb, 0x10, 0x1d, 9, 10]
    tab = [(r.choice(hot) if r.random() < 0.7 else r.getrandbits(8)) for _ in range(256)]
    c.emu.wbytes(base + 0x4c, bytes(tab))
    n = 0x80
    buf = bytearray(r.getrandbits(8) for _ in range(n))
    for i in range(0, n - 8, 2):
        x = r.random()
        if x < 0.5:
            buf[i + 1] = 0
        elif x < 0.7:
            buf[i + 1] = r.randint(0xd8, 0xff)
            buf[i] = r.choice([0xfc, 0xfd, 0xfe, 0xff, r.getrandbits(8)])
    p = 0
    nit = r.randint(1, 12)
    for it in range(nit):
        if it == nit - 1 and r.random() < 0.4:
            buf[p] = r.choice([0xfc, 0xfd, 0xfe, 0xff])
            buf[p + 1] = 0xff
        x = (_cls(tab, buf, p) - 5) & 0xffffffff
        if x > 5 or x in (0, 3):
            p += 2
        elif x == 1:
            p += 3
        elif x == 2:
            p += 4
        elif x == 4:
            p += 2
            if _cls(tab, buf, p) == 0xa:
                p += 2
        else:
            p += 2
    p0 = rnd(c, n + 8)
    c.emu.wbytes(p0, bytes(buf))
    st = rnd(c, 8)
    if r.random() < 0.5:
        c.emu.w32(st + 4, r.randint(0, 20))
    return [base, p0, p0 + p, st]


S(0x625cc0, 'scan_lines_cols_c', 'cdecl', None, ret='eax', gen=g625cc0)
