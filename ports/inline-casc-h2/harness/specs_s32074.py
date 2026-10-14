"""specs_s32074.py - h2 () batch 32074: 0x5d82a0, 0x5c2c10. Callees hooked as recorders."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g5d82a0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0xd0)
    src = me if r.random() < 0.2 else rnd(c, 0xd0)
    hook_rec(c, 0x634d2e, 5, ret=src, pop=0)
    return [me, r.getrandbits(32)]


def g5c2c10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x300)
    cnt = r.randrange(0, 5)
    e.w32(me + 0x2c0, cnt)
    for i in range(cnt):
        s = rnd(c, 0x20)
        e.wbytes(s, bytes(r.randrange(1, 256) for _ in range(r.randrange(2, 12))) + b'\0')
        e.w32(me + i * 14 + 8, s)
    idx = r.randrange(0, 6)
    rec = rnd(c, 0x60)
    n = r.choice([0, 1, 2, 5, 15, 16, 17, r.randrange(0, 18), (-r.randrange(1, 4)) & 0xffffffff])
    e.w32(rec + 0x44, n)
    pm = r.choice([0.0, 0.0, 0.05, 0.3])
    for i in range(16):
        if r.random() < pm:
            e.w32(rec + 4 + 4 * i, idx)
        else:
            e.w32(rec + 4 + 4 * i, (idx + 1 + r.randrange(0, 1000)) & 0xffffffff)
    hook_rec(c, 0x5c2e10, 1, this=True, ret=(rec if r.random() < 0.85 else 0))
    return [me, idx]


S(0x5d82a0, 'GUESS copy fields from dynamic-cast object', 'thiscall', None, ret='eax', gen=g5d82a0, note='batch32074')
S(0x5c2c10, 'GUESS register index in looked-up record', 'thiscall', None, ret=None, gen=g5c2c10, note='batch32074')
