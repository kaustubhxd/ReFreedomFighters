"""specs_s3308.py - area 73 batch 8 (residue 12): ZProjectile::Load (0x4ba200). The load object's slots +0x40, +0x50 and +0x6c
are logging stubs: the first +0x50 returns s1 and the first +0x40 returns s2 (objects with their own logging slots), the rest
return 0. The DBREAD helpers take a stack pointer: they are hooked, and their ECX (a stack address) is not logged. 0x4e5e60
returns three values in order, 0x4e5e80 a float in ST0, 0x4e5ef0 a random dword (al is used). 0x6352f0 logs its ECX only."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _projectile(c):
    e = c.emu
    self_o = _rnd(c, 0x200)
    obj6d = _rnd(c, 0x40)
    e.w32(obj6d, e.logging_vtable('o6d', 0x40 // 4, impl={}, argwords={}))
    e.w32(self_o + 0x6d, obj6d)

    s1 = _rnd(c, 0x40)
    e.w32(s1, e.logging_vtable('s1', 0x58 // 4, impl={0x50: lambda em, a: (0, None)}, argwords={0x50: 1}))
    s2 = _rnd(c, 0x40)
    e.w32(s2, e.logging_vtable('s2', 0x48 // 4, impl={0x40: lambda em, a: (0, None)}, argwords={0x40: 1}))

    calls50 = [0, s1]   # the first +0x50 call (+0x51) returns nothing used; the second (+0x55) gives s1
    calls40 = [s2]

    def r50(em, a):
        return (calls50.pop(0) if calls50 else 0, None)

    def r40(em, a):
        return (calls40.pop(0) if calls40 else 0, None)

    load = _rnd(c, 0x100)
    e.w32(load, e.logging_vtable('zload_proj', 0x70 // 4,
                                 impl={0x40: r40, 0x50: r50, 0x6c: lambda em, a: (0, None)},
                                 argwords={0x40: 1, 0x50: 1, 0x6c: 1}))

    seq = [c.rng.getrandbits(32) for _ in range(3)]
    f = c.rng.uniform(-100.0, 100.0)
    ok = c.rng.getrandbits(32)

    def h6352f0(em, r):
        em.calllog.append(('getinput', 0, em.reg('ecx'), ()))
        em.ret(argbytes=4)

    def h4e5e60(em, r):
        em.calllog.append(('dbread_u32', 0, None, ()))
        em.ret(eax=seq.pop(0) if seq else 0, argbytes=0)

    def h4e5e80(em, r):
        em.calllog.append(('dbread_float', 0, None, ()))
        em.ret(st0=f, argbytes=0)

    def h4e5ef0(em, r):
        em.calllog.append(('dbread_bool', 0, None, ()))
        em.ret(eax=ok, argbytes=0)

    def h4e7480(em, r):
        em.calllog.append(('4e7480', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(argbytes=4)

    e.hook(0x6352f0, h6352f0)
    e.hook(0x4e5e60, h4e5e60)
    e.hook(0x4e5e80, h4e5e80)
    e.hook(0x4e5ef0, h4e5ef0)
    e.hook(0x4e7480, h4e7480)
    return [self_o, load]


S(0x4ba200, 'ZProjectile::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_projectile,
  note='area 73 batch 8; load slots +0x50, +0x40, +0x6c; s1/s2; ext 0x4e7480; DBREAD helpers 0x6352f0, 0x4e5e60, 0x4e5e80, 0x4e5ef0')
