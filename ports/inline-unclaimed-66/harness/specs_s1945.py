"""specs_s1945.py - unclaimed-66 batch 46 (gap band, GUESS name). THISCALL(this), one stack argument, ret 4.

0x5003d0 (ret 4, one argument: the index; ECX = the holder) and 0x5002f0 (ret 4, one argument, ECX = p2) are recording GUESS stubs hooked by address.
The stub for 0x5003d0 returns p1 or p2 by its ECX (the two holders differ). [this+0xc] is a child whose +0x18 object has a logging vtable with slot 0x30
(one argument, ret 4). The object under test is random; the stored value at p1 is random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gap(c):
    rv30 = c.rng.getrandbits(32)

    def h30(e, r):
        e.calllog.append(('child+0x18 vtable +0x30 (stub)', 0x30, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=rv30, argbytes=4)
    vt_t = c.emu.fake_vtable('batch46 t', 0x30 // 4 + 1, slots={0x30: h30})
    t = _rnd(c, 0x40)
    c.emu.w32(t, vt_t)

    child = _rnd(c, 0x40)
    c.emu.w32(child + 0x18, t)
    self = _rnd(c, 0x40)
    c.emu.w32(self + 0xc, child)

    h1 = _rnd(c, 0x40)
    h2 = _rnd(c, 0x40)
    x = _rnd(c, 0x40)
    c.emu.w32(x + 4, h1)
    c.emu.w32(x + 8, h2)
    p1 = _rnd(c, 0x40)
    p2 = _rnd(c, 0x40)

    def h3d0(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=p1 if e.reg('ecx') == h1 else p2, argbytes=4)
    c.emu.hook(0x5003d0, h3d0)

    def h2f0(e, r):
        e.calllog.append(('0x5002f0 (GUESS stub)', 0x5002f0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x5002f0, h2f0)
    return [self, x]


S(0x509870, 'GUESS FUN_00509870 (0x5003d0, vtable +0x30 of child, 0x5003d0, 0x5002f0)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1945; gap band; 0x5003d0 and 0x5002f0 GUESS stubs by address')
