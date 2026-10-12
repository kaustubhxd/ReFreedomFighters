"""specs_s306.py - decomp area 39 (docs/20-unclaimed-39.md): 0x478ea0 keyed curve sample; exe 0x478f90, 0x43e920, 0x441940, 0x4e0d00."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _curve(c):
    e = c.emu
    n = c.rng.randint(2, 6)
    # The first key is 0 and the table is non-decreasing: the exe reads entry i-1, so a t below key 0 (index 0 with
    # a read before the table) is outside the real domain and is not generated.
    keys = [0.0] + sorted(c.rng.uniform(0.0, 4.0) for _ in range(n - 1))
    if c.rng.random() < 0.3 and n > 2:
        k = c.rng.randrange(1, n)
        keys[k] = keys[k - 1]                      # equal neighbours: dk == 0
    elif c.rng.random() < 0.3 and n > 2:
        k = c.rng.randrange(1, n)
        keys[k] = keys[k - 1] + 1e-5               # tiny gap: |dk| below 2^-13, division skipped
        keys = keys[:k] + [keys[k]] + [max(v, keys[k]) for v in keys[k + 1:]]
    arr = _rnd(c, 16 * n)
    for i in range(n):
        e.wf32(arr + 16 * i, keys[i])
        for k in (4, 8, 0xc):
            e.wf32(arr + 16 * i + k, c.rng.uniform(-5.0, 5.0))
    self_ = _rnd(c, 0x20)
    e.w32(self_ + 0x0, c.rng.randrange(n))             # cursor, starts in range
    end = keys[-1] + (c.rng.uniform(-0.5, 1.0) if c.rng.random() < 0.5 else 0.0)
    e.wf32(self_ + 0x4, end)
    e.w32(self_ + 0x8, n)
    e.w32(self_ + 0xc, arr)
    o = _rnd(c, 0x0c)
    r = c.rng.random()
    if r < 0.1:
        t = -abs(c.rng.uniform(0.0, 2.0))
    elif r < 0.2:
        t = end                                         # exact end: takes the t >= E branch
    elif r < 0.3:
        t = keys[c.rng.randrange(n)]                    # exact key
    else:
        t = c.rng.uniform(-1.0, max(keys[-1], end) + 1.0)
    return [self_, o, _fb(t)]


S(0x478ea0, 'keyedCurve (GUESS)', 'thiscall', None, ret=None, gen=_curve,
  note='batch306; stack pointer o and float t; ret 8; exe 0x478f90 (cursor search), 0x43e920, 0x441940, 0x4e0d00')
