"""specs_s5719.py - unclaimed-57, batch 19: 0x655b40 (GUESS). Stdcall, one argument n (the count), ret 4, returns eax. The engine
(global 0x70039c) field +0x190f is a stub object o with slot +0x20 (no arguments, returns the address of r); r has slot +0x14 (one
argument, returns a fixed value chosen in gen). n is zero in about one case in five, so the zero path runs too. Both slots are unverified
and stubbed."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _n(c):
    e = c.emu
    rval = c.rng.getrandbits(32)
    r = _rnd(c, 0x40)
    vt_r = e.logging_vtable('m655_r', 32, impl={0x14: lambda em, a: (rval, None)}, argwords={0x14: 1})
    e.w32(r, vt_r)
    vt_o = e.logging_vtable('m655_o', 40, impl={0x20: lambda em, a: (r, None)}, argwords={})
    o = _rnd(c, 0x40)
    e.w32(o, vt_o)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x190f, o)
    e.w32(0x70039c, eng)
    n = 0 if c.rng.random() < 0.2 else c.rng.getrandbits(30)
    return [n]


S(0x655b40, 'unnamed_655b40 (GUESS) stdcall', 'stdcall', None, ret='eax', gen=_n,
  note='unclaimed-57 batch 19; engine +0x190f object slot +0x20 and its result slot +0x14 stubbed')
