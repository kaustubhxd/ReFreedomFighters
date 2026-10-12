"""specs_s309.py - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md), batch 309: 0x616fa0 (stdcall; pure memory)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _pack(c):
    n = c.rng.choice([0, 1, 2, 5, c.rng.randrange(0, 9)])
    dst = _rnd(c, 4 * 16 + 16)
    src = _rnd(c, 0x18 + 0x24 * 10 + 16)
    return [dst, src, n]


S(0x616fa0, 'packHalf (GUESS)', 'stdcall', None, ret='eax', gen=_pack, note='batch309; ret 0xc')
