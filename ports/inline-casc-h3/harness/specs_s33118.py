"""specs_s33118.py - h3 (Sonnet) batch 33118: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g4fdb70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.randrange(1, 7)
    lst = rnd(c, 0x60)
    nodes = [rnd(c, 0x20) for _ in range(n)]
    mode = r.random()
    if mode < 0.3:
        keys = sorted(r.choice([0.0, 1.0, 2.0, 3.0, 5.0, -1.0]) for _ in range(n))
    elif mode < 0.4:
        keys = [r.choice([0.0, 1.0]) for _ in range(n)]
    else:
        keys = [r.choice([0.0, 1.0, 2.0, 3.0, 4.0, 5.0, -1.0, 2.5]) for _ in range(n)]
    special = None
    if n >= 3 and r.random() < 0.3:
        special = r.randrange(0, n - 1)
        keys = [r.choice([-2.0, -1.0, 0.0, 1.0]) for _ in range(n)]
        keys[special] = 2.0
        keys[special + 1] = 3.0
        keys[-1] = -5.0 if special + 1 != n - 1 else 3.0
    for i, nd in enumerate(nodes):
        e.w32(nd + 4, _b(keys[i]))
        e.w32(nd + 8, nodes[i - 1] if i > 0 else 0)
        e.w32(nd + 0xc, nodes[i + 1] if i + 1 < n else 0)
        e.w32(nd + 0x10, lst)
    e.w32(lst + 0x48, nodes[0])
    e.w32(lst + 0x4c, nodes[-1])
    e.w32(lst + 0x50, r.choice(nodes + [0]))
    pick = nodes[r.randrange(n)] if special is None else nodes[special]
    if special is None and r.random() < 0.5:
        # perturb the picked node's key so that it is out of order
        e.w32(pick + 4, _b(r.choice([-3.0, 0.0, 1.0, 2.0, 4.0, 6.0, 10.0])))
    return [pick]


S(0x4fdb70, 'GUESS re-sort node in doubly linked list by key', 'thiscall', None, ret=None, gen=_g4fdb70, note='batch33118')
