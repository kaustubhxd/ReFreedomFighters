"""specs_s1202.py - fresh slice 12, batch 2 (11 functions). Exe callees hooked by address and logged; deletes and new
are hooked (the fake heap has no free); fopen is replaced in the IAT slot 0x6763b0 by a logging stub."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, hk, hk_cdecl, done


def _del(c):
    c.emu.hook(0x634273, hk_cdecl(0x634273, 'delete_sized', 2))


def _s5ec880(c):
    _del(c)
    c.emu.hook(0x5ec7e0, hk(0x5ec7e0, 'base_dtor', 0, lambda em: em.reg('ecx') ^ 0x55))


S(0x5ec880, 'FUN_005ec880 scalar deleting dtor (size 0xd7)', 'thiscall', None, ret='eax', setup=_s5ec880,
  gen=lambda c: done(c, [rand_obj(c, 0x40), c.rng.getrandbits(32)]))


def _g63db40(c):
    n = c.rng.choice([0, 1, 2, 3, 5, 8])
    o = rand_obj(c, 4 + 4 * 9)
    c.emu.w32(o, n)
    key = rand_obj(c, 4)
    if n and c.rng.random() < 0.6:
        c.emu.w32(key, c.emu.r32(o + 4 + 4 * c.rng.randrange(n)))
    if n > 1 and c.rng.random() < 0.3:   # duplicates: the first match wins
        c.emu.w32(o + 4 + 4 * (n - 1), c.emu.r32(key))
    return done(c, [o, key])


S(0x63db40, 'FUN_0063db40 index of *key in counted array', 'thiscall', None, ret='eax', gen=_g63db40)


def _g54a6c0(c):
    o = logged_obj(c, 'Obj', 0x30, impl={0x8c: lambda e, a: (a[0] ^ 0x99, None)}, argwords={0x8c: 1})
    lst = rand_obj(c, 4 * 8)
    n = c.rng.choice([-5, -1, 0, 1, 2, 3, 8])
    return done(c, [o, lst, n & 0xffffffff])


S(0x54a6c0, 'FUN_0054a6c0 vslot 0x8c for each list item', 'thiscall', None, ret=None, gen=_g54a6c0)


def _g652680(c):
    o = rand_obj(c, 0x1200)
    c.emu.w32(o + 0x11e9, rand_obj(c, 0x10))
    return done(c, [o])


S(0x652680, 'FUN_00652680 free block at +0x11e9', 'thiscall', None, ret=None, setup=_del, gen=_g652680)


def _s56ad80(c):
    c.emu.hook(0x469870, hk(0x469870, 'base_ctor', 0, lambda em: em.reg('ecx')))


S(0x56ad80, 'FUN_0056ad80 constructor (vtable 0x6a7858)', 'thiscall', None, ret='eax', setup=_s56ad80,
  gen=lambda c: done(c, [rand_obj(c, 0x60)]))


def _g64fe80(c):
    o = rand_obj(c, 0x30)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0x20, 0)
    return done(c, [o, rand_obj(c, 0x10), c.rng.getrandbits(32)])


S(0x64fe80, 'FUN_0064fe80 set buffer +0x20/+0x24/+0x28', 'thiscall', None, ret='eax', setup=_del, gen=_g64fe80)


def _g54e180(c):
    o = rand_obj(c, 0x70)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0x53, 0)
    return done(c, [o, c.rng.getrandbits(32)])


S(0x54e180, 'FUN_0054e180 scalar deleting dtor (vt 0x6a3ea8, size 0x6b)', 'thiscall', None, ret='eax', setup=_del,
  gen=_g54e180)


def _g4d5640(c):
    o = rand_obj(c, 0x20)
    r = c.rng.random()
    if r < 0.25:
        c.emu.w32(o + 1, 0)
    if c.rng.random() < 0.5:
        c.emu.w8(o, 0)
    return done(c, [o])


S(0x4d5640, 'FUN_004d5640 clear buffer +1 (delete unless borrowed)', 'thiscall', None, ret=None, setup=_del, gen=_g4d5640)


def _s4d49c0(c):
    _del(c)
    c.emu.hook(0x41e290, hk_cdecl(0x41e290, 'new', 1, lambda em: em.alloc(8, 4)))


def _g4d49c0(c):
    res = c.rng.choice([0, 0x77aa0000 | c.rng.getrandbits(12)])

    def fop(em, r):
        em.calllog.append(('fopen', 0, 0, (em.arg32(0), em.arg32(1))))
        em.ret(eax=res, argbytes=0)
    c.emu.w32(0x6763b0, c.emu.stub_fn('fopen', fop))
    return done(c, [c.rng.getrandbits(32), c.rng.getrandbits(32)])


S(0x4d49c0, 'FUN_004d49c0 open file holder (new 4, fopen)', 'stdcall', None, ret='eax', setup=_s4d49c0, gen=_g4d49c0)


def _s554d00(c):
    c.emu.hook(0x642050, hk(0x642050, 'f642050', 0, lambda em: em.reg('ecx') * 7))
    c.emu.hook(0x5003d0, hk(0x5003d0, 'f5003d0', 1, lambda em: em.reg('ecx') ^ 0x3030))
    c.emu.hook(0x5002f0, hk(0x5002f0, 'f5002f0', 1))


def _g554d00(c):
    o = rand_obj(c, 0x40)
    mgr = logged_obj(c, 'Mgr', 0x40, impl={0x94: lambda e, a: (o, None)})
    eng = zero_obj(c, 0x1b00)
    c.emu.w32(eng + 0x1aa3, mgr)
    set_global(c, 0x70039c, eng)
    return done(c, [rand_obj(c, 0x10), rand_obj(c, 0x10)])


S(0x554d00, 'FUN_00554d00 engine+0x1aa3 slot 0x94 -> 0x5003d0/0x5002f0', 'thiscall', None, ret=None, setup=_s554d00,
  gen=_g554d00)


def _s56a100(c):
    c.emu.hook(0x5626c0, hk(0x5626c0, 'f5626c0', 0))
    c.emu.hook(0x56a140, hk(0x56a140, 'f56a140', 0))


def _g56a100(c):
    o = rand_obj(c, 0x200)
    if c.rng.random() < 0.7:
        c.emu.w32(o + 0x1c5, 2)
    c.emu.w32(o + 0x94, zero_obj(c, 0x132b0) if c.rng.random() < 0.8 else 0)
    v = c.rng.getrandbits(32)
    en = logged_obj(c, 'Eng', 0x20, impl={0x4c: lambda e, a: (v, None)}, argwords={0x4c: 1})
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    return done(c, [o])


S(0x56a100, 'FUN_0056a100 update then engine slot 0x4c into (+0x94)->+0x1329f', 'thiscall', None, ret=None,
  setup=_s56a100, gen=_g56a100)
