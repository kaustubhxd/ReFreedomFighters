"""specs_s1974.py - slice-5 batches 106 and 107 (GUESS names).
0x4bb310: the argument object has logging vtable slots 0x3c, 0x40 and 0x4c (one argument each, ret 4). 0x56df10: this's vtable +0xd0 (one
argument, ret 4) logs; 0x562b50 (THISCALL, one argument, ret 4) is a stub by address. [this+0x94] points at a random block."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_4bb310(c):
    def mk(slot, name):
        def h(e, r):
            e.calllog.append((name, slot, e.reg('ecx'), (e.arg32(0),)))
            e.ret(eax=0, argbytes=4)
        return h
    vt = c.emu.fake_vtable('batch106 a', 0x4c // 4 + 1, slots={0x3c: mk(0x3c, 'a vtable +0x3c'),
                                                                0x40: mk(0x40, 'a vtable +0x40'),
                                                                0x4c: mk(0x4c, 'a vtable +0x4c')})
    a = c.emu.fake_object('batch106 a', 0x40, vtable=vt)
    self = _rnd(c, 0x100)
    return [self, a]


def _gen_56df10(c):
    def h562(e, r):
        e.calllog.append(('0x562b50 (GUESS stub)', 0x562b50, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x562b50, h562)

    def hd0(e, r):
        e.calllog.append(('this vtable +0xd0 (stub)', 0xd0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    vt = c.emu.fake_vtable('batch107 self', 0xd0 // 4 + 1, slots={0xd0: hd0})
    self = _rnd(c, 0x400)
    c.emu.w32(self, vt)
    c.emu.w8(self + 0x85, c.rng.choice([0, 0, 1]))
    c.emu.w32(self + 0x94, _rnd(c, 0x80))
    return [self, c.rng.choice([0, 1, 2, 7])]


S(0x4bb310, 'GUESS FUN_004bb310 (clear bit 6; vtable +0x3c, +0x40, +0x4c on the argument; returns 1)', 'thiscall', None, ret='al',
  gen=_gen_4bb310, note='slice-5 batch 1974 (106)')
S(0x56df10, 'GUESS FUN_0056df10 (guarded: 0x562b50 for x == 0, vtable +0xd0 for x == 1; returns 0)', 'thiscall', None, ret='al',
  gen=_gen_56df10, note='slice-5 batch 1974 (107); 0x562b50 GUESS stub')
