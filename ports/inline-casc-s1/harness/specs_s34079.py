"""specs_s34079.py - cascade tier E, batch 34079 (all callees are cdecl recorders with pop 0).
0x61bb20: [this+4] zero in a third; every callee hooked (0x61bfa0 returns a handle).
0x620b30: [a+0xe8] zero or not (selects 0x626a80 / 0x626ac0, both hooked, result zero in a third); hooked 0x61fbc0 (zero in a half); [a+0x8c] is an object whose first dword is a code stub (4 args, cdecl; the last is a pointer to the
 caller's argument slot which the stub overwrites half the time); hooked 0x61dcd0 with 7 args.
0x405690: [p+0x14] null in a quarter else a record of five random dwords; [p+0xc] / [p+0x10] zero or not; hooked free 0x634d52."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g61bb20(c):
    clear_hooks(c)
    r = c.rng
    for a, n in ((0x61c3d0, 1), (0x61c640, 2), (0x61c5c0, 3), (0x61c590, 2), (0x61c620, 2), (0x61c5a0, 2), (0x61c630, 2), (0x61c610, 2), (0x61c600, 2)):
        hook_rec(c, a, n, pop=0, ret=r.getrandbits(32))
    hook_rec(c, 0x61c5e0, 3, pop=0, ret=r.getrandbits(32))
    hook_rec(c, 0x61bfa0, 4, pop=0, ret=lambda em, k: r.getrandbits(32))
    me = rnd(c, 0x20)
    if r.random() < 0.33:
        c.emu.w32(me + 4, 0)
    return [me]


def _g620b30(c):
    clear_hooks(c)
    r = c.rng
    z = lambda: r.choice([0, 0, 1, r.getrandbits(32)])
    hook_rec(c, 0x626a80, 3, pop=0, ret=lambda em, k: z(), deref={0: 1, 1: 1})
    hook_rec(c, 0x626ac0, 3, pop=0, ret=lambda em, k: z(), deref={0: 1, 1: 1})
    hook_rec(c, 0x61fbc0, 2, pop=0, ret=lambda em, k: z())
    hook_rec(c, 0x61dcd0, 7, pop=0, ret=lambda em, k: r.getrandbits(32))

    def side(em, k):
        if r.random() < 0.5:
            em.w32(em.arg32(3), r.getrandbits(32))
    stub = pystub(c, 4, pop=0, ret=lambda em, k: r.getrandbits(32), side=side, stackmark=(3,))
    P = rnd(c, 0x20)
    c.emu.w32(P, stub)
    a = rnd(c, 0x120)
    c.emu.w32(a + 0x8c, P)
    c.emu.w32(a + 0xe8, r.choice([0, 1, 5]))
    return [a, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g405690(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634d52, 1, pop=0)
    p = rnd(c, 0x40)
    c.emu.w32(p + 0x14, 0 if r.random() < 0.25 else rnd(c, 0x20))
    c.emu.w32(p + 0xc, r.choice([0, r.getrandbits(32)]))
    c.emu.w32(p + 0x10, r.choice([0, r.getrandbits(32)]))
    return [p]


S(0x61bb20, 'GUESS re-create handle and register callbacks', 'thiscall', None, ret='eax', gen=_g61bb20, note='batch34079')
S(0x620b30, 'GUESS probe table then dispatch', 'cdecl', None, ret='eax', gen=_g620b30, note='batch34079')
S(0x405690, 'GUESS free nested record and clear', 'cdecl', None, ret='eax', gen=_g405690, note='batch34079')
