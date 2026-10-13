"""specs_s1208.py - fresh slice 12, batch 8 (4 functions). Exe callees hooked by address and logged."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, rand_fast, hk, done


def _g4f0f80(c):
    o = rand_obj(c, 0x90)
    cur = c.rng.getrandbits(32)
    c.emu.w32(o + 0x18, cur)
    v = c.rng.choice([cur, cur ^ 0xff000000, cur ^ 0x00010000, cur ^ 0x00ff0000, c.rng.getrandbits(32)])
    n = c.rng.choice([0, 1, 3])
    c.emu.w32(o + 0x2e, n)
    c.emu.w32(o + 0x2a, c.rng.choice([0, rand_obj(c, 0x24 + 0x28 * 3)]))
    mgr = logged_obj(c, 'Mgr', 0x60, argwords={0x12c: 2})
    m = zero_obj(c, 0x20)
    c.emu.w32(m + 0x18, mgr)
    eng = zero_obj(c, 0x1b00)
    c.emu.w32(eng + 0x1aa3, m)
    set_global(c, 0x70039c, eng)
    return done(c, [o, v])


S(0x4f0f80, 'FUN_004f0f80 set colour and resend records', 'thiscall', None, ret=None, gen=_g4f0f80)


def _g50cb40(c):
    items = [rand_obj(c, 4), rand_obj(c, 4)]
    c.emu.hook(0x5003d0, hk(0x5003d0, 'f5003d0', 1, lambda em: items[em.arg32(0) & 1]))
    ok = c.rng.choice([0, 1, 0x100])
    a = logged_obj(c, 'A', 0x140, impl={0x1e0: lambda e, ar: (0xab00 | ok, None)}, argwords={0x1e0: 1, 0x4e4: 1})
    b = rand_obj(c, 0x10)
    va = c.rng.choice([a, a, 0])
    vb = c.rng.choice([b, b, 0])
    i0, i1 = c.emu.r32(items[0]), c.emu.r32(items[1])
    en = logged_obj(c, 'Eng', 0x30, impl={0x58: lambda e, ar: (va if ar[0] == i0 else vb, None)}, argwords={0x58: 1})
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    s = rand_obj(c, 8)
    return done(c, [rand_obj(c, 0x10), s])


S(0x50cb40, 'FUN_0050cb40 link two looked-up objects', 'thiscall', None, ret=None, gen=_g50cb40)


def _g54ddc0(c):
    o = zero_obj(c, 0x8070)
    n = c.rng.choice([-1, 0, 1, 3, 6])
    arr = zero_obj(c, 4 * 6)
    for i in range(max(n, 0)):
        x = logged_obj(c, 'X%d' % i, 0x20)
        for off in (0x7d, 0x7a, 0x79, 0x7c):
            c.emu.w8(x + off, c.rng.choice([0, 1, 1]))
        c.emu.w8(x + 0x7a, c.rng.choice([0, 0, 1]))
        c.emu.w8(x + 0x79, c.rng.choice([0, 0, 1]))
        c.emu.w32(x + 0x75, c.rng.choice([3, 3, 2, 4, c.rng.getrandbits(32)]))
        c.emu.w32(x + 0x61, c.rng.getrandbits(32))
        c.emu.w32(arr + 4 * i, x)
    c.emu.w32(o + 0x803d, c.rng.choice([arr, arr, 0]))
    c.emu.w32(o + 0x805d, n & 0xffffffff)
    c.emu.w32(o + 0x8014, c.rng.choice([0, 2, 7]))
    return done(c, [o])


S(0x54ddc0, 'FUN_0054ddc0 collect ready objects', 'thiscall', None, ret=None, gen=_g54ddc0)


def _g63b340(c):
    n = c.rng.choice([1, 2, 3, 6])
    blk = rand_fast(c, 0x10 + 0x40 * 6) if c.rng.random() < 0.85 else 0
    o = logged_obj(c, 'Pool', 0x20, impl={0x30: lambda e, a: (blk, None), 0x28: lambda e, a: (n, None)})
    c.emu.w8(o + 0x10, c.rng.getrandbits(8))
    if c.rng.random() < 0.6:
        h = rand_obj(c, 0x10)
        pv = h if c.rng.random() < 0.5 else rand_obj(c, 0x10)
        c.emu.w32(h + 0xc, pv)
        c.emu.w32(o + 8, h)
    else:
        c.emu.w32(o + 8, 0)
    return done(c, [o])


S(0x63b340, 'FUN_0063b340 add pool block', 'thiscall', None, ret='al', gen=_g63b340)
