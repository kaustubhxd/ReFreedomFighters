"""specs_s38005.py - cascade s8 batch 38005: 0x4e81d0 (red-black insert fix-up). A random binary tree of 2..14 nodes (0x14 bytes: parent, left, right, +0xc key, +0x10
color) with a nil node (all links point to valid nodes, color black) and random colors (root black 85%); the node to insert is a leaf (or the root). 0x4e8160 hooked."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g4e81d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.randrange(1, 15)
    nodes = [rnd(c, 0x14) for _ in range(n)]
    nil = rnd(c, 0x14)
    par = {}
    left = {a: nil for a in nodes}
    right = {a: nil for a in nodes}
    par[nodes[0]] = nil
    for i in range(1, n):
        while True:
            j = nodes[r.randrange(i)]
            side = r.choice(['l', 'r'])
            if side == 'l' and left[j] == nil:
                left[j] = nodes[i]
                break
            if side == 'r' and right[j] == nil:
                right[j] = nodes[i]
                break
        par[nodes[i]] = j
    for a in nodes:
        e.w32(a, par[a])
        e.w32(a + 4, left[a])
        e.w32(a + 8, right[a])
        e.wbytes(a + 0x10, bytes([1 if r.random() < 0.55 else 0]))
    if r.random() < 0.85:
        e.wbytes(nodes[0] + 0x10, bytes([0]))
    e.w32(nil, r.choice(nodes + [nil]))
    e.w32(nil + 4, r.choice(nodes + [nil]))
    e.w32(nil + 8, r.choice(nodes + [nil]))
    e.wbytes(nil + 0x10, bytes([0]))
    leaves = [a for a in nodes if left[a] == nil and right[a] == nil]
    x = r.choice(leaves) if r.random() < 0.93 else r.choice(nodes)
    me = rnd(c, 0x20)
    e.w32(me + 4, nodes[0])
    e.w32(me + 8, nil)
    hook_rec(c, 0x4e8160, 1, this=True, pop=4)
    return [me, x]


S(0x4e81d0, 'GUESS red-black insert fix-up', 'thiscall', None, ret='eax', gen=_g4e81d0, note='batch38005')
