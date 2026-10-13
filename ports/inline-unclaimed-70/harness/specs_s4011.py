"""specs_s4011.py - area 70 batch 4011: 0x4e0be0, the vector rotation by sines and cosines. The CRT sin and cos thunks
(0x634d76, 0x634d70) are the exe's own imports; the harness implements them. Source components are drawn over a wide range
(including near zero and large values) and destinations are random."""
from pilot import S, F


def _rot(c):
    e, r = c.emu, c.rng
    src = e.alloc(0x10, 4)
    for i in range(3):
        k = r.random()
        v = r.uniform(-3.5, 3.5) if k < 0.5 else (0.0 if k < 0.6 else r.uniform(-200, 200))
        e.wf32(src + 4 * i, v)
    dst = e.alloc(0x10, 4)
    for i in range(3):
        e.wf32(dst + 4 * i, r.uniform(-50, 50))
    return [dst, src]


S(0x4e0be0, 'rotate destination by sin/cos of source (name GUESS)', 'fastcall', None, gen=_rot, note='batch4011')
