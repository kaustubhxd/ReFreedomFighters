"""specs_s213020.py - batch 213020: wide numeric character reference parser, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _pairs(chars):
    out = bytearray()
    for ch in chars:
        out += bytes([0, ch & 0xff])
    return out


def g622410(c):
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
        body = bytes([r.getrandbits(8)]) + body[1:]    # a nonzero high byte: the -1 character path
    data = bytes(4) + bytes(body) + _pairs(b';') + _pairs(b';') * 4
    buf = rnd(c, len(data) + 8)
    e.wbytes(buf, data)
    return [r.getrandbits(32), buf]


S(0x622410, 'parse_char_ref', 'cdecl', None, ret='eax', gen=g622410)
