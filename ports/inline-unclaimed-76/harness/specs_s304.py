"""specs_s304.py - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x605ac0 (find-any) and 0x605b20 (span-not), both
case-insensitive scans over bytes with the exe's 0x4cc4b0 test (pure; no stubs)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _text(c, n):
    alph = b'abcXYZ[@`{ '
    return bytes(c.rng.choice(alph) for _ in range(n))


def _scan(c):
    e = c.emu
    hay_n = c.rng.randrange(0, 12)
    pat_n = c.rng.randrange(0, 5)
    hay = _rnd(c, 0x40)
    e.wbytes(hay, _text(c, hay_n))
    pat = _rnd(c, 0x20)
    e.wbytes(pat, _text(c, pat_n))
    begin = hay
    end = hay + hay_n
    s1 = pat
    s2e = pat + pat_n
    return [begin, end, s1, s2e, c.rng.getrandbits(32)]


S(0x605ac0, 'findAny (GUESS)', 'fastcall', None, ret='eax', gen=_scan, note='batch304; band 0x601000-0x621000; ret 0xc')
S(0x605b20, 'spanNot (GUESS)', 'fastcall', None, ret='eax', gen=_scan, note='batch304; band 0x601000-0x621000; ret 0xc')
