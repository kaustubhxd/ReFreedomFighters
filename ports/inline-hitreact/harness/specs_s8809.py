"""specs_s8809.py - hitreact batch 8809: the 3x3 Cramer solver 0x547860 (fastcall m, b; stack out; ret 4; al)."""
from pilot import S
from wkit import fedge
from hkit import fvec


def _gen(c):
    r = c.rng
    f = lambda: r.choice((r.uniform(-2, 2), r.uniform(-500, 500), 0.0, fedge(c))) if r.random() < 0.15 else r.uniform(-2, 2)
    m = [f() for _ in range(9)]
    if r.random() < 0.1:
        m[6:9] = m[0:3]          # singular
    if r.random() < 0.05:
        m = [x * 1e-3 for x in m]   # tiny determinant
    if r.random() < 0.15:          # det = d on the 1e-6 cut (diagonal)
        d = r.choice((1e-6, 0.99e-6, 1.01e-6, -1e-6, -1.01e-6, 9.999999974752427e-07))
        m = [d, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0]
    return [fvec(c, m), fvec(c, [f() for _ in range(3)]), c.emu.alloc(16, 4)]


S(0x547860, 'Cramer 3x3 solver', 'fastcall', ret='al', gen=_gen)
