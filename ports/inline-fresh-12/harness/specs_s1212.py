"""specs_s1212.py - fresh slice 12, batch 12: SEH-frame constructor, destructor and allocate + construct."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, hk, done


def _engine(c, slots, argwords, alloc=None):
    e = logged_obj(c, 'Eng', 0x50, impl=slots, argwords=argwords)
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x9b, e)
    set_global(c, 0x70039c, eng)
    c.emu.w32(0x6f5630, c.rng.getrandbits(32))   # security cookie
    return e


def g_4af440(c):
    c.emu.hook(0x469870, hk(0x469870, 'base', 0))
    r = c.rng.getrandbits(32)
    _engine(c, {0x114: lambda e, a: (r, None)}, {0x114: 4})
    return done(c, [rand_obj(c, 0x70)])


def g_5c2440(c):
    c.emu.hook(0x4ccf60, hk(0x4ccf60, 'mdtor', 0))
    r = c.rng.getrandbits(32)
    _engine(c, {0x34: lambda e, a: (r, None)}, {0x34: 1})
    return done(c, [rand_obj(c, 0x200)])


def g_4b2b40(c):
    c.emu.hook(0x469870, hk(0x469870, 'base', 0))
    c.emu.hook(0x4ccba0, hk(0x4ccba0, 'mctor', 0))
    o = c.rng.choice([0, rand_obj(c, 0x60)])
    a = logged_obj(c, 'Alloc', 0x20, impl={0x44: lambda e, ar: (o, None)})
    en = zero_obj(c, 0x10)
    c.emu.w32(en + 8, a)
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    c.emu.w32(0x6f5630, c.rng.getrandbits(32))
    return done(c, [rand_obj(c, 0x10)])


S(0x4af440, 'FUN_004af440 constructor (vt 0x690e10, type id from engine slot 0x114), SEH', 'thiscall', None, ret='eax', gen=g_4af440)
S(0x5c2440, 'FUN_005c2440 destructor (vt 0x6b3c58 -> 0x686874, engine slot 0x34), SEH', 'thiscall', None, ret='eax', gen=g_5c2440)
S(0x4b2b40, 'FUN_004b2b40 allocate + construct (vt 0x691900, member 0x4ccba0), SEH', 'thiscall', None, ret='eax', gen=g_4b2b40)
