"""specs_s826.py - core batch 826 (docs/20-unclaimed-65.md). 0x438290: stdcall, one argument (the scan code), ret 4. Pure: no calls. The render
object's byte at +0x6e is random. The table at 0x6e492c has 0..4 (key, value) pairs and a zero key ends it; the argument is one of the keys,
or random. Everything is written in gen."""
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
    render = _rnd(c, 0x200)
    c.emu.wbytes(render + 0x6e, bytes([c.rng.choice([0, 0, 1])]))
    c.emu.w32(0x70039c, render)
    n = c.rng.randint(0, 4)
    keys = [c.rng.randint(1, 0x7fffffff) for _ in range(n)]
    for i, k in enumerate(keys):
        c.emu.w32(0x6e492c + 8 * i, k)
        c.emu.w32(0x6e4928 + 8 * i, c.rng.getrandbits(32))
    c.emu.w32(0x6e492c + 8 * n, 0)
    key = c.rng.choice(keys + [c.rng.getrandbits(32), 0, 0x7fffffff]) if keys else c.rng.getrandbits(32)
    return [key]


S(0x438290, 'ZInputActions::ConvertScanCode (unknown) stdcall one arg', 'stdcall', None, ret='eax', gen=_gen,
  note='core batch 826: pass-through or table lookup of the scan code')
