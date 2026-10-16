"""specs_s5757.py - unclaimed-57, band batch 57 (GUESS): 0x5d9f00, stdcall with three args (a, b, c), ret 12. The engine's object (global 0x70039c,
+0x9b) has a logging slot +0x58 (one arg) that returns a pointer to a stub object s, or 0 in about one case in five. s has logging slots +0xbc and
+0x250 (one argument each). The arguments b and c are zero in about half the cases, so every branch runs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _tri(c):
    vt_s = c.emu.logging_vtable('band5d9f00_s', 160, argwords={0xbc: 1, 0x250: 1})
    s = _rnd(c, 0x40)
    c.emu.w32(s, vt_s)
    sv = 0 if c.rng.random() < 0.2 else s
    vt_obj = c.emu.logging_vtable('band5d9f00_obj', 40, impl={0x58: lambda em, a: (sv, None)}, argwords={0x58: 1})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt_obj)
    eng = _rnd(c, 0x100)
    c.emu.w32(eng + 0x9b, obj)
    c.emu.w32(0x70039c, eng)
    b = 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    cc = 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    return [c.rng.getrandbits(32), b, cc]


S(0x5d9f00, 'unnamed_5d9f00 (GUESS) stdcall', 'stdcall', None, ret=None, gen=_tri,
  note='unclaimed-57 band batch 57; engine object slot +0x58 and returned object slots +0xbc, +0x250 stubbed (logged)')
