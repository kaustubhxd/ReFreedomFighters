"""specs_s1970.py - slice-5 batches 95 to 97 (GUESS names).
0x54dc10: the object's vtable slots 0xc (returns al, chosen per case), 0x0 and 0x5c (no arguments, logging). The object is 0x8040 random bytes.
0x4c3150: the objects a and b are logging-free random memory; 0x44c370 (THISCALL, no arguments) is a GUESS stub by address.
0x575d50: 0x573590 (THISCALL, no arguments) is a GUESS stub by address; the object is 0x240 random bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _noarg_hook(c, addr, name):
    def h(e, r):
        e.calllog.append((name, addr, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(addr, h)


def _gen_54dc10(c):
    rv = c.rng.getrandbits(8)

    def h0(e, r):
        e.calllog.append(('this vtable +0x0 (stub)', 0, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)

    def h5c(e, r):
        e.calllog.append(('this vtable +0x5c (stub)', 0x5c, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)

    def hc(e, r):
        e.calllog.append(('this vtable +0xc (stub)', 0xc, e.reg('ecx'), ()))
        e.ret(eax=rv, argbytes=0)
    vt = c.emu.fake_vtable('batch95 self', 0x5c // 4 + 1, slots={0: h0, 0xc: hc, 0x5c: h5c})
    self = _rnd(c, 0x8040)
    c.emu.w32(self, vt)
    return [self]


def _gen_4c3150(c):
    _noarg_hook(c, 0x44c370, '0x44c370 (GUESS stub)')
    b = _rnd(c, 0x100)
    a = _rnd(c, 0x40)
    c.emu.w32(a + 0x18, b)
    c.emu.w8(a + 0x20, c.rng.choice([0, 1, 2]))
    self = _rnd(c, 0x100)
    c.emu.w32(self + 0x44, 0 if c.rng.random() < 0.2 else a)
    return [self]


def _gen_575d50(c):
    _noarg_hook(c, 0x573590, '0x573590 (GUESS stub)')
    return [_rnd(c, 0x240)]


S(0x54dc10, 'GUESS FUN_0054dc10 (slot 0xc as a flag; slots 0 and 0x5c; byte at +0x801c)', 'thiscall', None, ret='al',
  gen=_gen_54dc10, note='slice-5 batch 1970 (95)')
S(0x4c3150, 'GUESS FUN_004c3150 (copy a field through a and b; 0x44c370 when a byte is set)', 'thiscall', None, ret=None,
  gen=_gen_4c3150, note='slice-5 batch 1970 (96); 0x44c370 GUESS stub')
S(0x575d50, 'GUESS FUN_00575d50 (base call 0x573590; vtable 0x6a9348; three fields)', 'thiscall', None, ret='eax',
  gen=_gen_575d50, note='slice-5 batch 1970 (97); 0x573590 GUESS stub')
