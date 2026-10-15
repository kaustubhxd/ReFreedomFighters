"""specs_s45002.py - tier H slice 5: 0x4053f0 integer n-th root of m (struct {n, m}); real CRT import chain, n in 1..8, m up to 2^31-1, exact roots and off-by-one neighbours."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks


def _g4053f0(c):
    clear_hooks(c)
    r = c.rng
    for slot, nm in ((0x67630c, 'stub_ci_pow'), (0x67635c, 'stub_floor'), (0x676334, 'stub_ftol')):
        c.emu.w32(slot, c.emu.symbols[nm])
    n = r.choice([1, 2, 3, 4, 5, 6, 7, 8, r.randint(1, 10)])
    lo_, hi_ = 1, 2 ** 31
    while lo_ < hi_:   # largest kmax with (kmax + 2) ** n < 2 ** 31
        mid = (lo_ + hi_ + 1) // 2
        if (mid + 2) ** n < 2 ** 31:
            lo_ = mid
        else:
            hi_ = mid - 1
    kmax = lo_
    k = r.choice([0, 1, 2, 3, 5, 10, 31, 100, 1000, kmax, r.randint(0, kmax)])
    k = min(k, kmax)
    lo, hi = k ** n, (k + 1) ** n - 1
    m = r.choice([lo, lo, hi, lo + 1, hi - 1, r.randint(lo, hi)])
    m = max(1, min(m, 2 ** 31 - 1))
    bias = r.choice([0.0, 0.0, 1.0, -1.0, 2.0, -2.0, 3.5, -3.5]) if r.random() < 0.6 and k >= 4 and (k + 6) ** n < 2 ** 31 else 0.0
    c.emu.wbytes(c.emu.symbols['stub_pow_bias'], struct.pack('<d', bias))
    p = rnd(c, 16)
    c.emu.wbytes(p, struct.pack('<ii', n, m))
    return [p]


S(0x4053f0, 'GUESS integer nth root', 'cdecl', None, ret='eax', gen=_g4053f0, note='batch45002', max_insns=20000)
