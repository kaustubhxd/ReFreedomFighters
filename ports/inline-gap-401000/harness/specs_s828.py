"""specs_s828.py - core batch 828 (docs/20-unclaimed-65.md). 0x59e350: thiscall, no arguments, ends with a tail jump to 0x5a04f0. The object
this (a 0x1000 block) has slots 0x110 (two words, callee pops, logged), 0x678 (no arguments, returns a random R, logged), 0x6f4 (two words,
callee pops, logged) and 0x6cc (no arguments, logged). The render sub-object's vtable has slot 0x58 (one argument R, returns object X, logged);
X has slot 0x100 (one argument, returns Y, logged). HOOKED by address (GUESS): 0x477de0 (no arguments, logs ecx) and 0x5a04f0 (the tail target,
logs ecx, pops nothing). The result Y is stored at this+0x8ee."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x477de0, c.emu.stub_fn('477de0 hook', lambda e, r: (e.calllog.append(('0x477de0', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x5a04f0, c.emu.stub_fn('5a04f0 hook', lambda e, r: (e.calllog.append(('0x5a04f0', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    r_val = c.rng.getrandbits(32)
    y_val = c.rng.getrandbits(32)
    x_vt = c.emu.fake_vtable('c828-x', 0x200, {
        0x100: lambda e, r: (e.calllog.append(('0x100', e.reg('ecx'), e.arg32(0))), e.ret(eax=y_val, argbytes=4))[-1]})
    x = _rnd(c, 0x40)
    c.emu.w32(x, x_vt)
    r9_vt = c.emu.fake_vtable('c828-r9', 0x100, {
        0x58: lambda e, r: (e.calllog.append(('0x58', e.reg('ecx'), e.arg32(0))), e.ret(eax=x, argbytes=4))[-1]})
    r9 = _rnd(c, 0x100)
    c.emu.w32(r9, r9_vt)
    render = _rnd(c, 0x200)
    c.emu.w32(render + 0x9b, r9)
    c.emu.w32(0x70039c, render)
    this_vt = c.emu.fake_vtable('c828-this', 0x800, {
        0x110: lambda e, r: (e.calllog.append(('0x110', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=0, argbytes=8))[-1],
        0x678: lambda e, r: (e.calllog.append(('0x678', e.reg('ecx'))), e.ret(eax=r_val, argbytes=0))[-1],
        0x6f4: lambda e, r: (e.calllog.append(('0x6f4', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=0, argbytes=8))[-1],
        0x6cc: lambda e, r: (e.calllog.append(('0x6cc', e.reg('ecx'))), e.ret(eax=0, argbytes=0))[-1]})
    this = _rnd(c, 0x1000)
    c.emu.w32(this, this_vt)
    return [this]


S(0x59e350, 'ZFFActor::ClassInit2 (unknown) thiscall no args', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 828: slot calls on this and the render chain, hooked 0x477de0, tail jump to hooked 0x5a04f0')
