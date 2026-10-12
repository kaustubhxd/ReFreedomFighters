"""specs_s6333.py - unclaimed-63 gap-band batch 33: 0x4cf370 (C-set; thiscall, one pointer argument P, ret 4, returns a slot pointer or 0).
No stubs. The object holds a pointer to a list header (this+8, whose +8 dword is the end index) and two dwords (this+0x10, the
index to advance past; this+0x18, the base added on each step). P is a two-dword cursor (node, index) in the heap; the nodes are
0x40-byte heap cells whose +4 dword is the next node (or 0). P[1] is drawn from the two index values and random small values, so
both the advance branch and the end branch run. P[0] is always a real node, because the original reads node->next when the index
matches (a null node would fault in the original and in the port alike)."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_cf37(c):
    self_ = _rnd(c, 0x40)
    hdr = _rnd(c, 0x20)
    end_idx = c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])
    at_idx = c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])
    c.emu.w32(hdr + 8, end_idx)
    c.emu.w32(self_ + 8, hdr)
    c.emu.w32(self_ + 0x10, at_idx)
    c.emu.w32(self_ + 0x18, c.rng.getrandbits(32))
    nodes = [_rnd(c, 0x40) for _ in range(3)]
    for i, nd in enumerate(nodes):
        nxt = nodes[i + 1] if i + 1 < len(nodes) and c.rng.random() < 0.7 else 0
        if c.rng.random() < 0.3:
            nxt = 0
        c.emu.w32(nd + 4, nxt)
    P = c.emu.alloc(8, 4)
    c.emu.w32(P, c.rng.choice(nodes))
    idx = c.rng.choice([at_idx, end_idx, c.rng.getrandbits(32), 0, 1])
    c.emu.w32(P + 4, idx)
    return [self_, P]


S(0x4cf370, 'unnamed C-set 0x4cf370 thiscall', 'thiscall', None, ret='eax', gen=_gen_cf37,
  note='unclaimed-63 band batch 33')
