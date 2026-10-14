"""specs_s1689.py - residue 13 batch 1689: 0x476970. The allocator 0x41e290 (cdecl, one argument, recorded) returns two random
blocks in order; the manager's slot 0x58 returns the object (its +0x50 is a node list of 1..3 nodes, each with a value block at
+0x54 and the next node at +0x60); manager slot 0x4c (one argument, random eax) and the self vslot 0x28 are recorders."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED, sysobj


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    blocks = [rnd(c, 0x20), rnd(c, 0x20)]
    rec = c.emu.alloc(8, 4)
    cnt = c.emu.alloc(4, 4)

    def h(e, rr):
        i = e.r32(cnt)
        e.w32(cnt, i + 1)
        e.w32(rec + 4 * (i % 2), e.r32(e.reg('esp') + 4))
        e.ret(eax=blocks[i % 2], argbytes=0)
    HOOKED.add(0x41e290)
    c.emu.hook(0x41e290, h)
    k = r.randint(1, 3)
    nodes = [rnd(c, 0x80) for _ in range(k)]
    for i, nd in enumerate(nodes):
        val = rnd(c, 0x80)
        c.emu.w32(nd + 0x54, val)
        c.emu.w32(nd + 0x60, nodes[i + 1] if i + 1 < k else 0)
    o = rnd(c, 0x80)
    c.emu.w32(o + 0x50, nodes[0])
    mgr = obj(c, 0x100, {0x58: stub(c, seq, 1, ret=o if r.random() < 0.85 else 0),
                         0x4c: stub(c, seq, 1, ret=r.getrandbits(32))})
    sysobj(c, db=mgr)
    me = obj(c, 0x100, {0x28: stub(c, seq, 0, ret=r.getrandbits(32))})
    c.emu.w32(me + 0x5c, r.choice([0, 1, 2, 3]))
    c.emu.w8(me + 0x72, r.choice([0, 0, 0, 1]))
    c.emu.w32(me + 0x73, r.getrandbits(32))
    return [me]


S(0x476970, 'GUESS FUN_476970', 'thiscall', None, ret='eax', gen=_gen, note='batch1689; two saturating allocations; manager slots')
