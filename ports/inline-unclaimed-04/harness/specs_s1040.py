"""specs_s1040.py - unclaimed-04 batch 40 (docs/20-unclaimed-04.md): 0x5ffb70 (thiscall, one 16-bit key, ret 4).
A tree of 0x20-byte nodes: key word at +0xd, children dwords at +9 (taken when the node key is below the search key) and +5
(taken otherwise), value dword at +0xf. The root is this+0x118; its +1 dword is the first node. Children only point forward
(so the walk ends). The key argument carries random high bits (only the low word is compared)."""
from pilot import S


def _args(c):
    o = c.emu.alloc(0x200, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    root = c.emu.alloc(0x20, 4)
    c.emu.wbytes(root, bytes(0x20))
    n = c.rng.randrange(0, 6)
    nodes = [c.emu.alloc(0x20, 4) for _ in range(n)]
    for i, nd in enumerate(nodes):
        c.emu.wbytes(nd, bytes(0x20))
        c.emu.w32(nd + 0xd - 1, 0)  # keep the layout clear of unrelated bytes
        c.emu.wbytes(nd + 0xd, bytes([c.rng.randrange(0, 8), c.rng.randrange(0, 2)]))
        c.emu.w32(nd + 0xf, c.rng.getrandbits(32))
        later = nodes[i + 1:]
        c.emu.w32(nd + 5, c.rng.choice(later + [0]) if later else 0)
        c.emu.w32(nd + 9, c.rng.choice(later + [0]) if later else 0)
    c.emu.w32(root + 1, nodes[0] if nodes else 0)
    c.emu.w32(o + 0x118, root)
    key = c.rng.randrange(0, 9) | (c.rng.getrandbits(16) << 16)
    return [o, key]


S(0x5ffb70, 'unknown::tree_find_word_key (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args,
  note='unclaimed-04 batch 40; pure tree search (no calls)')
