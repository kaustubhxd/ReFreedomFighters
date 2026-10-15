"""specs_s31134.py - Sonnet h1 batch 31134: 0x65a490 (MMX 4x4 block multiply-accumulate, fastcall) and 0x602d80 (in-order position search in a tree)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def g65a490(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([1, 2, 3, 4, 5, 8, 9, 11])        # count dword; iterations = (n+3)>>2
    iters = (n + 3) >> 2
    sz = 0x20 * max(iters, 1) + 8
    dst = rnd(c, sz)
    tb = rnd(c, sz)
    tc = rnd(c, sz)
    a = rnd(c, 0x10)
    return [dst, tb, a, tc, n]


class _T:
    pass


def _build(c, n):
    """Random binary tree of n nodes laid out like the exe's: parent +1, left +5, right +9, key pointer +0x19."""
    r = c.rng
    e = c.emu
    H = rnd(c, 0x30)
    nodes = [rnd(c, 0x30) for _ in range(n)]
    keys = [rnd(c, 0x30) for _ in range(n)]
    for nd, k in zip(nodes, keys):
        e.w32(nd + 0x19, k)
        e.w32(nd + 1, H)
        e.w32(nd + 5, 0)
        e.w32(nd + 9, 0)
    root = None

    def place(i):
        nonlocal root
        if root is None:
            root = i
            return
        cur = root
        while True:
            side = r.choice([5, 9])
            ch = e.r32(nodes[cur] + side)
            if ch == 0:
                e.w32(nodes[cur] + side, nodes[i])
                e.w32(nodes[i] + 1, nodes[cur])
                return
            cur = nodes.index(ch)
    for i in range(n):
        place(i)
    if n == 0:
        for off in (1, 5, 9):
            e.w32(H + off, H)
    else:
        e.w32(H + 1, nodes[root])
        lm = nodes[root]
        while e.r32(lm + 5):
            lm = e.r32(lm + 5)
        rm = nodes[root]
        while e.r32(rm + 9):
            rm = e.r32(rm + 9)
        e.w32(H + 5, lm)
        e.w32(H + 9, rm)
    return H, nodes, keys


def g602d80(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3, 4, 5])
    H, nodes, keys = _build(c, n)
    for k in keys:
        c.emu.w32(k + 0x20, r.choice([0, 1, 2, 3, 0xff, r32(c)]))
    me = rnd(c, 0x20)
    c.emu.w32(me + 1, H)
    mask = r.choice([0, 0, 1, 2, 3, r32(c)])
    key = r.choice(keys + [r32(c)]) if keys else r32(c)
    return [me, key, mask]


S(0x65a490, 'GUESS MMX fixed-point multiply of three 4x4 word blocks, accumulate into dst (fastcall ecx=dst, edx=table, 3 stack args)', 'fastcall', None, ret=None, gen=g65a490, note='batch31134')
S(0x602d80, 'GUESS in-order position of key (optionally flag-filtered) in tree at this+1, -1 when absent', 'thiscall', None, ret='eax', gen=g602d80, note='batch31134')
