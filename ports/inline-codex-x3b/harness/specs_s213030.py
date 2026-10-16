"""specs_s213030.py - batch 213030: byte-swapped numeric reference parser, big-endian pair string compare, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _pairs(chars):
    out = bytearray()
    for ch in chars:
        out += bytes([ch & 0xff, 0])
    return out


def g624b70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hexm = r.random() < 0.5
    k = r.randint(0, 9)
    cps = [0, 1, 9, 10, 13, 0x20, 0x7f, 0x80, 0x9f, 0xff, 0x100, 0x1ff, 0xd7ff, 0xd800, 0xdbff, 0xdc00, 0xdfff, 0xe000,
           0xfffd, 0xfffe, 0xffff, 0x10000, 0x10ffff, 0x110000, 0x110001, 0x1fffff]
    if r.random() < 0.55:
        cp = r.choice(cps) if r.random() < 0.8 else r.randint(0, 0x1100ff)
        txt = ('%x' % cp if hexm else '%d' % cp).encode()
        if r.random() < 0.3:
            txt = txt.upper()
        chars = list(txt)
    elif hexm:
        alpha = b'0123456789abcdefABCDEFgxz'
        chars = [r.choice(alpha) if r.random() < 0.95 else r.randint(0, 255) for _ in range(k)]
    else:
        alpha = b'0123456789'
        chars = [r.choice(alpha) if r.random() < 0.93 else r.randint(0, 255) for _ in range(k)]
    body = (_pairs(b'x') if hexm else b'') + _pairs(chars)
    if r.random() < 0.05:
        body = body[:1] + bytes([r.getrandbits(8) | 1]) + body[2:]    # a nonzero high byte: the -1 character path
    data = bytes(4) + bytes(body) + _pairs(b';') + _pairs(b';') * 4
    buf = rnd(c, len(data) + 8)
    e.wbytes(buf, data)
    return [r.getrandbits(32), buf]


def g622980(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = rnd(c, 0x4c + 0x100 + 4)
    hot = [5, 6, 7, 5, 6, 7, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1d, 8, 0x10, 0x14, 9, 0x15, 0x1c]
    tab = [(r.choice(hot) if r.random() < 0.8 else r.getrandbits(8)) for _ in range(256)]
    tab[0] = 0x10
    e.wbytes(base + 0x4c, bytes(tab))
    n = r.randint(0, 12)
    sa = bytearray()
    for _ in range(n):
        x = r.random()
        if x < 0.6:
            sa += bytes([0, r.choice([r.getrandbits(8), r.randint(1, 20)]) or 1])
        elif x < 0.8:
            sa += bytes([r.randint(0xd8, 0xff), r.choice([0xfc, 0xfd, 0xfe, 0xff, r.getrandbits(8)])])
        else:
            sa += bytes(r.getrandbits(8) for _ in range(2))
    sb = bytearray(sa)
    for i in range(len(sb)):
        if r.random() < 0.05:
            sb[i] = r.getrandbits(8)
    ta = bytes(2)
    tb = bytes(2) if r.random() < 0.6 else bytes(r.getrandbits(8) for _ in range(2))
    if r.random() < 0.1:
        ta = bytes(r.getrandbits(8) for _ in range(2))
    a = bytes(sa) + ta + bytes(40)
    b = bytes(sb) + tb + bytes(40)
    pa = rnd(c, len(a))
    pb = rnd(c, len(b))
    e.wbytes(pa, a)
    e.wbytes(pb, b)
    return [base, pa, pb]


S(0x624b70, 'parse_char_ref_le', 'cdecl', None, ret='eax', gen=g624b70)
S(0x622980, 'wide_pair_string_equal', 'cdecl', None, ret='eax', gen=g622980)
