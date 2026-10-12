"""specs_s6344.py - unclaimed-63 gap-band batch 44: 0x4d2f20 (C-set; thiscall, two stack arguments s and n, ret 8, returns a node or 0).
Fakes per case (the image is restored between runs):
  * the object at this+0x4008 has a fake vtable: slot +0x4c (thiscall, one argument, ret 4) resets a ring; slot +0x5c (thiscall,
    one argument, ret 4) writes 1 or 0 through its argument (the local flag) and returns the next node of a ring of 0 to 3 nodes;
  * a node is a 0x20-byte heap block whose first dword is a length (n in half the cases) and whose bytes from +0xc are random;
  * 0x67640c (the compare, cdecl, a global function pointer) is a fake that records its three arguments and returns 0 or 1;
  * s is a random NUL-terminated string (0 to 10 characters); n is 0 in a third of the cases (the strlen path), else 1 to 12.
The compare fake is a pointer, so the port and the original call the same stub with the same arguments."""
from pilot import S


def _gen_2f20(c):
    e = c.emu
    self_ = e.alloc(0x4100, 4)
    e.wbytes(self_, bytes(0x4100))
    s_len = c.rng.randint(0, 10)
    s = e.alloc(s_len + 4, 4)
    e.wbytes(s, bytes([c.rng.randint(1, 255) for _ in range(s_len)]) + b'\x00')
    if c.rng.random() < 1 / 3:
        n = 0
    else:
        n = c.rng.randint(1, 12)
    nodes = []
    for _ in range(c.rng.randint(0, 3)):
        nd = e.alloc(0x20, 4)
        e.wbytes(nd, bytes(0x20))
        e.w32(nd, n if (n and c.rng.random() < 0.5) else c.rng.randint(1, 12))
        e.wbytes(nd + 0xc, bytes(c.rng.getrandbits(8) for _ in range(0x14)))
        nodes.append(nd)
    pos = [0]

    def slot4c(em, a):
        em.calllog.append(('O.reset', 0x4c, em.reg('ecx'), (em.arg32(0),)))
        pos[0] = 0
        em.ret(eax=0, argbytes=4)

    def slot5c(em, a):
        em.calllog.append(('O.next', 0x5c, em.reg('ecx'), ()))
        if pos[0] < len(nodes):
            nd = nodes[pos[0]]
            pos[0] += 1
            em.w32(em.arg32(0), 1)
            em.ret(eax=nd, argbytes=4)
        else:
            em.w32(em.arg32(0), 0)
            em.ret(eax=0, argbytes=4)
    e.w32(self_ + 0x4008, e.fake_vtable('O', 0x200 // 4, {0x4c: slot4c, 0x5c: slot5c}))

    def cmp(em, a):
        em.calllog.append(('cmp.67640c', None, None, tuple(em.arg32(k) for k in range(3))))
        em.ret(eax=c.rng.choice([0, 0, 1]), argbytes=0)
    e.w32(0x67640c, e.stub_fn('cmp 0x67640c', cmp))
    e.mu.ctl_flush_tb()
    return [self_, s, n]


S(0x4d2f20, 'unnamed C-set 0x4d2f20 thiscall', 'thiscall', None, ret='eax', gen=_gen_2f20,
  note='unclaimed-63 band batch 44')
