"""specs_s1969.py - slice-5 batches 92 to 94 (GUESS names). Callees are GUESS stubs by address: 0x6352f0 (STDCALL, one argument: writes a
random word to its argument), 0x548f40 (THISCALL, one argument, callee cleans), and vtable slots (one argument, callee cleans) on the objects."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_4b5910(c):
    w = c.rng.getrandbits(32)

    def h6352(e, r):
        pa = e.arg32(0)
        e.calllog.append(('0x6352f0 (GUESS stub)', 0x6352f0, None, (e.r32(pa),)))
        e.wbytes(pa, w.to_bytes(4, 'little'))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x6352f0, h6352)

    def h98(e, r):
        e.calllog.append(('this vtable +0x98 (stub)', 0x98, e.reg('ecx'), (e.r32(e.arg32(0)),)))
        e.ret(eax=0, argbytes=4)
    vt = c.emu.fake_vtable('batch92 self', 0x98 // 4 + 1, slots={0x98: h98})
    self = _rnd(c, 0x100)
    c.emu.w32(self, vt)
    return [self]


def _gen_4cbc10(c):
    def h40(e, r):
        e.calllog.append(('a vtable +0x40 (stub)', 0x40, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    vt = c.emu.fake_vtable('batch93 a', 0x40 // 4 + 1, slots={0x40: h40})
    a = c.emu.fake_object('batch93 a', 0x40, vtable=vt)
    self = _rnd(c, 0x100)
    return [self, a]


def _gen_548e90(c):
    def h548(e, r):
        e.calllog.append(('0x548f40 (GUESS stub)', 0x548f40, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x548f40, h548)
    self = _rnd(c, 0x100)
    a48 = c.rng.getrandbits(16)
    a4a = c.rng.getrandbits(16)
    c.emu.w8(self + 0x48, a48 & 0xff)
    c.emu.w8(self + 0x49, a48 >> 8)
    c.emu.w8(self + 0x4a, a4a & 0xff)
    c.emu.w8(self + 0x4b, a4a >> 8)
    k = c.rng.random()
    w = a48 if k < 0.4 else (a4a if k < 0.7 else c.rng.getrandbits(16))
    p = _rnd(c, 0x20)
    return [self, w | (c.rng.getrandbits(16) << 16 if c.rng.random() < 0.5 else 0), p]


S(0x4b5910, 'GUESS FUN_004b5910 (0x6352f0 into a local, vtable +0x98 with its address)', 'thiscall', None, ret=None, gen=_gen_4b5910,
  note='slice-5 batch 1969 (92); 0x6352f0 GUESS stub')
S(0x4cbc10, 'GUESS FUN_004cbc10 (clear bit 6; two vtable +0x40 calls on the argument with the two words)', 'thiscall', None, ret='al',
  gen=_gen_4cbc10, note='slice-5 batch 1969 (93)')
S(0x548e90, 'GUESS FUN_00548e90 (word compare; 0x548f40 on the first match, byte store on the second)', 'thiscall', None, ret='eax',
  gen=_gen_548e90, note='slice-5 batch 1969 (94); 0x548f40 GUESS stub')
