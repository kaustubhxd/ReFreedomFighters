"""specs_s31.py - inline session batch 31 (Haiku, evening): 0x4e0d80 vsetlen (uses the CRT sqrt import through 0x634d7c)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vl(c):
    r = c.rng
    v = c.emu.alloc(0x20, 4)
    if r.random() < 0.25:
        vals = [0.0, 0.0, 0.0]
    else:
        vals = [c.fv(), c.fv(), c.fv()]
    for i, x in enumerate(vals):
        c.emu.wf32(v + 4 * i, x)
    return [v, F(c.fv())]


S(0x4e0d80, 'vsetlen', 'thiscall', None, ret=None, gen=_vl,
  note='batch31; scales three floats to length s; zero length leaves them; sqrt through the CRT import')
