"""specs_s31130.py - Sonnet h1 batch 31130."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g607200(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 4])
    B = rnd(c, 0x40)
    idx = r.randrange(0, max(n, 1))
    nodes = []
    for i in range(max(n, 1)):
        chain = [rnd(c, 0x10) for _ in range(r.choice([0, 1, 2, 3]))]
        for j, nd in enumerate(chain):
            c.emu.w32(nd, chain[j + 1] if j + 1 < len(chain) else 0)
            c.emu.w32(nd + 4, r32(c))
        c.emu.w32(B + 4 * i, chain[0] if chain else 0)
    hook_rec(c, 0x606ea0, 2, ret=idx, pop=8, this=True, side=clob(c))
    cmpret = r.choice([[0], [1, 0], [1, 1, 0], [1, 1, 1, 1]])
    c.emu.w32(0x676414, pystub(c, 2, ret=lambda e, k: cmpret[min(k, len(cmpret) - 1)], pop=0))
    me = rnd(c, 0x20)
    c.emu.w32(me + 3, B)
    c.emu.w32(me + 7, B + 4 * n)
    return [me, rnd(c, 0x10), rnd(c, 0x10)]


def g5f2af0(c):
    clear_hooks(c)
    r = c.rng
    o2 = obj(c, 0x40, {0x2c: pystub(c, 3, ret=r32(c), pop=0)}, nslots=0x40)
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=o2)}, nslots=0x40))
    Y = obj(c, 0x40, {0: pystub(c, 2, ret=r32(c), this=True)}, nslots=0x10)
    X = rnd(c, 0x60)
    c.emu.w32(X + 0x3c, Y)
    W = rnd(c, 0x10)
    c.emu.w32(W, pystub(c, 2, ret=r32(c), pop=8, this=True))
    M = rnd(c, 0x20)
    c.emu.w32(M + 4, X)
    c.emu.w32(M + 8, W)
    me = rnd(c, 0x20)
    c.emu.w32(me + 0xc, M)
    return [me, r32(c), r32(c), r32(c)]


def g5fe920(c):
    clear_hooks(c)
    r = c.rng
    buf = rnd(c, 0x40)
    hook_rec(c, 0x41e290, 1, ret=buf, pop=0)
    hook_rec(c, 0x5ffb50, 0, ret=r.choice([0, 1, 5, r32(c) & 0xff]), pop=0, this=True)
    hook_rec(c, 0x5fe980, 3, ret=r32(c), pop=12, this=True, deref={1: 1})
    me = rnd(c, 0xa0)
    base = r.choice([0, 0x100, r32(c) & 0xffff])
    c.emu.w32(me + 0x60, base)
    c.emu.w32(me + 0x64, base + r.choice([0, 3, 10]))
    c.emu.w32(me + 0x9c, r.choice([0, 0, r32(c) | 1]))
    return [me, rnd(c, 0xb0), r32(c)]


def g64f8a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0, side=clob(c))
    me = rnd(c, 0x80)
    sub = lambda slot: r.choice([0, obj(c, 0x40, {slot: pystub(c, 1, ret=r32(c), this=True)}, nslots=0x100)])
    c.emu.w32(me + 0x20, r.choice([0, r32(c) | 1]))
    c.emu.w32(me + 0x2c, r.choice([0, r32(c) | 1]))
    c.emu.w32(me + 0x18, sub(0x160))
    c.emu.w32(me + 0x68, sub(0xc))
    return [me]


S(0x607200, 'GUESS hash-bucket lookup: 606ea0 index, walk chain with import compare', 'thiscall', None, ret='eax', gen=g607200, note='batch31130')
S(0x5f2af0, 'GUESS log, this[0xc] chain slot 0 word then call stored function pointer', 'thiscall', None, ret='eax', gen=g5f2af0, note='batch31130')
S(0x5fe920, 'GUESS allocate buffer sized from this span plus 5ffb50, 5fe980', 'thiscall', None, ret='eax', gen=g5fe920, note='batch31130')
S(0x64f8a0, 'GUESS release two buffers and two owned objects, zero fields', 'thiscall', None, ret='eax', gen=g64f8a0, note='batch31130')
