"""specs_s1023.py - unclaimed-10, batch 19: ZActionControlMap::Load2 (0x5b3e10). Thiscall, no arguments. Stubs: the sub-object at
this+0x5f has a logging vtable with slot +0x100 (one argument, returns a fixed value chosen in gen); the function 0x591ae0 is
hooked (fixed result, ecx = sub-object, logged); the object's own vtable slot +0xc is a logging stub (the tail call). The sub-object's
+0x85a flag is zero in half the cases (so the slot +0x100 path runs)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _acm(c):
    e = c.emu
    r100 = c.rng.getrandbits(32)
    r591 = c.rng.getrandbits(32)
    e.hook(0x591ae0, lambda em, rr: (em.calllog.append(('591ae0', 0, em.reg('ecx'), ())), em.ret(eax=r591, argbytes=0)))
    vt_sub = e.logging_vtable('acm_sub', 72, impl={0x100: lambda em, a: (r100, None)}, argwords={0x100: 1})
    vt_self = e.logging_vtable('acm', 8)
    sub = _rnd(c, 0x900)
    e.w32(sub, vt_sub)
    e.w32(sub + 0x85a, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    obj = _rnd(c, 0x800)
    e.w32(obj, vt_self)
    e.w32(obj + 0x5f, sub)
    return [obj]


S(0x5b3e10, 'ZActionControlMap::Load2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_acm,
  note='unclaimed-10 batch 19; sub slot +0x100 stubbed; 0x591ae0 hooked; this slot +0xc (tail) stubbed')
