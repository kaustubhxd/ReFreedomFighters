"""specs_s213017.py - batch 213017: multi-width string compare via a class table, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks

TERM = 0xaa


def g622310(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = rnd(c, 0x4c + 0x100 + 4)
    hot = [5, 6, 7, 5, 6, 7, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1d, 8, 0x10, 0x14, 9, 0x15, 0x1c]
    tab = [(r.choice(hot) if r.random() < 0.8 else r.getrandbits(8)) for _ in range(256)]
    tab[TERM] = 0x10
    e.wbytes(base + 0x4c, bytes(tab))
    n = r.randint(0, 16)
    sa = bytearray(r.choice([r.getrandbits(8), r.randint(0, 20)]) for _ in range(n))
    sa = bytearray(x if x != TERM else 1 for x in sa)
    sb = bytearray(sa)
    for i in range(len(sb)):
        if r.random() < 0.06:
            sb[i] = r.getrandbits(8)
    ta = TERM
    tb = TERM if r.random() < 0.6 else r.getrandbits(8)
    if r.random() < 0.1:
        ta = r.getrandbits(8)
    if r.random() < 0.25:
        tb = (ta - 1) & 0xff
    a = bytes(sa) + bytes([ta]) + bytes([TERM]) * 40
    b = bytes(sb) + bytes([tb]) + bytes([TERM]) * 40
    pa = rnd(c, len(a))
    pb = rnd(c, len(b))
    e.wbytes(pa, a)
    e.wbytes(pb, b)
    return [base, pa, pb]


S(0x622310, 'wide_string_equal', 'cdecl', None, ret='eax', gen=g622310)
