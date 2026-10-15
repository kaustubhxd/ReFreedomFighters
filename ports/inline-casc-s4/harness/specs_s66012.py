"""specs_s66012.py - cascade s4 batch 66012: 0x4d2030 (clear a list of owned nodes, one by index or all)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g4d2030(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t = e.alloc(0x30, 8)
    k = r.choice([0, 1, 2, 3, 4])
    nodes = [e.alloc(0x20, 8) for _ in range(k)]
    for i, n in enumerate(nodes):
        e.w32(n, t)
        e.w32(n + 4, nodes[i - 1] if i > 0 else 0)
        e.w32(n + 8, nodes[i + 1] if i + 1 < k else 0)
        e.w32(n + 0xc, rnd(c, 8))
    e.w32(t + 0x18, nodes[0] if k else 0)
    e.w32(t + 0x1c, nodes[-1] if k else 0)
    e.w32(t + 0x14, r.choice([0, rnd(c, 8)]))
    e.w32(t + 0x10, r.getrandbits(32))
    pick = r.choice(nodes + [0]) if nodes else 0
    hook_rec(c, 0x4d1cf0, 1, this=True, ret=pick)
    hook_rec(c, 0x634273, 2, pop=0)
    i = r.choice([-1, -1, 0, 1, 2, 0x7fffffff, 0xfffffff0])
    return [t, i & 0xffffffff]


S(0x4d2030, 'GUESS clear a list of owned nodes by index or all', 'thiscall', None, ret=None, gen=_g4d2030, note='batch66012')
