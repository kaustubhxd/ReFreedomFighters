"""specs_s776.py - gap band batch 776 (docs/20-gap-band-401000.md): 0x40b6a0, cdecl (a1..a5). The values are in [-1000, 1000] with a2 != a1,
so the signed divide cannot fault and the product cannot overflow."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _gen(c):
    a1 = c.rng.randint(-1000, 1000)
    a2 = a1
    while a2 == a1:
        a2 = c.rng.randint(-1000, 1000)
    vals = [a1, a2, c.rng.randint(-0x8000, 0x8000), c.rng.randint(-0x8000, 0x8000), c.rng.randint(-1000, 1000)]
    return [v & 0xffffffff for v in vals]


S(0x40b6a0, 'CRT helper 0x40b6a0 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='gap band batch 776: integer interpolation with signed divide')
