"""specs_s601.py - area 49 batch 601: ZFFSimpleTrain2 destructor (0x5b8400)."""
from pilot import S
from wkit import rnd, stub, obj, sysobj, patch_jmp


def _dtor(c):
    r = c.rng
    patch_jmp(c, 0x4690b0, stub(c, 2, cdecl=True))
    rm = obj(c, 0x100, {0x34: stub(c, 1)})
    sysobj(c, {})
    so = c.emu.r32(0x70039c)
    c.emu.w32(so + 0x9b, rm)
    c.emu.w32(0x7003b0, stub(c, 0))
    o = rnd(c, 0x80)
    flags = r.choice((0, 2, 4, 6, 1 | 4, 1 | 4 | 2, 1 | 4 | 0x10))
    if flags & 1 and not flags & 4:
        flags |= 4
    return [o, flags]


S(0x5b8400, 'ZFFSimpleTrain2::~ZFFSimpleTrain2', 'thiscall', None, ret='eax', gen=_dtor)
