"""specs_s67529.py - cascade s6 batch 67529 (0x5fa640, fastcall(first, last, pat, patEnd, 3 unused dwords) ret 0x14, returns eax). Text and pattern are random strings over a tiny alphabet that mixes
upper / lower case and a few non-letters (0x4cc4b0, the real case-insensitive compare, runs unhooked in both); the pattern is often cut out of the text so that matches (including several, and
overlapping ones) occur; the buffers are followed by a distinct sentinel so reading past the end changes the result."""
from pilot import S


def _g5fa640(c):
    r = c.rng
    e = c.emu
    alpha = b'aAbBcC@[`{'
    n = r.choice([0, 1, 2, 3, 5, 8, 12, 20])
    txt = bytes(r.choice(alpha) for _ in range(n))
    m = r.choice([0, 1, 1, 2, 2, 3, 4])
    if n >= m and r.random() < 0.7:
        s0 = r.randrange(0, n - m + 1)
        pat = bytes((ch ^ 0x20) if (65 <= ch <= 90 or 97 <= ch <= 122) and r.random() < 0.5 else ch for ch in txt[s0:s0 + m])
    else:
        pat = bytes(r.choice(alpha) for _ in range(m))
    tb = e.alloc(n + 16, 1)
    e.wbytes(tb, txt + bytes(r.choice(alpha) for _ in range(16)))
    pb = e.alloc(m + 16, 1)
    e.wbytes(pb, pat + bytes(r.choice(alpha) for _ in range(16)))
    return [tb, tb + n, pb, pb + m, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x5fa640, 'GUESS find_last_nocase', 'fastcall', None, ret='eax', gen=_g5fa640, note='batch67529')
