"""specs_s1956.py - unclaimed-66 batch 66 (gap band, GUESS name). THISCALL(this), one unread stack argument, ret 4.

All three callees are slots of the object at [this+0x18] (a logging vtable): +0x57c (two pointer arguments, ret 8) writes random contents to
the 9-dword A and the 3-dword B; +0x5f0 (no arguments) returns a fixed V; +0x370 (two arguments, ret 8) logs the contents of A and its second
argument V. The stubs log contents rather than stack addresses, which differ between the original and the port frames."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    a_bytes = bytes(c.rng.getrandbits(8) for _ in range(36))
    b_bytes = bytes(c.rng.getrandbits(8) for _ in range(12))
    V = c.rng.getrandbits(32)

    def h57c(e, r):
        pa, pb = e.arg32(0), e.arg32(1)
        e.calllog.append(('obj vtable +0x57c (stub)', 0x57c, e.reg('ecx'), ()))
        e.wbytes(pa, a_bytes)
        e.wbytes(pb, b_bytes)
        e.ret(eax=0, argbytes=8)

    def h5f0(e, r):
        e.calllog.append(('obj vtable +0x5f0 (stub)', 0x5f0, e.reg('ecx'), ()))
        e.ret(eax=V, argbytes=0)

    def h370(e, r):
        pa, val = e.arg32(0), e.arg32(1)
        contents = tuple(e.r32(pa + 4 * i) for i in range(9))
        e.calllog.append(('obj vtable +0x370 (stub)', 0x370, e.reg('ecx'), (contents, val)))
        e.ret(eax=0, argbytes=8)

    vt = c.emu.fake_vtable('batch66 obj', 0x5f0 // 4 + 1, slots={0x57c: h57c, 0x5f0: h5f0, 0x370: h370})
    obj = c.emu.fake_object('batch66 obj', 0x40, vtable=vt)
    self = _rnd(c, 0x40)
    c.emu.w32(self + 0x18, obj)
    unused = c.rng.getrandbits(32)
    return [self, unused]


S(0x5064a0, 'GUESS FUN_005064a0 (vtable +0x57c, +0x5f0, +0x370 of [this+0x18])', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-66 batch 1956; gap band; stubs log the locals A and B by content')
