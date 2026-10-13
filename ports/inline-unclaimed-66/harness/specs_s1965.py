"""specs_s1965.py - unclaimed-66 batch 83 (gap band, GUESS name). THISCALL(this), one stack argument, ret 4; returns eax.

0x5003d0 (ret 4, index argument; ECX = holder) is a GUESS stub by address; it returns p (random contents, zero half the time). The object at
[this+0x20] has a logging vtable whose +0x398 slot takes one argument (ret 4) and returns a fixed eax. Its +0xc child's +0x23 dword is either
0x100bc0 or random. [0x7003b0] is a stub function (the exe's pointer is always set)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    rv = c.rng.getrandbits(32)

    def h398(e, r):
        e.calllog.append(('a vtable +0x398 (stub)', 0x398, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=rv, argbytes=4)
    vt = c.emu.fake_vtable('batch83 a', 0x398 // 4 + 1, slots={0x398: h398})
    a = c.emu.fake_object('batch83 a', 0x40, vtable=vt)
    cc = _rnd(c, 0x40)
    c.emu.w32(cc + 0x23, 0x100bc0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    c.emu.w32(a + 0xc, cc)
    self = _rnd(c, 0x40)
    c.emu.w32(self + 0x20, a)

    def hfp(e, r):
        e.calllog.append(('0x7003b0 pointer target (stub)', 0, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.w32(0x7003b0, c.emu.stub_fn('batch83 fp', hfp))

    x = _rnd(c, 0x40)
    holder = _rnd(c, 0x40)
    c.emu.w32(x + 4, holder)
    p = 0 if c.rng.random() < 0.5 else _rnd(c, 0x40)
    pz = _rnd(c, 0x40)
    c.emu.w32(pz, 0)
    pv = _rnd(c, 0x40)

    def h3d0(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=pz if (p == 0) else pv, argbytes=4)
    c.emu.hook(0x5003d0, h3d0)
    return [self, x]


S(0x51fcc0, 'GUESS FUN_0051fcc0 (optional fn pointer; 0x5003d0 flag; tail vtable +0x398 of [this+0x20])', 'thiscall', None, ret='eax',
  gen=_gen, note='unclaimed-66 batch 1965; gap band; 0x5003d0 GUESS stub by address; 0x7003b0 stub')
