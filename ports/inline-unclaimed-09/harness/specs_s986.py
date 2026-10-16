"""specs_s986.py - area 56 band, claim A52 (0x5348e0): one helper call, two virtual calls, a list walk; void.

this is a 0x400-byte object of random bytes. The list entries sit at this + (k+1)*8 for index k: each entry is (value, next). b is a
random index in 1 to 3; the chain runs forward from b for 1 to 3 nodes and ends with next = 0x80000000. o is a 0x40-byte object whose
vtable slots 0x44 and 0x3c are GUESS recording stubs (thiscall, one argument, callee cleans). 0x534100 is hooked (GUESS; thiscall, one
argument; returns a random dword, plain ret with argbytes=4). ret=None (void)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h534(e2, r):
        e2.calllog.append(('H534100', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(eax=rng.getrandbits(32), argbytes=4)

    def h44(e2, r):
        e2.calllog.append(('V44', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    def h3c(e2, r):
        e2.calllog.append(('V3c', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    e.hook(0x534100, h534)
    vt = e.fake_vtable('vt5348e0', 0x80, {0x44: h44, 0x3c: h3c})
    o = e.alloc(0x40, 4)
    e.wbytes(o, bytes(rng.getrandbits(8) for _ in range(0x40)))
    e.w32(o, vt)
    this = e.alloc(0x400, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x400)))
    b = rng.randint(1, 3)
    nodes = rng.randint(1, 3)
    for k in range(nodes):
        idx = b + k
        nxt = (b + k + 1) if k + 1 < nodes else 0x80000000
        e.w32(this + (idx + 1) * 8, rng.getrandbits(32))
        e.w32(this + (idx + 1) * 8 + 4, nxt)
    return [this, o, b]


S(0x5348e0, 'unnamed 0x5348e0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A52; 0x534100 hooked (GUESS); vt slots 0x44/0x3c are GUESS recording stubs')
