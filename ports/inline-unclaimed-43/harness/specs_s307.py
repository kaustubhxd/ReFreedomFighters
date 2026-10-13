"""specs_s307.py - unclaimed-43 batch 307: ZGROUP::GetStaticLights(ZBaseGeom **out, ZBaseGeom **end) (0x440c20),
thiscall with two stack arguments, ret 8, returns the cursor.
The list hangs off this+0x48. Nodes: flag byte at +8. A node with bit 0 set links to the next node at +0xc and holds
entries from +0x10; a node with bit 0 clear holds entries from +0xc and ends the walk. Entries are 8-byte pairs (value,
flags) up to node + (flag + 3) * 4; random tags in the low three bits of flags pick which pairs are copied. The walk
starts with an optional link node (flag 1), so the iterator setup (0x440ce0, original code) skips it. The output window
has 0..6 slots, with end <= out in a few cases (immediate return)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E


def _node(c, flag, nxt, entries_fill):
    n = E.zero_obj(c, 0x40)
    c.emu.wbytes(n + 8, bytes([flag]))
    if flag & 1:
        c.emu.w32(n + 0xc, nxt)
        start = n + 0x10
    else:
        start = n + 0xc
    marker = n + (flag + 3) * 4
    addr = start
    while addr + 8 <= marker:
        v, f = entries_fill()
        c.emu.w32(addr, v)
        c.emu.w32(addr + 4, f)
        addr += 8
    return n


def _gen(c):
    r = c.rng

    def entry():
        v = r.getrandbits(32)
        f = (r.getrandbits(29) << 3) | r.randrange(8)
        return v, f

    nd = r.randrange(1, 4)
    flags = []
    for i in range(nd):
        if i < nd - 1:
            flags.append(r.choice([3, 5, 7]))
        else:
            flags.append(r.choice([2, 3, 4, 5, 6, 7]))
    nxt = 0
    nodes = []
    for f in reversed(flags):
        nxt = _node(c, f, nxt if f & 1 else 0, entry)
        nodes.insert(0, nxt)
    head = nodes[0]
    x = r.random()
    if x < 0.1:
        head = _node(c, 0, 0, entry)             # empty walk: the iterator setup finds no entry node
    elif x < 0.45:
        head = _node(c, 1, nodes[0], entry)      # link node in front of the chain
    this = E.zero_obj(c, 0x100)
    c.emu.w32(this + 0x48, head)
    out = c.bytes_(8 * 8)
    y = r.random()
    if y < 0.05:
        end = out
    else:
        end = out + 8 * r.randrange(0, 7)
    c.emu.mu.ctl_flush_tb()
    return [this, out, end]


S(0x440c20, 'ZGROUP::GetStaticLights(ZBaseGeom**, ZBaseGeom**)', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-43 batch 307; iterator setup 0x440ce0 is original exe code')
