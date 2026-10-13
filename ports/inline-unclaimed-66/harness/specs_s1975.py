"""specs_s1975.py - slice-5 batch 108 (GUESS name). THISCALL(this, a, b, c), ret 0xc.

0x5fb550 (THISCALL, one argument, ret 4; returns al) is a GUESS stub by address: it logs ECX and the argument and returns a random flag per case.
The object a has logging vtable slots 0x24 and 0x28 (no arguments) returning fixed values. b and c are 4-byte output cells."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    rflag = c.rng.choice([0, 1])
    rv24 = c.rng.getrandbits(32)
    rv28 = c.rng.getrandbits(32)

    def h5fb(e, r):
        e.calllog.append(('0x5fb550 (GUESS stub)', 0x5fb550, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=rflag, argbytes=4)
    c.emu.hook(0x5fb550, h5fb)

    def h24(e, r):
        e.calllog.append(('a vtable +0x24 (stub)', 0x24, e.reg('ecx'), ()))
        e.ret(eax=rv24, argbytes=0)

    def h28(e, r):
        e.calllog.append(('a vtable +0x28 (stub)', 0x28, e.reg('ecx'), ()))
        e.ret(eax=rv28, argbytes=0)
    vt = c.emu.fake_vtable('batch108 a', 0x28 // 4 + 1, slots={0x24: h24, 0x28: h28})
    a = c.emu.fake_object('batch108 a', 0x40, vtable=vt)
    cc = _rnd(c, 0x40)
    c.emu.w32(cc + 4, _rnd(c, 0x40))
    self = _rnd(c, 0x40)
    c.emu.w32(self + 0xc, cc)
    b = _rnd(c, 4)
    cell = _rnd(c, 4)
    return [self, a, b, cell]


S(0x5f1bd0, 'GUESS FUN_005f1bd0 (out cells; 0x5fb550 flag; vtable +0x24 and +0x28 of the argument)', 'thiscall', None, ret=None,
  gen=_gen, note='slice-5 batch 1975 (108); 0x5fb550 GUESS stub')
