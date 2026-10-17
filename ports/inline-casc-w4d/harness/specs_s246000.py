"""specs_s246000.py - w4d batch 246000: 0x628ed0, 0x62cf00, 0x499810."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g628ed0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x622ad0, 4, ret=lambda emu, k: r.getrandbits(32), pop=0)
    return [r.getrandbits(32) for _ in range(4)]


def g62cf00(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x20)
    code = r.choice([0xf, 0x19, 0x1c, 0x1c, 0x19, 0xf, 0, 1, r.getrandbits(32)])
    if r.random() < 0.5:
        c.emu.w32(o + 0xc, 0)
    return [o, code]


def g499810(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    R = rnd(c, 0x300)
    A = rnd(c, 0x10)
    em.w32(A + 4, R + 0x120 + r.choice([0, 0, 4, 0x10]))
    base = em.r32(A + 4)
    k = r.randrange(-2, 3)
    m = r.randrange(0, 5)
    p = base + 112 * k + r.randrange(0, 112) if r.random() < 0.9 else base + 112 * k
    if p + 0x40 > R + 0x300 or p < R:
        p = base + 112 * k
    em.w32(p + 0x3c, em.r32(p + 0x3c) & ~0x8000000)
    self_ = rnd(c, 0x70)
    em.w32(self_ + 0x14, A)
    em.w32(self_ + 0x28, 112 * m + r.randrange(0, 112))
    T = rnd(c, 0x80)
    em.w32(self_ + 0x5d, T + 0x40)
    return [self_, p, r.getrandbits(32)]


S(0x628ed0, 'GUESS FUN_628ed0', 'cdecl', None, ret='eax', gen=g628ed0, note='batch246000')
S(0x62cf00, 'GUESS FUN_62cf00', 'cdecl', None, ret='eax', gen=g62cf00, note='batch246000')
S(0x499810, 'GUESS FUN_499810', 'thiscall', None, ret='eax', gen=g499810, note='batch246000')
