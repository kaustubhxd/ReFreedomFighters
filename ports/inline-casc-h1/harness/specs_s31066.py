"""specs_s31066.py - Sonnet h1 batch 31066."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks


def r32(c):
    return c.rng.getrandbits(32)


def g589f70(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0xd91 + 0xf4 * 4 + 0x20)
    n = r.randrange(0, 4)
    c.emu.w32(me + 0xd8d, n)
    base = me + 0xd91
    p = r.choice([0, base, base + 0xf4, base + 0xf4 * 2, base + 0xf4 * 3, base + 4, r32(c)])
    return [me, p]


def g4febf0(c):
    clear_hooks(c)
    return [rnd(c, 0x140), rnd(c, 0x140)]


def g5e9070(c):
    clear_hooks(c)
    r = c.rng
    src = rnd(c, 0x460)
    c.emu.w32(src + 0x48, r.choice([0, 1, 2, 5, 20, 0x7f, -1 & 0xffffffff, 0x80000000]))
    return [rnd(c, 0x460), src]


def g5308e0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x60)
    n = r.randrange(0, 5)
    c.emu.w32(me + 0x48, n)
    blk = rnd(c, 0x200)
    j = r.randrange(2 * n, 40)
    s = r.randrange(0, 32)
    k = 32 * j + s - n * 64 + 0x40
    return [me, rnd(c, 4), blk, k & 0xffffffff]


def g597e00(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x2000)
    n = r.randrange(0, 7)
    c.emu.w32(me + 0x1fae, n)
    c.emu.w32(me + 0x1fb2, r.choice([max(n - 1, 0), n, 0, 3, r32(c), -1 & 0xffffffff, n - 1 & 0xffffffff]))
    if n and r.random() < 0.7:
        v = c.emu.r32(me + 0x1dae + 4 * r.randrange(n))
    else:
        v = r32(c)
    return [me, v]


def g4cc690(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 4, 9, 20])
    s = c.emu.alloc(n + 1, 4)
    c.emu.wbytes(s, bytes(r.choice([r.randrange(0x41, 0x5b), r.randrange(0x61, 0x7b), r.randrange(1, 256), 0x40, 0x5b]) for _ in range(n)) + b'\0')
    me = c.emu.alloc(4, 4)
    c.emu.w32(me, s)
    return [me]


def g57d830(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c)
    if r.random() < 0.15:
        c.emu.w32(so + 0x190b, 0)
        return [r.getrandbits(16)]
    v = r.getrandbits(16) if r.random() < 0.85 else r.choice([0x10000, 0xffff0000 | r.getrandbits(16)])
    tab = c.emu.alloc(0x10 * 5, 4)
    for i in range(4):
        c.emu.w32(tab + 0x10 * i, r.randrange(0, 0x1000))
        c.emu.w32(tab + 0x10 * i + 0xc, r.randrange(0, 0x400))
        c.emu.w32(tab + 0x10 * i + 4, r32(c))
    if r.random() < 0.4 and v < 0x10000:        # an earlier entry starting exactly at v+1 must be skipped
        c.emu.w32(tab, v + 1)
        c.emu.w32(tab + 0xc, r.randrange(1, 0x400))
    last = tab + 0x30
    a = r.randrange(0, 8)
    c.emu.w32(last, (v & 0xffff) - a if v < 0x10000 else 0)
    c.emu.w32(last + 0xc, a + 1 + r.randrange(0, 8))
    c.emu.w32(so + 0x190b, tab)
    return [v]


def g623b80(c):
    clear_hooks(c)
    r = c.rng
    n = 2 * r.randrange(0, 7)
    m = 2 * r.randrange(0, 9) if r.random() < 0.4 else max(0, n - 2 * r.randrange(1, 4))
    src = rnd(c, 16)
    if n >= 2 and r.random() < 0.5:
        c.emu.wbytes(src + n - 2, bytes([r.choice([0xd8, 0xdb, 0xdf, 0xd7, 0xe0]), r.getrandbits(8)]))
    dst = rnd(c, 24)
    ps, pd = c.emu.alloc(4, 4), c.emu.alloc(4, 4)
    c.emu.w32(ps, src)
    c.emu.w32(pd, dst)
    return [r32(c), ps, src + n, pd, dst + m]


S(0x589f70, 'GUESS index of record pointer', 'thiscall', None, ret='eax', gen=g589f70, note='batch31066')
S(0x4febf0, 'GUESS copy constructor vtable 68e948', 'thiscall', None, ret='eax', gen=g4febf0, note='batch31066')
S(0x5e9070, 'GUESS copy counted pair array', 'thiscall', None, ret=None, gen=g5e9070, note='batch31066')
S(0x5308e0, 'GUESS gather bits from dword stride', 'thiscall', None, ret=None, gen=g5308e0, note='batch31066')
S(0x597e00, 'GUESS list remove with cursor fixup', 'thiscall', None, ret=None, gen=g597e00, note='batch31066')
S(0x4cc690, 'GUESS lowercase string in place', 'thiscall', None, ret=None, gen=g4cc690, note='batch31066')
S(0x57d830, 'GUESS range table id remap', 'thiscall', None, ret='eax', gen=g57d830, note='batch31066')
S(0x623b80, 'GUESS byteswap copy 16-bit units', 'cdecl', None, ret=None, gen=g623b80, note='batch31066')
