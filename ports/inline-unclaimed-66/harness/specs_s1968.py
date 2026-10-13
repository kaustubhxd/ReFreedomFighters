"""specs_s1968.py - slice-5 batches 87 to 91 (GUESS names). Callees are GUESS stubs by address:
0x64f270 and 0x54acc0 (THISCALL, no arguments), 0x634273 (cdecl CRT free, two arguments; the flag path of 0x54add0)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub_noarg(c, addr, name):
    def h(e, r):
        e.calllog.append((name, addr, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(addr, h)


def _free_hook(c):
    def h(e, r):
        e.calllog.append(('CRT free 0x634273 (hook)', 0x634273, None, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x634273, h)


def _gen_63dad0(c):
    return []


def _gen_651850(c):
    _stub_noarg(c, 0x64f270, '0x64f270 (GUESS stub)')
    return [_rnd(c, 0x40)]


def _gen_54add0(c):
    _stub_noarg(c, 0x54acc0, '0x54acc0 (GUESS stub)')
    _free_hook(c)
    return [_rnd(c, 0x40), c.rng.getrandbits(32)]


def _gen_60fe50(c):
    def h(e, r):
        e.calllog.append(('o vtable +0xc8 (stub, callee cleans)', 0xc8, e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2))))
        e.ret(eax=0, argbytes=12)
    vt = c.emu.fake_vtable('batch90 o', 0xc8 // 4 + 1, slots={0xc8: h})
    o = c.emu.fake_object('batch90 o', 0x40, vtable=vt)
    c.emu.w32(0x724a00, o)
    v = c.rng.getrandbits(32)
    c.emu.w32(0x724954, v)
    c.emu.w32(0x724950, v if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return []


def _gen_64ff50(c):
    def h64(e, r):
        e.calllog.append(('o vtable +0x64 (stub)', 0x64, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    def h7c(e, r):
        e.calllog.append(('a vtable +0x7c (stub)', 0x7c, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    vt_o = c.emu.fake_vtable('batch91 o', 0x64 // 4 + 1, slots={0x64: h64})
    o = c.emu.fake_object('batch91 o', 0x40, vtable=vt_o)
    vt_a = c.emu.fake_vtable('batch91 a', 0x7c // 4 + 1, slots={0x7c: h7c})
    a = c.emu.fake_object('batch91 a', 0x40, vtable=vt_a)
    self = _rnd(c, 0x200)
    c.emu.w32(self + 0xbd, o)
    return [self, a]


S(0x63dad0, 'GUESS FUN_0063dad0 (returns 0x30)', 'cdecl', None, ret='eax', gen=_gen_63dad0, note='slice-5 batch 1968 (87)')
S(0x651850, 'GUESS FUN_00651850 (0x64f270, vtable 0x6c3974)', 'thiscall', None, ret='eax', gen=_gen_651850,
  note='slice-5 batch 1968 (88); 0x64f270 GUESS stub')
S(0x54add0, 'GUESS FUN_0054add0 (0x54acc0; CRT free when flag bit 0)', 'thiscall', None, ret='eax', gen=_gen_54add0,
  note='slice-5 batch 1968 (89); 0x54acc0 and 0x634273 GUESS stubs')
S(0x60fe50, 'GUESS FUN_0060fe50 (guarded vtable +0xc8 call)', 'cdecl', None, ret=None, gen=_gen_60fe50,
  note='slice-5 batch 1968 (90); callee stub')
S(0x64ff50, 'GUESS FUN_0064ff50 (vtable +0x64 of [this+0xbd], vtable +0x7c of the argument)', 'thiscall', None, ret='al', gen=_gen_64ff50,
  note='slice-5 batch 1968 (91); callee stubs')
