"""specs_s1217.py - fresh slice 12, batch 17."""
from pilot import S
from engine_stubs import zero_obj, logged_obj
from helpers12 import rand_obj, hk, hk_cdecl, done


def g_4d6040(c):
    c.emu.hook(0x41e2c0, hk_cdecl(0x41e2c0, 'free', 1))
    self_ = rand_obj(c, 0x70)
    for b in (0x46, 0x52, 0x5e):
        if c.rng.random() < 0.3:
            c.emu.w32(self_ + b + 8, 0)
    c.emu.w32(self_ + 0x15, logged_obj(c, 'L', 0x4, argwords={4: 1}))
    c.emu.w32(self_ + 0x6a, c.rng.choice([0, logged_obj(c, 'O', 0x4, argwords={0: 1})]))
    return done(c, [self_])


def g_63f800(c):
    npg = c.rng.randrange(1, 5)
    pages = [rand_obj(c, 0x100) for _ in range(npg)]
    for i, pg in enumerate(pages):
        c.emu.w32(pg + 8, pages[(i + 1) % npg])
        c.emu.w32(pg + 0xc, pages[(i - 1) % npg])
        c.emu.wbytes(pg, bytes([c.rng.choice([1, 1, 2, 3, 0xff])]))
    d = c.rng.choice(pages)
    p = d + 0x10 + 8 * c.rng.randrange(0, 0x1d)
    self_ = rand_obj(c, 0x10)
    c.emu.w32(self_, c.emu.logging_vtable('Pool', 0x10, impl={0x2c: lambda e, a: (d, None)}, argwords={0x2c: 1, 0x34: 1}))
    c.emu.w32(self_ + 8, c.rng.choice(pages + [d]))
    return done(c, [self_, p])


def g_4a2ec0(c):
    c.emu.hook(0x469870, hk(0x469870, 'base', 0))
    c.emu.hook(0x4ccba0, hk(0x4ccba0, 'mctor', 0))
    c.emu.w32(0x6f5630, c.rng.getrandbits(32))
    return done(c, [c.rng.choice([0, rand_obj(c, 0x80), rand_obj(c, 0x80)])])


S(0x4d6040, 'FUN_004d6040 release arrays and owned object', 'thiscall', None, ret=None, gen=g_4d6040)
S(0x63f800, 'FUN_0063f800 pool free (page ring)', 'thiscall', None, ret=None, gen=g_63f800)
S(0x4a2ec0, 'FUN_004a2ec0 constructor (vt 0x68f088, member vt 0x68f068), SEH', 'thiscall', None, ret='eax', gen=g_4a2ec0)
