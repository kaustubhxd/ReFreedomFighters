"""specs_s32071.py - h2 () batch 32071: 0x4e6720, 0x4ccd60, 0x5f1720. Callees hooked as recorders (0x41e290 returns a fixed spec buffer)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def g4e6720(c):
    clear_hooks(c)
    r = c.rng
    buf = rnd(c, 0x200)
    hook_rec(c, 0x41e290, 1, ret=buf, pop=0)
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x40)
    c.emu.w32(me + 4, r.choice([0, rnd(c, 8), r.getrandbits(32)]))
    ln = r.choice([0, 1, 2, r.randrange(0, 100)])
    s = rnd(c, 0x80)
    c.emu.wbytes(s, bytes(r.randrange(1, 256) for _ in range(ln)) + b'\0')
    return [me, r.getrandbits(32), s]


def g4ccd60(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3, r.randrange(0, 13), r.randrange(0, 13) + 32, r.randrange(0, 13), r.choice([16, 48, 49, 0x1010])])
    buf = rnd(c, 4 << (n & 31))
    hook_rec(c, 0x41e290, 1, ret=buf, pop=0)
    return [rnd(c, 0x20), n]


def g5f1720(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5fb5a0, 0, this=True, pop=0)
    inner = rnd(c, 0x20)
    b = rnd(c, 0x100)
    c.emu.w32(b + 4, inner)
    lo = r.getrandbits(32)
    c.emu.w32(b + 0xac, lo)
    c.emu.w32(b + 0xb0, r.choice([lo, (lo + 4 * r.randrange(0, 50)) & 0xffffffff, (lo - 4 * r.randrange(0, 50)) & 0xffffffff, (lo + r.randrange(0, 200)) & 0xffffffff, r.getrandbits(32)]))
    me = rnd(c, 0x20)
    c.emu.w32(me + 0xc, b)
    return [me]


S(0x4e6720, 'GUESS replace owned string copy + value', 'thiscall', None, ret='eax', gen=g4e6720, note='batch32071')
S(0x4ccd60, 'GUESS free-list table init', 'thiscall', None, ret='eax', gen=g4ccd60, note='batch32071')
S(0x5f1720, 'GUESS pull pointer back by whole dwords', 'thiscall', None, ret=None, gen=g5f1720, note='batch32071')
