"""specs_s933.py - unclaimed-09 batch 25 (docs/20-unclaimed-09.md, claim 27): 0x438840, stdcall with two arguments.

Argument 0 is a pointer p: a 0x40-byte object, zero at +0 in about half the cases (so the body runs), with random bytes
elsewhere; in about one case in four p is the global's address minus 0x21 (so p+0x21 equals global+0x40, exercising the
skip). Argument 1 is a random word that the body ignores. The global at 0x70039c is 0x2000 random bytes (no calls)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    g = _rnd(c, 0x2000)
    c.emu.w32(0x70039c, g)
    if c.rng.random() < 0.25:
        p = g + 0x1f  # p + 0x21 == g + 0x40
        c.emu.w32(p, 0)
    else:
        p = _rnd(c, 0x40)
        c.emu.w32(p, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32) | 1)
    c.emu.w8(p + 0x2e, c.rng.getrandbits(8))
    return [p, c.rng.getrandbits(32)]


S(0x438840, 'ZInputActions::ForceSetAction (unknown) stdcall', 'stdcall', None, ret=None, gen=_gen,
  note='unclaimed-09 b25; stdcall, two args, no calls out')
