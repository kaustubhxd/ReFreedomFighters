"""specs_s213007.py - batch 213007: line/column scanner and a parser step with a callback, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub


def _sim(tab, buf, n):
    """True if the walk from 0 lands exactly on n."""
    p = 0
    while p != n:
        if p > n or p < 0:
            return False
        c = tab[buf[p]] - 5
        if c < 0 or c > 5:
            p += 1
        elif c == 0:
            p += 2
        elif c == 1:
            p += 3
        elif c == 2:
            p += 4
        elif c == 3:
            p += 1
        elif c == 4:
            p += 1
            if p != n and p < len(buf) and tab[buf[p]] == 0xa:
                p += 1
        else:
            p += 1
    return True


def g622ad0(c):
    clear_hooks(c)
    r = c.rng
    base = rnd(c, 0x4c + 0x100 + 4)
    hot = [5, 6, 7, 8, 9, 0xa, 0x20, 0xb, 0x10]
    tab = [(r.choice(hot) if r.random() < 0.7 else r.getrandbits(8)) for _ in range(256)]
    c.emu.wbytes(base + 0x4c, bytes(tab))
    if r.random() < 0.05:
        n = 0
        buf = bytearray(8)
    else:
        while True:
            n = r.randint(1, 40)
            buf = bytearray(r.getrandbits(8) for _ in range(n + 8))
            if _sim(tab, buf, n):
                break
    p = rnd(c, n + 8)
    c.emu.wbytes(p, bytes(buf))
    st = rnd(c, 8)
    if r.random() < 0.5:
        c.emu.w32(st + 4, r.randint(0, 20))
    return [base, p, p + n, st]


def g62e070(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x20)
    if r.random() < 0.5:
        c.emu.w32(o + 0xc, 0)
    e = rnd(c, 0x60)
    c.emu.w32(e + 0x1c, pystub(c, 4, ret=r.choice([0, 1, r.getrandbits(32)]), pop=0))
    b = r.randint(9, 0x1f) if r.random() < 0.9 else r.getrandbits(32)
    if r.random() < 0.15:
        b = 0x1c
    return [o, b, r.getrandbits(32), r.getrandbits(32), e]


S(0x622ad0, 'scan_lines_cols', 'cdecl', None, ret='eax', gen=g622ad0)
S(0x62e070, 'parser_step_cb', 'cdecl', None, ret='eax', gen=g62e070)
