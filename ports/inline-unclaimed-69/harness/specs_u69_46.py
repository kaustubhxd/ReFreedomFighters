"""specs_u69_46.py - area 69, group 46 (slice 8): 0x645250 (SEH tag: the frame is not reproduced).
GUESS stubs: 0x641b60 (other area, thiscall, one arg, ret 4), 0x634273 (sized delete, CRT, cdecl). The fake vtable's slot 0x94 is the
virtual call. Only small integers are logged; pointers are compared as booleans."""
from pilot import S
from ckit import rnd, rvt


def _gen(c):
    e = c.emu
    o = rnd(c, 0x300)
    g = rnd(c, 0x1b00)
    e.w32(0x70039c, g)
    obj = rnd(c, 0x20)
    r_val = c.rng.choice([0, 0x1234, 0x5678])
    vt = rvt(e, 'boneobj', {0x94: (0, lambda e, ecx, args: (r_val, None, ('vt94',)))}, nslots=0x98 // 4)
    e.w32(obj, vt)
    e.w32(g + 0x1aa3, obj)
    e.w32(o + 0x291, c.rng.choice([0, 0x7, 0x13]))
    e.hook(0x641b60, lambda e, res: (e.calllog.append(('t641b60', e.reg('ecx'), e.arg32(0))), e.ret(eax=0, argbytes=4)))
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == o), e.arg32(1))), e.ret(argbytes=0)))
    return [o, c.rng.choice([0, 1, 2, 3])]


S(0x645250, 'dtor645250 (scalar deleting dtor, thiscall, one arg, ret 4; SEH tag)', 'thiscall', None, ret='eax', gen=_gen,
  note='u69 group 46; SEH frame not reproduced; GUESS stubs 0x641b60 and sized delete 0x634273; fake vtable slot 0x94')
