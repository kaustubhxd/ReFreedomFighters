"""specs_s43.py - inline session batch 43 (Haiku, night): walk-tree leaf 0x4dd930 (slab-style test; fastcall P in ECX,
D in EDX, stack Q; result in al)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(c, n, zero_frac=0.0):
    a = c.emu.alloc(4 * n, 4)
    for i in range(n):
        v = 0.0 if c.rng.random() < zero_frac else c.fv()
        c.emu.wf32(a + 4 * i, v)
    return a


def _seg(c):
    r = c.rng
    P = _fl(c, 9, zero_frac=0.1 if r.random() < 0.5 else 0.0)
    if r.random() < 0.2:
        D = _fl(c, 3)
        for i in range(3):
            c.emu.wf32(D + 4 * i, 1.0)  # ties on all three axes
    else:
        D = _fl(c, 3, zero_frac=0.1)
    Q = _fl(c, 3)
    if r.random() < 0.4:
        # small-scale cases: the cubic terms land near the -2^-13 threshold
        k = r.uniform(0.02, 0.12)
        for base, n in ((P, 9), (D, 3), (Q, 3)):
            for i in range(n):
                c.emu.wf32(base + 4 * i, c.emu.rf32(base + 4 * i) * k)
    return [P, D, Q]


S(0x4dd930, 'SegBoxTest', 'fastcall', None, ret='al', gen=_seg,
  note='batch43; dominant axis of D picks s and t; compares against -2^-13 on X, Y and Z')
