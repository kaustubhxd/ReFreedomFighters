"""specs_s36.py - inline session batch 36 (Haiku, night): createmat 0x4de040 (fastcall: out, p, q on the stack). vnorm and vcross
run as original code through ext_ symbols; the normalise is double arithmetic."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vec3(c, zero_frac=0.15):
    r = c.rng
    v = c.emu.alloc(0x20, 4)
    if r.random() < zero_frac:
        vals = [0.0, 0.0, 0.0]
    else:
        vals = [c.fv(), c.fv(), c.fv()]
        if r.random() < 0.2:
            vals[r.randint(0, 2)] = 0.0
    for i, x in enumerate(vals):
        c.emu.wf32(v + 4 * i, x)
    return v


def _cm(c):
    r = c.rng
    out = _rnd(c, 0x30)
    p = 0 if r.random() < 0.2 else _vec3(c)
    if r.random() < 0.2:
        q = 0
    elif r.random() < 0.3 and p:
        q = _vec3(c)
        for i in range(3):
            c.emu.wf32(q + 4 * i, c.rng.choice([1.0, 0.0, -1.0]) * (1.0 if r.random() < 0.5 else c.fv()))
    else:
        q = _vec3(c)
    return [out, p, q]


S(0x4de040, 'createmat', 'fastcall', None, ret=None, gen=_cm,
  note='batch36; frame from p and q: normalised p, cross with the reference vector, normalised; one stack arg q')
