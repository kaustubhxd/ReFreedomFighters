"""specs_s49003.py - cascade u2 batch 49003: 0x407770 (cdecl(x, lpc, n, m), returns the error in st0). x: n floats (0..24; sometimes all zero or a repeated value so the zero-error exit is
taken), lpc: m floats of random bytes (m 0..8) so every store is visible."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks


def _g407770(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5, 8, 12, 16, r.randrange(0, 25)])
    m = r.choice([0, 1, 2, 3, 4, 5, 6, 8, r.randrange(0, 9)])
    k = r.random()
    if k < 0.12:
        vals = [0.0] * n
    elif k < 0.2:
        v = c.fv(-4, 4, 0.1)
        vals = [v] * n
    elif k < 0.3:
        vals = [r.choice([0.0, 0.0, 1.0, -1.0]) for _ in range(n)]
    else:
        vals = [c.fv(-8, 8, 0.05) for _ in range(n)]
    x = e.alloc(4 * n + 16, 4)
    e.wbytes(x, struct.pack('<%df' % n, *vals) + bytes(r.getrandbits(8) for _ in range(16)))
    lpc = rnd(c, 4 * m + 16)
    return [x, lpc, n, m]


S(0x407770, 'GUESS autocorrelation + Levinson-Durbin LPC', 'cdecl', None, ret='st0', gen=_g407770, note='batch49003')
