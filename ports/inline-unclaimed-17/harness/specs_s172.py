"""specs_s172.py - unclaimed area 17, slice 16: 0x460c40 ZGlobalColiObj dtor (calls exe code: 0x43de70 -> 0x45c3e0, 0x45c510).
Engine global 0x70039c is a per-case heap fake; its +0x9b geom db is a logging vtable object (virtual calls are recorded).
The object's +8 is a per-case block with +0x3c negative (skips the 0x4da720 / 0x4dc630 paths) and +0x50 zero."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dtor(c):
    eng = _rnd(c, 0x200)
    geom = _rnd(c, 0xa0)
    c.emu.w32(geom, c.emu.logging_vtable('ZGeomDb', 0x140, argwords={}))
    c.emu.w32(eng + 0x9b, geom)
    c.emu.w32(0x70039c, eng)
    inner = _rnd(c, 0x100)
    c.emu.w32(inner + 0x3c, 0x80000000)
    c.emu.w32(inner + 0x50, 0)
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 8, inner)
    return [obj, c.rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 0x11, 0x15, c.rng.getrandbits(32)])]


S(0x460c40, 'ZGlobalColiObj::~ZGlobalColiObj', 'thiscall', None, ret='eax', gen=_dtor,
  note='batch172; base teardown ext_43de70, then ext_45c510 when flags bit0 set and bit2 clear')
