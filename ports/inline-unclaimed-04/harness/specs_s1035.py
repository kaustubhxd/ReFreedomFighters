"""specs_s1035.py - unclaimed-04 batch 35 (docs/20-unclaimed-04.md): two pure pattern-pair matchers (cdecl; four stack arguments, the first unused).
s, e (end, compared only), p (0-terminated pattern). 0x622b70 matches pairs (0, c); 0x625af0 matches pairs (c, 0).
The strings are built per case so that matches, prefix matches and mismatches all come up; the end pointer is s + 2k
(a match at the end) or a random value (never read)."""
from pilot import S


def _buf(c, pairs_first_zero, pat):
    s = bytearray()
    for ch in pat:
        if pairs_first_zero:
            s += bytes([0, ch])
        else:
            s += bytes([ch, 0])
    k = c.rng.randrange(0, 6)
    for _ in range(k):
        s += bytes([c.rng.getrandbits(8), c.rng.getrandbits(8)])
    if c.rng.random() < 0.3 and len(s) >= 2:
        i = c.rng.randrange(len(s))
        s[i] = c.rng.getrandbits(8)
    return bytes(s)


def _gen(first_zero):
    def g(c):
        pat = bytes(c.rng.choice(b'ab') for _ in range(c.rng.randrange(0, 4)))
        s_bytes = _buf(c, first_zero, pat)
        size = len(s_bytes) + 0x10
        s = c.emu.alloc(size, 4)
        c.emu.wbytes(s, s_bytes + bytes(size - len(s_bytes)))
        # the end pointer stays inside the buffer (the loop reads two bytes at a time up to e): e is the end of the bytes or
        # a pair boundary inside the slack
        e = s + len(s_bytes) if c.rng.random() < 0.5 else s + 2 * c.rng.randrange(0, 6)
        pb = pat + b'\0'
        p = c.emu.alloc(len(pb) + 4, 4)
        c.emu.wbytes(p, pb)
        return [c.rng.getrandbits(32), s, e, p]  # the first argument is not read
    return g


S(0x622b70, 'unknown::pair_match_zero_first (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen(True),
  note='unclaimed-04 batch 35; leaf (GUESS)')
S(0x625af0, 'unknown::pair_match_zero_second (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen(False),
  note='unclaimed-04 batch 35; leaf (GUESS)')
