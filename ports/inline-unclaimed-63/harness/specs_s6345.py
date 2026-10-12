"""specs_s6345.py - unclaimed-63 gap-band batch 45: 0x4cee80 (C-set; thiscall, one stack argument X, ret 4).
Fakes per case (the image is restored between runs):
  * X is a two-dword header whose first dword is a node (never 0: the original faults on an empty list, and the spec does not
    test that). X[1] is 0, 1, -1 or random (the sign test's boundary included). Nodes are 0x20-byte heap blocks whose +0 and +4 links point to other nodes or are 0;
  * this+0x24 is a fake object (its vtable slot +4 records ECX and its argument, ret 4) in 2 cases out of 3, else 0, so the
    allocation path runs (0x41e290, a hook that returns a fresh zeroed 0x1c block);
  * the new block's vtable is 0x695734: the spec writes a recording stub into the image at 0x695734 + 4 (the exe's own slot, image
    restored between runs), so the call through it is the fake;
  * the logger 0x700390 is never reached (the head is always non-zero)."""
from pilot import S


def _gen_ee80(c):
    e = c.emu
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, bytes(0x40))
    X = e.alloc(8, 4)
    nodes = []
    for _ in range(c.rng.randint(1, 4)):
        nd = e.alloc(0x20, 4)
        e.wbytes(nd, bytes(0x20))
        nodes.append(nd)
    for nd in nodes:
        e.w32(nd, c.rng.choice(nodes + [0]))
        e.w32(nd + 4, c.rng.choice(nodes + [0]))
    e.w32(X, nodes[0])
    e.w32(X + 4, c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)]))
    if c.rng.random() < 2 / 3:
        vt = e.fake_vtable('obj', 0x200 // 4, {4: lambda em, a: (em.calllog.append(('obj.store', 4, em.reg('ecx'), (em.arg32(0),))),
                                                                  em.ret(eax=0, argbytes=4))})
        ob = e.alloc(0x40, 4)
        e.w32(ob, vt)
        e.w32(self_ + 0x24, ob)
    else:
        e.w32(self_ + 0x24, 0)
    e.w32(self_ + 0x1c, c.rng.getrandbits(32))
    e.w32(self_ + 0x20, c.rng.getrandbits(32))
    e.hook(0x41e290, lambda em, a: (em.calllog.append(('alloc.1c', None, None, (em.arg32(0),))),
                                    em.ret(eax=_zero_block(em, 0x1c), argbytes=0)))
    node_stub = e.stub_fn('node vt +4', lambda em, a: (em.calllog.append(('node.store', 4, em.reg('ecx'), (em.arg32(0),))),
                                                       em.ret(eax=0, argbytes=4)))
    e.w32(0x695734 + 4, node_stub)
    e.mu.ctl_flush_tb()
    return [self_, X]


def _zero_block(em, n):
    a = em.alloc(n, 4)
    em.wbytes(a, bytes(n))
    return a


S(0x4cee80, 'unnamed C-set 0x4cee80 thiscall', 'thiscall', None, ret=None, gen=_gen_ee80,
  note='unclaimed-63 band batch 45')
