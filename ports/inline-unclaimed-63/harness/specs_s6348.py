"""specs_s6348.py - unclaimed-63 gap-band batch 48: 0x4d3840 (C-set; thiscall, one stack argument X, ret 4).
Fakes per case (the image is restored between runs):
  * the object O at this+0x4008: slot +0x4c (thiscall, one argument, ret 4) resets a ring; slot +0x5c (thiscall, one argument, ret 4)
    writes 1 or 0 through its argument (the loop flag L) and returns the next node of a ring of 0 to 3 nodes;
  * a node is a 0x10-byte heap block: +0 and +8 are random (their sum plus 0xc is the first write), +4 is a random dword (its index is
    (value - 0x6e7a30) / 20, signed, so negative and positive indices both occur);
  * X is a stream object whose slot +0x10 (thiscall, two arguments, ret 8) records ECX, its first argument's contents and its second
    argument, and whose slot +0x3c (thiscall, one argument, ret 4) records ECX and its argument.
The first argument of slot +0x10 is a stack address in the first write (its contents are recorded, not the address)."""
from pilot import S


def _gen_3840(c):
    e = c.emu
    self_ = e.alloc(0x4100, 4)
    e.wbytes(self_, bytes(0x4100))
    nodes = []
    for _ in range(c.rng.randint(0, 3)):
        nd = e.alloc(0x10, 4)
        e.w32(nd, c.rng.getrandbits(32))
        e.w32(nd + 4, c.rng.choice([0x6e7a30 + 20 * c.rng.randint(-3, 40), c.rng.getrandbits(32)]))
        e.w32(nd + 8, c.rng.randint(0, 0x400))
        nodes.append(nd)
    pos = [0]
    O = self_ + 0x4008

    def slot4c(em, a):
        em.calllog.append(('O.reset', 0x4c, em.reg('ecx'), ()))
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
    e.w32(O, e.fake_vtable('O', 0x200 // 4, {0x4c: slot4c, 0x5c: slot5c}))

    def slot10(em, a):
        em.calllog.append(('X.write', 0x10, em.reg('ecx'), (em.r32(em.arg32(0)), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def slot3c(em, a):
        em.calllog.append(('X.index', 0x3c, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    X = e.alloc(0x40, 4)
    e.wbytes(X, bytes(0x40))
    e.w32(X, e.fake_vtable('X', 0x200 // 4, {0x10: slot10, 0x3c: slot3c}))
    e.mu.ctl_flush_tb()
    return [self_, X]


S(0x4d3840, 'unnamed C-set 0x4d3840 thiscall', 'thiscall', None, ret=None, gen=_gen_3840,
  note='unclaimed-63 band batch 48')
