"""specs_s5723.py - unclaimed-57, band batch 23: 0x5de3d0 (fastcall, value in ECX) and 0x5da650 (thiscall, no args). 0x5de3d0 stores its
value at (global 0x7003b8) + 0x2c4d; the global points at a random block. 0x5da650 clears this+0x4c and calls the sub-object's slot
+0xbc with the constant 1 (a logging stub). Recording stubs only; nothing else is called."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fc(c):
    g = _rnd(c, 0x3000)
    c.emu.w32(0x7003b8, g)
    return [c.rng.getrandbits(32)]


def _th(c):
    vt = c.emu.logging_vtable('band5da650_sub', 64, argwords={0xbc: 1})
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, vt)
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 0x44, sub)
    return [obj]


S(0x5de3d0, 'unnamed_5de3d0 (GUESS) fastcall', 'fastcall', None, ret=None, gen=_fc,
  note='unclaimed-57 band batch 23; stores ECX at global 0x7003b8 + 0x2c4d')
S(0x5da650, 'unnamed_5da650 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_th,
  note='unclaimed-57 band batch 23; sub slot +0xbc stubbed (logged)')
