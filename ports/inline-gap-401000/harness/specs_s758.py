"""specs_s758.py - gap band batch 758 (docs/20-gap-band-401000.md): 0x410db0, cdecl (p, b). p is a block of four dwords; b is any value
(small or large, both signs), so the sign-dependent rounding is exercised."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    p = _rnd(c, 0x20)
    b = c.rng.choice([c.rng.randint(-40, 40), c.rng.randint(-0x10000, 0x10000), c.rng.getrandbits(32)])
    return [p, b & 0xffffffff]


S(0x410db0, 'CRT helper 0x410db0 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='gap band batch 758: bit-position update with signed rounding')
