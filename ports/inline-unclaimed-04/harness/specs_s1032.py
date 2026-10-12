"""specs_s1032.py - unclaimed-04 batch 32 (docs/20-unclaimed-04.md): 0x64a670 (thiscall, no arguments). A linked list headed
at this+0xc (next pointer at node+8) is drained: each node is passed to the item's vtable slot 0xc (a recording stub). Then
+8 and +0x10 are cleared. The spec gives an empty list, and lists of 1 to 3 nodes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _list(c):
    o = _rnd(c, 0x100)
    n = c.rng.choice([0, 1, 2, 3])

    def h_c(em, r):
        em.calllog.append(('item.c', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    item_vt = c.emu.fake_vtable('item', 0xc // 4 + 1, {0xc: h_c})
    item = c.emu.alloc(0x20, 4)
    c.emu.w32(item, item_vt)
    c.emu.w32(o + 4, item)
    nodes = [c.emu.alloc(0x20, 4) for _ in range(n)]
    for k, nd in enumerate(nodes):
        c.emu.w32(nd + 8, nodes[k + 1] if k + 1 < n else 0)
    c.emu.w32(o + 0xc, nodes[0] if n else 0)
    c.emu.w32(o + 8, c.rng.getrandbits(32))
    c.emu.w32(o + 0x10, c.rng.getrandbits(32))
    return [o]


S(0x64a670, 'unknown::drain_list_vt_c (unknown) thiscall', 'thiscall', None, ret=None, gen=_list,
  note='unclaimed-04 batch 32; item vtable slot 0xc is a recording stub (GUESS)')
