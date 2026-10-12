"""specs_s962.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x451340 (see src/batch962.cpp). The predicate 0x45f960 (claimed
elsewhere) is hooked by address with a recording stub returning a per-case bool. The argument object has a logging vtable (slot +0x3c one
argument; slot +0x10 two arguments; both callee-cleaned). The global object at [[0x70039c]+0x9b] has a logging vtable whose slot +0x4c
returns a per-case value. The predicate is false 30% of the time."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    bit = 1 if c.rng.random() < 0.7 else 0
    ss_ret = bit
    import serial_stubs as ss
    ss.patch(c, 0x45f960, ss.rec(c, 1, ret=ss_ret))
    gobj = _rnd(c, 0x80)

    def impl4c(e, a, g=gobj):
        # two results per case: the first call reads the first dword at +0x70, the second the one at +0x74
        k = int.from_bytes(bytes(e.rbytes(g + 0x60, 4)), 'little')
        e.w32(g + 0x60, k + 1)
        return (int.from_bytes(bytes(e.rbytes(g + 0x70 + 4 * k, 4)), 'little') if k < 2 else 0, None)

    c.emu.w32(gobj + 0x60, 0)
    c.emu.w32(gobj + 0x70, c.rng.getrandbits(32))
    c.emu.w32(gobj + 0x74, c.rng.getrandbits(32))
    c.emu.w32(gobj, c.emu.logging_vtable('ZGlobGroup', 0x14, impl={0x4c: impl4c}, argwords={0x4c: 1}))
    g = _rnd(c, 0x100)
    c.emu.w32(g + 0x9b, gobj)
    c.emu.w32(0x70039c, g)
    o = _rnd(c, 0x100)
    c.emu.w32(o, c.emu.logging_vtable('ZTailArg', 0x11, argwords={0x3c: 1, 0x10: 2}))
    self_o = _rnd(c, 0x100)
    return [self_o, o]


S(0x451340, 'predicate then vtable calls (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-80 gap band; predicate 0x45f960 hooked by address (claimed elsewhere); one stack argument, ret 4')
