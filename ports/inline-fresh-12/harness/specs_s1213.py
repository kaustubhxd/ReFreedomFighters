"""specs_s1213.py - fresh slice 12, batch 13."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, hk, done


def _int(c):
    return c.rng.choice([0, 1, -1, 640, 480, 0x7fffffff, c.rng.randrange(-5000, 5000), c.rng.getrandbits(32)]) & 0xffffffff


def g_65f600(c):
    a, b, x, y = (_int(c) for _ in range(4))
    v = logged_obj(c, 'View', 0x40, impl={0xd8: lambda e, ar: (a, None), 0xdc: lambda e, ar: (b, None)})
    eng = zero_obj(c, 0x2000)
    c.emu.w32(eng + 0x190f, v)
    set_global(c, 0x70039c, eng)
    s = logged_obj(c, 'Self', 0x4, impl={0: lambda e, ar: (x, None), 4: lambda e, ar: (y, None)})
    return done(c, [s])


def g_4a3b40(c):
    c.emu.hook(0x469870, hk(0x469870, 'base', 0))
    c.emu.hook(0x4ccba0, hk(0x4ccba0, 'mctor', 0))
    c.emu.w32(0x6f5630, c.rng.getrandbits(32))
    return done(c, [rand_obj(c, 0x110)])


def g_4d08c0(c):
    c.emu.hook(0x4cfc70, hk(0x4cfc70, 'link', 1))
    c.emu.hook(0x4d09b0, hk(0x4d09b0, 'mark', 2))
    self_ = rand_obj(c, 0x8220)
    size = c.rng.choice([c.rng.randrange(0, 0x200), c.rng.randrange(0, 0x40)]) & ~3
    blk = rand_obj(c, size + 0x40)
    c.emu.w32(blk + 8, size)
    k = c.rng.randrange(5)
    n = (size - c.rng.randrange(0, 0x30)) if k == 0 else (size - 0x18 if k == 1 else (size - 0x19 if k == 2 else (c.rng.randrange(0, size + 1) if k == 3 else size + c.rng.randrange(1, 0x21))))
    n = max(0, n)
    return done(c, [self_, blk, n])


S(0x65f600, 'FUN_0065f600 aspect ratio (view w/h vs own w/h), float', 'thiscall', None, ret='st0', gen=g_65f600)
S(0x4a3b40, 'FUN_004a3b40 constructor (vt 0x68fbe8, two 0x4ccba0 members), SEH', 'thiscall', None, ret='eax', gen=g_4a3b40)
S(0x4d08c0, 'FUN_004d08c0 heap block take (split or whole)', 'thiscall', None, ret='eax', gen=g_4d08c0)
