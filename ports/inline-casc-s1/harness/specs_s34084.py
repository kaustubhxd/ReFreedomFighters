"""specs_s34084.py - six queue items. 0x497610: base pointer differences around multiples of 112; 0x52d510 / 0x52d380: [a+0x38] - e - 1 equals [this+8] in a half of the cases; 0x64b0b0: entry array of 0..4 pointers, indices below 0x20;
0x62df30 filter; 0x4e5de0: width byte 1..24 (also 0, 0x80, 33), b in 0..20 (0..5 when negative)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g497610b(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x80)
    base = rnd(c, 0x20)
    c.emu.w32(me + 0x14, base)
    a = rnd(c, 0x50)
    d = r.choice([0, 111, 112, 113, 224, -112, -1, -300, 1000000, -1000000, 7 * 112])
    c.emu.w32(base + 4, (a - d) & 0xffffffff)
    c.emu.w32(me + 0x28, r.choice([0, 111, 112, 113, 224, 0xffffffff, r.getrandbits(32), 5000]))
    c.emu.wbytes(me + 0x5d, r.getrandbits(32).to_bytes(4, 'little'))
    fl = r.getrandbits(32)
    fl = fl | 0x8000000 if r.random() < 0.2 else fl & ~0x8000000
    c.emu.w32(a + 0x3c, fl)
    return [me, a]


def _rec(nargs, ke_idx, kind):
    def g(c):
        clear_hooks(c)
        r = c.rng
        me = rnd(c, 0x40)
        o = rnd(c, 0x20)
        c.emu.w32(me + 4, o)
        a = rnd(c, 0x50)
        e = r.getrandbits(32) if r.random() < 0.3 else r.randrange(0, 6)
        k = r.randrange(0, 50)
        c.emu.w32(a + 0x38, (k + e + 1) & 0xffffffff)
        c.emu.w32(me + 8, k if r.random() < 0.6 else r.randrange(0, 50))
        cb = rnd(c, 0x10)
        if kind == 'b':
            args = [a, rnd(c, 0x10), cb, r.getrandbits(32), e]
        else:
            b = rnd(c, 0x10)
            c.emu.w32(b, r.choice([0, 1, r.getrandbits(32)]))
            args = [a, b, r.getrandbits(32), cb, r.getrandbits(32), e, r.getrandbits(32)]
        return [me] + args
    return g


def _g64b0b0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x10300)
    n = r.choice([0, 1, 2, 4])
    c.emu.wbytes(me + 0x101c1, n.to_bytes(4, 'little'))
    for i in range(n):
        e = rnd(c, 0x20)
        c.emu.wbytes(e + 0x12, r.choice([0, 1, 3, 0x1f, 5]).to_bytes(2, 'little'))
        t = rnd(c, 0x30)
        y = 0 if r.random() < 0.3 else rnd(c, 0x80)
        c.emu.w32(t + 0x20, y)
        c.emu.w32(e + 0x14, t)
        c.emu.wbytes(me + 0x101c5 + 4 * i, e.to_bytes(4, 'little'))
    return [me]


def _g62df30(c):
    clear_hooks(c)
    r = c.rng
    a = rnd(c, 0x20)
    c.emu.w32(a + 0xc, r.choice([0, 0, 1, r.getrandbits(32)]))
    return [a, r.choice([0x11, 0x11, 0x1b, 0xf, 0x1c, 0x1c, 0, 0x1d, r.getrandbits(32), 0xffffffff])]


def _g4e5de0(c):
    clear_hooks(c)
    r = c.rng
    buf = rnd(c, 0x200)
    me = rnd(c, 0x20)
    w = r.choice([1, 3, 5, 8, 12, 16, 24, 0, 33, 0x80, 0xff])
    off = 0x100
    c.emu.w32(me + 0x10, buf)
    c.emu.wbytes(buf + off, bytes([w]))
    signed = w >= 0x80
    b = r.randrange(0, 6) if signed else r.choice([0, 1, 2, 3, 5, 9, 15, 20])
    return [me, off, b]


S(0x497610, 'GUESS scaled slot index', 'thiscall', None, ret='eax', gen=_g497610b, note='batch34084')
S(0x52d510, 'GUESS write record kind 1', 'thiscall', None, ret='al', gen=_rec(5, 5, 'b'), note='batch34084')
S(0x52d380, 'GUESS write record kind 3', 'thiscall', None, ret='al', gen=_rec(7, 5, 'c'), note='batch34084')
S(0x64b0b0, 'GUESS refresh flags from entries', 'thiscall', None, ret=None, gen=_g64b0b0, note='batch34084')
S(0x62df30, 'GUESS event filter J', 'cdecl', None, ret='eax', gen=_g62df30, note='batch34084')
S(0x4e5de0, 'GUESS read bit field', 'thiscall', None, ret='eax', gen=_g4e5de0, note='batch34084')
