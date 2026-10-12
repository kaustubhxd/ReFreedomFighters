"""specs_s304.py - decomp area 39 (docs/20-unclaimed-39.md): 0x53d160 normal frame; calls exe 0x43e920 and 0x446ee0."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c):
    # Small integers hit exact zeros and equal components; otherwise random floats.
    if c.rng.random() < 0.5:
        return float(c.rng.randint(-3, 3))
    return c.rng.uniform(-10.0, 10.0)


def _vec(c, vals=None):
    v = _rnd(c, 0x0c)
    for i in range(3):
        c.emu.wf32(v + 4 * i, vals[i] if vals else _f(c))
    return v


def _frame(c):
    out = _rnd(c, 0x0c)
    e = _vec(c)
    s1 = _vec(c)
    s2 = _vec(c)
    if c.rng.random() < 0.15:
        s1 = e   # loc1 = 0: the cross product is zero, so the zero branch runs
    return [out, e, s1, s2]


S(0x53d160, 'normFrame (GUESS)', 'fastcall', None, ret=None, gen=_frame,
  note='batch304; ecx = out vec3, edx = e, two stack vec pointers; ret 8; exe 0x43e920 and 0x446ee0')
