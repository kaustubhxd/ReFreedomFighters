"""specs_s785.py - gap band batch 785 (docs/20-gap-band-401000.md): 0x402290, cdecl (p, out). The record has the count object X at +4 (X[1] is
the count, 0 to 5), the source array at +8 and the destination at +0xc, idx at +0x18 and the limit at +0x30. The index is in range in most cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    n = c.rng.randint(0, 5)
    X = _rnd(c, 0x20)
    c.emu.w32(X + 4, n)
    A = _rnd(c, 0x40)
    B = _rnd(c, 0x40)
    p = _rnd(c, 0x40)
    c.emu.w32(p + 4, X)
    c.emu.w32(p + 8, A)
    c.emu.w32(p + 0xc, B)
    c.emu.w32(p + 0x18, c.rng.randint(-2, 6) & 0xffffffff)
    c.emu.w32(p + 0x30, c.rng.randint(0, 8))
    out = _rnd(c, 0x10) if c.rng.random() < 0.7 else 0
    return [p, out]


S(0x402290, 'CRT helper 0x402290 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  setup=lambda c: (c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000), c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)),
  note='gap band batch 785: index copy into an output array, store the pointer')
