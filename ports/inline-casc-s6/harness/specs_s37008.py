"""specs_s37008.py - cascade s6 batch 37008: 0x430480 (red-black insert fix-up, fastcall(node, &root)). Random binary tree of packed 13-byte nodes
{colour, parent, left, right}, root black, other colours random; x is a random node."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g430480(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([1, 2, 3, 4, 5, 6, 8, 10, 14])
    nodes = [e.alloc(16, 1) for _ in range(n)]
    for a in nodes:
        e.wbytes(a, bytes(16))
    kids = {a: [0, 0] for a in nodes}
    par = {nodes[0]: 0}
    free = [(nodes[0], 0), (nodes[0], 1)]
    for a in nodes[1:]:
        k = r.randrange(len(free))
        p, side = free.pop(k)
        kids[p][side] = a
        par[a] = p
        free += [(a, 0), (a, 1)]
    for a in nodes:
        col = 1 if a == nodes[0] else r.choice([0, 0, 1])
        e.wbytes(a, bytes([col]) + par[a].to_bytes(4, 'little') + kids[a][0].to_bytes(4, 'little') + kids[a][1].to_bytes(4, 'little'))
    rootcell = e.alloc(4, 4)
    e.w32(rootcell, nodes[0])
    x = nodes[0] if r.random() < 0.05 else r.choice(nodes)
    return [x, rootcell]


S(0x430480, 'GUESS red-black insert fixup', 'fastcall', None, ret='eax', gen=_g430480, note='batch37008')
