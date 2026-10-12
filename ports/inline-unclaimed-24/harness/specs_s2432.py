"""specs_s2432.py - decomp area 24, batch 2432.
0x43e570 ZHELPER::DispBox(int), thiscall, ret 4: when the low bits 1 and 2 of the dword at +0x18 are clear, bit 3 is set
(argument nonzero) or cleared (argument zero) and the dword is stored.
0x4d1c30 (unnamed), thiscall, ret 4: walk from the dword at +0x24 through the next pointers at +0x30; the node whose dword
at +0x20 equals the argument is returned, else 0.
0x632a70 inflate_trees_fixed (zlib name), cdecl, four pointer arguments: *a0 = global 0x6f55e0, *a1 = global 0x6f55e4,
*a2 = 0x6f44e0, *a3 = 0x6f54e0; returns 0. The four output buffers are random heap blocks."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _disp(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    e.w32(o + 0x18, r.getrandbits(32))
    return [o, r.choice([0, 1, r.randint(2, 50)])]


def _find(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    n = r.randint(0, 6)
    nodes = [rnd(c, 0x40) for _ in range(n)]
    keys = []
    for i, nd in enumerate(nodes):
        k = r.choice([r.randint(0, 5), r.getrandbits(32)])
        keys.append(k)
        e.w32(nd + 0x20, k)
        e.w32(nd + 0x30, nodes[i + 1] if i + 1 < n else 0)
    e.w32(o + 0x24, nodes[0] if nodes else 0)
    key = r.choice(keys) if keys and r.random() < 0.6 else r.randint(0, 5)
    return [o, key]


def _trees(c):
    clear_hooks(c)
    r = c.rng
    a = [rnd(c, 16) for _ in range(4)]
    return a


S(0x43e570, 'ZHELPER::DispBox', 'thiscall', None, ret=None, gen=_disp, note='batch2432')
S(0x4d1c30, 'GUESS: list lookup at +0x24 (0x4d1c30)', 'thiscall', None, ret='eax', gen=_find, note='batch2432')
S(0x632a70, 'inflate_trees_fixed', 'cdecl', None, ret='eax', gen=_trees, note='batch2432')
