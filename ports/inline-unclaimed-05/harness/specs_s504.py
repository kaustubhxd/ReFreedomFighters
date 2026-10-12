"""specs_s504.py - unclaimed-05 batch 4 (claim 4): ZFFHeroIf::calcPositionInBox (0x55f900), stdcall, ret 0xc.
The geom holds a pointer at +8 to a sub-struct with two scale floats (+0x40, +0x48). The engine object at 0x70039c is a
logging vtable whose slot +0x1c0 takes (file, line) and returns a float in ST0 (the two values come from the gen, in call
order). Vec3 scaled add (0x451890) is the original code, so its effect is compared as memory."""
import struct
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(c):
    return c.fv(-50.0, 50.0)


def _calc(c):
    q = c.emu.alloc(0x80, 16)
    c.emu.wbytes(q, bytes(0x80))
    c.emu.wbytes(q + 0x40, struct.pack('<f', F(_fl(c))))
    c.emu.wbytes(q + 0x48, struct.pack('<f', F(_fl(c))))
    geom = c.emu.alloc(0x40, 16)
    c.emu.wbytes(geom, bytes(0x40))
    c.emu.w32(geom + 8, q)
    a = _rnd(c, 0x30)
    b = _rnd(c, 0x40)
    vals = [F(_fl(c)), F(_fl(c))]
    eng = c.emu.alloc(0x100, 16)
    c.emu.wbytes(eng, bytes(0x100))
    vt = c.emu.logging_vtable('ZEngine', 0x71, impl={0x1c0: lambda e, a_: (None, vals.pop(0))},
                              argwords={0x1c0: 2})
    c.emu.w32(eng, vt)
    c.emu.w32(0x70039c, eng)
    return [geom, a, b]


S(0x55f900, 'ZFFHeroIf::calcPositionInBox (unknown) stdcall', 'stdcall', None, ret=None, gen=_calc,
  note='unclaimed-05 batch 4; scaled adds via 0x451890 on arg3; engine vcall slot +0x1c0 (stubbed)')
