"""specs_s1218.py - fresh slice 12, batch 18."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, hk, hk_cdecl, done


def g_555e80(c):
    c.emu.hook(0x5003d0, hk(0x5003d0, 'sub', 1, lambda em: 0x5003d0 ^ em.reg('ecx')))
    c.emu.hook(0x506040, hk(0x506040, 'key', 0, lambda em: em.reg('ecx') + 7))
    rid = c.rng.getrandbits(32)

    def look(em, r):
        name, out = em.arg32(0), em.arg32(1)
        em.calllog.append(('lookup', 0, em.reg('ecx'), (name,)))   # &id is a stack local: write it, log the name
        em.w32(out, rid)
        em.ret(eax=0, argbytes=8)
    reg = zero_obj(c, 0x10)
    c.emu.w32(reg, c.emu.fake_vtable('Reg', 0x30, {0x88: look}))
    o = c.rng.choice([0, logged_obj(c, 'Obj', 0x50, argwords={0x128: 1})])
    v = c.rng.getrandbits(32)
    e = logged_obj(c, 'Eng', 0x50, impl={0x138: lambda em, a: (reg, None), 0x58: lambda em, a: (o, None),
                                        0x114: lambda em, a: (v, None)}, argwords={0x58: 1, 0x114: 6})
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x9b, e)
    set_global(c, 0x70039c, eng)
    return done(c, [rand_obj(c, 0x10)])


def g_4f4f40(c):
    def fc(em, r):
        em.calllog.append(('make2', 0, 0, (em.reg('ecx'), em.reg('edx'), em.arg32(0), em.arg32(1))))
        em.ret(eax=0x4f4e2000 ^ em.reg('ecx'), argbytes=8)
    c.emu.hook(0x4f4e20, fc)
    o = c.rng.choice([0, rand_obj(c, 0xc8)])
    c.emu.hook(0x45c4b0, hk_cdecl(0x45c4b0, 'alloc', 1, lambda em: o))
    c.emu.hook(0x4ee240, hk(0x4ee240, 'base', 3))
    c.emu.w32(0x6f5630, c.rng.getrandbits(32))
    r = lambda: c.rng.getrandbits(32)
    return done(c, [r(), r(), r(), c.rng.choice([0, r()])])


S(0x555e80, 'FUN_00555e80 bind named object (0x6a5c48) slot 0x128', 'stdcall', None, ret=None, gen=g_555e80)
S(0x4f4f40, 'FUN_004f4f40 factory (vt 0x699f78) or 0x4f4e20, SEH', 'fastcall', None, ret='eax', gen=g_4f4f40)
