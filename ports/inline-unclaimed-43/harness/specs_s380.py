"""specs_s380.py - gap band batch 380: 0x411076, cdecl(out, a, b) returning out. a and b are random 3-vectors (fv values), out is
a 3-float block. Values include zeros so cancellation to zero is exercised."""
from pilot import S, F


def _gen(c):
    r = c.rng
    out = c.fbuf(3, pad=0)
    a = c.fbuf(3, pad=0)
    b = c.fbuf(3, pad=0)
    if r.random() < 0.3:
        c.emu.wf32(a + 4, 0.0)
        c.emu.wf32(b + 4, 0.0)
    if r.random() < 0.5:
        # widely different magnitudes per component, so the two products of a component differ by many binades
        for k in range(3):
            for base in (a, b):
                v = c.emu.rf32(base + 4 * k)
                if v == v and abs(v) < 1e4:
                    c.emu.wf32(base + 4 * k, v * (2.0 ** r.randrange(-40, 40)))
    c.emu.mu.ctl_flush_tb()
    return [out, a, b]


S(0x411076, 'cross product of 3-vectors (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='gap band batch 380; x87 products in extended precision, one float rounding per component')
