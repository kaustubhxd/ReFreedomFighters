"""specs_s34085.py - six queue items.
0x6238e0: source and destination are heap buffers, both even lengths; high-surrogate-like last source byte in a third.
0x5fb210: a valid red-black-like tree (parent +1, left +5, right +9, all unaligned) with a header node (parent = root, left = min, right = max) of 1..6 nodes; start node random (header included).
0x638ea0: limits 0..40 or large. 0x5ec5f0: idx -1 or 0..2, count 0..3. 0x61bac0: pairs table with equal / near-equal names."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g6238e0(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 2, 4, 6, 10])
    m = r.choice([0, 2, 4, 6, 12, 1, 3, 5, 7, 9])
    src = rnd(c, 0x40)
    dst = rnd(c, 0x40)
    if n and r.random() < 0.4:
        c.emu.wbytes(src + n - 1, bytes([r.choice([0xd8, 0xdb, 0xdf, 0xd7, 0xe0])]))
    ps = rnd(c, 0x10)
    pd = rnd(c, 0x10)
    c.emu.w32(ps, src)
    c.emu.w32(pd, dst)
    return [r.getrandbits(32), ps, src + n, pd, dst + m]


def _g5fb210(c):
    clear_hooks(c)
    r = c.rng
    k = r.randrange(1, 7)
    nodes = [rnd(c, 0x20) for _ in range(k)]
    keys = r.sample(range(100), k)
    hdr = rnd(c, 0x20)
    left = {}
    right = {}
    parent = {}
    root = nodes[0]
    order = sorted(range(k), key=lambda i: keys[i])
    rank = {i: keys[i] for i in range(k)}
    for i in range(1, k):
        cur = 0
        while True:
            if keys[i] < keys[cur]:
                if cur in left:
                    cur = left[cur]
                else:
                    left[cur] = i; parent[i] = cur; break
            else:
                if cur in right:
                    cur = right[cur]
                else:
                    right[cur] = i; parent[i] = cur; break
    def put(addr, p, l, rr):
        c.emu.wbytes(addr + 1, p.to_bytes(4, 'little'))
        c.emu.wbytes(addr + 5, l.to_bytes(4, 'little'))
        c.emu.wbytes(addr + 9, rr.to_bytes(4, 'little'))
    for i in range(k):
        put(nodes[i], nodes[parent[i]] if i in parent else hdr, nodes[left[i]] if i in left else 0, nodes[right[i]] if i in right else 0)
    put(hdr, nodes[0], nodes[order[0]], nodes[order[-1]])
    start = r.choice(nodes + [hdr])
    me = rnd(c, 0x10)
    c.emu.w32(me, start)
    return [me, rnd(c, 0x10), r.getrandbits(32)]


def _g638ea0(c):
    clear_hooks(c)
    r = c.rng
    lim = lambda: r.choice([0, 1, 2, 3, 5, 8, 13, 21, 33, 40, 0x7fffffff, 0x80000001, 0xffffffff, r.getrandbits(32)])
    return [rnd(c, 0x30), lim(), lim(), lim()]


def _g5ec5f0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x50)
    cnt = r.choice([0, 1, 2, 3])
    c.emu.wbytes(me + 0x3e, cnt.to_bytes(4, 'little'))
    base = rnd(c, 0x20)
    arr = rnd(c, 0x100)
    c.emu.w32(base + 4, arr)
    c.emu.wbytes(me + 0x3a, base.to_bytes(4, 'little'))
    return [me, rnd(c, 0x10), r.choice([0xffffffff, 0xffffffff, 0, 1, 2, 3])]


def _g61bac0(c):
    clear_hooks(c)
    r = c.rng
    alpha = b'abcAB'
    mk = lambda n: bytes(r.choice(alpha) for _ in range(n))
    key = mk(r.choice([0, 1, 2, 3]))
    kp = rnd(c, 0x10)
    c.emu.wbytes(kp, key + b'\0')
    n = r.choice([0, 1, 2, 4])
    table = rnd(c, 0x60)
    for i in range(n):
        nm = key if r.random() < 0.3 else mk(r.choice([0, 1, 2, 3]))
        sp = rnd(c, 0x10)
        c.emu.wbytes(sp, nm + b'\0')
        c.emu.w32(table + 8 * i, sp)
        c.emu.w32(table + 8 * i + 4, r.getrandbits(32))
    c.emu.w32(table + 8 * n, 0)
    return [table, kp]


S(0x6238e0, 'GUESS bounded word copy', 'cdecl', None, ret=None, gen=_g6238e0, note='batch34085')
S(0x5fb210, 'GUESS tree successor', 'thiscall', None, ret='eax', gen=_g5fb210, note='batch34085')
S(0x638ea0, 'GUESS bit mask setup', 'thiscall', None, ret='eax', gen=_g638ea0, note='batch34085')
S(0x57f820, 'GUESS constructor of grouped fields', 'thiscall', None, ret='eax', gen=lambda c: (clear_hooks(c), [rnd(c, 0xb0)])[1], note='batch34085')
S(0x5ec5f0, 'GUESS set vector in entries', 'thiscall', None, ret=None, gen=_g5ec5f0, note='batch34085')
S(0x61bac0, 'GUESS string table lookup', 'stdcall', None, ret='eax', gen=_g61bac0, note='batch34085')
