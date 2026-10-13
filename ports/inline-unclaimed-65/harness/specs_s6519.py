"""specs_s6519.py - unclaimed-65 batch 19 (docs/20-unclaimed-65.md, claim 19), branch group 1: ZItem::ClassInit2 with the first
0x2e8 virtual call returning zero (46bce7 to 46bd45). The chain: this's slot 0x2e8 (zero), slot 0x1d8 (returns a block p, two args,
callee pops), slot 0x210 (logs its one argument); the global 0x700390 object's slot 0x20 (two args) returns obj, whose slot 0x2c is
caller-cleaned (three args, logged). 0x4cc1d0 and 0x4cbec0 run as the real exe code. The cookie check 0x633654 is patched to a ret.
Stack-pointer arguments (the frame addresses passed to 0x1d8 and 0x4cbec0) are not logged: the exe and the port have different
frames. Translation cache flushed after the patch."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x633654, c.emu.stub_fn('cookie', lambda e, r: e.ret(eax=0, argbytes=0)))
    # 0x45d3a0 (plain thiscall, no args) is a large helper with many virtual calls and a CRT free() path (return address 0x41e309);
    # it is stubbed as a logging callee for both sides (the port calls it through ext_45d3a0, the same address)
    ss.patch(c, 0x45d3a0, c.emu.stub_fn('45d3a0 logger', lambda e, r: (e.calllog.append(('0x45d3a0', e.reg('ecx'), ())),
                                                                        e.ret(eax=0, argbytes=0))))
    _flush_code(c)


def _gen(c):
    # p: the block returned by slot 0x1d8; its first dword is what 0x4cc1d0 returns (the third argument of the 0x2c call)
    p = _rnd(c, 0x80)
    pv = c.rng.getrandbits(32)
    c.emu.w32(p, pv)

    def s1d8(e, r):
        # arguments: (stack frame pointer, 1); only the value is logged. The out list head is written as an empty list
        # (first dword = its own address + 4): 0x4cbec0 then skips its non-empty branch, which calls 0x634273 (delete)
        out = e.arg32(0)
        e.w32(out, (out + 4) & 0xffffffff)
        e.calllog.append(('0x1d8', e.reg('ecx'), (e.arg32(1),)))
        e.ret(eax=p, argbytes=8)

    def s210(e, r):
        e.calllog.append(('0x210', e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)

    # this: slot 0x2e8 returns zero (group 1), slot 0x1d8 and slot 0x210 as above
    this_vt = c.emu.fake_vtable('classinit2-this', 0x240, {
        0x2e8: lambda e, r: (e.calllog.append(('0x2e8', e.reg('ecx'), ())), e.ret(eax=0, argbytes=0)),
        0x1d8: s1d8,
        0x210: s210,
    })
    self_ = _rnd(c, 0x400)
    c.emu.w32(self_, this_vt)

    # x: the object whose slot 0x2c is caller-cleaned; it logs its three stack arguments (ecx is the 0x1d8 block p)
    def s2c(e, r):
        e.calllog.append(('0x2c', e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2))))
        e.ret(eax=0, argbytes=0)

    x_vt = c.emu.fake_vtable('classinit2-x', 0x40, {0x2c: s2c})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, x_vt)

    # global 0x700390: slot 0x20 (two args, callee pops) returns obj
    def s20(e, r):
        e.calllog.append(('0x20', e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=obj, argbytes=8)

    g_vt = c.emu.fake_vtable('classinit2-g', 0x30, {0x20: s20})
    g = _rnd(c, 0x40)
    c.emu.w32(g, g_vt)
    c.emu.w32(0x700390, g)
    return [self_]


S(0x46bca0, 'ZItem::ClassInit2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 19 (residue 17 gap, claim 19); branch group 1: first 0x2e8 returns zero')
