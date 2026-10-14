"""specs_s31078.py - batch 31078."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, clear_hooks, hook_rec


def r32(c):
    return c.rng.getrandbits(32)


def _clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g44c930(c):
    clear_hooks(c)
    hook_rec(c, 0x43de40, 3, ret=r32(c), pop=0xc, this=True, side=_clob(c))
    return [rnd(c, 0x140), r32(c), r32(c), r32(c)]


def g534190(c):
    clear_hooks(c)
    r = c.rng
    blk = c.emu.alloc(0x3f500, 16)
    c.emu.wbytes(blk, r.randbytes(0x3f500))      # non-zero contents so zeroing stores are visible
    hook_rec(c, 0x41e290, 1, ret=blk, pop=0)
    hook_rec(c, 0x533ef0, 0, ret=r32(c), pop=0, this=True)
    me = rnd(c, 0x1030)
    c.emu.w32(me + 8, 0 if r.random() < 0.6 else blk)
    return [me]


def g645c30(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x645c90, 4, ret=r32(c), pop=0x10, this=True)
    me = rnd(c, 0x300)
    c.emu.w32(me + 0x291, r.choice([0, 0, 0, 1]))
    c.emu.wbytes(me + 0x295, bytes([r.choice([0, 0, 0, 1])]))
    c.emu.w32(me + 0x11, r.choice([1, 2, 3, 5]))
    return [me, r32(c), r32(c), r32(c), r32(c)]


def g65f0f0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0, side=_clob(c))
    me = rnd(c, 0x6c00)
    c.emu.w32(me + 0xc8, r.choice([0, 1, 2, 4]))
    return [me]


def g4a1850(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, ret=r32(c), pop=0, side=_clob(c))
    me = rnd(c, 0xa0)
    n = r.choice([0, 1, 2, 3, 4, -1 & 0xffffffff])
    c.emu.w32(me + 0x48, n)
    vals = []
    for i in range(4):
        b = rnd(c, 0x10)
        v = r.choice([1, 2, 3, r32(c)])
        c.emu.w32(b, v)
        c.emu.w32(me + 0x5c + 4 * i, b)
        vals.append(v)
    a = r.choice(vals + [r32(c)])
    return [me, a]


def g615ee0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x64d400, 1, ret=r32(c), pop=4)
    Z = rnd(c, 0x10)
    Y = rnd(c, 0x20)
    c.emu.w32(Y + 8, Z)
    X = rnd(c, 0x20)
    c.emu.w32(X + 0x10, Y)
    E = rnd(c, 0x40)
    c.emu.w32(E + 8, r32(c))
    c.emu.w32(E + 0xc, r.choice([0, r32(c)]))
    obj_ = rnd(c, 0x40)
    c.emu.w32(obj_ + 8, X)
    c.emu.w32(obj_ + 0x14, E)
    c.emu.w32(obj_ + 0xc, r.choice([0, r32(c)]))
    return [obj_]


def g5be190(c):
    clear_hooks(c)
    r = c.rng
    idx = r.randrange(0, 8)
    hook_rec(c, 0x5be690, 1, ret=idx, pop=4, this=True)
    me = rnd(c, 0xa00)
    w = r.randrange(0, 0x10000)
    mode = r.choice([0, 0, 1, 2])
    c.emu.wbytes(me + 0x914, (w if mode == 0 else r32(c) & 0xffff).to_bytes(2, 'little'))
    c.emu.wbytes(me + 0x918, (w if mode == 1 else (r32(c) & 0xffff)).to_bytes(2, 'little'))
    b = r.choice([0xff, 0xff, 0, 1, 3, 6])
    c.emu.wbytes(me + 0x71c + 5 * idx, bytes([b]))
    if b != 0xff:
        c.emu.wbytes(me + 0x85 + 0x3a * b, bytes([r.choice([0, 1, 2])]))
    c.emu.w32(me + 0x92a, r.randrange(0, 0x40))
    return [me, w, r32(c)]


S(0x44c930, 'GUESS ctor base 43de40, vtable 6803c0, clear table', 'thiscall', None, ret='eax', gen=g44c930, note='batch31078')
S(0x534190, 'GUESS init 1024-entry pool, tail 533ef0', 'thiscall', None, ret='eax', gen=g534190, note='batch31078')
S(0x645c30, 'GUESS loop 645c90 over entries', 'thiscall', None, ret=None, gen=g645c30, note='batch31078')
S(0x65f0f0, 'GUESS free records and reset table', 'thiscall', None, ret='eax', gen=g65f0f0, note='batch31078')
S(0x4a1850, 'GUESS remove entry by key with swap', 'thiscall', None, ret=None, gen=g4a1850, note='batch31078')
S(0x615ee0, 'GUESS fill member pointers from linked records', 'stdcall', None, ret='al', gen=g615ee0, note='batch31078')
S(0x5be190, 'GUESS slot refcount update', 'thiscall', None, ret='eax', gen=g5be190, note='batch31078')
