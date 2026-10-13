"""specs_s337.py - area 71 batch 337: 0x478420, stdcall with three float arguments (x, a, b), ret 0xc, result in ST0.
x is exactly 0.0 (or -0.0) in 20% of cases, which takes the zero path; NaN is drawn sometimes and takes the general path."""
from pilot import S, F


def _gen(c):
    r = c.rng
    x = F(0.0) if r.random() < 0.1 else (F(-0.0) if r.random() < 0.1 else F(c.fv(-20.0, 20.0)))
    a = F(c.fv(-20.0, 20.0))
    b = F(c.fv(-20.0, 20.0))
    c.emu.mu.ctl_flush_tb()
    return [x, a, b]


S(0x478420, 'ratio of difference (unknown) stdcall', 'stdcall', None, ret='st0', gen=_gen,
  note='area 71 batch 337 (leaf, residue 10); float result in ST0')
