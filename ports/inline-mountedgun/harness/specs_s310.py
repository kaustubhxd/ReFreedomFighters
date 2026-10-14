"""specs_s310.py - mounted gun batch 310: vangpul (0x4e0130). vnorm, PSVECSubtract, PSVECAdd and the CRT
acos/sin/cos run as exe code / built-in stubs on both sides."""
import math
from pilot import S, F


def _vec(c, base=None):
    r = c.rng
    k = r.random()
    if base and k < 0.15:
        v = list(base)                                          # same direction
    elif base and k < 0.25:
        v = [-x for x in base]                                  # opposite (NaN stays NaN)
    elif base and k < 0.4:
        s = r.uniform(0.5, 3)
        v = [max(-3.4e38, min(3.4e38, x * s + c.fv(-0.05, 0.05, 0))) for x in base]   # nearly parallel
    elif k < 0.45:
        v = [0.0, 0.0, 0.0]
    else:
        v = [c.fv(-5, 5) for _ in range(3)]
    a = c.emu.alloc(4 * 11, 4)
    for i in range(11):
        c.emu.wf32(a + 4 * i, v[i] if i < 3 else c.fv())
    return a, v


def _gen(c):
    r = c.rng
    a, av = _vec(c)
    b, _ = _vec(c, av)
    k = r.random()
    m = r.uniform(0, 0.5) if k < 0.6 else (r.uniform(0, math.pi) if k < 0.9 else c.fv())
    out = c.emu.alloc(4 * 11, 4)
    for i in range(11):
        c.emu.wf32(out + 4 * i, c.fv())
    return [out, a, b, F(m)]


S(0x4e0130, 'vangpul', 'fastcall', None, ret='al', gen=_gen, note='batch310; x87 normalise; CRT acos/sin/cos')
