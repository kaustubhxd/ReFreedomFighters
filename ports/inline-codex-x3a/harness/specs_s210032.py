"""specs_s210032.py - Sonnet-w3a: suffix matcher, stored-block writer, list unlink with lazy pool, indexed cache; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g626ed0(c):
    clear_hooks(c)
    p = rnd(c, 0x10)
    pat = [0, c.rng.choice([0x58, 0x78, 0x58, 0x78, 0x41]), 0, c.rng.choice([0x4d, 0x6d, 0x4d, 0x6d, 0x41]), 0,
           c.rng.choice([0x4c, 0x6c, 0x4c, 0x6c, 0x41])]
    if c.rng.random() < 0.15: pat[c.rng.randrange(0, 6)] = c.rng.randrange(0, 256)
    c.emu.wbytes(p, bytes(pat))
    L = 6 if c.rng.random() < 0.9 else c.rng.choice([0, 5, 7])
    return [_r(c), p, p + L, rnd(c, 8)]


def g630910(c):
    clear_hooks(c)
    a = rnd(c, 0x16c0)
    buf = rnd(c, 0x1400)
    c.emu.w32(a + 8, buf); c.emu.w32(a + 0x14, c.rng.randrange(0, 8))
    hook_rec(c, 0x6301a0, 1, ret=_r(c), pop=0)
    n = c.rng.choice([0, 1, 2, 3, 5, 8, 0x100, 0x181, 0x1000])
    return [a, rnd(c, 0x1400), n, c.rng.choice([0, 1, 1])]


def g4cdd50(c):
    clear_hooks(c)
    t = rnd(c, 0x40)
    c.emu.w32(t + 0x18, c.rng.choice([0, 1, 2, 3]))
    node = rnd(c, 0x30)
    a = node + 8 - 0  # a - 8 + idx*4 == node when idx*? choose a so esi points inside node region
    idx = c.emu.r32(t + 0x18)
    a = node + 8 - idx * 4
    prev = 0 if c.rng.random() < 0.4 else rnd(c, 0x10)
    nxt = 0 if c.rng.random() < 0.4 else rnd(c, 0x10)
    c.emu.w32(node, prev); c.emu.w32(node + 4, nxt)
    pool = obj(c, 0x20, {4: pystub(c, 1, ret=_r(c), this=True)}, nslots=8)
    c.emu.w32(t + 0x24, 0 if c.rng.random() < 0.4 else pool)
    hook_rec(c, 0x41e290, 1, ret=lambda e, k: rnd(c, 0x20), pop=0)
    return [t, a]


def g4d1cf0(c):
    clear_hooks(c)
    t = obj(c, 0x40, {0x2c: pystub(c, 0, ret=c.rng.choice([0, 1, 2, 3, 4]), this=True)}, nslots=0x20)
    arr = 0 if c.rng.random() < 0.3 else rnd(c, 0x80) + 0x20
    c.emu.w32(t + 0x10, c.rng.choice([0, 1, 2, 3, 4]) if arr else 0)
    c.emu.w32(t + 0x14, arr)
    k = c.rng.choice([0, 1, 2, 3, 4])
    nodes = [rnd(c, 0x10) for _ in range(k)]
    for i, nd in enumerate(nodes): c.emu.w32(nd + 8, nodes[i + 1] if i + 1 < k else 0)
    c.emu.w32(t + 0x18, nodes[0] if nodes else 0)
    hook_rec(c, 0x634273, 2, ret=_r(c), pop=0)
    hook_rec(c, 0x41e290, 1, ret=lambda e, k: rnd(c, 0x80) + 0x20, pop=0)
    return [t, c.rng.choice([0, 1, 2, 3, 5, 0xffffffff, 0xfffffffe] if arr else [0, 1, 2, 3, 5])]


S(0x626ed0, 'match_x_m_l_pattern', 'cdecl', None, ret='eax', gen=g626ed0, note='batch210032')
S(0x630910, 'write_stored_block', 'cdecl', None, ret='eax', gen=g630910, note='batch210032')
S(0x4cdd50, 'unlink_node_lazy_pool', 'thiscall', None, ret='eax', gen=g4cdd50, note='batch210032')
S(0x4d1cf0, 'indexed_cache_rebuild', 'thiscall', None, ret='eax', gen=g4d1cf0, note='batch210032')
