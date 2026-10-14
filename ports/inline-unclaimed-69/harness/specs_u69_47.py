"""specs_u69_47.py - area 69, group 47 (slice 8): 0x4c3350 (SEH tag: the frame is not reproduced).
Fake vtables: the member at +0x48 (slot 0, one arg) and the object at 0x70039c -> +0x9b (slot 0x34, one arg).
GUESS stubs: 0x4690b0 (empty cdecl), 0x40ce50 (the indirect target; the global 0x7003b0 is set to it, since the original traps with int3 when that global is null).
Only small integers are logged; pointers are compared as booleans."""
from pilot import S
from ckit import rnd, rvt


def _gen(c):
    e = c.emu
    o = rnd(c, 0x100)
    member = rnd(c, 0x40) if c.rng.random() < 0.7 else 0
    e.w32(o + 0x48, member)
    if member:
        mvt = rvt(e, 'member', {0: (1, lambda e, ecx, args: (0, None, ('mvt0', int(ecx == member), args[0])))}, nslots=0x10)
        e.w32(member, mvt)
    g = rnd(c, 0x100)
    e.w32(0x70039c, g)
    obj = rnd(c, 0x40)
    e.w32(g + 0x9b, obj)
    ovt = rvt(e, 'owner', {0x34: (1, lambda e, ecx, args: (0, None, ('ovt34', int(ecx == obj), int(args[0] == o))))}, nslots=0x38 // 4)
    e.w32(obj, ovt)
    e.w32(0x7003b0, 0x40ce50)
    e.hook(0x4690b0, lambda e, res: (e.calllog.append(('t4690b0', int(e.arg32(0) == o), e.arg32(1))), e.ret(argbytes=0)))
    e.hook(0x40ce50, lambda e, res: (e.calllog.append(('indirect',)), e.ret(argbytes=0)))
    return [o, c.rng.choice([0, 1, 2, 3, 4, 5, 6, 7])]


S(0x4c3350, 'dtor4c3350 (thiscall, one arg, ret 4; SEH tag)', 'thiscall', None, ret='eax', gen=_gen,
  note='u69 group 47; SEH frame not reproduced; GUESS stubs 0x4690b0 and 0x40ce50; fake vtables for member slot 0 and owner slot 0x34')
