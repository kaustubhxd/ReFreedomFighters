"""specs_s35093.py - 0x4fd800 (thiscall(key) ret 4). this = random 0x60 bytes: head [+0x48] (null in 1/6, else a consistent doubly linked chain of 1..4 nodes of 0x20 bytes with keys, prev/next and owner = this), [+0x4c] tail, [+0x50] pointing at a node in
half of the cases, [+0x44] -> block whose [+0x18] is an object with slot 0x3c (1 arg); the key is one of the nodes' keys (3/4) or absent; 0x634273 cdecl recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4fd800(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x60)
    n = 0 if r.random() < 1 / 6 else r.choice([1, 2, 3, 4])
    nodes = [rnd(c, 0x20) for _ in range(n)]
    keys = [r.getrandbits(32) for _ in range(n)]
    for i, nd in enumerate(nodes):
        e.w32(nd, keys[i])
        e.w32(nd + 8, nodes[i - 1] if i else 0)
        e.w32(nd + 0xc, nodes[i + 1] if i + 1 < n else 0)
        e.w32(nd + 0x10, me)
    e.w32(me + 0x48, nodes[0] if n else 0)
    e.w32(me + 0x4c, nodes[-1] if n else 0)
    if n and r.random() < 0.5:
        e.w32(me + 0x50, r.choice(nodes))
    holder = rnd(c, 0x30)
    e.w32(holder + 0x18, obj(c, 0x20, {0x3c: pystub(c, 1, this=True)}, nslots=0x10))
    e.w32(me + 0x44, holder)
    key = r.choice(keys) if (n and r.random() < 0.75) else r.getrandbits(32)
    return [me, key]


S(0x4fd800, 'GUESS unlink node by key and free', 'thiscall', None, ret=None, gen=_g4fd800, note='batch35093')
