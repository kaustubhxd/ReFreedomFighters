"""specs_s31065.py - batch 31065."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def r32(c):
    return c.rng.getrandbits(32)


def g6301a0(c):
    clear_hooks(c)
    r = c.rng
    s = rnd(c, 0x16c0)
    c.emu.w32(s + 8, rnd(c, 0x80))
    c.emu.w32(s + 0x14, r.randrange(0, 0x20))
    c.emu.w32(s + 0x16b4, r.choice([-1 & 0xffffffff, 0, 1, 5, 8, 9, 20, 0x80000000]))
    return [s]


def _list(c, n):
    me = rnd(c, 0x60)
    c.emu.w32(me, n)
    return me


def g_list(c):
    clear_hooks(c)
    r = c.rng
    n = r.randrange(0, 7)
    me = _list(c, n)
    r1 = r.random()
    if r1 < 0.6 and n > 0:
        v = c.emu.r32(me + 4 + 4 * r.randrange(n))
    elif r1 < 0.8:
        v = 0
    else:
        v = r32(c)
    if r.random() < 0.3 and n > 1:        # duplicates
        c.emu.w32(me + 4 + 4 * (n - 1), v)
    return [me, v]


def g629480(c):
    clear_hooks(c)
    r = c.rng
    tag = c.emu.rbytes(0x6bfe60, 6)
    n = r.choice([0, 6, 11, 12, 12, 14, 20])
    buf = rnd(c, 32)
    if r.random() < 0.6:
        k = r.randrange(0, 7)
        w = b''.join(bytes([t, 0]) for t in tag[:k])
        c.emu.wbytes(buf, w)
        if r.random() < 0.3 and k < 6:
            c.emu.wbytes(buf + 2 * k, bytes([tag[k], 1]))
    out = c.emu.alloc(4, 4)
    return [r32(c), buf, buf + n, out]


def g62cce0(c):
    clear_hooks(c)
    me = rnd(c, 0x20)
    if c.rng.random() < 0.5:
        c.emu.w32(me + 0xc, 0)
    return [me, c.rng.choice([0xf, 0x15, 0x18, 0x1c, 0x1c, 0x17, c.rng.getrandbits(8)])]


def g4d06a0(c):
    clear_hooks(c)
    r = c.rng
    p = rnd(c, 0x30)
    for i in range(4):
        v = r.choice([0, 1, 2, 0x80, 0xff, 0x100, 0xc0, 0x80000000, r32(c), r32(c) & 0xff00, 0x6 << r.randrange(0, 20)])
        c.emu.w32(p + 4 * i, v)
    return [p]


def g454d30(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45d5b0, 1, ret=r32(c), pop=4, this=True)
    src = rnd(c, 0x60)
    inner = rnd(c, 0x40)
    c.emu.w32(inner + 0x23, 0x2000f0 if r.random() < 0.6 else r.choice([0x2000f1, r32(c)]))
    c.emu.w32(src + 0xc, inner)
    me = rnd(c, 0x60)
    return [me, src]


def g4e6880(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 5, 12])
    s = c.emu.alloc(n + 1, 4)
    c.emu.wbytes(s, bytes(r.choice([r.randrange(1, 256), r.randrange(0x61, 0x7b)]) for _ in range(n)) + b'\0')
    me = c.emu.alloc(4, 4)
    c.emu.w32(me, s)
    return [me, rnd(c, 4), rnd(c, 4)]


S(0x6301a0, 'GUESS flush pending bytes', 'cdecl', None, ret='eax', gen=g6301a0, note='batch31065')
S(0x5af260, 'GUESS swap-remove from list', 'thiscall', None, ret=None, gen=g_list, note='batch31065')
S(0x58a360, 'GUESS swap-remove from list, bool', 'thiscall', None, ret='al', gen=g_list, note='batch31065')
S(0x629480, 'GUESS match wide 6-char tag', 'cdecl', None, ret='eax', gen=g629480, note='batch31065')
S(0x62cce0, 'GUESS message handler 15/18', 'cdecl', None, ret='eax', gen=g62cce0, note='batch31065')
S(0x4d06a0, 'GUESS bit scan 4 dwords', 'stdcall', None, ret=None, gen=g4d06a0, note='batch31065')
S(0x454d30, 'GUESS conditional copy 12 fields then tail 45d5b0', 'thiscall', None, ret='eax', gen=g454d30, note='batch31065')
S(0x4e6880, 'GUESS rotate-xor string hashes', 'fastcall', None, ret=None, gen=g4e6880, note='batch31065')
