"""specs_s310.py - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md), batch 310: 0x616fe0 (stdcall, record copy with a halved
dword) and 0x606a30 (fastcall, bounded dword copy). Pure memory."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _recs(c):
    n = c.rng.choice([0, 1, 2, 3])
    dst = _rnd(c, 0x24 * 4 + 0x40)
    src = _rnd(c, 0x24 * 4 + 0x40)
    return [dst, src, n]


def _span(c):
    b = _rnd(c, 0x80)
    cnt = c.rng.randrange(0, 12)
    e = b + 4 * cnt + c.rng.choice([0, 1, 2, 3])
    p = _rnd(c, 0x80)
    if c.rng.random() < 0.1:
        return [0, 0, 0]
    return [b, e if c.rng.random() < 0.9 else b - 4, p]


S(0x616fe0, 'copyRecords (GUESS)', 'stdcall', None, ret=None, gen=_recs, note='batch310; ret 0xc')
S(0x606a30, 'copySpan (GUESS)', 'fastcall', None, ret='eax', gen=_span, note='batch310; ret 4')
