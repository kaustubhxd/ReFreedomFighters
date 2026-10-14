"""specs_s34098.py - seven items. 0x445750: hooked tail 0x45d5b0 (one arg, this recorded); 0x533ba0: hooked 0x5390b0 (plain, this recorded) with a random eax; 0x622fb0: random bytes (high bit in a half), room around the needed size.
0x532770: tables at the unaligned +0x5a (12-byte entries) and +0x54 (22-byte entries) with words 0xffff in a third; c = m, m-1 or other. 0x600420: random src with n small."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g53b7f0(c):
    clear_hooks(c)
    r = c.rng
    dst = rnd(c, 0x100)
    src = rnd(c, 0x100)
    c.emu.wbytes(src + 0x25, r.choice([0, 1, 2, 4, 0xffffffff]).to_bytes(4, 'little'))
    return [dst, src]


def _g622fb0(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 3, 6])
    m = r.choice([0, 1, 2, 3, 5, 8, 12])
    src = rnd(c, 0x40)
    dst = rnd(c, 0x40)
    c.emu.wbytes(src, bytes(r.choice([0x41, 0x7f, 0x80, 0xc3, 0xff, 0x20, r.getrandbits(8)]) for _ in range(n + 1)))
    ps = rnd(c, 0x10)
    pd = rnd(c, 0x10)
    c.emu.w32(ps, src)
    c.emu.w32(pd, dst)
    return [r.getrandbits(32), ps, src + n, pd, dst + m]


def _g445750(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45d5b0, 1, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x190), rnd(c, 0x190)]


def _g533ba0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5390b0, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x40)]


def _g532770(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x70)
    m = r.choice([0, 1, 5, 100])
    c.emu.w32(me + 0x38, m)
    t1 = rnd(c, 0x100)
    t2 = rnd(c, 0x100)
    for t in (t1, t2):
        for off in range(0, 0xf0, 2):
            if r.random() < 0.3:
                c.emu.wbytes(t + off, b'\xff\xff')
    c.emu.wbytes(me + 0x5a, t1.to_bytes(4, 'little'))
    c.emu.w32(me + 0x54, t2)
    # small indices so every access stays inside the tables
    for t in (t1, t2):
        for off in (4, 4 + 12, 4 + 24, 4 + 0x16, 4 + 0x2c):
            if r.random() < 0.7:
                c.emu.wbytes(t + off, r.choice([0, 1, 2, 3, 0xffff if False else 4]).to_bytes(2, 'little'))
    b = r.choice([0, 1, 2, 0x10000, 0x10001])
    return [me, r.getrandbits(32), b, r.choice([m, (m - 1) & 0xffffffff, m + 1, 7, r.getrandbits(32)])]


def _g600420(c):
    clear_hooks(c)
    r = c.rng
    src = rnd(c, 0x40)
    c.emu.w32(src + 8, r.choice([0, 1, 3, 10, 0x40]))
    c.emu.w32(src + 0x18, r.choice([0, 4, 0x10, r.randrange(0, 0x100)]))
    c.emu.w32(src + 0x10, r.choice([0, 1, 5, 0x10]))
    return [rnd(c, 0x40), src]


def _g4c3c90(c):
    clear_hooks(c)
    return [rnd(c, 0xb0), rnd(c, 0xb0)]


S(0x53b7f0, 'GUESS copy record with counted entries', 'stdcall', None, ret=None, gen=_g53b7f0, note='batch34098')
S(0x622fb0, 'GUESS Latin-1 to UTF-8', 'cdecl', None, ret=None, gen=_g622fb0, note='batch34098')
S(0x445750, 'GUESS copy fields then tail', 'thiscall', None, ret='eax', gen=_g445750, note='batch34098')
S(0x532770, 'GUESS entry marked invalid', 'thiscall', None, ret='al', gen=_g532770, note='batch34098')
S(0x600420, 'GUESS lay out packed table', 'thiscall', None, ret='eax', gen=_g600420, note='batch34098')
S(0x4c3c90, 'GUESS copy state fields', 'thiscall', None, ret='eax', gen=_g4c3c90, note='batch34098')
S(0x533ba0, 'GUESS call then return true', 'thiscall', None, ret='eax', gen=_g533ba0, note='batch34098')
