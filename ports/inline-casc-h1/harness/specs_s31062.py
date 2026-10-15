"""specs_s31062.py - Sonnet h1 batch 31062."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def r32(c):
    return c.rng.getrandbits(32)


def g494000(c):
    clear_hooks(c)
    so = sysobj(c)
    c.emu.w32(so + 0x1a9f, 0 if c.rng.random() < 0.4 else obj(c, 0x40, {0x128: pystub(c, 1, ret=r32(c), this=True)}))
    return [r32(c)]


def g5a5f40(c):
    clear_hooks(c)
    me = rnd(c, 0x490)
    for i in range(12):
        c.emu.w32(me + 0x440 + 4 * i, rnd(c, 0x40))
    return [me]


def g463fc0(c):
    clear_hooks(c)
    me = rnd(c, 0x40)
    n = c.rng.choice([0, 1, 2, 5, 9])
    c.emu.w32(me + 0x1c, rnd(c, 0x18 * max(n, 1) + 8))
    c.emu.w32(me + 0x20, n)
    return [me]


def g462d30(c):
    clear_hooks(c)
    me = rnd(c, 0x40)
    n = 4
    arr = rnd(c, 0x18 * n)
    for i in range(n):
        c.emu.w32(arr + 0x18 * i + 0x14, 0 if c.rng.random() < 0.3 else rnd(c, 0x40))
    c.emu.w32(me + 0x1c, arr)
    return [me, c.rng.randrange(n)]


def g537310(c):
    clear_hooks(c)
    me = rnd(c, 0x5310)
    c.emu.w32(me + 0x5302, 0 if c.rng.random() < 0.3 else r32(c))
    if c.rng.random() < 0.25:
        a = 0
    else:
        a = rnd(c, 0x10)
        c.emu.w32(a + 4, 0 if c.rng.random() < 0.3 else r32(c))
    return [me, a]


def g4669c0(c):
    clear_hooks(c)
    me = rnd(c, 0x40)
    if c.rng.random() < 0.4:
        c.emu.w32(me + 0x25, 0x7fffffff)
    return [me, rnd(c, 0x10)]


def g6361e0(c):
    clear_hooks(c)
    return [rnd(c, 0x40)]


S(0x494000, 'GUESS sysobj->[0x1a9f] null-checked vtable tail slot 0x128', 'stdcall', None, ret='eax', gen=g494000, note='batch31062')
S(0x5a5f40, 'GUESS clear byte 0x35 of 12 listed objects', 'thiscall', None, ret=None, gen=g5a5f40, note='batch31062')
S(0x463fc0, 'GUESS clear +0x10 of unflagged array entries', 'thiscall', None, ret=None, gen=g463fc0, note='batch31062')
S(0x462d30, 'GUESS entry linked-object field lookup', 'thiscall', None, ret='eax', gen=g462d30, note='batch31062')
S(0x537310, 'GUESS base plus offset lookup', 'thiscall', None, ret='eax', gen=g537310, note='batch31062')
S(0x4669c0, 'GUESS copy 3 dwords unless sentinel, bool', 'thiscall', None, ret='al', gen=g4669c0, note='batch31062')
S(0x6361e0, 'GUESS constructor vtable 6c2114', 'thiscall', None, ret='eax', gen=g6361e0, note='batch31062')
