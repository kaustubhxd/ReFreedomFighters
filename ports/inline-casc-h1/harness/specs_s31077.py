"""specs_s31077.py - batch 31077."""
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, clear_hooks, hook_rec


def r32(c):
    return c.rng.getrandbits(32)


def _clob(c, extra=None):
    j = r32(c)

    def f(emu, k):
        if extra:
            extra(emu, k)
        emu.mu.reg_write(REGS['ecx'], j)
    return f


def g498960(c):
    clear_hooks(c)
    r = c.rng
    scratch = c.emu.alloc(8, 4)

    def rec(emu, k):
        emu.w32(scratch, emu.reg('edx'))
        emu.mu.reg_write(REGS['ecx'], 0x77)
    hook_rec(c, 0x4daf20, 0, ret=r32(c), pop=0, this=True, side=rec)
    hook_rec(c, 0x498750, 4, ret=r32(c), pop=0x10, this=True)
    me = rnd(c, 0x40)
    b = rnd(c, 0x60)
    if r.random() < 0.7:
        P = rnd(c, 0x20)
        Q = rnd(c, 0x40)
        c.emu.w32(P + 0xc, Q)
        c.emu.w32(b + 0x54, P)
    else:
        c.emu.w32(b + 0x54, 0)
    return [me, r32(c), b, r32(c)]


def g5fd630(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5fd670, 4, ret=r32(c), pop=0x10, this=True)
    me = rnd(c, 0x10)
    start = r.randrange(0, 0x10000)
    c.emu.w32(me, start)
    c.emu.w32(me + 4, start + r.choice([0, 5, 0x20, 0x100]) + r.randrange(0, 4))
    return [r.randrange(0, 0x40), r.choice([0, 3, 0x10, 0x200, r32(c)]), rnd(c, 8)]


def _tree(c, n):
    nodes = [rnd(c, 0x20) for _ in range(n)]
    for nd in nodes:
        c.emu.w32(nd + 5, 0)
        c.emu.w32(nd + 9, 0)
    free = list(nodes[1:])
    c.rng.shuffle(free)
    for i, nd in enumerate(nodes):
        for off in (5, 9):
            if free and c.rng.random() < 0.5:
                cand = free.pop()
                if nodes.index(cand) > i:
                    c.emu.w32(nd + off, cand)
                else:
                    free.append(cand)
    return nodes


def g5fb330(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x54f870, 2, ret=r32(c), pop=8, this=True)
    n = r.randrange(0, 5)
    nodes = _tree(c, n)
    return [rnd(c, 0x20), nodes[0] if nodes else 0]


def g61cce0(c):
    clear_hooks(c)
    r = c.rng
    val = r.choice([0, 0, r32(c)])

    def put(emu, k):
        emu.w32(emu.arg32(2), val)
        emu.mu.reg_write(REGS['ecx'], 0x55)
    hook_rec(c, 0x61ce20, 5, ret=r32(c), pop=0, deref={2: 1}, side=put)
    hook_rec(c, 0x61d090, 6, ret=r32(c), pop=0)
    me = rnd(c, 0x120)
    return [me, r32(c), r32(c), r32(c)]


def _walk(first, tail):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, first, 0, ret=r.choice([0, 1, 0x100, 0x101]), pop=0, this=True, side=_clob(c))
        hook_rec(c, tail, 0, ret=r32(c), pop=0, this=True)
        me = rnd(c, 0x20)
        n = r.randrange(0, 5)
        nodes = [rnd(c, 0x20) for _ in range(n)]
        for i, nd in enumerate(nodes):
            w = 0xffff if r.random() < 0.6 else r.randrange(0, 0xfffe)
            c.emu.wbytes(nd + 2, w.to_bytes(2, 'little'))
            nxt = nodes[i + 1] if i + 1 < n else r.choice([0, nodes[0]])
            c.emu.w32(nd + 8, nxt)
        c.emu.w32(me + 8, nodes[0] if nodes else 0)
        return [me]
    return g


def g5255d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x529ca0, 1, ret=r32(c), pop=4, this=True)
    hook_rec(c, 0x529cd0, 1, ret=r32(c), pop=4, this=True)
    me = rnd(c, 0xe00)
    c.emu.w32(me + 0x8c, r.choice([0, -1 & 0xffffffff, 1, 2, 3]))
    c.emu.w32(me + 0x90, r.choice([0, -2 & 0xffffffff, 1, 2, 4]))
    return [me]


def g5fb5b0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5fe200, 1, ret=r32(c), pop=4, this=True)
    hook_rec(c, 0x54f870, 2, ret=r32(c), pop=8, this=True)
    me = rnd(c, 0x20)
    head = rnd(c, 0x20)
    n = r.randrange(0, 4)
    nodes = [rnd(c, 0x20) for _ in range(n)]
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 5, nodes[i + 1] if i + 1 < n else 0)
    c.emu.w32(head + 1, nodes[0] if nodes else 0)
    c.emu.w32(me, head)
    c.emu.w32(me + 4, r.choice([0, 1, r32(c)]))
    return [me]


S(0x498960, 'GUESS call 4daf20 then 498750 with member', 'thiscall', None, ret='eax', gen=g498960, note='batch31077')
S(0x5fd630, 'GUESS clamp span and call 5fd670', 'thiscall', None, ret='eax', gen=g5fd630, note='batch31077')
S(0x5fb330, 'GUESS post-order walk calling 54f870', 'thiscall', None, ret=None, gen=g5fb330, note='batch31077')
S(0x61cce0, 'GUESS call 61ce20 with &out, then 61d090', 'cdecl', None, ret=None, gen=g61cce0, note='batch31077')
S(0x6154b0, 'GUESS skip free entries then 615650/615560', 'thiscall', None, ret='eax', gen=_walk(0x615650, 0x615560), note='batch31077')
S(0x6482a0, 'GUESS skip free entries then 648c50/648630', 'thiscall', None, ret='eax', gen=_walk(0x648c50, 0x648630), note='batch31077')
S(0x5255d0, 'GUESS loop 529ca0/529cd0 with 0.5', 'thiscall', None, ret=None, gen=g5255d0, note='batch31077')
S(0x5fb5b0, 'GUESS free list nodes and reset head', 'thiscall', None, ret=None, gen=g5fb5b0, note='batch31077')
