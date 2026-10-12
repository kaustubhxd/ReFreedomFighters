"""specs_s6237.py - unclaimed-62 claim 30 (short SSE vector helpers, fastcall): 0x4dfd50 (dst in ecx, b in edx, a as one stack word), 0x4dfd80 (dst in
ecx, src in edx; dst[0] and dst[1] get sums) and 0x4e0010 (the same with subtraction). Each vector is a 0x10-byte block of finite floats (the
sums and differences stay finite, so no NaN ordering is involved). The stack word is a pointer to a vector block. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, sf


def _vec(c):
    e = c.emu
    v = rnd(c, 0x10)
    e.wf32(v, sf(c.fv(-300, 300)))
    e.wf32(v + 4, sf(c.fv(-300, 300)))
    return v


def _x4dfd50(c):
    return [_vec(c), _vec(c), _vec(c)]


def _x2(c):
    return [_vec(c), _vec(c)]


S(0x4dfd50, 'unnamed 0x4dfd50', 'fastcall', None, gen=_x4dfd50, n=300)
S(0x4dfd80, 'unnamed 0x4dfd80', 'fastcall', None, gen=_x2, n=300)
S(0x4e0010, 'unnamed 0x4e0010', 'fastcall', None, gen=_x2, n=300)
