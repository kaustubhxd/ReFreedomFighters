"""specs_s38091.py - cascade s8 batch 38091. thiscall(node) ret 4. A random binary tree (0..9 nodes, random shape, random colours with bias towards the cases of the red-black erase fix-up) of 0x20-byte nodes {+0 parent, +4 left,
+8 right, +0x10 colour}; the header (this) holds root +4 and the nil node +8 (nil is black and points to itself, root's parent = nil). The node argument is any tree node or the nil node itself (parent link set to a real node, as
after an erase). The function is pure memory manipulation, so the comparison is the heap image."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks


def _g4e8450(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t = rnd(c, 0x20)
    nil = rnd(c, 0x20)
    e.w32(nil, nil)
    e.w32(nil + 4, nil)
    e.w32(nil + 8, nil)
    e.wbytes(nil + 0x10, b'\0')
    nodes = []

    def build(k, parent):
        if k == 0:
            return nil
        nl = r.randrange(k)
        n = rnd(c, 0x20)
        nodes.append(n)
        e.w32(n, parent)
        e.wbytes(n + 0x10, bytes([r.choice([0, 1, 1, 0, 0])]))
        left = build(nl, n)
        right = build(k - 1 - nl, n)
        e.w32(n + 4, left)
        e.w32(n + 8, right)
        return n
    root = build(r.choice([0, 1, 2, 3, 4, 5, 6, 8, 9]), nil)
    if root == nil:
        e.w32(t + 4, nil)
    else:
        e.w32(t + 4, root)
    e.w32(t + 8, nil)
    if nodes and r.random() < 0.85:
        x = r.choice(nodes)
    elif nodes:
        x = nil
        p = r.choice(nodes)
        e.w32(nil, p)   # temporary parent link of the nil sentinel
        # nil as a child of p already (its absent child); if p has no nil child fall back to the node itself
        if e.r32(p + 4) != nil and e.r32(p + 8) != nil:
            x = p
    else:
        x = root
        if x == nil:
            x = nil
    return [t, x]


S(0x4e8450, 'GUESS rb-tree erase fixup', 'thiscall', None, ret=None, gen=_g4e8450, note='batch38091')
