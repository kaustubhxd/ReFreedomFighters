"""specs_s981.py - unclaimed-80 residue-19 batch 59 (docs/20-unclaimed-80.md), see src/batch981.cpp. self points to a head node; head +1 is the root
(null about 10%). Nodes are 0x15-byte packed blocks: left +5, right +9, key begin +0xd, key end +0x11. The tree has 1..12 nodes with a random shape
(the walk does not need a valid order). Keys are 0..11 bytes from a small alphabet (with some bytes >= 0x80 for the unsigned order), and the search key
is a copy of a node key (about 40%), a prefix or extension of one, or random, so ties, prefix ties and dword and byte-tail mismatches all occur. out
is a zeroed dword."""
from pilot import S

ALPHA = b'ab\x00\x7f\x80\xff'


def _gen(c):
    r = c.rng

    def rkey():
        return bytes(r.choice(ALPHA) for _ in range(r.randint(0, 11)))

    def kblock(k):
        a = c.emu.alloc(len(k) + 4, 1)
        c.emu.wbytes(a, k + b'\xcc' * 4)
        return a

    head = c.emu.alloc(0x15, 1)
    c.emu.wbytes(head, bytes(0x15))
    keys = []
    if r.random() >= 0.1:
        nodes = []
        for i in range(r.randint(1, 12)):
            k = rkey()
            keys.append(k)
            nd = c.emu.alloc(0x15, 1)
            c.emu.wbytes(nd, bytes(0x15))
            kb = kblock(k)
            c.emu.w32(nd + 0xd, kb)
            c.emu.w32(nd + 0x11, kb + len(k))
            if nodes:
                while True:
                    par = r.choice(nodes)
                    off = r.choice((5, 9))
                    if int.from_bytes(c.emu.rbytes(par + off, 4), 'little') == 0:
                        c.emu.w32(par + off, nd)
                        break
            nodes.append(nd)
        c.emu.w32(head + 1, nodes[0])
    u = r.random()
    if keys and u < 0.4:
        k = r.choice(keys)
    elif keys and u < 0.7:
        k = r.choice(keys)
        k = k[:r.randint(0, len(k))] if r.random() < 0.5 else k + rkey()[:3]
    else:
        k = rkey()
    kb = kblock(k)
    kr = c.emu.alloc(8, 4)
    c.emu.w32(kr, kb)
    c.emu.w32(kr + 4, kb + len(k))
    selfp = c.emu.alloc(4, 4)
    c.emu.w32(selfp, head)
    out = c.emu.alloc(4, 4)
    c.emu.w32(out, 0)
    return [selfp, out, kr]


S(0x431330, 'packed map upper-bound search by byte-range key (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-80 residue-19; two stack arguments, ret 8; returns out')
