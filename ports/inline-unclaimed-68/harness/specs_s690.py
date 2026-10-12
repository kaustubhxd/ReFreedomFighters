"""specs_s690.py - unclaimed-68 batch 10 (claim 9): ZGEOM::DispBound (0x45dc30) and GUESS FUN_5deaf0 (0x5deaf0).
DispBound: the object holds a random dword at +0x14, the flag is random (both branches, both flag states).
FUN_5deaf0: the object holds a float at +0 and a dword at +4; the argument is a logging object whose slot +0x4c returns a
second logging object, whose slot +0x3c logs its argument."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj


def _disp(c):
    o = zero_obj(c, 0x40)
    c.emu.w32(o + 0x14, c.rng.getrandbits(32))
    return [o, c.rng.randrange(0, 2)]


def _x(c):
    o = zero_obj(c, 0x40)
    c.emu.wbytes(o, struct.pack('<f', c.rng.uniform(-10.0, 10.0)))
    c.emu.w32(o + 4, c.rng.getrandbits(32))
    x = logged_obj(c, 'ZFun5deafX', 0x80, impl={0x3c: lambda e, a: (None, None)}, argwords={0x3c: 1})
    obj = logged_obj(c, 'ZFun5deafObj', 0x80, impl={0x4c: lambda e, a: (x, None)}, argwords={0x4c: 1})
    return [o, obj]


S(0x45dc30, 'ZGEOM::DispBound (unknown) thiscall', 'thiscall', None, ret=None, gen=_disp,
  note='unclaimed-68 batch 10; bit 2 of +0x14 and bit 0')
S(0x5deaf0, 'GUESS FUN_5deaf0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_x,
  note='unclaimed-68 batch 10; GUESS name; slot +0x4c then +0x3c')
