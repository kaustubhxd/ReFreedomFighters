"""specs_s1955.py - unclaimed-66 batch 65 (gap band, GUESS name). THISCALL(this), one stack argument (flags), ret 4; eax = this.

0x511950 (no arguments), 0x45c510 (cdecl, one argument) and 0x4690b0 (cdecl, two arguments) are recording GUESS stubs hooked by address.
0x512070 runs as exe code (its CRT free 0x634273 and base step 0x43ea20 are hooked by address, as in batch 38). The object is 0x400 random
bytes with a pointer at +0x5c and optional fake sub-objects at +0x127, +0x12b, +0x1ed (slot 0 logs)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slot0(name):
    def h(e, r):
        e.calllog.append((name, 0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    return h


def _gen(c):
    def h511(e, r):
        e.calllog.append(('0x511950 (GUESS stub)', 0x511950, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x511950, h511)

    def hfree(e, r):
        e.calllog.append(('CRT free 0x634273 (hook)', 0x634273, None, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x634273, hfree)

    def hbase(e, r):
        e.calllog.append(('base step 0x43ea20 (GUESS stub)', 0x43ea20, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x43ea20, hbase)

    def h45c(e, r):
        e.calllog.append(('0x45c510 (GUESS stub)', 0x45c510, None, (e.arg32(0),)))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x45c510, h45c)

    def h469(e, r):
        e.calllog.append(('0x4690b0 (GUESS stub)', 0x4690b0, None, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x4690b0, h469)

    self = _rnd(c, 0x400)
    c.emu.w32(self + 0x5c, _rnd(c, 0x20))
    for off in (0x127, 0x12b, 0x1ed):
        if c.rng.random() < 0.3:
            c.emu.w32(self + off, 0)
        else:
            vt = c.emu.fake_vtable('flag obj %x' % off, 4, slots={0: _slot0('flag obj %x slot0 (stub)' % off)})
            c.emu.w32(self + off, c.emu.fake_object('flag obj %x' % off, 0x40, vtable=vt))
    flags = c.rng.getrandbits(32)
    return [self, flags]


S(0x51f4e0, 'GUESS FUN_0051f4e0 (flagged variant of 0x51f4c0; 0x45c510 or 0x4690b0 when flags are set)', 'thiscall', None, ret='eax',
  gen=_gen, note='unclaimed-66 batch 1955; gap band; helpers GUESS stubs by address; 0x512070 exe bound')
