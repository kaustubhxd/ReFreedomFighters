"""specs_u69_86.py - area 69, gameplay-core residue-8 destructor 0x519440 (ZMoveOnSplineIf, scalar deleting).
GUESS stubs: 0x500a10 (base class destructor, thiscall, no args) and 0x634273 (sized delete, cdecl, two args). Both are logging hooks.
The hooks log only booleans (ECX/pointer equality) and the size, never pointers."""
from pilot import S
from ckit import rnd


def _dtor(c):
    e = c.emu
    obj = rnd(c, 0x40)
    e.hook(0x500a10, lambda e, res: (e.calllog.append(('base500a10', int(e.reg('ecx') == obj))), e.ret(argbytes=0)))
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == obj), e.arg32(1))), e.ret(argbytes=0)))
    return [obj, c.rng.getrandbits(32)]


S(0x519440, 'ZMoveOnSplineIf::~ZMoveOnSplineIf (scalar deleting, thiscall, one stack arg, ret 4)', 'thiscall', None, ret='eax', gen=_dtor,
  note='u69 gameplay-core; GUESS stubs 0x500a10 (base dtor) and 0x634273 (sized delete)')
