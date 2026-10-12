"""specs_s1944.py - unclaimed-66 batch 45 (gap band, GUESS name). THISCALL(this), one stack argument, ret 4.

0x5003d0 (ret 4, one argument: the index; ECX = the holder) and 0x5002f0 (ret 4, one argument, ECX = p) are recording GUESS stubs hooked by address.
Their fixed results are chosen in gen. [this+0xc], when set, is a child whose +0x18 object has a logging vtable with slot 0x14."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gap(c):
    rv14 = c.rng.getrandbits(32)

    def h14(e, r):
        e.calllog.append(('child+0x18 vtable +0x14 (stub)', 0x14, e.reg('ecx'), ()))
        e.ret(eax=rv14, argbytes=0)
    vt_t = c.emu.fake_vtable('batch45 t', 0x14 // 4 + 1, slots={0x14: h14})
    t = _rnd(c, 0x40)
    c.emu.w32(t, vt_t)

    child = _rnd(c, 0x40)
    c.emu.w32(child + 0x18, t)
    self = _rnd(c, 0x40)
    k = c.rng.random()
    c.emu.w32(self + 0xc, 0 if k < 0.3 else child)

    holder = _rnd(c, 0x40)
    x = _rnd(c, 0x40)
    c.emu.w32(x + 8, holder)
    p = _rnd(c, 0x40)

    def h3d0(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=p, argbytes=4)
    c.emu.hook(0x5003d0, h3d0)

    def h2f0(e, r):
        e.calllog.append(('0x5002f0 (GUESS stub)', 0x5002f0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x5002f0, h2f0)
    return [self, x]


S(0x509840, 'GUESS FUN_00509840 (child vtable +0x14 when set; 0x5003d0 then 0x5002f0)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1944; gap band; 0x5003d0 and 0x5002f0 GUESS stubs by address')
