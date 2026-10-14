"""specs_s5737.py - unclaimed-57, band batch 37: 0x5de3e0 (GUESS). Thiscall, no args. Stubs: the engine's sub-object (global 0x70039c, +0x9b)
has slot +0x58 (one argument; returns the address of r1, a stub object); r1 has slot +0x100 (one argument, fixed result chosen in gen);
the object's +0x114 pointer is a block whose dword at +0x676 is random. The global block at 0x7003b8 (dword at +0x2c4d receives this) is a heap
fake. Recording stubs only."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _e(c):
    rv = c.rng.getrandbits(32)
    r1 = _rnd(c, 0x40)
    vt_r1 = c.emu.logging_vtable('band5de3e0_r1', 80, impl={0x100: lambda em, a: (rv, None)}, argwords={0x100: 1})
    c.emu.w32(r1, vt_r1)
    vt_sub = c.emu.logging_vtable('band5de3e0_sub', 96, impl={0x58: lambda em, a: (r1, None)}, argwords={0x58: 1})
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, vt_sub)
    eng = _rnd(c, 0x200)
    c.emu.w32(eng + 0x9b, sub)
    c.emu.w32(0x70039c, eng)
    g = _rnd(c, 0x3000)
    c.emu.w32(0x7003b8, g)
    o = _rnd(c, 0x800)
    c.emu.w32(o + 0x676, c.rng.getrandbits(32))
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 0x114, o)
    return [obj]


S(0x5de3e0, 'unnamed_5de3e0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_e,
  note='unclaimed-57 band batch 37; sub slot +0x58 and r1 slot +0x100 stubbed (logged); global 0x7003b8 heap fake')
