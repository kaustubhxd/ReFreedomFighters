"""specs_s6350.py - unclaimed-63 gap-band batch 50: 0x4ceb60 (C-set; thiscall, no stack arguments, plain ret).
Fakes per case (the image is restored between runs; hooks are set in gen):
  * 0x41e290 (cdecl allocator, another area's claim): a hook that returns a zeroed 0x100-byte heap block;
    0x41e2c0 (cdecl free): a hook that records its argument;
  * 0x6762d0 (cdecl formatter, a global function pointer): a fake that writes the decimal text of its first argument at its second
    argument (with a NUL) and returns the second argument; the spec's values are random 32-bit numbers (the formatter is a stub, so
    the text is only what the stub writes);
  * the list at this+4: 0 to 2 nodes, each 0x40 bytes: +4 links the next node, +8 is an item count 0 to 3, and the values are at
    node+0x10 with a stride of this+0x18 (0 to 3) dwords;
  * logger 0x700390 as in the other specs: slot +0x20 (file, line) returns the log object, whose slot +0x2c is a cdecl printf-like."""
from pilot import S
import struct


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_b60(c):
    e = c.emu
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, bytes(0x40))
    e.w32(self_ + 0x18, c.rng.randint(0, 3))
    nodes = []
    for _ in range(c.rng.randint(0, 2)):
        nd = e.alloc(0x40, 4)
        e.wbytes(nd, bytes(0x40))
        cnt = c.rng.randint(0, 3)
        e.w32(nd + 8, cnt)
        for i in range(cnt):
            e.w32(nd + 0x10 + 4 * i * 1, c.rng.getrandbits(32))
        nodes.append(nd)
    for i, nd in enumerate(nodes):
        e.w32(nd + 4, nodes[i + 1] if i + 1 < len(nodes) else 0)
    e.w32(self_ + 4, nodes[0] if nodes else 0)

    def alloc_hook(em, a):
        em.calllog.append(('alloc.100', None, None, (em.arg32(0),)))
        p = em.alloc(0x100, 4)
        em.wbytes(p, bytes(0x100))
        em.ret(eax=p, argbytes=0)

    def free_hook(em, a):
        em.calllog.append(('free', None, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x41e290, alloc_hook)
    e.hook(0x41e2c0, free_hook)

    def fmt(em, a):
        v, buf = em.arg32(0), em.arg32(1)
        em.calllog.append(('fmt.6762d0', None, None, (v, em.arg32(2))))
        em.wbytes(buf, str(v).encode() + b'\x00')
        em.ret(eax=buf, argbytes=0)
    e.w32(0x6762d0, e.stub_fn('fmt 0x6762d0', fmt))

    def printf(em, r):
        # the first call pushes three arguments and the second four: record only the ones the caller pushed
        nargs = 3 if em.arg32(1) == 0x695bfc else 4
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=0, argbytes=0)
    logobj = _rnd(c, 16)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    e.mu.ctl_flush_tb()
    return [self_]


S(0x4ceb60, 'unnamed C-set 0x4ceb60 thiscall', 'thiscall', None, ret=None, gen=_gen_b60,
  note='unclaimed-63 band batch 50; 0x41e290/0x41e2c0 hooked (area 20)')
