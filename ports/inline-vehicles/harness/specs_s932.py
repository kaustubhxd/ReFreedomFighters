"""specs_s932.py - vehicles batch 932: ZVehicle ctor and deleting dtor. The base ctor/dtor, the message list
push and the dealloc are stood in for each case (both runs)."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, hookrec


def g_ctor(c):
    hookrec(c, 0x511cd0, 3)          # ZMoveOnSpline base ctor, callee pops 12
    hookrec(c, 0x4301c0, 2, skip=(1,))   # list push, callee pops 8; skip the stack pointer to item
    s = _rnd(c, 0x200)
    lst = c.emu.alloc(16, 4)
    base = c.emu.alloc(32, 4)
    c.emu.w32(lst + 4, base)
    c.emu.w32(lst + 8, base + (4 * c.rng.randint(0, 3)))
    c.emu.w32(0x7003b8, c.emu.alloc(0x500, 4))
    c.emu.w32(c.emu.r32(0x7003b8) + 0x4a4, c.emu.r32(lst + 4)) if False else None
    g = c.emu.alloc(0x500, 4)
    c.emu.w32(g + 0x4a0 + 4, base)
    c.emu.w32(g + 0x4a0 + 8, c.emu.r32(lst + 8))
    c.emu.w32(0x7003b8, g)
    rm = obj(c, 0x200, {0x114: _stub(c, 4, ret=c.rng.randint(1, 0xffff)), 0x4c: _stub(c, 1, ret=r32(c))})
    c.emu.w32(s + 0x9b, rm)
    c.emu.w32(0x70039c, s)
    info, name, geom = r32(c), r32(c), r32(c)
    v = _rnd(c, 0x400)
    path = _rnd(c, 0x80)
    c.emu.w32(v + 0x5c, path)
    return [v, info, name, geom]


S(0x514940, 'ZVehicle::ZVehicle', 'thiscall', ret='eax', gen=g_ctor)


def g_dtor(c):
    hookrec(c, 0x512070, 0)
    hookrec(c, 0x45c510, 1, this=False, cdecl=True)
    return [_rnd(c, 0x400), c.rng.choice([0, 1, 3, 5, 7])]


S(0x514b90, 'ZVehicle::~ZVehicle', 'thiscall', ret='eax', gen=g_dtor)
