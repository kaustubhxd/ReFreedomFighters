"""specs_s31076.py - batch 31076."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def r32(c):
    return c.rng.getrandbits(32)


def _clob(c, extra=None):
    j = r32(c)

    def f(emu, k):
        emu.mu.reg_write(REGS['ecx'], j)
        if extra:
            extra(emu, k)
    return f


def g5d34a0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x60)

    def flip(emu, k):                       # the first callee may change the flag byte
        emu.mu.mem_write(emu.reg('ecx') + 0x54, bytes([r.choice([0, 1])]))
    # `ecx` is clobbered by _clob after reading it, so capture first
    def side(emu, k, j=r32(c), b=r.choice([0, 1, 0, 1, None])):
        if b is not None:
            emu.mu.mem_write(emu.reg('ecx') + 0x54, bytes([b]))
        emu.mu.reg_write(REGS['ecx'], j)
    hook_rec(c, 0x5d3520, 0, ret=r32(c), pop=0, this=True, side=side)
    hook_rec(c, 0x5d3780, 0, ret=r32(c), pop=0, this=True)
    src = rnd(c, 0x60)
    if r.random() < 0.5:
        c.emu.wbytes(src + 0x54, bytes([r.choice([0, 1])]))
    return [me, src]


def g626a80(c):
    clear_hooks(c)
    hook_rec(c, 0x628c10, 1, ret=c.rng.choice([0xffffffff, 0xffffffff, 0, 1, 0x7f, 0x1ff, 0x12345678]), pop=0)
    return [rnd(c, 0x60), rnd(c, 0x10), r32(c)]


def g447640(c):
    clear_hooks(c)
    hook_rec(c, 0x45c3a0, 3, ret=r32(c), pop=0xc, this=True, side=_clob(c))
    so = sysobj(c, table_size=0xbb8)
    tab = c.emu.r32(so + 0x9b)
    c.emu.wbytes(tab + 0xbad, bytes([c.rng.choice([0, 1, 0x80])]))
    return [rnd(c, 0x40), r32(c), r32(c), r32(c)]


def _ctor3(base, size):
    def g(c):
        clear_hooks(c)
        hook_rec(c, base, 3, ret=r32(c), pop=0xc, this=True, side=_clob(c))
        return [rnd(c, size), r32(c), r32(c), r32(c)]
    return g


def g4d0f80(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0, side=_clob(c))
    me = rnd(c, 0x100)
    n = r.choice([0, 1, 2, 4, 5])
    c.emu.w32(me + 0x88, n)
    for i in range(6):
        c.emu.w32(me + 0x18 + 0xc * i, rnd(c, 0x10) if r.random() < 0.6 else 0)
    return [me]


def g54e9d0(c):
    clear_hooks(c)
    hook_rec(c, 0x634d10, 3, ret=r32(c), pop=0)
    return [rnd(c, 0x60)]


def g65f580(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4db9e0, 0, ret=r.choice([0, 1, 0x100, 0x101, r32(c)]), pop=0, this=True)
    hook_rec(c, 0x4db6c0, 2, ret=r32(c), pop=8, this=True)
    E = rnd(c, 0x50)
    fl = c.emu.r32(E + 0x3c)
    c.emu.w32(E + 0x3c, (fl | 0x40000000) if r.random() < 0.5 else (fl & ~0x40000000))
    B = rnd(c, 0x50)
    c.emu.w32(B + 0x38, E)
    A = rnd(c, 0x20)
    c.emu.w32(A + 8, B)
    c.emu.w32(A + 0xc, 0 if r.random() < 0.25 else rnd(c, 0x40))
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, A)
    return [me]


S(0x5d34a0, 'GUESS copy fields from arg, 5d3520, conditional 5d3780', 'thiscall', None, ret='eax', gen=g5d34a0, note='batch31076')
S(0x626a80, 'GUESS init object if 628c10 accepts', 'cdecl', None, ret='eax', gen=g626a80, note='batch31076')
S(0x447640, 'GUESS ctor base 45c3a0, vtable 67dc30, flag from sysobj', 'thiscall', None, ret='eax', gen=g447640, note='batch31076')
S(0x4ee1b0, 'GUESS ctor base 4ee240, vtable 698118', 'thiscall', None, ret='eax', gen=_ctor3(0x4ee240, 0xb0), note='batch31076')
S(0x4f97f0, 'GUESS ctor base 4ee210, vtable 69b6fc', 'thiscall', None, ret='eax', gen=_ctor3(0x4ee210, 0x90), note='batch31076')
S(0x4d0f80, 'GUESS delete each non-null record pointer', 'thiscall', None, ret='eax', gen=g4d0f80, note='batch31076')
S(0x54e9d0, 'GUESS ctor memset, float constants', 'thiscall', None, ret='eax', gen=g54e9d0, note='batch31076')
S(0x65f580, 'GUESS conditional 4db6c0 on linked object', 'thiscall', None, ret='eax', gen=g65f580, note='batch31076')
