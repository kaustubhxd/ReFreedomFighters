"""specs_s8009.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _self(c, slot, h):
    # this: first dword is its vtable; slot +slot is the logged handler h(e, r)
    o = _obj(c, 0x40)
    vt = c.emu.fake_vtable("SelfVt9", 0x50, {slot: h})
    c.emu.w32(o, vt)
    return o

def _argslot(c):
    def h(e, r):
        args = [e.arg32(0), e.arg32(1)]
        e.calllog.append(("slot 18", e.reg("ecx"), tuple(args)))
        e.ret(eax=0, argbytes=8)
    return [_self(c, 0x18, h), c.rng.getrandbits(32)]

def _glob(c):
    def h(e, r):
        args = [e.arg32(0)]
        e.calllog.append(("sys slot 104", e.reg("ecx"), tuple(args)))
        e.ret(eax=c.rng.getrandbits(32), argbytes=4)
    sysobj = _obj(c, 0x40)
    vt = c.emu.fake_vtable("SysVt9", 0x50, {0x104: h})
    c.emu.w32(sysobj, vt)
    c.emu.w32(0x70039c, sysobj)
    return []

S(0x49a480, '(GUESS) 0x49a480 vcall slot 0x18', 'thiscall', None, ret=None, gen=_argslot,
  note='unclaimed-79 gap-band thiscall, calls slot +0x18 with (arg, 4)')

S(0x48a370, '(GUESS) 0x48a370 global vcall slot 0x104', 'cdecl', None, ret='eax', gen=_glob,
  note='unclaimed-79 gap-band no-arg, calls slot +0x104 of the global 0x70039c with 0')
