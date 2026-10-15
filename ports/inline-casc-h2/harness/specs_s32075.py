"""specs_s32075.py - h2 (Sonnet) batch 32075: 0x4d0840, 0x436b30. Callees hooked as recorders."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g4d0840(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4cfc70, 1, this=True, pop=4)
    hook_rec(c, 0x4d09b0, 2, this=True, pop=8)
    blk = rnd(c, 0x400)
    m = r.choice([r.randrange(0, 0x20), r.randrange(0, 0x100), r.randrange(0x19, 0x30), 0x18, 0x19])
    n = r.choice([0, m, max(0, m - 0x18), max(0, m - 0x19), r.randrange(0, m + 1)])
    e.w32(blk + 8, m)
    me = rnd(c, 0x8300)
    return [me, blk, n]


def g436b30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    buf = rnd(c, 0x200)
    hook_rec(c, 0x41e290, 1, ret=buf, pop=0)
    hook_rec(c, 0x439c20, 1, this=True, pop=4)
    p = rnd(c, 0x20)
    if r.random() < 0.7:
        s = rnd(c, 0x80)
        e.wbytes(s, bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, r.randrange(0, 100)]))) + b'\0')
        e.w32(p, s)
    else:
        e.w32(p, 0)
    return [rnd(c, 0x40), r.choice([0, r.getrandbits(32), 1]), p]


S(0x4d0840, 'GUESS split free block and mark used', 'thiscall', None, ret='eax', gen=g4d0840, note='batch32075')
S(0x436b30, 'GUESS init record with string copy', 'thiscall', None, ret='eax', gen=g436b30, note='batch32075')
