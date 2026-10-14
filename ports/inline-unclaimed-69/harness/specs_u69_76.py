"""specs_u69_76.py - area 69, group 76 (slice 8): 0x444b00, a walk over a chain of nodes (no cycles: each node links to a later one). The helper 0x440ce0 is real code.
Nodes are 0x20 bytes: a flag byte at +8 (0..7, so both the bit-0 and the >= 2 branches occur), the next link at +0xc, and two random dwords at +0 and +4."""
from pilot import S
from ckit import rnd


def _walk(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x100)
    K = r.randrange(0, 5)
    nodes = [rnd(c, 0x20) for _ in range(K)]
    for i, n in enumerate(nodes):
        e.w32(n + 0xc, nodes[i + 1] if i + 1 < K else 0)
        e.wbytes(n + 8, bytes([r.randrange(0, 8)]))
        e.w32(n, r.getrandbits(32))
        e.w32(n + 4, r.getrandbits(32))
    e.w32(self_ + 0xb4, nodes[0] if nodes else 0)
    out = rnd(c, 0x40)
    limit = out + 8 * r.randrange(0, 7)
    return [self_, out, limit]


S(0x444b00, 'walk444b00 (thiscall, two stack args, ret 8, returns the out pointer)', 'thiscall', None, ret='eax', gen=_walk,
  note='u69 group 76; helper 0x440ce0 is real code (pure)')
