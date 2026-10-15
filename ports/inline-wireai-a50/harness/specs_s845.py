"""specs_s845.py - area 50, batch 845: ZInputAction::AddNode. The node allocator (0x4382e0) is hooked (returns fresh
memory, logged); the sub-object virtual is logged; the head is a tag-3 node whose owner is known."""
import struct
from pilot import S
from anim_common import only_hooks, rnd, vt_object, vslot


def _gen(c):
    e, r = c.emu, c.rng
    alloc_log = []

    def newnode(e, res):
        a = e.reg('ecx')
        n = rnd(c, 0x20)
        e.wbytes(n, bytes(r.getrandbits(8) for _ in range(0x20)))
        e.calllog.append(('node.new', a))
        e.ret(eax=n, argbytes=0)

    only_hooks(c, {0x4382e0: newnode})
    owner = rnd(c, 0x40)
    head = owner + 4
    e.w32(head, 3)
    obj = rnd(c, 0x2000)
    e.w32(owner + 0x11, obj)
    e.w32(obj + 0x1210, r.randint(0, 12))
    tbl = rnd(c, 0x10 * 10 + 0x20)
    for i in range(10 * 10):
        e.wbytes(tbl + 10 * i, bytes(r.getrandbits(8) for _ in range(10)))
    e.w32(obj + 0x1344, tbl)
    sub = vt_object(c, 0x20, {4: vslot('sub.4', 1)}, nslots=0x10, name='sub')
    self = vt_object(c, 0x200, {}, nslots=0x10, name='inputaction')
    e.w32(self + 0xc, head)
    e.w32(self + 0x15, sub)
    e.w32(self + 0x42, r.getrandbits(32))
    e.w32(self + 0x19, r.getrandbits(32))
    e.w8(self + 0x32, r.getrandbits(8))
    # index is a table slot (0..12). Negative or huge indices read far outside the table (stale memory between cases);
    # the game only passes slots, so those are not generated.
    index = r.randint(0, 12)
    on = r.choice([0, 1, 0x100])
    return [self, index, on]


S(0x4377e0, 'ZInputAction::AddNode', 'thiscall', None, gen=_gen, note='area50 batch845')
