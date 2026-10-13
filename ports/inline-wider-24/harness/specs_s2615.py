"""specs_s2615.py - wider batch 2615: twelve unclaimed functions; every callee hooked (arities from the exe's `ret` immediates)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, stub_memset


def rl(r, n, f):
    v = [f() for _ in range(n)]
    return lambda em, k: v[k % n]


def _w(e, a, v):
    e.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g421600(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x41e290, 1, pop=0, ret=rl(r, 4, lambda: 0) if r.random() < 0.25 else (lambda em, k: em.alloc(0x120, 4)))
    hook_rec(c, 0x433d20, 0, this=True, ret=lambda em, k: r.getrandbits(32))
    return [rnd(c, 0x1b60)]


def g423e60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4cc5f0, 0, this=True, ret=rl(r, 4, lambda: r.choice([0, 1, 1])))
    hook_rec(c, 0x4cc1d0, 0, this=True, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x634273, 2, pop=0)
    e.w32(0x700394, obj(c, 0x20, {0x64: pystub(c, 4, this=True)}))
    me = rnd(c, 0x2600)
    a = r.choice([0, rnd(c, 8), r.getrandbits(32)])
    e.w32(me + 0x25dc, a)
    e.w32(me + 0x25e0, a + r.choice([0, 5, 0x40]) if a else r.getrandbits(32))
    return [me]


def g428770(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x436260, 0, this=True)
    hook_rec(c, 0x435ba0, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x100)
    c.emu.w32(me + 0x7c, obj(c, 0x20, {8: pystub(c, 1, this=True)}) if r.random() < 0.7 else 0)
    c.emu.w32(0x7003a0, r.getrandbits(32))
    return [me, r.choice([0, 1, 2, 0x100, r.getrandbits(32)])]


def _str_pair(c, off, takes_arg):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4cbe80, 1, this='mark')
    hook_rec(c, 0x4cbee0, 1, this=True, nullflag=(0,))
    hook_rec(c, 0x4cbec0, 0, this='mark')
    return [rnd(c, 0x1b00)] + ([r.getrandbits(32)] if takes_arg else [])


def g42cba0(c):
    return _str_pair(c, 0x1a17, False)


def g42fac0(c):
    return _str_pair(c, 0x1997, True)


def g433f90(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x434fb0, 0, this=True)
    hook_rec(c, 0x4cbec0, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x100)
    c.emu.w32(me + 8, obj(c, 0x20, {0: pystub(c, 1, this=True)}) if r.random() < 0.7 else 0)
    return [me, r.choice([0, 1, 2, 0x100, r.getrandbits(32)])]


def g435c00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x43cfb0, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x80)
    _w(e, me + 0x65, rnd(c, 8) if r.random() < 0.7 else 0)
    e.w32(me + 8, rnd(c, 8) if r.random() < 0.7 else 0)
    return [me, r.choice([0, 1, 2, 0x100, r.getrandbits(32)])]


def g43cf00(c):
    clear_hooks(c)
    stub_memset(c)
    return [rnd(c, 0x360), c.rng.getrandbits(32)]


def g443f40(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x441b90, 3, this=True)
    return [rnd(c, 0xd0), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g445e10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x100)
    n = r.choice([0, 1, 2, 3, 4])
    e.w32(me + 4, n)
    for i in range(4):
        e.w32(me + 8 + 4 * i, r.randint(0, 3))
    return [me, rnd(c, 0x100)]


def _g448(c, tail):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x448a30, 1, this=True)
    hook_rec(c, 0x4e1600, 0, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x101, 2]))
    hook_rec(c, 0x4e12f0, 2, this=True, nullflag=(0,))
    hook_rec(c, 0x4e1b30, 0, this=True)
    hook_rec(c, 0x4e0fd0, 1, this=True)
    me = rnd(c, 0x40)
    return [me, rnd(c, 0x40)]


def g448950(c):
    return _g448(c, True)


def g448c00(c):
    return _g448(c, False)


S(0x421600, 'GUESS alloc + ctor into member (SEH)', 'thiscall', None, ret='eax', gen=g421600, note='batch2615')
S(0x423e60, 'GUESS flush buffer through engine slot 0x64', 'thiscall', None, ret=None, gen=g423e60, note='batch2615')
S(0x428770, 'GUESS scalar deleting dtor (size 0x8f, SEH)', 'thiscall', None, ret='eax', gen=g428770, note='batch2615')
S(0x42cba0, 'GUESS set string member from constant (SEH, cookie)', 'thiscall', None, ret='al', gen=g42cba0, note='batch2615')
S(0x42fac0, 'GUESS set string member (SEH, cookie)', 'thiscall', None, ret=None, gen=g42fac0, note='batch2615')
S(0x433f90, 'GUESS scalar deleting dtor (size 0x10c, SEH)', 'thiscall', None, ret='eax', gen=g433f90, note='batch2615')
S(0x435c00, 'GUESS scalar deleting dtor (size 0x71)', 'thiscall', None, ret='eax', gen=g435c00, note='batch2615')
S(0x43cf00, 'GUESS init clear record array', 'thiscall', None, ret='eax', gen=g43cf00, note='batch2615')
S(0x443f40, 'GUESS ctor reset fields', 'thiscall', None, ret='eax', gen=g443f40, note='batch2615')
S(0x445e10, 'GUESS gather four dwords per index', 'thiscall', None, ret='eax', gen=g445e10, note='batch2615')
S(0x448950, 'GUESS apply three out-params then finish', 'thiscall', None, ret=None, gen=g448950, note='batch2615')
S(0x448c00, 'GUESS apply three out-params', 'thiscall', None, ret=None, gen=g448c00, note='batch2615')
