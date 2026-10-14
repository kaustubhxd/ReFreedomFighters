"""specs_s31079.py - batch 31079."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, clear_hooks, hook_rec


def r32(c):
    return c.rng.getrandbits(32)


def _clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g462a70(c):
    clear_hooks(c)
    r = c.rng
    rows = c.emu.alloc(0x40, 4)
    cnt = [0]

    def rec(emu, k):
        emu.w32(rows + 4 * min(k, 15), emu.reg('edx'))
        emu.mu.reg_write(REGS['ecx'], 0x1234)
    hook_rec(c, 0x4cc850, 0, ret=r.choice([0, 1, 0]), pop=0, this=True, side=rec)
    hook_rec(c, 0x465330, 1, ret=r32(c), pop=4, this=True)
    me = rnd(c, 0x40)
    n = r.randrange(0, 5)
    arr = rnd(c, 0x18 * 6)
    for i in range(n):
        c.emu.w32(arr + 0x18 * i + 4, r32(c) | (r.getrandbits(1)))
        c.emu.w32(arr + 0x18 * i + 0x14, 0 if r.random() < 0.25 else rnd(c, 0x60))
    c.emu.w32(me + 0x1c, arr)
    c.emu.w32(me + 0x20, n)
    return [me, r32(c)]


def g430c70(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x10)
    base = r.randrange(0x1000, 0x100000)
    end = base + r.choice([0, 8, 0x20, 0x100])
    c.emu.w32(me, base)
    c.emu.w32(me + 4, end)
    scratch = c.emu.alloc(8, 4)

    def rec(emu, k):                      # records the register arguments ECX and EDX
        emu.w32(scratch, emu.reg('ecx'))
        emu.w32(scratch + 4, emu.reg('edx'))
    hook_rec(c, 0x42b1e0, 3, ret=r.choice([end, end, base, base + 3, 0, r32(c)]), pop=0xc, side=rec)
    a = rnd(c, 0x10)
    s = r.randrange(0, 0x1000)
    c.emu.w32(a, s)
    c.emu.w32(a + 4, s + r.choice([0, 1, 4, 0x10, 0x200]))
    return [me, a, r.choice([0, 1, 4, 0x10, 0x80, 0x300])]


def g63ad70(c):
    clear_hooks(c)
    r = c.rng
    fresh = rnd(c, 0x80)
    c.emu.wbytes(fresh + 2, r.choice([0, 1, 2, 5, 0xffff]).to_bytes(2, 'little'))

    def side(emu, k):
        emu.w32(emu.reg('ecx') + 8, fresh)
    hook_rec(c, 0x63b2c0, 0, ret=r.choice([0, 1, 0x100, 0x101]), pop=0, this=True, side=side)
    me = rnd(c, 0x20)
    n = r.randrange(0, 5)
    nodes = [rnd(c, 0x80) for _ in range(n)]
    for i, nd in enumerate(nodes):
        w = 0xffff if r.random() < 0.55 else r.randrange(0, 7)
        c.emu.wbytes(nd + 2, w.to_bytes(2, 'little'))
        c.emu.w32(nd + 8, nodes[i + 1] if i + 1 < n else r.choice([0, nodes[0]]))
    c.emu.w32(me + 8, nodes[0] if nodes else 0)
    return [me]


def g4247e0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634d10, 3, ret=r32(c), pop=0)
    hook_rec(c, 0x634d22, 3, ret=r32(c), pop=0)
    runs = []
    total = 0
    for _ in range(r.randrange(0, 5)):
        n = r.randrange(1, 9)
        if r.random() < 0.5:
            runs.append(n.to_bytes(2, 'little') + bytes([r.randrange(0, 256)]))
        else:
            runs.append((-n & 0xffff).to_bytes(2, 'little') + bytes(r.randrange(0, 256) for _ in range(n)))
        total += n
    stream = b''
    for i, run in enumerate(runs):
        if i < len(runs) - 1 and r.random() < 0.3:
            stream += b'\x00\x00'                  # zero-length run in the middle
        stream += run
    sbuf = c.emu.alloc(len(stream) + 8, 4)
    c.emu.wbytes(sbuf, stream)
    dst = rnd(c, 0x60)
    return [dst, dst + total, sbuf, r32(c)]


def g48b530(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4920e0, 2, ret=r32(c), pop=8, this=True)
    me = rnd(c, 0xa20)
    cap = r.randrange(0, 6)
    cur = r.randrange(0, 7)
    c.emu.w32(me + 0xa08, cap)
    c.emu.w32(me + 0xa0c, cur)
    n = r.randrange(0, 4)
    nodes = [rnd(c, 0x20) for _ in range(n)]
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 8, 0 if r.random() < 0.7 else r32(c))
        c.emu.w32(nd + 4, r.choice([-5, 0, 3, 10, 100]) & 0xffffffff)
        c.emu.w32(nd + 0x10, nodes[i + 1] if i + 1 < n else 0)
    c.emu.w32(me + 0xa04, nodes[0] if nodes else 0)
    return [me, r32(c), r.choice([-7, -1, 0, 3, 10, 50, 1000]) & 0xffffffff]


def g4d92e0(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x40)
    blk2 = rnd(c, 0x20)
    hook_rec(c, 0x41e290, 1, ret=blk, pop=0)
    hook_rec(c, 0x4d9090, 2, ret=blk2, pop=8, this=True)
    n = r.choice([0, 1, 5, 20])
    s = c.emu.alloc(n + 1, 4)
    c.emu.wbytes(s, bytes(r.randrange(1, 256) for _ in range(n)) + b'\0')
    return [rnd(c, 0x20), s, r32(c)]


def g4e4890(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e6bf0, 1, ret=r32(c), pop=4, this=True)
    stride = 0x20
    base = c.emu.alloc(stride * 8 + 0x20, 16)
    c.emu.wbytes(base, bytes(stride * 8 + 0x20))
    a = rnd(c, 0x20)
    c.emu.w32(a, base)
    c.emu.w32(a + 0xc, stride)
    depth = r.randrange(1, 4)
    idxs = r.sample(range(1, 7), depth + 1)
    # idxs[0] is the leaf (this), idxs[i+1] its parent chain
    for i in range(depth):
        node = base + stride * idxs[i]
        parent = idxs[i + 1]
        c.emu.wbytes(node + 8, parent.to_bytes(2, 'little'))
        slot = r.randrange(0, 4)
        c.emu.wbytes(base + stride * parent + 2 * slot, idxs[i].to_bytes(2, 'little'))
        c.emu.wbytes(base + stride * parent + 8, (idxs[i + 2] if i + 2 <= depth else 0).to_bytes(2, 'little'))
    if r.random() < 0.15:
        c.emu.w32(base + stride * idxs[0] + 0xc, 1)
    if r.random() < 0.15:
        c.emu.wbytes(base + stride * idxs[0] + 8, (0).to_bytes(2, 'little'))
    return [base + stride * idxs[0], a]


S(0x462a70, 'GUESS per-entry check, call 465330 on failure', 'thiscall', None, ret=None, gen=g462a70, note='batch31079')
S(0x430c70, 'GUESS bounded append via 42b1e0, return offset', 'thiscall', None, ret='eax', gen=g430c70, note='batch31079')
S(0x63ad70, 'GUESS take free slot from ring, init entry', 'thiscall', None, ret='eax', gen=g63ad70, note='batch31079')
S(0x4247e0, 'GUESS run-length decode into buffer', 'stdcall', None, ret='eax', gen=g4247e0, note='batch31079')
S(0x48b530, 'GUESS insert sorted entry into list', 'thiscall', None, ret='eax', gen=g48b530, note='batch31079')
S(0x4d92e0, 'GUESS duplicate string into node', 'thiscall', None, ret=None, gen=g4d92e0, note='batch31079')
S(0x4e4890, 'GUESS clear child link and recurse to parent', 'thiscall', None, ret=None, gen=g4e4890, note='batch31079')
