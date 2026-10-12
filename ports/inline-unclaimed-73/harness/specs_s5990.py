"""specs_s5990.py - area 73 batch 59 (gap band, GUESS name). FUN_4f2a00 (ret 4): r = vtable +0x58 on the control object at
g_sys+0x9b with the argument; then vtable +0x2fc on this with r. Both vtables are logging stubs with one argument."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    o = _rnd(c, 0x100)
    rv = c.rng.getrandbits(32)
    ctl = _rnd(c, 0x100)
    e.w32(ctl, e.logging_vtable('ctl4f2a00', 0x60 // 4, impl={0x58: (lambda v: (lambda em, a: (v, None)))(rv)},
                                argwords={0x58: 1}))
    e.w32(o, e.logging_vtable('self4f2a00', 0x300 // 4, impl={0x2fc: lambda em, a: (0, None)}, argwords={0x2fc: 1}))
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, ctl)
    e.w32(0x70039c, sys)
    return [o, c.rng.getrandbits(32)]


S(0x4f2a00, 'GUESS FUN_4f2a00 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 73 batch 59; r = g_sys+0x9b obj vt+0x58(arg); vt+0x2fc(r) on this')
