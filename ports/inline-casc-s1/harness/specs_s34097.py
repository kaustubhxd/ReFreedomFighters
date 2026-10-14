"""specs_s34097.py - seven items.
0x6200d0 / 0x620120: short strings over {'\\r', '\\n', ' ', 'a', 'b'}. 0x52d4a0: key matches [this+8] in a half. 0x60f040: register ABI (ecx, edx, stack s2). 0x5de900: entry count 0..3.
0x4e5360: the exe faults on a non-negative flag word so the spec keeps it negative. 0x4e83f0: acyclic parent links ([x] -> a later node or the sentinel)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _str(c, r, alphabet, n):
    s = rnd(c, 0x30)
    c.emu.wbytes(s, bytes(r.choice(alphabet) for _ in range(n)) + b'\0')
    return s


def _g6200d0(c):
    clear_hooks(c)
    r = c.rng
    return [_str(c, r, b'\r\nab\r\r\n', r.choice([0, 1, 2, 3, 5, 9]))]


def _g620120(c):
    clear_hooks(c)
    r = c.rng
    return [_str(c, r, b'\r\n  ab', r.choice([0, 1, 2, 3, 5, 9]))]


def _g52d4a0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x40)
    o = rnd(c, 0x20)
    c.emu.w32(me + 4, o)
    a = rnd(c, 0x50)
    e = r.choice([0, 1, 2, 5, r.getrandbits(32)])
    k = r.randrange(0, 50)
    c.emu.w32(a + 0x38, (k + e + 1) & 0xffffffff)
    c.emu.w32(me + 8, k if r.random() < 0.6 else r.randrange(0, 50))
    return [me, a, rnd(c, 0x10), rnd(c, 0x10), r.getrandbits(32), e]


def _g60f040(c):
    clear_hooks(c)
    return [rnd(c, 0x50), rnd(c, 0x30), rnd(c, 0x10)]


def _g5de900(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x100)
    c.emu.w32(me, r.choice([0, 1, 2, 3]))
    return [me, rnd(c, 0x30)]


def _g4e5360(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x20)
    cc = rnd(c, 0x100)
    v = 0x80000000 | (r.getrandbits(32) & 0x7fffffff)
    c.emu.w32(cc + 4, v)
    c.emu.w32(cc + 0x10, r.randrange(0, 4))
    c.emu.w32(me + 4, cc)
    p = cc + 0x14 + 4 * c.emu.r32(cc + 0x10) if v & 0x40000000 else cc + 0x10
    a = r.choice([0, 1, 2, 3, 0xffffffff, 0x7fffffff, 0x80000000])
    c.emu.w32(p, r.choice([a, (a + 1) & 0xffffffff, (a - 1) & 0xffffffff, 0, 5, r.getrandbits(32)]))
    c.emu.w32(p + 8, r.randrange(0, 0x10))
    return [me, a]


def _g4e83f0(c):
    clear_hooks(c)
    r = c.rng
    s = rnd(c, 0x20)
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, s)
    k = r.randrange(2, 5)
    nodes = [rnd(c, 0x20) for _ in range(k)]
    pool = nodes + [s]
    for i, n in enumerate(nodes):
        c.emu.w32(n, r.choice(nodes[i + 1:] + [s]))
        c.emu.w32(n + 4, r.choice(pool) if r.random() < 0.5 else s)
        c.emu.w32(n + 8, r.choice(pool))
    return [me, nodes[0]]


S(0x6200d0, 'GUESS CRLF to LF', 'cdecl', None, ret='eax', gen=_g6200d0, note='batch34097')
S(0x52d4a0, 'GUESS write record kind 2', 'thiscall', None, ret='al', gen=_g52d4a0, note='batch34097')
S(0x60f040, 'GUESS build matrix rows', ('regs', ['ecx', 'edx', 's']), None, ret=None, gen=_g60f040, note='batch34097')
S(0x5de900, 'GUESS append 40-byte record', 'thiscall', None, ret='eax', gen=_g5de900, note='batch34097')
S(0x620120, 'GUESS collapse whitespace', 'cdecl', None, ret='eax', gen=_g620120, note='batch34097')
S(0x4e5360, 'GUESS indexed element plus base', 'thiscall', None, ret='eax', gen=_g4e5360, note='batch34097')
S(0x4e83f0, 'GUESS tree neighbour', 'thiscall', None, ret='eax', gen=_g4e83f0, note='batch34097')
